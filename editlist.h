#ifndef EDITLIST_H
#define EDITLIST_H

#include <QDialog>
#include <QWidget>

namespace Ui {
class EditList;
}

class EditList : public QDialog
{
    Q_OBJECT

public:
    explicit EditList(QWidget *parent = nullptr);
    ~EditList();
    void EditListShow(QStringList userList,QString user);
signals:
    void toMainWidget();
    void updateNeedCompTableWidget();
private slots:
    void on_btnSave_clicked();

    void on_btnReturn_clicked();

private:
    Ui::EditList *ui;
    QString user;
};

#endif // EDITLIST_H
