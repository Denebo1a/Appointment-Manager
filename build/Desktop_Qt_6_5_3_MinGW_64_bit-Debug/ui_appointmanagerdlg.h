/********************************************************************************
** Form generated from reading UI file 'appointmanagerdlg.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPOINTMANAGERDLG_H
#define UI_APPOINTMANAGERDLG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AppointManagerDlg
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_Ok;
    QPushButton *btn_Cancel;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lb_Name;
    QLineEdit *le_Name_Apt;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lb_PhoneNum;
    QLineEdit *le_PhoneNum_Apt;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lb_Gender;
    QComboBox *comb_Gender_Apt;
    QHBoxLayout *horizontalLayout_5;
    QLabel *lb_Age;
    QSpinBox *spb_Age_Apt;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_6;
    QLabel *lb_Time;
    QLabel *lb_Date_Apt;
    QLabel *lb_Duration_Apt;

    void setupUi(QDialog *AppointManagerDlg)
    {
        if (AppointManagerDlg->objectName().isEmpty())
            AppointManagerDlg->setObjectName("AppointManagerDlg");
        AppointManagerDlg->resize(450, 300);
        AppointManagerDlg->setMinimumSize(QSize(450, 300));
        AppointManagerDlg->setMaximumSize(QSize(450, 300));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/icon/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        AppointManagerDlg->setWindowIcon(icon);
        AppointManagerDlg->setStyleSheet(QString::fromUtf8("#AppointManagerDlg\n"
"{\n"
"	background-image: url(:/image/icon/ui_dlg.png);\n"
"\n"
"	min-width: 450px;\n"
"	max-width: 450px;\n"
"\n"
"	min-height: 300px;\n"
"	max-height: 300px;\n"
"}\n"
"\n"
"QLabel\n"
"{\n"
"	font-size: 16px;         \n"
"	font: \"Microsoft YaHei UI\";\n"
"	font-weight: bold;\n"
"	color: #3dcce1;\n"
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
"	background-image: url(:/image/icon/btn_background_hover.png)\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background-image: url(:/image/icon/btn_background_pressed.png)\n"
"}\n"
"\n"
""
                        "QLineEdit\n"
"{\n"
"	font-size: 14px;\n"
"	color: #3dcce1;\n"
"	font-weight: bold;\n"
"	padding: 1px;\n"
"	border-style: solid;\n"
"	border: 3px solid #3dcce1;\n"
"	border-radius: 5px;\n"
"\n"
"	min-width:150px;  \n"
"}"));
        layoutWidget = new QWidget(AppointManagerDlg);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(90, 230, 269, 52));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btn_Ok = new QPushButton(layoutWidget);
        btn_Ok->setObjectName("btn_Ok");

        horizontalLayout->addWidget(btn_Ok);

        btn_Cancel = new QPushButton(layoutWidget);
        btn_Cancel->setObjectName("btn_Cancel");

        horizontalLayout->addWidget(btn_Cancel);

        widget = new QWidget(AppointManagerDlg);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(110, 30, 261, 134));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lb_Name = new QLabel(widget);
        lb_Name->setObjectName("lb_Name");
        lb_Name->setStyleSheet(QString::fromUtf8("#lb_Name\n"
"{\n"
"	min-width: 35px;\n"
"	max-width: 35px;\n"
"\n"
"	min-height: 25px;\n"
"	max-height: 25px;\n"
"}"));

        horizontalLayout_2->addWidget(lb_Name);

        le_Name_Apt = new QLineEdit(widget);
        le_Name_Apt->setObjectName("le_Name_Apt");
        le_Name_Apt->setStyleSheet(QString::fromUtf8("#le_Name_Apt\n"
"{\n"
"	font-size: 14px;\n"
"	padding: 1px;\n"
"	border-style: solid;\n"
"	border: 1px solid #3dcce1;;\n"
"	border-radius: 5px;\n"
"\n"
"	min-width:150px;  \n"
"}"));

        horizontalLayout_2->addWidget(le_Name_Apt);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        lb_PhoneNum = new QLabel(widget);
        lb_PhoneNum->setObjectName("lb_PhoneNum");
        lb_PhoneNum->setStyleSheet(QString::fromUtf8("#lb_PhoneNum\n"
"{\n"
"	min-width: 35px;\n"
"	max-width: 35px;\n"
"\n"
"	min-height: 25px;\n"
"	max-height: 25px;\n"
"}"));

        horizontalLayout_3->addWidget(lb_PhoneNum);

        le_PhoneNum_Apt = new QLineEdit(widget);
        le_PhoneNum_Apt->setObjectName("le_PhoneNum_Apt");
        le_PhoneNum_Apt->setStyleSheet(QString::fromUtf8("#le_PhoneNum_Apt\n"
"{\n"
"	font-size: 14px;\n"
"	padding: 1px;\n"
"	border-style: solid;\n"
"	border: 1px solid #3dcce1;;\n"
"	border-radius: 5px;\n"
"\n"
"	min-width:150px;  \n"
"}"));

        horizontalLayout_3->addWidget(le_PhoneNum_Apt);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        lb_Gender = new QLabel(widget);
        lb_Gender->setObjectName("lb_Gender");
        lb_Gender->setStyleSheet(QString::fromUtf8("#lb_Gender\n"
"{\n"
"	min-width: 35px;\n"
"	max-width: 35px;\n"
"\n"
"	min-height: 25px;\n"
"	max-height: 25px;\n"
"}"));

        horizontalLayout_4->addWidget(lb_Gender);

        comb_Gender_Apt = new QComboBox(widget);
        comb_Gender_Apt->setObjectName("comb_Gender_Apt");
        comb_Gender_Apt->setStyleSheet(QString::fromUtf8("#comb_Gender_Apt\n"
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
"#comb_Gender_Apt QAbstractItemView\n"
"{\n"
"	outline: none;\n"
"	border:3px solid #3dcce1;\n"
"}\n"
"\n"
"#comb_Gender_Apt QAbstractItemView::item\n"
"{\n"
"	color: #3dcce1;\n"
"}\n"
"\n"
"#comb_Gender_Apt QAbstractItemView::item::hover\n"
"{\n"
"	color: #FFFFFF;\n"
"	background-color: #3dcce1;\n"
"}\n"
"\n"
"#comb_Gender_Apt QAbstractItemView::item::selected\n"
"{\n"
"	color: #FFFFFF;\n"
"	background-color: #3dcce1;\n"
"}"));

        horizontalLayout_4->addWidget(comb_Gender_Apt);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        lb_Age = new QLabel(widget);
        lb_Age->setObjectName("lb_Age");
        lb_Age->setStyleSheet(QString::fromUtf8("#lb_Age\n"
"{\n"
"	min-width: 35px;\n"
"	max-width: 35px;\n"
"\n"
"	min-height: 25px;\n"
"	max-height: 25px;\n"
"}"));

        horizontalLayout_5->addWidget(lb_Age);

        spb_Age_Apt = new QSpinBox(widget);
        spb_Age_Apt->setObjectName("spb_Age_Apt");
        spb_Age_Apt->setStyleSheet(QString::fromUtf8("#spb_Age_Apt\n"
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

        horizontalLayout_5->addWidget(spb_Age_Apt);


        verticalLayout->addLayout(horizontalLayout_5);

        widget1 = new QWidget(AppointManagerDlg);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(110, 170, 261, 22));
        horizontalLayout_6 = new QHBoxLayout(widget1);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        lb_Time = new QLabel(widget1);
        lb_Time->setObjectName("lb_Time");
        lb_Time->setStyleSheet(QString::fromUtf8("#lb_Time\n"
"{\n"
"	min-width: 65px;\n"
"	max-width: 65px;\n"
"\n"
"	max-height: 35px;\n"
"	max-height: 35px;\n"
"}"));

        horizontalLayout_6->addWidget(lb_Time);

        lb_Date_Apt = new QLabel(widget1);
        lb_Date_Apt->setObjectName("lb_Date_Apt");
        lb_Date_Apt->setStyleSheet(QString::fromUtf8("#lb_Date_Apt\n"
"{\n"
"	font-size: 14px;  \n"
"	\n"
"	max-height: 35px;\n"
"	max-height: 35px;\n"
"}"));

        horizontalLayout_6->addWidget(lb_Date_Apt);

        lb_Duration_Apt = new QLabel(widget1);
        lb_Duration_Apt->setObjectName("lb_Duration_Apt");
        lb_Duration_Apt->setStyleSheet(QString::fromUtf8("#lb_Duration_Apt\n"
"{\n"
"	font-size: 14px;  \n"
"\n"
"	max-height: 35px;\n"
"	max-height: 35px;\n"
"}"));

        horizontalLayout_6->addWidget(lb_Duration_Apt);


        retranslateUi(AppointManagerDlg);

        QMetaObject::connectSlotsByName(AppointManagerDlg);
    } // setupUi

    void retranslateUi(QDialog *AppointManagerDlg)
    {
        AppointManagerDlg->setWindowTitle(QCoreApplication::translate("AppointManagerDlg", "Dialog", nullptr));
        btn_Ok->setText(QCoreApplication::translate("AppointManagerDlg", "\347\241\256\345\256\232", nullptr));
        btn_Cancel->setText(QCoreApplication::translate("AppointManagerDlg", "\345\217\226\346\266\210", nullptr));
        lb_Name->setText(QCoreApplication::translate("AppointManagerDlg", "\345\247\223\345\220\215", nullptr));
        le_Name_Apt->setText(QString());
        lb_PhoneNum->setText(QCoreApplication::translate("AppointManagerDlg", "\347\224\265\350\257\235", nullptr));
        lb_Gender->setText(QCoreApplication::translate("AppointManagerDlg", "\346\200\247\345\210\253", nullptr));
        lb_Age->setText(QCoreApplication::translate("AppointManagerDlg", "\345\271\264\351\276\204", nullptr));
        lb_Time->setText(QCoreApplication::translate("AppointManagerDlg", "\351\242\204\347\272\246\346\227\266\351\227\264", nullptr));
        lb_Date_Apt->setText(QCoreApplication::translate("AppointManagerDlg", "TextLabel", nullptr));
        lb_Duration_Apt->setText(QCoreApplication::translate("AppointManagerDlg", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AppointManagerDlg: public Ui_AppointManagerDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPOINTMANAGERDLG_H
