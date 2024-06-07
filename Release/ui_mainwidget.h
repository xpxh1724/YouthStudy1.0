/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainWidget
{
public:
    QVBoxLayout *verticalLayout_3;
    QStackedWidget *stackedWidget;
    QWidget *studentPage;
    QVBoxLayout *verticalLayout_4;
    QWidget *topWidget;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label1;
    QLabel *UserName;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout;
    QLabel *snum;
    QLabel *schedule;
    QSpacerItem *horizontalSpacer_3;
    QWidget *bottomWidget;
    QHBoxLayout *horizontalLayout_4;
    QWidget *leftWidget;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *NeedCompTableWidget;
    QWidget *buttonWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *btnEditList;
    QPushButton *btnXlsx;
    QPushButton *btnExitLogin;
    QWidget *midWidget;
    QVBoxLayout *verticalLayout_5;
    QTableWidget *UserTableWidget;
    QLabel *UserCount;
    QWidget *rightWidget;
    QVBoxLayout *verticalLayout_6;
    QTableWidget *InCompTableWidget;
    QWidget *buttonWidget_2;
    QVBoxLayout *verticalLayout_8;
    QPushButton *btnCopyList;
    QLabel *label;
    QWidget *teacherPage;
    QVBoxLayout *verticalLayout_7;
    QWidget *topWidget_2;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_4;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label1_2;
    QLabel *UsersName;
    QSpacerItem *horizontalSpacer_5;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_7;
    QLabel *snum2;
    QLabel *schedule_2;
    QSpacerItem *horizontalSpacer_7;
    QWidget *bottomWidget_2;
    QVBoxLayout *verticalLayout_9;
    QTableWidget *UsersTableWidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *btnReQuery;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *btnCopyAllInCompList;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *btnImport;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *btnExit;
    QSpacerItem *horizontalSpacer_8;
    QWidget *widgetbottom;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_12;
    QLabel *label_2;

    void setupUi(QWidget *mainWidget)
    {
        if (mainWidget->objectName().isEmpty())
            mainWidget->setObjectName(QString::fromUtf8("mainWidget"));
        mainWidget->resize(1430, 860);
        mainWidget->setMinimumSize(QSize(1430, 860));
        mainWidget->setStyleSheet(QString::fromUtf8("*{\n"
"font: 12pt \"\346\245\267\344\275\223\";\n"
"}\n"
"#mainWidget\n"
"{\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"                                stop:0 rgb(226,238,243),\n"
"                                stop:1 rgb(240,207,214));\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(mainWidget);
        verticalLayout_3->setSpacing(3);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(mainWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        studentPage = new QWidget();
        studentPage->setObjectName(QString::fromUtf8("studentPage"));
        verticalLayout_4 = new QVBoxLayout(studentPage);
        verticalLayout_4->setSpacing(2);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        topWidget = new QWidget(studentPage);
        topWidget->setObjectName(QString::fromUtf8("topWidget"));
        topWidget->setMinimumSize(QSize(1410, 77));
        topWidget->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"font: 20pt \"\346\245\267\344\275\223\";\n"
"font-weight:bold;\n"
"color:rgb(136, 193, 150);\n"
"}\n"
"#topWidget\n"
"{\n"
"border-bottom:1px solid gray;\n"
"}"));
        horizontalLayout_3 = new QHBoxLayout(topWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(180, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        widget_4 = new QWidget(topWidget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_2 = new QHBoxLayout(widget_4);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label1 = new QLabel(widget_4);
        label1->setObjectName(QString::fromUtf8("label1"));
        label1->setStyleSheet(QString::fromUtf8(""));
        label1->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label1);

        UserName = new QLabel(widget_4);
        UserName->setObjectName(QString::fromUtf8("UserName"));
        UserName->setStyleSheet(QString::fromUtf8(""));
        UserName->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(UserName);


        horizontalLayout_3->addWidget(widget_4);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        widget_3 = new QWidget(topWidget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout = new QHBoxLayout(widget_3);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        snum = new QLabel(widget_3);
        snum->setObjectName(QString::fromUtf8("snum"));
        snum->setStyleSheet(QString::fromUtf8(""));
        snum->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(snum);

        schedule = new QLabel(widget_3);
        schedule->setObjectName(QString::fromUtf8("schedule"));
        schedule->setStyleSheet(QString::fromUtf8(""));
        schedule->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(schedule);


        horizontalLayout_3->addWidget(widget_3);

        horizontalSpacer_3 = new QSpacerItem(180, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout_4->addWidget(topWidget);

        bottomWidget = new QWidget(studentPage);
        bottomWidget->setObjectName(QString::fromUtf8("bottomWidget"));
        bottomWidget->setMinimumSize(QSize(1430, 770));
        bottomWidget->setStyleSheet(QString::fromUtf8("#bottomWidget\n"
"{\n"
"border-top:1px solid gray;\n"
"}"));
        horizontalLayout_4 = new QHBoxLayout(bottomWidget);
        horizontalLayout_4->setSpacing(2);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        leftWidget = new QWidget(bottomWidget);
        leftWidget->setObjectName(QString::fromUtf8("leftWidget"));
        leftWidget->setMinimumSize(QSize(190, 0));
        leftWidget->setMaximumSize(QSize(190, 16777215));
        leftWidget->setStyleSheet(QString::fromUtf8("#leftWidget\n"
"{\n"
"border-right:1px solid gray;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(leftWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(5, 5, 5, 0);
        NeedCompTableWidget = new QTableWidget(leftWidget);
        if (NeedCompTableWidget->columnCount() < 1)
            NeedCompTableWidget->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        NeedCompTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        NeedCompTableWidget->setObjectName(QString::fromUtf8("NeedCompTableWidget"));
        NeedCompTableWidget->setMinimumSize(QSize(180, 0));
        NeedCompTableWidget->setMaximumSize(QSize(180, 16777215));
        NeedCompTableWidget->setStyleSheet(QString::fromUtf8("QTableView QHeaderView{\n"
"background-color:rgb(240,207,214);/*\350\241\250\345\244\264\347\232\204\350\203\214\346\231\257\350\211\262*/\n"
"}\n"
"QTableView QHeaderView::section{\n"
"color: rgb(122, 175, 227);/*\350\241\250\345\244\264\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"border-right: 1px solid rgb(240,207,214);\n"
"border-left: 1px solid rgb(240,207,214);\n"
"font-weight:bold;\n"
"height: 35px;\n"
"}\n"
"QTableView{\n"
"color: rgb(122, 175, 227);\n"
"selection-background-color: rgba(0,0,0,0.6);/*\351\200\211\344\270\255\345\220\216\350\203\214\346\231\257\351\242\234\350\211\262*/\n"
"selection-color: red;\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"                                stop:0 rgb(226,238,243),\n"
"                                stop:1 rgb(240,207,214));\n"
"gridline-color: rgb(226,238,243);\n"
"}\n"
"QTableView::item{\n"
"color:black;\n"
"background-color: rgba(0,0,0,0.1);\n"
"}\n"
"QTableView::item:hover{\n"
"color: red;\n"
"background-color: rgba(0,0,0,0.3);"
                        "\n"
"}\n"
""));
        NeedCompTableWidget->setFrameShape(QFrame::NoFrame);
        NeedCompTableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        NeedCompTableWidget->horizontalHeader()->setMinimumSectionSize(40);
        NeedCompTableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        NeedCompTableWidget->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_2->addWidget(NeedCompTableWidget);

        buttonWidget = new QWidget(leftWidget);
        buttonWidget->setObjectName(QString::fromUtf8("buttonWidget"));
        buttonWidget->setMinimumSize(QSize(0, 40));
        buttonWidget->setMaximumSize(QSize(180, 16777215));
        buttonWidget->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"font: 11pt \"\346\245\267\344\275\223\";\n"
"font-weight:bold;\n"
"border-radius:10px;\n"
"border:2px solid gray;\n"
"background-color: rgba(202, 221, 245,0.7);\n"
"height:35;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"font: 12pt \"\346\245\267\344\275\223\";\n"
"font-weight:bold;\n"
"border:2px solid;\n"
"background-color: rgb(202, 221, 245);\n"
"}"));
        verticalLayout = new QVBoxLayout(buttonWidget);
        verticalLayout->setSpacing(5);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 10, 0, 10);
        btnEditList = new QPushButton(buttonWidget);
        btnEditList->setObjectName(QString::fromUtf8("btnEditList"));
        btnEditList->setMinimumSize(QSize(165, 30));

        verticalLayout->addWidget(btnEditList);

        btnXlsx = new QPushButton(buttonWidget);
        btnXlsx->setObjectName(QString::fromUtf8("btnXlsx"));

        verticalLayout->addWidget(btnXlsx);

        btnExitLogin = new QPushButton(buttonWidget);
        btnExitLogin->setObjectName(QString::fromUtf8("btnExitLogin"));

        verticalLayout->addWidget(btnExitLogin);


        verticalLayout_2->addWidget(buttonWidget);


        horizontalLayout_4->addWidget(leftWidget);

        midWidget = new QWidget(bottomWidget);
        midWidget->setObjectName(QString::fromUtf8("midWidget"));
        midWidget->setMinimumSize(QSize(1040, 0));
        midWidget->setStyleSheet(QString::fromUtf8("#midWidget\n"
"{\n"
"border-left:1px solid gray;\n"
"border-right:1px solid gray;\n"
"}"));
        verticalLayout_5 = new QVBoxLayout(midWidget);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(5, 5, 5, 0);
        UserTableWidget = new QTableWidget(midWidget);
        if (UserTableWidget->columnCount() < 4)
            UserTableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        UserTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        UserTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        UserTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        UserTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem4);
        UserTableWidget->setObjectName(QString::fromUtf8("UserTableWidget"));
        UserTableWidget->setMinimumSize(QSize(1030, 0));
        UserTableWidget->setStyleSheet(QString::fromUtf8("QTableView QHeaderView{\n"
"background-color:rgb(240,207,214);/*\350\241\250\345\244\264\347\232\204\350\203\214\346\231\257\350\211\262*/\n"
"}\n"
"QTableView QHeaderView::section{\n"
"color: rgb(122, 175, 227);/*\350\241\250\345\244\264\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"border-right: 1px solid rgb(240,207,214);\n"
"border-left: 1px solid rgb(240,207,214);\n"
"font-weight:bold;\n"
"height: 35px;\n"
"}\n"
"QTableView{\n"
"color: rgb(122, 175, 227);\n"
"selection-background-color: rgba(0,0,0,0.6);/*\351\200\211\344\270\255\345\220\216\350\203\214\346\231\257\351\242\234\350\211\262*/\n"
"selection-color: red;\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"                                stop:1 rgb(226,238,243),\n"
"                                stop:0 rgb(240,207,214));\n"
"gridline-color: rgb(226,238,243);\n"
"}\n"
"QTableView::item{\n"
"color:black;\n"
"background-color: rgba(0,0,0,0.1);\n"
"}\n"
"QTableView::item:hover{\n"
"color: red;\n"
"background-color: rgba(0,0,0,0.3);"
                        "\n"
"}"));
        UserTableWidget->setFrameShape(QFrame::NoFrame);
        UserTableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        UserTableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        UserTableWidget->horizontalHeader()->setStretchLastSection(true);
        UserTableWidget->verticalHeader()->setVisible(false);

        verticalLayout_5->addWidget(UserTableWidget);

        UserCount = new QLabel(midWidget);
        UserCount->setObjectName(QString::fromUtf8("UserCount"));
        UserCount->setMinimumSize(QSize(0, 40));
        UserCount->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"font: 20pt \"\346\245\267\344\275\223\";\n"
"font-weight:bold;\n"
"color:rgb(136, 193, 150);\n"
"}"));
        UserCount->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(UserCount);


        horizontalLayout_4->addWidget(midWidget);

        rightWidget = new QWidget(bottomWidget);
        rightWidget->setObjectName(QString::fromUtf8("rightWidget"));
        rightWidget->setMinimumSize(QSize(190, 0));
        rightWidget->setMaximumSize(QSize(190, 16777215));
        rightWidget->setStyleSheet(QString::fromUtf8("#rightWidget\n"
"{\n"
"border-left:1px solid gray;\n"
"}"));
        verticalLayout_6 = new QVBoxLayout(rightWidget);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(5, 5, 5, 0);
        InCompTableWidget = new QTableWidget(rightWidget);
        if (InCompTableWidget->columnCount() < 1)
            InCompTableWidget->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        InCompTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        InCompTableWidget->setObjectName(QString::fromUtf8("InCompTableWidget"));
        InCompTableWidget->setMinimumSize(QSize(180, 0));
        InCompTableWidget->setMaximumSize(QSize(180, 16777215));
        InCompTableWidget->setStyleSheet(QString::fromUtf8("QTableView QHeaderView{\n"
"background-color:rgb(240,207,214);/*\350\241\250\345\244\264\347\232\204\350\203\214\346\231\257\350\211\262*/\n"
"}\n"
"QTableView QHeaderView::section{\n"
"color: rgb(122, 175, 227);/*\350\241\250\345\244\264\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"border-right: 1px solid rgb(240,207,214);\n"
"border-left: 1px solid rgb(240,207,214);\n"
"font-weight:bold;\n"
"height: 35px;\n"
"}\n"
"QTableView{\n"
"color: rgb(122, 175, 227);\n"
"selection-background-color: rgba(0,0,0,0.6);/*\351\200\211\344\270\255\345\220\216\350\203\214\346\231\257\351\242\234\350\211\262*/\n"
"selection-color: red;\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"                                stop:0 rgb(226,238,243),\n"
"                                stop:1 rgb(240,207,214));\n"
"gridline-color: rgb(226,238,243);\n"
"}\n"
"QTableView::item{\n"
"color:black;\n"
"background-color: rgba(0,0,0,0.1);\n"
"}\n"
"QTableView::item:hover{\n"
"color: red;\n"
"background-color: rgba(0,0,0,0.3);"
                        "\n"
"}"));
        InCompTableWidget->setFrameShape(QFrame::NoFrame);
        InCompTableWidget->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_6->addWidget(InCompTableWidget);

        buttonWidget_2 = new QWidget(rightWidget);
        buttonWidget_2->setObjectName(QString::fromUtf8("buttonWidget_2"));
        buttonWidget_2->setMinimumSize(QSize(0, 40));
        buttonWidget_2->setMaximumSize(QSize(180, 16777215));
        buttonWidget_2->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"font: 11pt \"\346\245\267\344\275\223\";\n"
"font-weight:bold;\n"
"border-radius:10px;\n"
"border:2px solid gray;\n"
"background-color: rgba(202, 221, 245,0.7);\n"
"height:35;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"font: 12pt \"\346\245\267\344\275\223\";\n"
"font-weight:bold;\n"
"border:2px solid;\n"
"background-color: rgb(202, 221, 245);\n"
"}"));
        verticalLayout_8 = new QVBoxLayout(buttonWidget_2);
        verticalLayout_8->setSpacing(5);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 10, 0, 0);
        btnCopyList = new QPushButton(buttonWidget_2);
        btnCopyList->setObjectName(QString::fromUtf8("btnCopyList"));
        btnCopyList->setMinimumSize(QSize(0, 30));

        verticalLayout_8->addWidget(btnCopyList);

        label = new QLabel(buttonWidget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(180, 15));
        label->setMaximumSize(QSize(180, 15));
        label->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"font: 9pt \"\346\245\267\344\275\223\";\n"
