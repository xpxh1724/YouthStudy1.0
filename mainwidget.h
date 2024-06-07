#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QLabel>
#include <QMovie>
#include <QWidget>
// QXlsx
#include "xlsxdocument.h"
#include "xlsxworksheet.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

#include "editlist.h"
#include "login.h"
#include <atomic>
using namespace QXlsx;
namespace Ui {
class mainWidget;
}

class mainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit mainWidget(QWidget *parent = nullptr);
    ~mainWidget();
    void initLogin();
    void initButton();
    int findLastRowWithDataInColumnA(Worksheet *worksheet);
    bool initCompList();
    void startRequestPost(const QUrl &requestedUrl);
    void startRequestPost2(const QUrl &requestedUrl);
    void startRequestGet(const QUrl &requestedUrl);
private slots:
    void getIdNameSnum();
    void select();
    void replyFinishedPost();
    void replyFinishedPost2();
    void replyFinishedGet();
    void on_btnImport_clicked();

private:
    Ui::mainWidget *ui;
    Login *login;
    EditList *editlist;

    QStringList NeedCompList;
    QUrl url;
    //获取orgId,token
    QNetworkRequest req;
    QNetworkReply *reply;
    QNetworkAccessManager *manager;
    //获取id,name,snum
    QNetworkRequest req2;
    QNetworkReply *reply2;
    QNetworkAccessManager *manager2;
    //下载xlsx文件
    QNetworkRequest req3;
    QNetworkReply *reply3;
    QNetworkAccessManager *manager3;

    QString user,pwd,name,snum;
    QString token;
    int orgId,id;
    QStringList Users;
    std::atomic<int> atomicInt{0};

    QMovie *movie;
    QLabel *loadLabel ;
};

#endif // MAINWIDGET_H
