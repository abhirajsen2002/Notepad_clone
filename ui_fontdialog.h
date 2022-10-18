/********************************************************************************
** Form generated from reading UI file 'fontdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FONTDIALOG_H
#define UI_FONTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FontDialog
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_font;
    QFontComboBox *fontComboBox;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_style;
    QComboBox *comboBox_style;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_size;
    QComboBox *comboBox_size;
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget_2;
    QFormLayout *formLayout;
    QLabel *label_sample;
    QLineEdit *lineEdit_sample;

    void setupUi(QDialog *FontDialog)
    {
        if (FontDialog->objectName().isEmpty())
            FontDialog->setObjectName(QString::fromUtf8("FontDialog"));
        FontDialog->resize(551, 284);
        layoutWidget = new QWidget(FontDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 521, 131));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_font = new QLabel(layoutWidget);
        label_font->setObjectName(QString::fromUtf8("label_font"));

        verticalLayout_3->addWidget(label_font);

        fontComboBox = new QFontComboBox(layoutWidget);
        fontComboBox->setObjectName(QString::fromUtf8("fontComboBox"));

        verticalLayout_3->addWidget(fontComboBox);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_style = new QLabel(layoutWidget);
        label_style->setObjectName(QString::fromUtf8("label_style"));

        verticalLayout_4->addWidget(label_style);

        comboBox_style = new QComboBox(layoutWidget);
        comboBox_style->setObjectName(QString::fromUtf8("comboBox_style"));

        verticalLayout_4->addWidget(comboBox_style);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_size = new QLabel(layoutWidget);
        label_size->setObjectName(QString::fromUtf8("label_size"));

        verticalLayout_5->addWidget(label_size);

        comboBox_size = new QComboBox(layoutWidget);
        comboBox_size->setObjectName(QString::fromUtf8("comboBox_size"));

        verticalLayout_5->addWidget(comboBox_size);


        horizontalLayout->addLayout(verticalLayout_5);

        buttonBox = new QDialogButtonBox(FontDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(26, 240, 511, 29));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget_2 = new QWidget(FontDialog);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(20, 150, 521, 81));
        formLayout = new QFormLayout(layoutWidget_2);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_sample = new QLabel(layoutWidget_2);
        label_sample->setObjectName(QString::fromUtf8("label_sample"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_sample);

        lineEdit_sample = new QLineEdit(layoutWidget_2);
        lineEdit_sample->setObjectName(QString::fromUtf8("lineEdit_sample"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_sample);


        retranslateUi(FontDialog);

        QMetaObject::connectSlotsByName(FontDialog);
    } // setupUi

    void retranslateUi(QDialog *FontDialog)
    {
        FontDialog->setWindowTitle(QCoreApplication::translate("FontDialog", "Dialog", nullptr));
        label_font->setText(QCoreApplication::translate("FontDialog", "Font:", nullptr));
        label_style->setText(QCoreApplication::translate("FontDialog", "Font Style:", nullptr));
        label_size->setText(QCoreApplication::translate("FontDialog", "Font Size:", nullptr));
        label_sample->setText(QCoreApplication::translate("FontDialog", "Sample", nullptr));
        lineEdit_sample->setText(QCoreApplication::translate("FontDialog", "AaBbYyZz", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FontDialog: public Ui_FontDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FONTDIALOG_H