"font-weight:bold;\n"
"}"));

        verticalLayout_8->addWidget(label);


        verticalLayout_6->addWidget(buttonWidget_2);


        horizontalLayout_4->addWidget(rightWidget);


        verticalLayout_4->addWidget(bottomWidget);

        stackedWidget->addWidget(studentPage);
        teacherPage = new QWidget();
        teacherPage->setObjectName(QString::fromUtf8("teacherPage"));
        verticalLayout_7 = new QVBoxLayout(teacherPage);
        verticalLayout_7->setSpacing(2);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        topWidget_2 = new QWidget(teacherPage);
        topWidget_2->setObjectName(QString::fromUtf8("topWidget_2"));
        topWidget_2->setMinimumSize(QSize(1410, 77));
        topWidget_2->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"font: 20pt \"\346\245\267\344\275\223\";\n"
"font-weight:bold;\n"
"color:rgb(136, 193, 150);\n"
"}\n"
"#topWidget_2\n"
"{\n"
"border-bottom:1px solid gray;\n"
"}"));
        horizontalLayout_5 = new QHBoxLayout(topWidget_2);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_4 = new QSpacerItem(180, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        widget_5 = new QWidget(topWidget_2);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_6 = new QHBoxLayout(widget_5);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label1_2 = new QLabel(widget_5);
        label1_2->setObjectName(QString::fromUtf8("label1_2"));
        label1_2->setStyleSheet(QString::fromUtf8(""));
        label1_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label1_2);

        UsersName = new QLabel(widget_5);
        UsersName->setObjectName(QString::fromUtf8("UsersName"));
        UsersName->setStyleSheet(QString::fromUtf8(""));
        UsersName->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(UsersName);


        horizontalLayout_5->addWidget(widget_5);

        horizontalSpacer_5 = new QSpacerItem(162, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        widget_6 = new QWidget(topWidget_2);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        horizontalLayout_7 = new QHBoxLayout(widget_6);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        snum2 = new QLabel(widget_6);
        snum2->setObjectName(QString::fromUtf8("snum2"));
        snum2->setStyleSheet(QString::fromUtf8(""));
        snum2->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(snum2);

        schedule_2 = new QLabel(widget_6);
        schedule_2->setObjectName(QString::fromUtf8("schedule_2"));
        schedule_2->setStyleSheet(QString::fromUtf8(""));
        schedule_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(schedule_2);


        horizontalLayout_5->addWidget(widget_6);

        horizontalSpacer_7 = new QSpacerItem(180, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);


        verticalLayout_7->addWidget(topWidget_2);

        bottomWidget_2 = new QWidget(teacherPage);
        bottomWidget_2->setObjectName(QString::fromUtf8("bottomWidget_2"));
        bottomWidget_2->setMinimumSize(QSize(1430, 770));
        bottomWidget_2->setStyleSheet(QString::fromUtf8("#bottomWidget_2\n"
"{\n"
"border-top:1px solid gray;\n"
"}"));
        verticalLayout_9 = new QVBoxLayout(bottomWidget_2);
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(5, 5, 5, 5);
        UsersTableWidget = new QTableWidget(bottomWidget_2);
        if (UsersTableWidget->columnCount() < 1)
            UsersTableWidget->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        UsersTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        UsersTableWidget->setObjectName(QString::fromUtf8("UsersTableWidget"));
        UsersTableWidget->setStyleSheet(QString::fromUtf8("QTableView QHeaderView{\n"
"background-color:rgb(240,207,214);/*\350\241\250\345\244\264\347\232\204\350\203\214\346\231\257\350\211\262*/\n"
"}\n"
"QTableView QHeaderView::section{\n"
"color: rgb(122, 175, 227);/*\350\241\250\345\244\264\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"border-right: 1px solid rgb(240,207,214);\n"
"border-left: 1px solid rgb(240,207,214);\n"
"font-weight:bold;\n"
"height: 35px;\n"
"}\n"
"QTableView{\n"
"color: rgb(122, 175, 227);\n"
"selection-background-color: rgba(0,0,0,0.6);/*\351\200\211\344\270\255\345\220\216\350\203\214\346\231\257\351\242\234\350\211\262*/\n"
"selection-color: red;\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"                                stop:1 rgb(226,238,243),\n"
"                                stop:0 rgb(240,207,214));\n"
"gridline-color: rgb(226,238,243);\n"
"}\n"
"QTableView::item{\n"
"color:black;\n"
"background-color: rgba(0,0,0,0.1);\n"
"}\n"
"QTableView::item:hover{\n"
"color: red;\n"
"background-color: rgba(0,0,0,0.3);"
                        "\n"
"}"));
        UsersTableWidget->setFrameShape(QFrame::NoFrame);
        UsersTableWidget->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_9->addWidget(UsersTableWidget);

        widget = new QWidget(bottomWidget_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 60));
        widget->setMaximumSize(QSize(16777215, 60));
        horizontalLayout_8 = new QHBoxLayout(widget);
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_6 = new QSpacerItem(166, 50, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_6);

        btnReQuery = new QPushButton(widget);
        btnReQuery->setObjectName(QString::fromUtf8("btnReQuery"));
        btnReQuery->setMinimumSize(QSize(200, 50));
        btnReQuery->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"font: 12pt \"\346\245\267\344\275\223\";\n"
