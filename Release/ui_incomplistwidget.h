/********************************************************************************
** Form generated from reading UI file 'incomplistwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INCOMPLISTWIDGET_H
#define UI_INCOMPLISTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InCompListWidget
{
public:
    QLabel *username;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QPushButton *btnCopyList;
    QPushButton *btnReturn;

    void setupUi(QWidget *InCompListWidget)
    {
        if (InCompListWidget->objectName().isEmpty())
            InCompListWidget->setObjectName(QString::fromUtf8("InCompListWidget"));
        InCompListWidget->resize(310, 670);
        InCompListWidget->setMinimumSize(QSize(310, 670));
        InCompListWidget->setMaximumSize(QSize(310, 670));
        InCompListWidget->setStyleSheet(QString::fromUtf8("*{\n"
"font: 12pt \"\346\245\267\344\275\223\";\n"
"}\n"
"#InCompListWidget\n"
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
        username = new QLabel(InCompListWidget);
        username->setObjectName(QString::fromUtf8("username"));
        username->setGeometry(QRect(-1, 20, 311, 61));
        username->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\245\267\344\275\223\";\n"
"font-weight:bold;"));
        username->setAlignment(Qt::AlignCenter);
        groupBox = new QGroupBox(InCompListWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(15, 90, 280, 477));
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

        btnCopyList = new QPushButton(InCompListWidget);
        btnCopyList->setObjectName(QString::fromUtf8("btnCopyList"));
        btnCopyList->setGeometry(QRect(20, 590, 110, 47));
        btnReturn = new QPushButton(InCompListWidget);
        btnReturn->setObjectName(QString::fromUtf8("btnReturn"));
        btnReturn->setGeometry(QRect(179, 590, 110, 47));

        retranslateUi(InCompListWidget);

        QMetaObject::connectSlotsByName(InCompListWidget);
    } // setupUi

    void retranslateUi(QWidget *InCompListWidget)
    {
        InCompListWidget->setWindowTitle(QApplication::translate("InCompListWidget", "Form", nullptr));
        username->setText(QApplication::translate("InCompListWidget", "\347\275\221\347\273\234\345\267\245\347\250\2132021\347\272\2471\347\217\255\345\233\242\346\224\257\351\203\250", nullptr));
        groupBox->setTitle(QApplication::translate("InCompListWidget", "\346\234\252\345\256\214\346\210\220\344\272\272\345\221\230\345\220\215\345\215\225", nullptr));
        btnCopyList->setText(QApplication::translate("InCompListWidget", "\345\244\215\345\210\266\345\220\215\345\215\225", nullptr));
        btnReturn->setText(QApplication::translate("InCompListWidget", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InCompListWidget: public Ui_InCompListWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INCOMPLISTWIDGET_H
