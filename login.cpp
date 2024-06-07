#include "login.h"
#include "ui_login.h"

#include <QFile>
#include <QMessageBox>
#include <QDebug>
#include <QDir>
#include <QListView>
Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    setWindowTitle("青年大学习后台管理系统-登录");
    ui->IdentityBox->setView(new QListView());
    initUser();

}

Login::~Login()
{
    delete ui;
}

void Login::initUser()
{
    //读取默认账号信息
    QFile f("./userList/defaultmsg.txt");
    if(f.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        while(!f.atEnd())
        {
            QByteArray line = f.readLine();
            QString msg(line);
            ui->usernameLine->setText(msg.split(' ').at(0));
            ui->passwordLine->setText(msg.split(' ').at(1));
            ui->IdentityBox->setCurrentText(msg.split(' ').at(2));
        }
    }
    f.close();
    //读取账号信息
    QFile file("./userList/userlist.txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"userlist.txt文件不存在!"<<endl;
        qDebug()<<QDir::currentPath();
        return;
    }
    while(!file.atEnd())
    {
        QByteArray line = file.readLine();
        QString str(line);
        str.remove('\n');
        userList.append(str);
    }
    file.close();
}

void Login::on_btnLogin_clicked()
{
    QString user=ui->usernameLine->text();
    QString pwd=ui->passwordLine->text();
    QString identity=ui->IdentityBox->currentText();
    if(user.isEmpty()||pwd.isEmpty())
    {
        QMessageBox::information(this,"登录提示","UserName或PassWord为空！");
        return;
    }
    QString msg=user+' '+pwd+' '+identity;
    if(userList.contains(msg))
    {
        qDebug()<<"账号: "<<user<<"登录成功";
        if(identity=="团支书")
            emit loginSuccess(user,pwd);
        else if(identity=="老师")
        {
            QString str=user.split("团支部").at(0);
            QStringList users;
            for(auto a:userList)
            {
                if(a.split(' ').at(0).contains(str)&&a.split(' ').at(0).contains("团支部")&&a.split(' ').at(0)!=user)
                {
                    users.append(a);
                }
            }
            emit loginTeacher(users,user);
        }
    }
    else {
        QMessageBox::information(this,"登录提示","UserName或PassWord或Identity错误！");
        return;
    }
}