"font-weight:bold;\n"
"border-radius:8px;\n"
"border:2px solid gray;\n"
"background-color: rgba(202, 221, 245,0.7);\n"
"height:35;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"font: 13pt \"\346\245\267\344\275\223\";\n"
"font-weight:bold;\n"
"border:2px solid;\n"
"background-color: rgb(202, 221, 245);\n"
"}"));

        horizontalLayout_8->addWidget(btnReQuery);

        horizontalSpacer_9 = new QSpacerItem(206, 50, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_9);

        btnCopyAllInCompList = new QPushButton(widget);
        btnCopyAllInCompList->setObjectName(QString::fromUtf8("btnCopyAllInCompList"));
        btnCopyAllInCompList->setMinimumSize(QSize(250, 50));
        btnCopyAllInCompList->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"font: 12pt \"\346\245\267\344\275\223\";\n"
"font-weight:bold;\n"
"border-radius:8px;\n"
"border:2px solid gray;\n"
"background-color: rgba(202, 221, 245,0.7);\n"
"height:35;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"font: 13pt \"\346\245\267\344\275\223\";\n"
"font-weight:bold;\n"
"border:2px solid;\n"
"background-color: rgb(202, 221, 245);\n"
"}"));

        horizontalLayout_8->addWidget(btnCopyAllInCompList);

        horizontalSpacer_10 = new QSpacerItem(206, 50, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_10);

        btnImport = new QPushButton(widget);
        btnImport->setObjectName(QString::fromUtf8("btnImport"));
        btnImport->setMinimumSize(QSize(150, 50));
        btnImport->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"font: 12pt \"\346\245\267\344\275\223\";\n"
