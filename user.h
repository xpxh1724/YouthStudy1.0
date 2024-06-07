#ifndef USER_H
#define USER_H

#include <QLabel>
#include <QMovie>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QWidget>
// QXlsx
#include "xlsxdocument.h"
#include "xlsxworksheet.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
using namespace QXlsx;
namespace Ui {
class User;
}

class User : public QWidget
{
    Q_OBJECT

public:
    explicit User(QWidget *parent = nullptr);
    ~User();
    void UserWorking(QString user,QString pwd);
    int findLastRowWithDataInColumnA(Worksheet *worksheet);
    bool initCompList();
    void startRequestPost(const QUrl &requestedUrl);
    void startRequestPost2(const QUrl &requestedUrl);
    void startRequestGet(const QUrl &requestedUrl);
    void ReQuery();
    QString CopyAllInCompList();
private slots:
    void select();
    void getIdNameSnum();
    void replyFinishedPost();
    void replyFinishedPost2();
    void replyFinishedGet();
    void on_btnLoad_clicked();

    void on_btnLook_clicked();

signals:
    void allSuccess();
    void loadSelect();
    void updateSnum2(QString snum2);
private:
    Ui::User *ui;
    QStringList NeedCompList;//需完成人员名单
    QStringList InCompList;//未完成人员名单
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

    QMovie *movie;
    QLabel *loadLabel ;

};

#endif // USER_H
