#include "incomplistwidget.h"
#include "ui_incomplistwidget.h"
#include <QClipboard>
#include <QMessageBox>
#include <QDebug>
InCompListWidget::InCompListWidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InCompListWidget)
{
    ui->setupUi(this);
    setWindowTitle("未完成人员名单");
    setModal(true);
    connect(ui->btnReturn,&QPushButton::clicked,this,[=]{
        emit Return();
    });
    connect(ui->btnCopyList,&QPushButton::clicked,this,[=]{
        QClipboard *clipboard = QApplication::clipboard();
        clipboard->setText(ui->textEdit->toPlainText());
        QMessageBox::information(this,"提醒","未完成人员名单已复制到粘贴板！");
    });
}

InCompListWidget::~InCompListWidget()
{
    delete ui;
}

void InCompListWidget::initInCompListWidget(QString user, QStringList inCompList)
{
    ui->username->setText(user);
    ui->textEdit->clear();
    QString displayString;
    for (int i=0;i<inCompList.count();++i) {
        if(i==inCompList.count()-1)
        {
            displayString+=inCompList[i];
        }
        else {
            displayString+=inCompList[i]+"\n";
        }
    }
    qDebug()<<displayString;
    ui->textEdit->setPlainText(displayString);
    this->show();
}