"font-weight:bold;\n"
"border-radius:8px;\n"
"border:2px solid gray;\n"
"background-color: rgba(202, 221, 245,0.7);\n"
"height:35;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"font: 13pt \"\346\245\267\344\275\223\";\n"
"font-weight:bold;\n"
"border:2px solid;\n"
"background-color: rgb(202, 221, 245);\n"
"}"));

        horizontalLayout_8->addWidget(btnImport);

        horizontalSpacer_11 = new QSpacerItem(206, 50, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_11);

        btnExit = new QPushButton(widget);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));
        btnExit->setMinimumSize(QSize(150, 50));
        btnExit->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"font: 12pt \"\346\245\267\344\275\223\";\n"
"font-weight:bold;\n"
"border-radius:8px;\n"
"border:2px solid gray;\n"
"background-color: rgba(202, 221, 245,0.7);\n"
"height:35;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"font: 13pt \"\346\245\267\344\275\223\";\n"
"font-weight:bold;\n"
"border:2px solid;\n"
"background-color: rgb(202, 221, 245);\n"
"}"));

        horizontalLayout_8->addWidget(btnExit);

        horizontalSpacer_8 = new QSpacerItem(166, 50, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_8);


        verticalLayout_9->addWidget(widget);

        widgetbottom = new QWidget(bottomWidget_2);
        widgetbottom->setObjectName(QString::fromUtf8("widgetbottom"));
        widgetbottom->setMinimumSize(QSize(0, 15));
        widgetbottom->setMaximumSize(QSize(16777215, 15));
        horizontalLayout_9 = new QHBoxLayout(widgetbottom);
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_12 = new QSpacerItem(1237, 12, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_12);

        label_2 = new QLabel(widgetbottom);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(180, 15));
        label_2->setMaximumSize(QSize(180, 15));
        label_2->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"font: 9pt \"\346\245\267\344\275\223\";\n"
