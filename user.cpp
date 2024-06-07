#include "user.h"
#include "ui_user.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QMessageBox>
#include <QTextCodec>
#include <QTimer>
#include <incomplistwidget.h>
User::User(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::User)
{
    ui->setupUi(this);
}

User::~User()
{
    delete ui;
}

void User::UserWorking(QString user, QString pwd)
{
    this->user=user;this->pwd=pwd;
    ui->user->setText(user);
    initCompList();//初始化需完成人员名单
    ui->schedule->setText(QString("完成进度：0/%1").arg(NeedCompList.count()));
    startRequestPost(QUrl("https://dxx.scyol.com/backend/adminUser/login"));//发送登录账号请求
}

int User::findLastRowWithDataInColumnA(Worksheet *worksheet)
{
    int lastRow = 0; // 初始化行号为0，假设没有数据
    for (int row = 1; row <= worksheet->dimension().lastRow(); ++row) {
        if (worksheet->read(row, 0).toString().isEmpty()) { // 读取A列的单元格，列索引为0
            lastRow = row; // 更新最后一个有数据的行号
        }
    }
    return lastRow;
}

bool User::initCompList()
{
    //读取需完成人员名单
    QFile file(QString("./compList/%1.txt").arg(user));
    QString displayString;
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"文件不存在!"<<endl;
        return false;
    }
    QTextStream in(&file);
    // 设置文本流的编码格式为UTF-8
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    in.setCodec(codec); // 设置编码为UTF-8
    while(!in.atEnd())
    {
        QString str = in.readLine();
        displayString.append(str);
        str.remove('\n');
        NeedCompList.append(str);
    }
    file.close();
    return true;
}

void User::startRequestPost(const QUrl &requestedUrl)
{
    url=requestedUrl;
    //1.json格式传输报文
    QJsonObject json;
    QJsonDocument jsonDoc;
    //构建json数据
    json["username"] = user;
    json["password"] = pwd;
    jsonDoc.setObject(json);
    QByteArray dataArray = jsonDoc.toJson(QJsonDocument::Compact);
    //2.构造URL&&请求头
    //构造请求头
    req.setUrl(url);
    req.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json;charset=UTF-8"));
    //3.post数据
    manager = new QNetworkAccessManager(this);
    reply = manager->post(req,dataArray);
    QEventLoop eventLoop;
    connect(manager,SIGNAL(finished(QNetworkReply*)),&eventLoop,SLOT(quit()));
    connect(reply,&QNetworkReply::finished,this,&User::replyFinishedPost);
    eventLoop.exec();
}

void User::startRequestPost2(const QUrl &requestedUrl)
{
    url=requestedUrl;
    //1.json格式传输报文
    QJsonObject json;
    QJsonDocument jsonDoc;
    //构建json数据
    json["pageNo"] = 1;
    json["pageSize"] = 500;
    jsonDoc.setObject(json);
    QByteArray dataArray = jsonDoc.toJson(QJsonDocument::Compact);
    //2.构造URL&&请求头
    //构造请求头
    req2.setUrl(url);
    req2.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json;charset=UTF-8"));
    //3.post数据
    manager2 = new QNetworkAccessManager(this);
    reply2 = manager2->post(req2,dataArray);
    QEventLoop eventLoop;
    connect(manager2,SIGNAL(finished(QNetworkReply*)),&eventLoop,SLOT(quit()));
    connect(reply2,&QNetworkReply::finished,this,&User::replyFinishedPost2);
    eventLoop.exec();
}

void User::startRequestGet(const QUrl &requestedUrl)
{
    url=requestedUrl;
    manager3 = new QNetworkAccessManager(this);
    req3.setUrl(url);
    //由于请求发生重定向，所以一定要加上这行代码，设置自动跳转，否则会返回 302
    req3.setAttribute(QNetworkRequest::FollowRedirectsAttribute, true);
    //get方式发送请求
    reply3 = manager3->get(req3);
    //    //将服务器的返回信号与replyFinished槽连接起来，当服务器返回消息时，会在槽里做相应操作
    connect(reply3,&QNetworkReply::finished,this,&User::replyFinishedGet);
}

void User::ReQuery()
{
    ui->btnLoad->clicked();
}

QString User::CopyAllInCompList()
{
    QString msg=user+" 未完成人员名单如下:\n";
    for(int i=0;i<InCompList.count();++i)
    {
        if(i==InCompList.count()-1)
        {
            msg+=InCompList[i];
        }
        else {
            msg+=InCompList[i]+"\n";
        }
    }
    return msg;
}

void User::select()
{
    if(token.isEmpty())
    {
        qDebug()<<"token为空";
        QMessageBox::information(this,"提示","select时token为空");
        return;
    }
    if(id==0)
    {
        qDebug()<<"id为0";
        QMessageBox::information(this,"提示","select时id为0");
        return;
    }
    //发送下载用户学习数据请求
    startRequestGet(QUrl(QString("https://dxx.scyol.com/backend//study/student/excel?stagesId=%1&orgId=%2&name=&tel=&token=%3").arg(id).arg(orgId).arg(token)));
}

