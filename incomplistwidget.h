#ifndef INCOMPLISTWIDGET_H
#define INCOMPLISTWIDGET_H
#include <QDialog>
#include <QWidget>

namespace Ui {
class InCompListWidget;
}

class InCompListWidget : public QDialog
{
    Q_OBJECT

public:
    explicit InCompListWidget(QWidget *parent = nullptr);
    ~InCompListWidget();
    void initInCompListWidget(QString user,QStringList inCompList);
signals:
    void Return();
private:
    Ui::InCompListWidget *ui;
};

#endif // INCOMPLISTWIDGET_H
