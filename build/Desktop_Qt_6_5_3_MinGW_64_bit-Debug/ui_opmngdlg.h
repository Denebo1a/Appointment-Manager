/********************************************************************************
** Form generated from reading UI file 'opmngdlg.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPMNGDLG_H
#define UI_OPMNGDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OPMngDlg
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_3;
    QLabel *label_16;
    QLineEdit *le_PhoneNum_OP;
    QLineEdit *le_ID_OP;
    QLabel *label_4;
    QComboBox *comb_Duration_OP;
    QLabel *label_11;
    QLineEdit *le_Address_OP;
    QLineEdit *le_Name_OP;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_14;
    QLabel *label_15;
    QLineEdit *le_Number_OP;
    QSpinBox *spb_Capacity_OP;
    QDateEdit *de_Date_OP;

    void setupUi(QDialog *OPMngDlg)
    {
        if (OPMngDlg->objectName().isEmpty())
            OPMngDlg->setObjectName("OPMngDlg");
        OPMngDlg->resize(511, 407);
        buttonBox = new QDialogButtonBox(OPMngDlg);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(140, 350, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget = new QWidget(OPMngDlg);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(100, 60, 317, 245));
        gridLayout_3 = new QGridLayout(layoutWidget);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_16 = new QLabel(layoutWidget);
        label_16->setObjectName("label_16");

        gridLayout_3->addWidget(label_16, 8, 0, 1, 2);

        le_PhoneNum_OP = new QLineEdit(layoutWidget);
        le_PhoneNum_OP->setObjectName("le_PhoneNum_OP");

        gridLayout_3->addWidget(le_PhoneNum_OP, 8, 2, 1, 2);

        le_ID_OP = new QLineEdit(layoutWidget);
        le_ID_OP->setObjectName("le_ID_OP");

        gridLayout_3->addWidget(le_ID_OP, 2, 2, 1, 2);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");

        gridLayout_3->addWidget(label_4, 0, 0, 1, 2);

        comb_Duration_OP = new QComboBox(layoutWidget);
        comb_Duration_OP->setObjectName("comb_Duration_OP");

        gridLayout_3->addWidget(comb_Duration_OP, 3, 3, 2, 1);

        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName("label_11");

        gridLayout_3->addWidget(label_11, 3, 0, 2, 2);

        le_Address_OP = new QLineEdit(layoutWidget);
        le_Address_OP->setObjectName("le_Address_OP");

        gridLayout_3->addWidget(le_Address_OP, 7, 2, 1, 2);

        le_Name_OP = new QLineEdit(layoutWidget);
        le_Name_OP->setObjectName("le_Name_OP");

        gridLayout_3->addWidget(le_Name_OP, 1, 2, 1, 2);

        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName("label_9");

        gridLayout_3->addWidget(label_9, 1, 0, 1, 2);

        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName("label_10");

        gridLayout_3->addWidget(label_10, 2, 0, 1, 2);

        label_14 = new QLabel(layoutWidget);
        label_14->setObjectName("label_14");

        gridLayout_3->addWidget(label_14, 5, 0, 1, 2);

        label_15 = new QLabel(layoutWidget);
        label_15->setObjectName("label_15");

        gridLayout_3->addWidget(label_15, 7, 0, 1, 2);

        le_Number_OP = new QLineEdit(layoutWidget);
        le_Number_OP->setObjectName("le_Number_OP");

        gridLayout_3->addWidget(le_Number_OP, 0, 2, 1, 2);

        spb_Capacity_OP = new QSpinBox(layoutWidget);
        spb_Capacity_OP->setObjectName("spb_Capacity_OP");

        gridLayout_3->addWidget(spb_Capacity_OP, 5, 2, 1, 2);

        de_Date_OP = new QDateEdit(layoutWidget);
        de_Date_OP->setObjectName("de_Date_OP");

        gridLayout_3->addWidget(de_Date_OP, 3, 2, 2, 1);


        retranslateUi(OPMngDlg);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, OPMngDlg, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, OPMngDlg, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(OPMngDlg);
    } // setupUi

    void retranslateUi(QDialog *OPMngDlg)
    {
        OPMngDlg->setWindowTitle(QCoreApplication::translate("OPMngDlg", "Dialog", nullptr));
        label_16->setText(QCoreApplication::translate("OPMngDlg", "\350\201\224\347\263\273\347\224\265\350\257\235", nullptr));
        label_4->setText(QCoreApplication::translate("OPMngDlg", "\351\227\250\350\257\212\345\217\267", nullptr));
        label_11->setText(QCoreApplication::translate("OPMngDlg", "\346\216\245\350\257\212\346\227\266\351\227\264", nullptr));
        label_9->setText(QCoreApplication::translate("OPMngDlg", "\351\227\250\350\257\212\345\220\215\347\247\260", nullptr));
        label_10->setText(QCoreApplication::translate("OPMngDlg", "\345\214\273\347\224\237\345\267\245\345\217\267", nullptr));
        label_14->setText(QCoreApplication::translate("OPMngDlg", "\345\256\271\351\207\217", nullptr));
        label_15->setText(QCoreApplication::translate("OPMngDlg", "\351\227\250\350\257\212\345\234\260\345\235\200", nullptr));
        le_Number_OP->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class OPMngDlg: public Ui_OPMngDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPMNGDLG_H