"font-weight:bold;\n"
"}"));

        horizontalLayout_9->addWidget(label_2);


        verticalLayout_9->addWidget(widgetbottom);


        verticalLayout_7->addWidget(bottomWidget_2);

        stackedWidget->addWidget(teacherPage);

        verticalLayout_3->addWidget(stackedWidget);


        retranslateUi(mainWidget);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(mainWidget);
    } // setupUi

    void retranslateUi(QWidget *mainWidget)
    {
        mainWidget->setWindowTitle(QApplication::translate("mainWidget", "mainWidget", nullptr));
        label1->setText(QApplication::translate("mainWidget", "\347\224\250\346\210\267:", nullptr));
        UserName->setText(QApplication::translate("mainWidget", "\347\275\221\347\273\234\345\267\245\347\250\2132021\347\272\2471\347\217\255\345\233\242\346\224\257\351\203\250", nullptr));
        snum->setText(QApplication::translate("mainWidget", "2024\345\271\264\347\254\254X\346\234\237 \345\256\214\346\210\220\350\277\233\345\272\246:", nullptr));
        schedule->setText(QApplication::translate("mainWidget", "0/38", nullptr));
        QTableWidgetItem *___qtablewidgetitem = NeedCompTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("mainWidget", "\351\234\200\345\256\214\346\210\220\345\220\215\345\215\225", nullptr));
        btnEditList->setText(QApplication::translate("mainWidget", "\347\274\226\350\276\221\345\220\215\345\215\225", nullptr));
        btnXlsx->setText(QApplication::translate("mainWidget", "\346\230\276\347\244\272\346\234\252\345\256\214\346\210\220", nullptr));
        btnExitLogin->setText(QApplication::translate("mainWidget", "\351\200\200\345\207\272\347\231\273\345\275\225", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = UserTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem1->setText(QApplication::translate("mainWidget", "\345\247\223\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = UserTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem2->setText(QApplication::translate("mainWidget", "\346\211\213\346\234\272\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = UserTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem3->setText(QApplication::translate("mainWidget", "\347\273\204\347\273\207\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = UserTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem4->setText(QApplication::translate("mainWidget", "\345\255\246\344\271\240\346\227\266\351\227\264", nullptr));
        UserCount->setText(QApplication::translate("mainWidget", "\345\205\261\350\256\241 XX \346\235\241\346\225\260\346\215\256", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = InCompTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QApplication::translate("mainWidget", "\346\234\252\345\256\214\346\210\220\345\220\215\345\215\225", nullptr));
        btnCopyList->setText(QApplication::translate("mainWidget", "\345\244\215\345\210\266\345\220\215\345\215\225", nullptr));
        label->setText(QApplication::translate("mainWidget", "\345\207\272\345\223\201:\347\275\221\347\273\234\345\267\245\347\250\213\347\263\273\345\205\232\346\224\257\351\203\250", nullptr));
        label1_2->setText(QApplication::translate("mainWidget", "\347\224\250\346\210\267:", nullptr));
        UsersName->setText(QApplication::translate("mainWidget", "\347\275\221\347\273\234\345\267\245\347\250\2132021\347\272\247\345\233\242\346\224\257\351\203\250", nullptr));
        snum2->setText(QApplication::translate("mainWidget", "2024\345\271\264\347\254\254X\346\234\237 \345\256\214\346\210\220\350\277\233\345\272\246:", nullptr));
        schedule_2->setText(QApplication::translate("mainWidget", "0/6", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = UsersTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QApplication::translate("mainWidget", "\345\220\204\345\233\242\346\224\257\351\203\250\350\277\233\345\272\246", nullptr));
        btnReQuery->setText(QApplication::translate("mainWidget", "\344\270\200\351\224\256\351\207\215\346\226\260\346\237\245\350\257\242", nullptr));
        btnCopyAllInCompList->setText(QApplication::translate("mainWidget", "\345\244\215\345\210\266\345\205\250\351\203\250\346\234\252\345\256\214\346\210\220\345\220\215\345\215\225", nullptr));
        btnImport->setText(QApplication::translate("mainWidget", "\345\257\274\345\205\245\344\272\272\345\221\230\346\225\260\346\215\256", nullptr));
        btnExit->setText(QApplication::translate("mainWidget", "\351\200\200\345\207\272\347\231\273\345\275\225", nullptr));
        label_2->setText(QApplication::translate("mainWidget", "\345\207\272\345\223\201:\347\275\221\347\273\234\345\267\245\347\250\213\347\263\273\345\205\232\346\224\257\351\203\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainWidget: public Ui_mainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
