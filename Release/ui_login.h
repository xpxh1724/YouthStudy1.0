/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QLabel *title;
    QLabel *usernameLab;
    QLineEdit *usernameLine;
    QLineEdit *passwordLine;
    QLabel *passwordLab;
    QPushButton *btnLogin;
    QLabel *IdentityLab;
    QComboBox *IdentityBox;
    QLabel *cp;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(850, 700);
        Login->setMinimumSize(QSize(850, 700));
        Login->setMaximumSize(QSize(850, 700));
        Login->setStyleSheet(QString::fromUtf8("#Login\n"
"{\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"                                stop:0 rgb(226,238,243),\n"
"                                stop:1 rgb(240,207,214));\n"
"}\n"
"#title\n"
"{\n"
"font: 24pt \"\346\245\267\344\275\223\";\n"
"font-weight:bold;\n"
"background-color: rgba(202, 221, 245,0.5);\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"                                stop:1 rgb(226,238,243),\n"
"                                stop:0 rgb(240,207,214));\n"
"border-radius:20px;\n"
"}\n"
"#cp\n"
"{\n"
"font: 11pt \"\346\245\267\344\275\223\";\n"
"font-weight:bold;\n"
"}\n"
"#usernameLab\n"
"{\n"
"font: 18pt \"\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223\";\n"
"color: rgb(3, 57, 103);\n"
"}\n"
"#passwordLab\n"
"{\n"
"font: 18pt \"\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223\";\n"
"color: rgb(3, 57, 103);\n"
"}\n"
"QLineEdit\n"
"{\n"
"font: 14pt \"\346\245\267\344\275\223\";\n"
"font-we"
                        "ight:bold;\n"
"background-color: rgba(136, 193, 150,0.3);\n"
"border-radius:10px;\n"
"border:2px solid gray;\n"
"}\n"
"QLineEdit:hover\n"
"{\n"
"font: 14pt \"\346\245\267\344\275\223\";\n"
"font-weight:bold;\n"
"border:2px solid ;\n"
"}\n"
"#IdentityLab\n"
"{\n"
"font: 18pt \"\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223\";\n"
"color: rgb(3, 57, 103);\n"
"}\n"
"#btnLogin\n"
"{\n"
"font: 20pt \"\346\245\267\344\275\223\";\n"
"font-weight:bold;\n"
"border-radius:10px;\n"
"border:2px solid gray;\n"
"background-color: rgba(202, 221, 245,0.7);\n"
"}\n"
"#btnLogin:hover\n"
"{\n"
"font: 22pt \"\346\245\267\344\275\223\";\n"
"font-weight:bold;\n"
"border:3px solid;\n"
"background-color: rgb(202, 221, 245);\n"
"}"));
        title = new QLabel(Login);
        title->setObjectName(QString::fromUtf8("title"));
        title->setGeometry(QRect(55, 10, 740, 120));
        title->setMinimumSize(QSize(740, 120));
        title->setMaximumSize(QSize(740, 120));
        title->setStyleSheet(QString::fromUtf8(""));
        title->setAlignment(Qt::AlignCenter);
        usernameLab = new QLabel(Login);
        usernameLab->setObjectName(QString::fromUtf8("usernameLab"));
        usernameLab->setGeometry(QRect(180, 150, 250, 60));
        usernameLab->setMinimumSize(QSize(250, 60));
        usernameLab->setMaximumSize(QSize(250, 60));
        usernameLab->setStyleSheet(QString::fromUtf8(""));
        usernameLine = new QLineEdit(Login);
        usernameLine->setObjectName(QString::fromUtf8("usernameLine"));
        usernameLine->setGeometry(QRect(180, 210, 490, 62));
        passwordLine = new QLineEdit(Login);
        passwordLine->setObjectName(QString::fromUtf8("passwordLine"));
        passwordLine->setGeometry(QRect(180, 340, 490, 62));
        passwordLine->setEchoMode(QLineEdit::Password);
        passwordLab = new QLabel(Login);
        passwordLab->setObjectName(QString::fromUtf8("passwordLab"));
        passwordLab->setGeometry(QRect(180, 280, 250, 60));
        passwordLab->setMinimumSize(QSize(250, 60));
        passwordLab->setMaximumSize(QSize(250, 60));
        passwordLab->setStyleSheet(QString::fromUtf8(""));
        btnLogin = new QPushButton(Login);
        btnLogin->setObjectName(QString::fromUtf8("btnLogin"));
        btnLogin->setGeometry(QRect(180, 590, 490, 61));
        IdentityLab = new QLabel(Login);
        IdentityLab->setObjectName(QString::fromUtf8("IdentityLab"));
        IdentityLab->setGeometry(QRect(180, 410, 250, 60));
        IdentityLab->setMinimumSize(QSize(250, 60));
        IdentityLab->setMaximumSize(QSize(250, 60));
        IdentityLab->setStyleSheet(QString::fromUtf8(""));
        IdentityBox = new QComboBox(Login);
        IdentityBox->addItem(QString());
        IdentityBox->addItem(QString());
        IdentityBox->setObjectName(QString::fromUtf8("IdentityBox"));
        IdentityBox->setGeometry(QRect(180, 471, 490, 62));
        IdentityBox->setStyleSheet(QString::fromUtf8("/*QCombobox\344\270\273\344\275\223*/\n"
"QComboBox {\n"
"	font: 14pt \"\346\245\267\344\275\223\";\n"
"	font-weight:bold;\n"
"	background-color: rgba(136, 193, 150,0.3);\n"
"	border-radius:10px;\n"
"	border:2px solid gray;\n"
"    padding: 1px 2px 1px 2px;  /*\351\222\210\345\257\271\344\272\216\347\273\204\345\220\210\346\241\206\344\270\255\347\232\204\346\226\207\346\234\254\345\206\205\345\256\271*/\n"
"	text-align:bottom;\n"
"	padding-left: 20px;/*\345\267\246\344\276\247\350\276\271\350\267\235*/\n"
"}\n"
"QComboBox:hover\n"
"{\n"
"	border:3px solid;\n"
"}\n"
"/*QCombobox\345\217\263\344\276\247\346\214\211\351\222\256*/\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;/*\346\224\276\344\272\216\345\217\263\346\226\271\351\241\266\351\203\250*/\n"
"    width: 50px;/*\350\256\276\347\275\256\346\214\211\351\222\256\350\214\203\345\233\264\345\256\275\345\272\246*/\n"
"    border-top-right-radius: 3px;/*\350\256\276\347\275\256\350\276\271\346\241\206\345"
                        "\234\206\350\247\222*/\n"
"    border-bottom-right-radius: 3px;\n"
"/*padding-right: 50px;*/\n"
"}\n"
"/*QCombobox\345\217\263\344\276\247\346\214\211\351\222\256\347\232\204\347\256\255\345\244\264\345\233\276\346\240\207*/\n"
"QComboBox::down-arrow {\n"
"	border-image: url(:/ptr/down.png);/*\350\207\252\345\256\232\344\271\211\345\233\276\347\211\207\345\241\253\345\205\205*/\n"
"	width: 28px;/*\350\256\276\347\275\256\350\257\245\345\233\276\346\240\207\347\232\204\345\256\275\351\253\230*/\n"
"	height: 28px;\n"
"}\n"
"/*QCombobox\345\217\263\344\276\247\346\214\211\351\222\256\347\232\204\347\256\255\345\244\264\345\233\276\346\240\207*/\n"
"QComboBox::down-arrow::on {\n"
"	border-image: url(:/ptr/up.png);/*\350\207\252\345\256\232\344\271\211\345\233\276\347\211\207\345\241\253\345\205\205*/\n"
"	width: 28px;/*\350\256\276\347\275\256\350\257\245\345\233\276\346\240\207\347\232\204\345\256\275\351\253\230*/\n"
"	height: 28px;\n"
"}\n"
"\n"
"\n"
"/* \344\270\213\346\213\211\345\220\216\357\274\214\346\225\264"
                        "\344\270\252\344\270\213\346\213\211\347\252\227\344\275\223\346\240\267\345\274\217 */\n"
"QComboBox QAbstractItemView {\n"
"	font: 16pt \"\346\245\267\344\275\223\";\n"
"	font-weight: bold;  \n"
"    border: 2px solid white;/*\350\276\271\346\241\206\345\256\275\345\272\246\343\200\201\347\272\277\345\275\242\343\200\201\351\242\234\350\211\262*/\n"
"	/*\350\203\214\346\231\257\351\242\234\350\211\262*/\n"
"	background-color: rgba(136, 193, 150,0.3);\n"
"    border-radius: 10px;/*\345\234\206\350\247\222*/\n"
"    padding: 1px 2px 1px 2px;  /*\351\222\210\345\257\271\344\272\216\347\273\204\345\220\210\346\241\206\344\270\255\347\232\204\346\226\207\346\234\254\345\206\205\345\256\271*/\n"
"    min-width: 10em;   /*# \347\273\204\345\220\210\346\241\206\347\232\204\346\234\200\345\260\217\345\256\275\345\272\246*/\n"
"}\n"
"\n"
"/* \344\270\213\346\213\211\345\220\216\357\274\214\346\225\264\344\270\252\344\270\213\346\213\211\347\252\227\344\275\223\346\257\217\351\241\271\347\232\204\346\240\267\345\274\217"
                        " */\n"
"QComboBox QAbstractItemView::item {\n"
"	font: 16pt \"\346\245\267\344\275\223\";\n"
"	font-weight: bold;\n"
"	border-radius: 10px;/*\345\234\206\350\247\222*/\n"
"    height: 50px;   /* \351\241\271\347\232\204\351\253\230\345\272\246\357\274\210\350\256\276\347\275\256pComboBox->setView(new QListView());\345\220\216\357\274\214\350\257\245\351\241\271\346\211\215\350\265\267\344\275\234\347\224\250\357\274\211 */\n"
"	background-color: rgba(136, 193, 150,0.3);\n"
"\n"
"}\n"
"\n"
"/*\344\273\245\344\270\213\351\203\250\345\210\206\344\270\215\347\237\245\344\270\272\344\275\225\344\270\215\347\224\237\346\225\210\357\274\214\346\234\211\345\276\205\350\260\203\350\257\225*/\n"
"/* \344\270\213\346\213\211\345\220\216\357\274\214\346\225\264\344\270\252\344\270\213\346\213\211\347\252\227\344\275\223\350\266\212\350\277\207\346\257\217\351\241\271\347\232\204\346\240\267\345\274\217 */\n"
"QComboBox QAbstractItemView::item:hover {\n"
"	font: 16pt \"\346\245\267\344\275\223\";\n"
"	font-weight: bold;\n"
""
                        "       /* \346\225\264\344\270\252\344\270\213\346\213\211\347\252\227\344\275\223\350\266\212\350\277\207\346\257\217\351\241\271\347\232\204\350\203\214\346\231\257\350\211\262 */\n"
"	background-color: rgba(136, 193, 150,0.5);\n"
"}\n"
"\n"
"/* \344\270\213\346\213\211\345\220\216\357\274\214\346\225\264\344\270\252\344\270\213\346\213\211\347\252\227\344\275\223\350\242\253\351\200\211\346\213\251\347\232\204\346\257\217\351\241\271\347\232\204\346\240\267\345\274\217 */\n"
"QComboBox QAbstractItemView::item:selected {\n"
"	font: 16pt \"\346\245\267\344\275\223\";\n"
"	font-weight: bold;\n"
"	background-color: rgba(136, 193, 150,0.5);\n"
"}\n"
""));
        cp = new QLabel(Login);
        cp->setObjectName(QString::fromUtf8("cp"));
        cp->setGeometry(QRect(641, 670, 210, 30));
        cp->setMinimumSize(QSize(210, 30));
        cp->setMaximumSize(QSize(210, 30));
        cp->setAlignment(Qt::AlignCenter);
        cp->setWordWrap(false);
        cp->setOpenExternalLinks(false);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Form", nullptr));
        title->setText(QApplication::translate("Login", "\351\235\222\345\271\264\345\244\247\345\255\246\344\271\240\345\220\216\345\217\260\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        usernameLab->setText(QApplication::translate("Login", "UserName", nullptr));
        usernameLine->setText(QString());
        passwordLine->setText(QString());
        passwordLab->setText(QApplication::translate("Login", "PassWord", nullptr));
        btnLogin->setText(QApplication::translate("Login", "\347\231\273\345\275\225", nullptr));
#ifndef QT_NO_SHORTCUT
        btnLogin->setShortcut(QApplication::translate("Login", "Return", nullptr));
#endif // QT_NO_SHORTCUT
        IdentityLab->setText(QApplication::translate("Login", "Identity", nullptr));
        IdentityBox->setItemText(0, QApplication::translate("Login", "\345\233\242\346\224\257\344\271\246", nullptr));
        IdentityBox->setItemText(1, QApplication::translate("Login", "\350\200\201\345\270\210", nullptr));

        cp->setText(QApplication::translate("Login", "\345\207\272\345\223\201:\347\275\221\347\273\234\345\267\245\347\250\213\347\263\273\345\205\232\346\224\257\351\203\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
