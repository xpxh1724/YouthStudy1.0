/********************************************************************************
** Form generated from reading UI file 'editlist.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITLIST_H
#define UI_EDITLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditList
{
public:
    QLabel *label;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QPushButton *btnSave;
    QPushButton *btnReturn;

    void setupUi(QWidget *EditList)
    {
        if (EditList->objectName().isEmpty())
            EditList->setObjectName(QString::fromUtf8("EditList"));
        EditList->resize(310, 670);
        EditList->setMinimumSize(QSize(310, 670));
        EditList->setMaximumSize(QSize(310, 670));
        EditList->setStyleSheet(QString::fromUtf8("*{\n"
"font: 12pt \"\346\245\267\344\275\223\";\n"
"}\n"
"#EditList\n"
"{\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"                                stop:1 rgb(226,238,243),\n"
"                                stop:0 rgb(240,207,214));\n"
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
        label = new QLabel(EditList);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 20, 220, 61));
        label->setStyleSheet(QString::fromUtf8("font: 24pt \"\346\245\267\344\275\223\";\n"
"font-weight:bold;"));
        label->setAlignment(Qt::AlignCenter);
        groupBox = new QGroupBox(EditList);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(16, 90, 280, 477));
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"border:2px solid gray;\n"
"border-radius:10px;\n"
"margin-top:11px;\n"
"}\n"
"QGroupBox::title {\n"
"      subcontrol-origin: margin;\n"
"      subcontrol-position: top;\n"
"}"));
        groupBox->setAlignment(Qt::AlignCenter);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textEdit = new QTextEdit(groupBox);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout->addWidget(textEdit);

        btnSave = new QPushButton(EditList);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        btnSave->setGeometry(QRect(20, 602, 112, 42));
        btnReturn = new QPushButton(EditList);
        btnReturn->setObjectName(QString::fromUtf8("btnReturn"));
        btnReturn->setGeometry(QRect(179, 602, 112, 42));

        retranslateUi(EditList);

        QMetaObject::connectSlotsByName(EditList);
    } // setupUi

    void retranslateUi(QWidget *EditList)
    {
        EditList->setWindowTitle(QApplication::translate("EditList", "Form", nullptr));
        label->setText(QApplication::translate("EditList", "\347\274\226\350\276\221\345\220\215\345\215\225", nullptr));
        groupBox->setTitle(QApplication::translate("EditList", "\351\234\200\345\256\214\346\210\220\344\272\272\345\221\230\345\220\215\345\215\225", nullptr));
        btnSave->setText(QApplication::translate("EditList", "\344\277\235\345\255\230", nullptr));
        btnReturn->setText(QApplication::translate("EditList", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditList: public Ui_EditList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITLIST_H