void User::getIdNameSnum()
{
    if(token.isEmpty())
    {
        QMessageBox::information(this,"提示","getIdNameSnum时token为空！");
        return;
    }
    startRequestPost2(QString("https://dxx.scyol.com/backend/stages/select/list?token=%1").arg(token));
}

void User::replyFinishedPost()
{
    // <1>判断有没有错误
    if (reply->error()){
        qDebug()<<reply->errorString();
        reply->deleteLater();
        return;
    }
    // <2>检测网页返回状态码，常见是200，404等，200为成功
    int statusCode  = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    //    qDebug() << "statusCode:" << statusCode;
    // <3>判断是否需要重定向
    if (statusCode >= 200 && statusCode <300){
        // ok 准备读数据
        QTextCodec *codec = QTextCodec::codecForName("utf8");
        QString all = codec->toUnicode(reply->readAll());
        //转为json格式
        QJsonDocument jsonDocument = QJsonDocument::fromJson(all.toUtf8().data());
        if (jsonDocument.isNull()){
            qDebug()<<"数据解析有误"; //判断是否解析出问题
        }
        QJsonObject jsonObject = jsonDocument.object();
        if(jsonObject["data"].isObject())
        {
            QJsonObject dataObj=jsonObject["data"].toObject();
            orgId=dataObj["orgId"].toInt();
            token=dataObj["token"].toString();
            qDebug()<<"orgId:"<<orgId<<" token:"<<token;
            if(orgId!=0&&!token.isEmpty())
                QMetaObject::invokeMethod(this, "getIdNameSnum", Qt::QueuedConnection);
            else
            {
                QMessageBox::information(this,"提示","orgId=0或token为空无法继续执行getIdNameSnum");
                return;
            }
        }
        // 数据读取完成之后，清除reply
        reply->deleteLater();
        reply = nullptr;
    }
    else if (statusCode >=300 && statusCode <400){
        // redirect

        // 获取重定向信息
        const QVariant redirectionTarget = reply->attribute(QNetworkRequest::RedirectionTargetAttribute);
        // 检测是否需要重定向，如果不需要则读数据
        if (!redirectionTarget.isNull()) {
            const QUrl redirectedUrl = url.resolved(redirectionTarget.toUrl());

            reply->deleteLater();
            reply = nullptr;
            startRequestGet(redirectedUrl);
            qDebug()<< "http redirect to " << redirectedUrl.toString();
            return;
        }
    }
}

void User::replyFinishedPost2()
{
    // <1>判断有没有错误
    if (reply2->error()){
        qDebug()<<reply2->errorString();
        reply2->deleteLater();
        return;
    }
    // <2>检测网页返回状态码，常见是200，404等，200为成功
    int statusCode  = reply2->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    //    qDebug() << "statusCode:" << statusCode;
    // <3>判断是否需要重定向
    if (statusCode >= 200 && statusCode <300){
        // ok 准备读数据
        QTextCodec *codec = QTextCodec::codecForName("utf8");
        QString all = codec->toUnicode(reply2->readAll());
        //转为json格式
        QJsonDocument jsonDocument = QJsonDocument::fromJson(all.toUtf8().data());
        if (jsonDocument.isNull()){
            qDebug()<<"数据解析有误"; //判断是否解析出问题
        }
        QJsonObject jsonObject = jsonDocument.object();
        if (jsonObject["data"].isArray())
        {
            QJsonArray dataArray=jsonObject["data"].toArray();
            QJsonValue dataArrayFrist=dataArray[0];
            if (dataArrayFrist.isObject())
            {
                QJsonObject dataArrayFristObj = dataArrayFrist.toObject();
                if(dataArrayFristObj["snumList"].isArray())
                {
                    QJsonArray snumListArray=dataArrayFristObj["snumList"].toArray();
                    QJsonValue snumListArrayFrist=snumListArray[0];
                    if(snumListArrayFrist.isObject())
                    {
                        QJsonObject nowObj = snumListArrayFrist.toObject();
                        id=nowObj["id"].toInt();
                        name=nowObj["name"].toString();
                        snum=nowObj["snum"].toString();
                        qDebug()<<user<<" id:"<<id<<"name:"<<name<<"snum:"<<snum;
                        emit updateSnum2(name+snum+" 完成团支部:");
                        if(id!=0&&!name.isEmpty()&&!snum.isEmpty())
                        {
                            QMetaObject::invokeMethod(this, "select", Qt::QueuedConnection);
                        }
                        else {
                            QMessageBox::information(this,"提示",QString("id:%1 name:%2 snum:%3 数据异常无法下载xlsx文件！").arg(id).arg(name).arg(snum));
                            return;
                        }
                    }
                }
            }
            else
            {
                // 不是对象
                qDebug() << "解析获取当前期数失败！";
            }
        }
        // 数据读取完成之后，清除reply
        reply2->deleteLater();
        reply2 = nullptr;
    }
    else if (statusCode >=300 && statusCode <400){
        // redirect
        // 获取重定向信息
        const QVariant redirectionTarget = reply2->attribute(QNetworkRequest::RedirectionTargetAttribute);
        // 检测是否需要重定向，如果不需要则读数据
        if (!redirectionTarget.isNull()) {
            const QUrl redirectedUrl = url.resolved(redirectionTarget.toUrl());

            reply2->deleteLater();
            reply2 = nullptr;
            startRequestGet(redirectedUrl);
            qDebug()<< "http redirect to " << redirectedUrl.toString();
            return;
        }
    }
}

