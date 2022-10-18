/********************************************************************************
** Form generated from reading UI file 'finddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDDIALOG_H
#define UI_FINDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FindDialog
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_buttons;
    QPushButton *pushButton_find_prev;
    QPushButton *pushButton_find_next;
    QPushButton *pushButton_replace;
    QPushButton *pushButton_replace_all;
    QPushButton *pushButton_cancel;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_input;
    QFormLayout *formLayout_text;
    QLabel *label_find;
    QLineEdit *lineEdit_find;
    QLineEdit *lineEdit_replace;
    QLabel *label_replace;
    QCheckBox *checkBox_match_case;
    QCheckBox *checkBox_wrap_around;

    void setupUi(QDialog *FindDialog)
    {
        if (FindDialog->objectName().isEmpty())
            FindDialog->setObjectName(QString::fromUtf8("FindDialog"));
        FindDialog->resize(420, 169);
        layoutWidget = new QWidget(FindDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(330, 0, 86, 161));
        verticalLayout_buttons = new QVBoxLayout(layoutWidget);
        verticalLayout_buttons->setObjectName(QString::fromUtf8("verticalLayout_buttons"));
        verticalLayout_buttons->setSizeConstraint(QLayout::SetMinimumSize);
        verticalLayout_buttons->setContentsMargins(0, 0, 0, 0);
        pushButton_find_prev = new QPushButton(layoutWidget);
        pushButton_find_prev->setObjectName(QString::fromUtf8("pushButton_find_prev"));

        verticalLayout_buttons->addWidget(pushButton_find_prev);

        pushButton_find_next = new QPushButton(layoutWidget);
        pushButton_find_next->setObjectName(QString::fromUtf8("pushButton_find_next"));

        verticalLayout_buttons->addWidget(pushButton_find_next);

        pushButton_replace = new QPushButton(layoutWidget);
        pushButton_replace->setObjectName(QString::fromUtf8("pushButton_replace"));

        verticalLayout_buttons->addWidget(pushButton_replace);

        pushButton_replace_all = new QPushButton(layoutWidget);
        pushButton_replace_all->setObjectName(QString::fromUtf8("pushButton_replace_all"));

        verticalLayout_buttons->addWidget(pushButton_replace_all);

        pushButton_cancel = new QPushButton(layoutWidget);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));

        verticalLayout_buttons->addWidget(pushButton_cancel);

        layoutWidget_2 = new QWidget(FindDialog);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(3, 0, 321, 161));
        verticalLayout_input = new QVBoxLayout(layoutWidget_2);
        verticalLayout_input->setObjectName(QString::fromUtf8("verticalLayout_input"));
        verticalLayout_input->setContentsMargins(0, 0, 0, 0);
        formLayout_text = new QFormLayout();
        formLayout_text->setObjectName(QString::fromUtf8("formLayout_text"));
        label_find = new QLabel(layoutWidget_2);
        label_find->setObjectName(QString::fromUtf8("label_find"));

        formLayout_text->setWidget(0, QFormLayout::LabelRole, label_find);

        lineEdit_find = new QLineEdit(layoutWidget_2);
        lineEdit_find->setObjectName(QString::fromUtf8("lineEdit_find"));

        formLayout_text->setWidget(0, QFormLayout::FieldRole, lineEdit_find);

        lineEdit_replace = new QLineEdit(layoutWidget_2);
        lineEdit_replace->setObjectName(QString::fromUtf8("lineEdit_replace"));

        formLayout_text->setWidget(1, QFormLayout::FieldRole, lineEdit_replace);

        label_replace = new QLabel(layoutWidget_2);
        label_replace->setObjectName(QString::fromUtf8("label_replace"));

        formLayout_text->setWidget(1, QFormLayout::LabelRole, label_replace);


        verticalLayout_input->addLayout(formLayout_text);

        checkBox_match_case = new QCheckBox(layoutWidget_2);
        checkBox_match_case->setObjectName(QString::fromUtf8("checkBox_match_case"));

        verticalLayout_input->addWidget(checkBox_match_case);

        checkBox_wrap_around = new QCheckBox(layoutWidget_2);
        checkBox_wrap_around->setObjectName(QString::fromUtf8("checkBox_wrap_around"));

        verticalLayout_input->addWidget(checkBox_wrap_around);


        retranslateUi(FindDialog);

        QMetaObject::connectSlotsByName(FindDialog);
    } // setupUi

    void retranslateUi(QDialog *FindDialog)
    {
        FindDialog->setWindowTitle(QCoreApplication::translate("FindDialog", "Dialog", nullptr));
        pushButton_find_prev->setText(QCoreApplication::translate("FindDialog", "Find Prev.", nullptr));
        pushButton_find_next->setText(QCoreApplication::translate("FindDialog", "Find Next", nullptr));
        pushButton_replace->setText(QCoreApplication::translate("FindDialog", "Replace", nullptr));
        pushButton_replace_all->setText(QCoreApplication::translate("FindDialog", "Replace All", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("FindDialog", "Close", nullptr));
        label_find->setText(QCoreApplication::translate("FindDialog", "Find what:", nullptr));
        label_replace->setText(QCoreApplication::translate("FindDialog", "Replace with:", nullptr));
        checkBox_match_case->setText(QCoreApplication::translate("FindDialog", "Match case", nullptr));
        checkBox_wrap_around->setText(QCoreApplication::translate("FindDialog", "Wrap around", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FindDialog: public Ui_FindDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDDIALOG_H
