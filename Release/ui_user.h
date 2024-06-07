/********************************************************************************
** Form generated from reading UI file 'user.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USER_H
#define UI_USER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_User
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *user;
    QSpacerItem *horizontalSpacer;
    QLabel *schedule;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnLoad;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnLook;

    void setupUi(QWidget *User)
    {
        if (User->objectName().isEmpty())
            User->setObjectName(QString::fromUtf8("User"));
        User->resize(814, 60);
        User->setStyleSheet(QString::fromUtf8("*{\n"
"font: 12pt \"\346\245\267\344\275\223\";\n"
"}\n"
"QPushButton\n"
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
        horizontalLayout = new QHBoxLayout(User);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, 5, 5, 5);
        user = new QLabel(User);
        user->setObjectName(QString::fromUtf8("user"));

        horizontalLayout->addWidget(user);

        horizontalSpacer = new QSpacerItem(42, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        schedule = new QLabel(User);
        schedule->setObjectName(QString::fromUtf8("schedule"));

        horizontalLayout->addWidget(schedule);

        horizontalSpacer_2 = new QSpacerItem(42, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btnLoad = new QPushButton(User);
        btnLoad->setObjectName(QString::fromUtf8("btnLoad"));
        btnLoad->setMinimumSize(QSize(100, 50));

        horizontalLayout->addWidget(btnLoad);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        btnLook = new QPushButton(User);
        btnLook->setObjectName(QString::fromUtf8("btnLook"));
        btnLook->setMinimumSize(QSize(210, 50));

        horizontalLayout->addWidget(btnLook);


        retranslateUi(User);

        QMetaObject::connectSlotsByName(User);
    } // setupUi

    void retranslateUi(QWidget *User)
    {
        User->setWindowTitle(QApplication::translate("User", "Form", nullptr));
        user->setText(QApplication::translate("User", "\347\275\221\347\273\234\345\267\245\347\250\2132021\347\272\2471\347\217\255\345\233\242\346\224\257\351\203\250", nullptr));
        schedule->setText(QApplication::translate("User", "\345\256\214\346\210\220\350\277\233\345\272\246\357\274\2320/38", nullptr));
        btnLoad->setText(QApplication::translate("User", "\351\207\215\346\226\260\345\212\240\350\275\275", nullptr));
        btnLook->setText(QApplication::translate("User", "\346\237\245\347\234\213\346\234\252\345\256\214\346\210\220\344\272\272\345\221\230\345\220\215\345\215\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class User: public Ui_User {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USER_H