void User::replyFinishedGet()
{
    bool success = QFile::remove(QString("%1学习用户明细.xlsx").arg(user));
    if (success) {
        qDebug() << QString("%1学习用户明细.xlsx").arg(user)<<"文件已删除";
    } else {
        qDebug() << QString("%1学习用户明细.xlsx").arg(user)<<"删除文件失败";
    }
    // <1>判断有没有错误
    if (reply3->error())
    {
        qDebug()<<reply3->errorString();
        reply3->deleteLater();
        return;
    }
    // <2>检测网页返回状态码，常见是200，404等，200为成功
    int statusCode  = reply3->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    // <3>判断是否需要重定向
    if (statusCode >= 200 && statusCode <300)
    {
        QFile file(QString("%1学习用户明细.xlsx").arg(user));
        if (!file.open(QIODevice::WriteOnly))
        {
            qDebug() << "Failed to open file for writing:" << file.errorString();
            return;
        }
        QByteArray byteArray=reply3->readAll(); //包含XLSX数据的QByteArray
        if (byteArray.size() > 0)
        {
            qint64 bytesWritten = file.write(byteArray);
            if (bytesWritten == -1)
            {
                qDebug() << "文件下载失败，原因如下:\n" << file.errorString();
            }
            else
            {
                qDebug() << bytesWritten << "bytes 文件下载成功！";
                file.close();
                QStringList incompList=NeedCompList;//拷贝需要完成的人员名单
                // 打开 Excel 文件
                QXlsx::Document xlsx(QString("%1学习用户明细.xlsx").arg(user));
                // 获取工作表对象
                QXlsx::Worksheet *worksheet = xlsx.currentWorksheet();
                int lastRow=findLastRowWithDataInColumnA(worksheet);
                qDebug()<<"一共 "<<lastRow<<"条数据"<<endl;

                // 获取单元格内容
                for(int i=2;i<=lastRow;++i)
                {
                    QVariant value = worksheet->read(i,1);
                    QString strValue=value.toString();
                    if(incompList.contains(strValue))
                        incompList.removeOne(strValue);
                    else{
                        incompList.append(strValue+"(非本支部)");
                    }
                }
                // 保存文件
                xlsx.save();
                InCompList=incompList;
                ui->schedule->setText(QString("完成进度：%1/%2").arg(lastRow-1).arg(NeedCompList.count()));
                if(lastRow-1>=NeedCompList.count())
                {
                    qDebug()<<user<<"已全部完成";
                    emit allSuccess();
                }
                else {
                    qDebug()<<user<<"未完成名单如下:\n"<<InCompList;
                }
            }
        }
        else
        {
            qDebug() << "文件为空!";
        }
        // 数据读取完成之后，清除reply
        reply3->deleteLater();
        reply3 = nullptr;
    }
    else if (statusCode >=300 && statusCode <400)
    {
        // 获取重定向信息
        const QVariant redirectionTarget = reply3->attribute(QNetworkRequest::RedirectionTargetAttribute);
        // 检测是否需要重定向，如果不需要则读数据
        if (!redirectionTarget.isNull()) {
            const QUrl redirectedUrl = url.resolved(redirectionTarget.toUrl());
            reply3->deleteLater();
            reply3 = nullptr;
            startRequestGet(redirectedUrl);
            qDebug()<< "http redirect to " << redirectedUrl.toString();
            return;
        }
    }
}
//重新加载
void User::on_btnLoad_clicked()
{
    ui->schedule->setText(QString("完成进度：0/%1").arg(NeedCompList.count()));
    if(InCompList.count()==0)
        emit loadSelect();
    select();
}
//查看未完成人员名单
void User::on_btnLook_clicked()
{
    if(InCompList.count()==0)
    {
        QMessageBox::information(this,"提示",QString("%1 已全部完成！").arg(user));
        return;
    }
    else if(InCompList.count()>0)
    {
        InCompListWidget *inCompListWidget=new InCompListWidget;
        connect(inCompListWidget,&InCompListWidget::Return,this,[=]{inCompListWidget->close();inCompListWidget->deleteLater();});
        inCompListWidget->initInCompListWidget(user,InCompList);
    }
}
