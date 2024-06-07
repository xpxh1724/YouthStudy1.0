#include "mainwidget.h"
#include "ui_mainwidget.h"

#include <QDebug>
#include <QDir>
#include <QFileDialog>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>
#include <QTextCodec>
#include <QTimer>
#include <QScrollBar>
#include <QJsonArray>
#include <QClipboard>
#include <QMovie>
#include "user.h"
mainWidget::mainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainWidget)
{
    ui->setupUi(this);
    setWindowTitle("青年大学习后台管理系统");
    initButton();//初始化按钮
    initLogin();//初始化登录类

}

mainWidget::~mainWidget()
{
    editlist->deleteLater();
    login->deleteLater();
    delete ui;
}
//初始化登录类
void mainWidget::initLogin()
{
    login=new Login;
    login->show();
    //团支书登录信号
    connect(login,&Login::loginSuccess,this,[=](QString user,QString pwd){
        this->user=user;this->pwd=pwd;
        ui->UserName->setText(user);
        login->hide();
        ui->stackedWidget->setCurrentIndex(0);
        this->show();
        loadLabel->show();
        //初始化需完成人员名单
        if(!initCompList())
            QMessageBox::information(this,"提示","初始化需完成人员名单失败！");
        ui->schedule->setText(QString("0/%1").arg(NeedCompList.count()));
        startRequestPost(QUrl("https://dxx.scyol.com/backend/adminUser/login"));//发送登录账号请求
    });
    //老师登录信号
    connect(login,&Login::loginTeacher,this,[=](QStringList users,QString team){
        Users=users;
        ui->UsersName->setText(team);
        QString horQss="QTableView QHeaderView{background-color:rgb(240,207,214);}"
                       "QTableView QHeaderView::section{color: rgb(122, 175, 227);"
                       "border-right: 1px solid rgb(240,207,214);border-left: 1px solid rgb(240,207,214);"
                       "font-weight:bold;height: 35px;}";
        QString scrollBarStyle = "QScrollBar { background: rgb(240,207,214); width: 12px; }"
                                 "QScrollBar::handle { background: rgba(136, 193, 150,0.5); border: 0px solid rgb(255, 255, 255); border-radius: 5px; }"
                                 "QScrollBar::handle:hover { background: rgba(136, 193, 150,0.7); }"
                                 "QScrollBar::sub-line, QScrollBar::add-line { background: rgb(210,225,243); }"
                                 "QScrollBar::sub-page:vertical, QScrollBar::add-page:vertical { background: rgb(210,225,243); }";
        ui->UsersTableWidget->horizontalHeader()->setVisible(true);//显示水平头
        ui->UsersTableWidget->verticalHeader()->setVisible(false);//显示垂直头
        ui->UsersTableWidget->horizontalHeader()->setStretchLastSection(true);
        ui->UsersTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//用户不能直接在表格或列表的单元格中进行编辑
        ui->UsersTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);// 设置表头自适应列宽
        ui->UsersTableWidget->horizontalHeader()->setStyleSheet(horQss);
        ui->UsersTableWidget->verticalScrollBar()->setStyleSheet(scrollBarStyle);
        ui->UsersTableWidget->horizontalScrollBar()->setStyleSheet(scrollBarStyle);
        ui->schedule_2->setText(QString("0/%1").arg(Users.count()));
        //退出登录
        connect(ui->btnExit,&QPushButton::clicked,this,[=]{
            ui->UsersName->clear();
            ui->schedule_2->clear();
            int rowCount = ui->UsersTableWidget->rowCount();
            for (int i = rowCount - 1; i >= 0; --i) {
                ui->UsersTableWidget->removeRow(i);
            }
            Users.clear();
            atomicInt=0;
            this->hide();
            login->show();
        });
        //一键重新查询
        connect(ui->btnReQuery,&QPushButton::clicked,this,[=]{
            int row=ui->UsersTableWidget->rowCount();
            for (int i=0;i<row;++i) {
                QWidget *widget = ui->UsersTableWidget->cellWidget(i, 0);
                if (widget)
                {
                    User *myuser = qobject_cast<User *>(widget); //判断是不是User控件
                    if (myuser)
                    {
                        // 确实是User 控件
                        myuser->ReQuery();
                    }
                }
            }
        });
        //复制全部未完成名单
        connect(ui->btnCopyAllInCompList,&QPushButton::clicked,this,[=]{
            QString msg;
            int row=ui->UsersTableWidget->rowCount();
            for (int i=0;i<row;++i) {
                QWidget *widget = ui->UsersTableWidget->cellWidget(i, 0);
                if (widget)
                {
                    User *myuser = qobject_cast<User *>(widget); //判断是不是User控件
                    if (myuser)
                    {
                        // 确实是User 控件
                        if(i==row-1)
                        {
                            msg+=myuser->CopyAllInCompList();
                        }
                        else {
                            msg+=myuser->CopyAllInCompList()+"\n";
                        }
                    }
                }
            }
            QClipboard *clipboard = QApplication::clipboard();
            clipboard->setText(msg);
            QMessageBox::information(this,"提醒","团支部全部未完成人员名单已复制到粘贴板！");
        });
        login->hide();
        ui->stackedWidget->setCurrentIndex(1);
        this->show();
        for(QString msg:Users)
        {
            User *myuser=new User;
            connect(myuser,&User::allSuccess,this,[=]{++atomicInt;ui->schedule_2->setText(QString("%1/%2").arg(atomicInt).arg(Users.count()));});
            connect(myuser,&User::loadSelect,this,[=]{
                if(atomicInt!=0)
                    --atomicInt;
                ui->schedule_2->setText(QString("%1/%2").arg(atomicInt).arg(Users.count()));
            });
            connect(myuser,&User::updateSnum2,this,[=](QString snum2){ui->snum2->setText(snum2);});
            int nowRow=ui->UsersTableWidget->rowCount();
            ui->UsersTableWidget->insertRow(nowRow);
            ui->UsersTableWidget->setRowHeight(nowRow,65);
            ui->UsersTableWidget->setCellWidget(nowRow,0,myuser);
            myuser->UserWorking(msg.split(' ').at(0),msg.split(' ').at(1));
        }

    });

}
//初始化按钮
void mainWidget::initButton()
{
    QString horQss="QTableView QHeaderView{background-color:rgb(240,207,214);}"
                   "QTableView QHeaderView::section{color: rgb(122, 175, 227);"
                   "border-right: 1px solid rgb(240,207,214);border-left: 1px solid rgb(240,207,214);"
                   "font-weight:bold;height: 35px;}";
    QString scrollBarStyle = "QScrollBar { background: rgb(240,207,214); width: 12px; }"
                             "QScrollBar::handle { background: rgba(136, 193, 150,0.5); border: 0px solid rgb(255, 255, 255); border-radius: 5px; }"
                             "QScrollBar::handle:hover { background: rgba(136, 193, 150,0.7); }"
                             "QScrollBar::sub-line, QScrollBar::add-line { background: rgb(210,225,243); }"
                             "QScrollBar::sub-page:vertical, QScrollBar::add-page:vertical { background: rgb(210,225,243); }";
    ui->NeedCompTableWidget->horizontalHeader()->setVisible(true);//显示水平头
    ui->NeedCompTableWidget->verticalHeader()->setVisible(false);//显示垂直头
    ui->NeedCompTableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->NeedCompTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//用户不能直接在表格或列表的单元格中进行编辑
    ui->NeedCompTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);// 设置表头自适应列宽
    ui->NeedCompTableWidget->horizontalHeader()->setStyleSheet(horQss);
    ui->NeedCompTableWidget->verticalScrollBar()->setStyleSheet(scrollBarStyle);
    ui->NeedCompTableWidget->horizontalScrollBar()->setStyleSheet(scrollBarStyle);

    ui->InCompTableWidget->horizontalHeader()->setVisible(true);//显示水平头
    ui->InCompTableWidget->verticalHeader()->setVisible(false);//显示垂直头
    ui->InCompTableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->InCompTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//用户不能直接在表格或列表的单元格中进行编辑
    ui->InCompTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);// 设置表头自适应列宽
    ui->InCompTableWidget->horizontalHeader()->setStyleSheet(horQss);
    ui->InCompTableWidget->verticalScrollBar()->setStyleSheet(scrollBarStyle);
    ui->InCompTableWidget->horizontalScrollBar()->setStyleSheet(scrollBarStyle);

    ui->UserTableWidget->horizontalHeader()->setVisible(true);//显示水平头
    ui->UserTableWidget->verticalHeader()->setVisible(false);//显示垂直头
    ui->UserTableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->UserTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//用户不能直接在表格或列表的单元格中进行编辑
    ui->UserTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);// 设置表头自适应列宽
    ui->UserTableWidget->horizontalHeader()->setStyleSheet(horQss);
    ui->UserTableWidget->verticalScrollBar()->setStyleSheet(scrollBarStyle);
    ui->UserTableWidget->horizontalScrollBar()->setStyleSheet(scrollBarStyle);
    movie = new QMovie(":/ptr/load.gif");
    loadLabel = new QLabel;
    loadLabel->setMovie(movie);
    movie->start();
    loadLabel->setParent(ui->UserTableWidget);
    loadLabel->resize(200,200);
    loadLabel->move(mapFromGlobal(ui->UserTableWidget->pos()+QPoint(400,300)));
    //编辑名单
    connect(ui->btnEditList,&QPushButton::clicked,this,[=]{
        editlist=new EditList;
        //返回信号
        connect(editlist,&EditList::toMainWidget,this,[=]{editlist->close();});
        //保存文件信号
        connect(editlist,&EditList::updateNeedCompTableWidget,this,[=]{
            editlist->close();
            int rowCount = ui->NeedCompTableWidget->rowCount();
            for (int i = rowCount - 1; i >= 0; --i) {
                ui->NeedCompTableWidget->removeRow(i);
            }
            QFile f(QString("./compList/%1.txt").arg(user));
            f.open(QIODevice::ReadOnly | QIODevice::Text);
            NeedCompList.clear();
            while(!f.atEnd())
            {
                QByteArray line = f.readLine();
                QString str(line);
                str.remove('\n');
                NeedCompList.append(str);
                int nowRow=ui->NeedCompTableWidget->rowCount();
                ui->NeedCompTableWidget->insertRow(nowRow);//增加一行
                //                ui->NeedCompTableWidget->setRowHeight(nowRow,30);//设置行高度
                QTableWidgetItem *nameItem=new QTableWidgetItem(str);
                nameItem->setTextAlignment(Qt::AlignCenter);
                ui->NeedCompTableWidget->setItem(nowRow,0,nameItem);
            }
            f.close();
            QMessageBox::information(this,"保存文件","保存成功!");
        });
        QStringList editList;
        int rowCount = ui->NeedCompTableWidget->rowCount();
        for(int i=0;i<rowCount;++i)
        {
            editList.append(ui->NeedCompTableWidget->item(i,0)->text());
        }
        editlist->EditListShow(editList,user);
    });
    //显示未完成
    connect(ui->btnXlsx,&QPushButton::clicked,this,[=]{
        if(ui->NeedCompTableWidget->item(0,0)->text()=="请录入需完成人员名单")
        {
            QMessageBox::information(this,"提示","请录入需完成人员名单");
            return;
        }
        if(token.isEmpty())
        {
            QMessageBox::information(this,"提示","token为空");
            return;
        }
        if(id==0)
        {
            QMessageBox::information(this,"提示","id为空");
            return;
        }
        //发送下载用户学习数据请求
        startRequestGet(QUrl(QString("https://dxx.scyol.com/backend//study/student/excel?stagesId=%1&orgId=%2&name=&tel=&token=%3").arg(id).arg(orgId).arg(token)));
        loadLabel->show();
        int rowCount = ui->UserTableWidget->rowCount();
        for (int i = rowCount - 1; i >= 0; --i) {
            ui->UserTableWidget->removeRow(i);
        }
        int rowCount2 = ui->InCompTableWidget->rowCount();
        for (int i = rowCount2 - 1; i >= 0; --i) {
            ui->InCompTableWidget->removeRow(i);
        }
        ui->UserCount->setText(QString("共计 XX 条数据"));
        ui->schedule->setText(QString("0/%1").arg(NeedCompList.count()));
    });
    //退出登录
    connect(ui->btnExitLogin,&QPushButton::clicked,this,[=]{
        int rowCount = ui->UserTableWidget->rowCount();
        for (int i = rowCount - 1; i >= 0; --i) {
            ui->UserTableWidget->removeRow(i);
        }

        int rowCount2 = ui->InCompTableWidget->rowCount();
        for (int i = rowCount2 - 1; i >= 0; --i) {
            ui->InCompTableWidget->removeRow(i);
        }
        int rowCount3 = ui->NeedCompTableWidget->rowCount();
        for (int i = rowCount3 - 1; i >= 0; --i) {
            ui->NeedCompTableWidget->removeRow(i);
        }
        user.clear();
        pwd.clear();
        token.clear();
        orgId=0;
        NeedCompList.clear();
        ui->UserCount->setText(QString("共计 XX 条数据"));
        this->hide();
        login->show();
    });
    //复制名单
    connect(ui->btnCopyList,&QPushButton::clicked,this,[=]{
        QClipboard *clipboard = QApplication::clipboard();
        QString incomplist;
        for(int i=0;i<ui->InCompTableWidget->rowCount();++i)
        {
            if(i==ui->InCompTableWidget->rowCount()-1)
            {
                incomplist+=ui->InCompTableWidget->item(i,0)->text();
            }
            else {
                incomplist+=ui->InCompTableWidget->item(i,0)->text()+"\n";
            }
        }
        clipboard->setText(incomplist);
        QMessageBox::information(this,"提醒","未完成人员名单已复制到粘贴板！");
    });
}
//查询xlsx文件行数
int mainWidget::findLastRowWithDataInColumnA(Worksheet *worksheet)
{
    int lastRow = 0; // 初始化行号为0，假设没有数据
    for (int row = 1; row <= worksheet->dimension().lastRow(); ++row) {
        if (worksheet->read(row, 0).toString().isEmpty()) { // 读取A列的单元格，列索引为0
            lastRow = row; // 更新最后一个有数据的行号
        }
    }
    return lastRow;
}
//初始化需完成人员名单
bool mainWidget::initCompList()
{
    //读取需完成人员名单
    QFile file(QString("./compList/%1.txt").arg(user));
    QString displayString;
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"文件不存在!"<<endl;
        ui->NeedCompTableWidget->insertRow(0);
        ui->NeedCompTableWidget->setRowHeight(0,70);
        QTableWidgetItem *tsItem=new QTableWidgetItem("请录入需完成人员名单");
        tsItem->setTextAlignment(Qt::AlignCenter);
        ui->NeedCompTableWidget->setItem(0,0,tsItem);
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
        int nowRow=ui->NeedCompTableWidget->rowCount();
        ui->NeedCompTableWidget->insertRow(nowRow);//增加一行
        ui->NeedCompTableWidget->setRowHeight(nowRow,30);//设置行高度
        QTableWidgetItem *cidItem=new QTableWidgetItem(str);
        cidItem->setTextAlignment(Qt::AlignCenter);
        ui->NeedCompTableWidget->setItem(nowRow,0,cidItem);
    }
    file.close();
    return true;
}
//Post请求(获取orgId,token)
void mainWidget::startRequestPost(const QUrl &requestedUrl)
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
    connect(reply,&QNetworkReply::finished,this,&mainWidget::replyFinishedPost);
    eventLoop.exec();
}
//Post请求2(获取id下载号,name年,snum期数)
void mainWidget::startRequestPost2(const QUrl &requestedUrl)
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
    connect(reply2,&QNetworkReply::finished,this,&mainWidget::replyFinishedPost2);
    eventLoop.exec();
}
//Get请求
void mainWidget::startRequestGet(const QUrl &requestedUrl)
{
    url=requestedUrl;
    manager3 = new QNetworkAccessManager(this);
    req3.setUrl(url);
    //由于请求发生重定向，所以一定要加上这行代码，设置自动跳转，否则会返回 302
    req3.setAttribute(QNetworkRequest::FollowRedirectsAttribute, true);
    //get方式发送请求
    reply3 = manager3->get(req3);
    //    //将服务器的返回信号与replyFinished槽连接起来，当服务器返回消息时，会在槽里做相应操作
    connect(reply3,&QNetworkReply::finished,this,&mainWidget::replyFinishedGet);
}
//获取id下载号,name年,snum期数
void mainWidget::getIdNameSnum()
{
    if(token.isEmpty())
    {
        QMessageBox::information(this,"提示","getIdNameSnum时token为空！");
        return;
    }
    startRequestPost2(QString("https://dxx.scyol.com/backend/stages/select/list?token=%1").arg(token));
}
//查询显示未完成
void mainWidget::select()
{
    ui->btnXlsx->clicked();
}
//Post返回结果处理(获取orgId、token)
void mainWidget::replyFinishedPost()
{
    // <1>判断有没有错误
    if (reply->error()){
        qDebug()<<reply->errorString();
        reply->deleteLater();
        return;
    }
    // <2>检测网页返回状态码，常见是200，404等，200为成功
    int statusCode  = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
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
                QMessageBox::information(this,"提示","orgId或token为空无法继续执行getIdNameSnum");
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
            qDebug()<< "http redirect to " << redirectedUrl.toString();
            return;
        }
    }

}
//Post返回结果处理2(获取id、name、snum)
void mainWidget::replyFinishedPost2()
{
    // <1>判断有没有错误
    if (reply2->error()){
        qDebug()<<reply2->errorString();
        reply2->deleteLater();
        return;
    }
    // <2>检测网页返回状态码，常见是200，404等，200为成功
    int statusCode  = reply2->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    // <3>判断是否需要重定向
    if (statusCode >= 200 && statusCode <300){
        // ok 准备读数据
        QTextCodec *codec = QTextCodec::codecForName("utf8");
        QString all = codec->toUnicode(reply2->readAll());
        //转为json格式
        QJsonDocument jsonDocument = QJsonDocument::fromJson(all.toUtf8().data());
        if (jsonDocument.isNull())
        {
            qDebug()<<"数据解析有误"; //判断是否解析出问题
        }
        QJsonObject jsonObject = jsonDocument.object();
        if (jsonObject["data"].isArray())
        {
            QJsonArray dataArray=jsonObject["data"].toArray();
            QJsonValue dataArrayFrist=dataArray[0];
            if (dataArrayFrist.isObject()) {
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
                        qDebug()<<"id:"<<id<<"name:"<<name<<"snum:"<<snum;
                        ui->snum->setText(name+snum+" 完成进度:");
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
            qDebug()<< "http redirect to " << redirectedUrl.toString();
            return;
        }
    }
}
//Get返回结果处理(获取xlsx数据)
void mainWidget::replyFinishedGet()
{
    int rowCount = ui->UserTableWidget->rowCount();
    for (int i = rowCount - 1; i >= 0; --i) {
        ui->UserTableWidget->removeRow(i);
    }

    int rowCount2 = ui->InCompTableWidget->rowCount();
    for (int i = rowCount2 - 1; i >= 0; --i) {
        ui->InCompTableWidget->removeRow(i);
    }
    bool success = QFile::remove("学习用户明细.xlsx");
    if (success) {
        qDebug() << "学习用户明细.xlsx文件已删除";
    } else {
        qDebug() << "学习用户明细.xlsx删除文件失败";
    }
    // <1>判断有没有错误
    if (reply3->error()){
        qDebug()<<reply3->errorString();
        reply3->deleteLater();
        return;
    }
    // <2>检测网页返回状态码，常见是200，404等，200为成功
    int statusCode  = reply3->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    // <3>判断是否需要重定向
    if (statusCode >= 200 && statusCode <300){
        // ok 准备读数据
        QFile file("学习用户明细.xlsx");
        if (!file.open(QIODevice::WriteOnly)) {
            qDebug() << "Failed to open file for writing:" << file.errorString();
            return;
        }
        QByteArray byteArray=reply3->readAll(); //包含XLSX数据的QByteArray
        if (byteArray.size() > 0) {
            qint64 bytesWritten = file.write(byteArray);
            if (bytesWritten == -1) {
                qDebug() << "文件下载失败，原因如下:\n" << file.errorString();
            } else {
                qDebug() << bytesWritten << "bytes 文件下载成功！";
                file.close();
                QStringList incompList=NeedCompList;//拷贝需要完成的人员名单
                // 打开 Excel 文件
                QXlsx::Document xlsx("学习用户明细.xlsx");
                // 获取工作表对象
                QXlsx::Worksheet *worksheet = xlsx.currentWorksheet();
                int lastRow=findLastRowWithDataInColumnA(worksheet);
                qDebug()<<"一共 "<<lastRow<<"条数据"<<endl;

                for(int i=2;i<=lastRow;++i)
                {
                    QVariant name = worksheet->read(i,1);
                    QVariant iphone = worksheet->read(i,2);
                    QVariant organization = worksheet->read(i,3);
                    QVariant time = worksheet->read(i,4);
                    int nowRow=ui->UserTableWidget->rowCount();
                    ui->UserTableWidget->insertRow(nowRow);//增加一行
                    ui->UserTableWidget->setRowHeight(nowRow,30);//设置行高度
                    QTableWidgetItem *nameItem=new QTableWidgetItem(name.toString());
                    nameItem->setTextAlignment(Qt::AlignCenter);
                    ui->UserTableWidget->setItem(nowRow,0,nameItem);
                    QTableWidgetItem *iphoneItem=new QTableWidgetItem(iphone.toString());
                    iphoneItem->setTextAlignment(Qt::AlignCenter);
                    ui->UserTableWidget->setItem(nowRow,1,iphoneItem);
                    QTableWidgetItem *organizationItem=new QTableWidgetItem(organization.toString());
                    organizationItem->setTextAlignment(Qt::AlignCenter);
                    ui->UserTableWidget->setItem(nowRow,2,organizationItem);
                    QTableWidgetItem *timeItem=new QTableWidgetItem(time.toString());
                    timeItem->setTextAlignment(Qt::AlignCenter);
                    ui->UserTableWidget->setItem(nowRow,3,timeItem);
                }

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
                for(auto a:incompList)
                {
                    int nowRow=ui->InCompTableWidget->rowCount();
                    ui->InCompTableWidget->insertRow(nowRow);//增加一行
                    ui->InCompTableWidget->setRowHeight(nowRow,30);//设置行高度
                    QTableWidgetItem *cidItem=new QTableWidgetItem(a);
                    cidItem->setTextAlignment(Qt::AlignCenter);
                    ui->InCompTableWidget->setItem(nowRow,0,cidItem);
                }
                ui->UserCount->setText(QString("共计 %1 条数据").arg(lastRow-1));
                ui->schedule->setText(QString("%1/%2").arg(lastRow-1).arg(NeedCompList.count()));
                loadLabel->hide();
            }
        } else {
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
            qDebug()<< "http redirect to " << redirectedUrl.toString();
            return;
        }
    }

}
//导入人员数据
void mainWidget::on_btnImport_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(nullptr, tr("选择xlsx文件"), "", tr("Excel Files (*.xlsx)"));
    // 打开 Excel 文件
    QXlsx::Document xlsx(filePath);
    // 获取工作表对象
    QXlsx::Worksheet *worksheet = xlsx.currentWorksheet();
    int lastRow=findLastRowWithDataInColumnA(worksheet);
    qDebug()<<"一共 "<<lastRow<<"条数据"<<endl;

    QMap<QString,QVector<QString>>shuju;
    for(int i=3;i<=lastRow;++i)
    {
        QString bj = worksheet->read(i,2).toString();
        QString tzb= bj.left(bj.length() - 5)+"20"+bj.right(5).left(2)+QString("级%1班团支部").arg(bj.right(2).toInt());
        QString name = worksheet->read(i,4).toString();
        //        qDebug()<<"团支部："<<tzb<<" 姓名："<<name;
        shuju[tzb].push_back(name);
    }

    for(int i=0;i<shuju.size();++i)
    {
        //追加账号
        // 创建一个QFile对象，打开文件
        QString userListTxtPath = "./userList/userlist.txt";
        QFile fileUserList(userListTxtPath);
        if (!fileUserList.open(QIODevice::Append | QIODevice::Text))
        {
            qDebug() << "无法打开文件：" << userListTxtPath;
            return;
        }
        // 设置文本流的编码格式为UTF-8
        QTextCodec *codec = QTextCodec::codecForName("UTF-8");
        QTextStream outUserList(&fileUserList);
        outUserList.setCodec(codec);
        outUserList<<"\n"<<QString("%1 123456 团支书").arg(shuju.keys()[i]);
        // 关闭文件
        fileUserList.close();

        // 创建一个QFile对象，打开文件
        QString txtName=QString("./compList/%1.txt").arg(shuju.keys()[i]);
        QFile file(txtName);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            qDebug() << "无法打开文件：" << txtName;
            return;
        }
        // 创建一个QTextStream对象，用于写入数据
        QTextStream out(&file);
        out.setCodec(codec);
        for (int j=0;j<shuju.value(shuju.keys()[i]).size();++j) {
            if(j==shuju.first().size()-1)
            {
                out<<shuju.value(shuju.keys()[i])[j];
            }
            else {
                out<<shuju.value(shuju.keys()[i])[j]<<"\n";
            }
        }
        // 关闭文件
        file.close();
    }
    QMessageBox::information(this,"导入人员数据","导入人员数据成功！");
}
