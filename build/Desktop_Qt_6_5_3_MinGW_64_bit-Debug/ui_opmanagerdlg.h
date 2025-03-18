/********************************************************************************
** Form generated from reading UI file 'opmanagerdlg.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPMANAGERDLG_H
#define UI_OPMANAGERDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OPManagerDlg
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_Ok;
    QPushButton *btn_Cancel;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lb_1;
    QLineEdit *le_Number_OP;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lb_2;
    QLineEdit *le_Name_OP;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lb_3;
    QLineEdit *le_ID_OP;
    QHBoxLayout *horizontalLayout_5;
    QLabel *lb_4;
    QDateEdit *de_Date_OP;
    QComboBox *comb_Duration_OP;
    QHBoxLayout *horizontalLayout_6;
    QLabel *lb_5;
    QSpinBox *spb_Capacity_OP;
    QHBoxLayout *horizontalLayout_7;
    QLabel *lb_6;
    QLineEdit *le_Address_OP;
    QHBoxLayout *horizontalLayout_8;
    QLabel *lb_7;
    QLineEdit *le_PhoneNum_OP;

    void setupUi(QDialog *OPManagerDlg)
    {
        if (OPManagerDlg->objectName().isEmpty())
            OPManagerDlg->setObjectName("OPManagerDlg");
        OPManagerDlg->resize(600, 450);
        OPManagerDlg->setStyleSheet(QString::fromUtf8("#OPManagerDlg\n"
"{\n"
"	background-image: url(:/image/icon/ui_dlg_OP.png);\n"
"\n"
"	min-width: 600px;\n"
"	max-width: 600px;\n"
"	\n"
"	min-height: 450px;\n"
"	max-height: 450px;\n"
"}\n"
"\n"
"QLineEdit\n"
"{\n"
"	font-size: 14px;         \n"
"	font: \"Microsoft YaHei UI\";\n"
"	font-weight: bold;\n"
"	color: #3dcce1;\n"
"\n"
"	padding: 1px;\n"
"	border-style: solid;\n"
"	border: 1px solid #3dcce1;\n"
"	border-radius: 5px;\n"
"\n"
"	min-width:150px;  \n"
"}\n"
"\n"
"QPushButton\n"
"{\n"
"	font-size: 16px;         \n"
"	font: \"Microsoft YaHei UI\";\n"
"	font-weight: bold;\n"
"	color: #3dcce1;\n"
"\n"
"\n"
"	border: none;\n"
"	border-radius: 15px;\n"
"	\n"
"	min-height: 50px;\n"
"	max-height: 50px;\n"
"\n"
"	min-width: 130px;\n"
"	max-width: 130px;\n"
"\n"
"	background-image: url(:/image/icon/btn_background.png)\n"
"}\n"
"\n"
"QPushButton:disabled\n"
"{\n"
"	background-image: url(:/image/icon/btn_background_disabled.png);\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-image: url(:/image/icon/btn_back"
                        "ground_hover.png)\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background-image: url(:/image/icon/btn_background_pressed.png)\n"
"}"));
        layoutWidget = new QWidget(OPManagerDlg);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(170, 360, 269, 52));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btn_Ok = new QPushButton(layoutWidget);
        btn_Ok->setObjectName("btn_Ok");

        horizontalLayout->addWidget(btn_Ok);

        btn_Cancel = new QPushButton(layoutWidget);
        btn_Cancel->setObjectName("btn_Cancel");

        horizontalLayout->addWidget(btn_Cancel);

        layoutWidget1 = new QWidget(OPManagerDlg);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(140, 50, 381, 261));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lb_1 = new QLabel(layoutWidget1);
        lb_1->setObjectName("lb_1");
        lb_1->setStyleSheet(QString::fromUtf8("#lb_1\n"
"{\n"
"	min-width: 70px;\n"
"	max-width: 70px;\n"
"\n"
"	min-height: 25px;\n"
"	max-height: 25px;\n"
"}"));

        horizontalLayout_2->addWidget(lb_1);

        le_Number_OP = new QLineEdit(layoutWidget1);
        le_Number_OP->setObjectName("le_Number_OP");

        horizontalLayout_2->addWidget(le_Number_OP);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        lb_2 = new QLabel(layoutWidget1);
        lb_2->setObjectName("lb_2");
        lb_2->setStyleSheet(QString::fromUtf8("#lb_2\n"
"{\n"
"	min-width: 70px;\n"
"	max-width: 70px;\n"
"\n"
"	min-height: 25px;\n"
"	max-height: 25px;\n"
"}"));

        horizontalLayout_3->addWidget(lb_2);

        le_Name_OP = new QLineEdit(layoutWidget1);
        le_Name_OP->setObjectName("le_Name_OP");

        horizontalLayout_3->addWidget(le_Name_OP);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        lb_3 = new QLabel(layoutWidget1);
        lb_3->setObjectName("lb_3");
        lb_3->setStyleSheet(QString::fromUtf8("#lb_3\n"
"{\n"
"	min-width: 70px;\n"
"	max-width: 70px;\n"
"\n"
"	min-height: 25px;\n"
"	max-height: 25px;\n"
"}"));

        horizontalLayout_4->addWidget(lb_3);

        le_ID_OP = new QLineEdit(layoutWidget1);
        le_ID_OP->setObjectName("le_ID_OP");

        horizontalLayout_4->addWidget(le_ID_OP);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        lb_4 = new QLabel(layoutWidget1);
        lb_4->setObjectName("lb_4");
        lb_4->setStyleSheet(QString::fromUtf8("#lb_4\n"
"{\n"
"	min-width: 70px;\n"
"	max-width: 70px;\n"
"\n"
"	min-height: 25px;\n"
"	max-height: 25px;\n"
"}"));

        horizontalLayout_5->addWidget(lb_4);

        de_Date_OP = new QDateEdit(layoutWidget1);
        de_Date_OP->setObjectName("de_Date_OP");
        de_Date_OP->setStyleSheet(QString::fromUtf8("#de_Date_OP\n"
"{\n"
"  font: \"Microsoft YaHei UI\";\n"
"  font-size:14px;\n"
"  font-weight: bold;\n"
"  color: #3dcce1;\n"
"\n"
"  padding: 1px 15px 1px 3px;\n"
"  border:1px solid #3dcce1;\n"
"  border-radius:5px 5px 0px 0px;\n"
"}"));

        horizontalLayout_5->addWidget(de_Date_OP);

        comb_Duration_OP = new QComboBox(layoutWidget1);
        comb_Duration_OP->setObjectName("comb_Duration_OP");
        comb_Duration_OP->setStyleSheet(QString::fromUtf8("#comb_Duration_OP\n"
"{\n"
"	font: \"Microsoft YaHei UI\";\n"
"	font-size: 14px;\n"
"	font-weight: bold;\n"
"    color: #3dcce1;\n"
"\n"
"	padding: 1px 15px 1px 3px;\n"
"	border:1px solid #3dcce1;\n"
"	border-radius:5px 5px 0px 0px;\n"
"}\n"
"\n"
"#comb_Duration_OP QAbstractItemView\n"
"{\n"
"	outline: none;\n"
"	border:3px solid #3dcce1;\n"
"}\n"
"\n"
"#comb_Duration_OP QAbstractItemView::item\n"
"{\n"
"	color: #3dcce1;\n"
"}\n"
"\n"
"#comb_Duration_OP QAbstractItemView::item::hover\n"
"{\n"
"	color: #FFFFFF;\n"
"	background-color: #3dcce1;\n"
"}\n"
"\n"
"#comb_Duration_OP QAbstractItemView::item::selected\n"
"{\n"
"	color: #FFFFFF;\n"
"	background-color: #3dcce1;\n"
"}"));

        horizontalLayout_5->addWidget(comb_Duration_OP);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        lb_5 = new QLabel(layoutWidget1);
        lb_5->setObjectName("lb_5");
        lb_5->setStyleSheet(QString::fromUtf8("#lb_5\n"
"{\n"
"	min-width: 70px;\n"
"	max-width: 70px;\n"
"\n"
"	min-height: 25px;\n"
"	max-height: 25px;\n"
"}"));

        horizontalLayout_6->addWidget(lb_5);

        spb_Capacity_OP = new QSpinBox(layoutWidget1);
        spb_Capacity_OP->setObjectName("spb_Capacity_OP");
        spb_Capacity_OP->setStyleSheet(QString::fromUtf8("#spb_Capacity_OP\n"
"{\n"
"  font: \"Microsoft YaHei UI\";\n"
"  font-size:14px;\n"
"  font-weight: bold;\n"
"  color: #3dcce1;\n"
"\n"
"  padding: 1px 15px 1px 3px;\n"
"  border:1px solid #3dcce1;\n"
"  border-radius:5px 5px 0px 0px;\n"
"}"));

        horizontalLayout_6->addWidget(spb_Capacity_OP);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        lb_6 = new QLabel(layoutWidget1);
        lb_6->setObjectName("lb_6");
        lb_6->setStyleSheet(QString::fromUtf8("#lb_6\n"
"{\n"
"	min-width: 70px;\n"
"	max-width: 70px;\n"
"\n"
"	min-height: 25px;\n"
"	max-height: 25px;\n"
"}"));

        horizontalLayout_7->addWidget(lb_6);

        le_Address_OP = new QLineEdit(layoutWidget1);
        le_Address_OP->setObjectName("le_Address_OP");

        horizontalLayout_7->addWidget(le_Address_OP);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        lb_7 = new QLabel(layoutWidget1);
        lb_7->setObjectName("lb_7");
        lb_7->setStyleSheet(QString::fromUtf8("#lb_7\n"
"{\n"
"	min-width: 70px;\n"
"	max-width: 70px;\n"
"\n"
"	min-height: 25px;\n"
"	max-height: 25px;\n"
"}"));

        horizontalLayout_8->addWidget(lb_7);

        le_PhoneNum_OP = new QLineEdit(layoutWidget1);
        le_PhoneNum_OP->setObjectName("le_PhoneNum_OP");

        horizontalLayout_8->addWidget(le_PhoneNum_OP);


        verticalLayout->addLayout(horizontalLayout_8);


        retranslateUi(OPManagerDlg);

        QMetaObject::connectSlotsByName(OPManagerDlg);
    } // setupUi

    void retranslateUi(QDialog *OPManagerDlg)
    {
        OPManagerDlg->setWindowTitle(QCoreApplication::translate("OPManagerDlg", "Dialog", nullptr));
        btn_Ok->setText(QCoreApplication::translate("OPManagerDlg", "\347\241\256\345\256\232", nullptr));
        btn_Cancel->setText(QCoreApplication::translate("OPManagerDlg", "\345\217\226\346\266\210", nullptr));
        lb_1->setText(QCoreApplication::translate("OPManagerDlg", "\351\227\250\350\257\212\345\217\267", nullptr));
        le_Number_OP->setText(QString());
        lb_2->setText(QCoreApplication::translate("OPManagerDlg", "\351\227\250\350\257\212\345\220\215\347\247\260", nullptr));
        lb_3->setText(QCoreApplication::translate("OPManagerDlg", "\345\214\273\347\224\237\345\267\245\345\217\267", nullptr));
        lb_4->setText(QCoreApplication::translate("OPManagerDlg", "\346\216\245\350\257\212\346\227\266\351\227\264", nullptr));
        lb_5->setText(QCoreApplication::translate("OPManagerDlg", "\345\256\271\351\207\217", nullptr));
        lb_6->setText(QCoreApplication::translate("OPManagerDlg", "\351\227\250\350\257\212\345\234\260\345\235\200", nullptr));
        lb_7->setText(QCoreApplication::translate("OPManagerDlg", "\350\201\224\347\263\273\347\224\265\350\257\235", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OPManagerDlg: public Ui_OPManagerDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPMANAGERDLG_H
