#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
    void initUser();
signals:
    void loginSuccess(QString user,QString pwd);
    void loginTeacher(QStringList users,QString team);
private slots:
    void on_btnLogin_clicked();

private:
    Ui::Login *ui;
    QStringList userList;
};

#endif // LOGIN_H
