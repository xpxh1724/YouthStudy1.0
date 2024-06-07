#include "editlist.h"
#include "ui_editlist.h"
#include <QDebug>
#include <QFile>
#include <QMessageBox>
#include <QTextCodec>
EditList::EditList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditList)
{
    ui->setupUi(this);
    setWindowTitle(QString("%1需完成人员名单").arg(user));
    setModal(true);
}

EditList::~EditList()
{
    delete ui;
}

void EditList::EditListShow(QStringList userList,QString user)
{
    this->user=user;
    ui->textEdit->clear();
    QString displayString;
    for (int i=0;i<userList.count();++i) {
        if(i==userList.count()-1)
        {
            displayString+=userList[i];
        }
        else {
            displayString+=userList[i]+"\n";
        }
    }
    if(displayString!="请录入需完成人员名单")
    {
        ui->textEdit->setPlainText(displayString);
    }
    this->show();
}

void EditList::on_btnSave_clicked()
{
    if(ui->textEdit->toPlainText()==nullptr)
    {
        QMessageBox::information(this,"提示","名单不可保存为空");
        return;
    }
    bool success = QFile::remove(QString("./compList/%1.txt").arg(user));
    if (success) {
        qDebug() << "文件已删除";
    } else {
        qDebug() << "删除文件失败";
    }
    //重新创建文件
    QFile f(QString("./compList/%1.txt").arg(user));
    f.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream txtOutput(&f);
    txtOutput.setCodec(QTextCodec::codecForName("UTF-8"));
    txtOutput<<ui->textEdit->toPlainText();//将内容添加到文件中
    f.close();
    emit updateNeedCompTableWidget();
}

void EditList::on_btnReturn_clicked()
{
    emit toMainWidget();
}
