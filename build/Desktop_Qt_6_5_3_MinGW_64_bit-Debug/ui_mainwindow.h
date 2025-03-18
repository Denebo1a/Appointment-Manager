/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Admin;
    QAction *action_JSON_Import;
    QAction *action_JSON_SaveAs;
    QAction *action_Save;
    QAction *action_Mute;
    QAction *action_BGM01;
    QAction *action_BGM02;
    QAction *action_JSON_New;
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lb_2;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lb_3;
    QLabel *lb_Date_Apt;
    QSpacerItem *horizontalSpacer_5;
    QLabel *lb_4;
    QLabel *lb_AvailableSize;
    QTableWidget *tw_AppointInfo;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QCheckBox *chkb_EnableFilter;
    QDateEdit *de_Date_Filter;
    QComboBox *comb_Duration_Filter;
    QSpacerItem *horizontalSpacer;
    QCheckBox *chkb_Available;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *le_Search;
    QSpacerItem *horizontalSpacer_2;
    QLabel *lb_1;
    QLabel *lb_curDate;
    QLabel *lb_curTime;
    QTableWidget *tw_OutPatient;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *btn_AddAppoint;
    QPushButton *btn_EditApt;
    QPushButton *btn_DeleteApt;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout_4;
    QPushButton *btn_AddOP;
    QPushButton *btn_EditOP;
    QPushButton *btn_DeleteOP;
    QMenuBar *menubar;
    QMenu *menu_File;
    QMenu *menu_Import;
    QMenu *menu_SaveAs;
    QMenu *menu_New;
    QMenu *menu_3;
    QMenu *menu_BGM;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1100, 798);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/icon/windowIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	font-size: 14px;         \n"
"	font: \"Microsoft YaHei UI\";\n"
"	font-weight: bold;\n"
"	color: #3dcce1;\n"
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
"	color: rgb(130, 130, 130);\n"
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
"QMainWindow QLabel\n"
"{\n"
"	font: \"Microsoft YaHei UI\";\n"
"	font-size: 16px;	\n"
"	font-weight: bold;\n"
"	color: #3dcce1;\n"
"}\n"
"\n"
"QCheckBox\n"
"{\n"
"	font: \"Microsoft YaHei UI\";\n"
"	font-size: 16px;	\n"
"	font-weight: bold;\n"
"	color: #3dcce1;\n"
"}"));
        action_Admin = new QAction(MainWindow);
        action_Admin->setObjectName("action_Admin");
        action_Admin->setCheckable(false);
        action_JSON_Import = new QAction(MainWindow);
        action_JSON_Import->setObjectName("action_JSON_Import");
        action_JSON_SaveAs = new QAction(MainWindow);
        action_JSON_SaveAs->setObjectName("action_JSON_SaveAs");
        action_Save = new QAction(MainWindow);
        action_Save->setObjectName("action_Save");
        action_Mute = new QAction(MainWindow);
        action_Mute->setObjectName("action_Mute");
        action_BGM01 = new QAction(MainWindow);
        action_BGM01->setObjectName("action_BGM01");
        action_BGM02 = new QAction(MainWindow);
        action_BGM02->setObjectName("action_BGM02");
        action_JSON_New = new QAction(MainWindow);
        action_JSON_New->setObjectName("action_JSON_New");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setMinimumSize(QSize(1100, 770));
        centralwidget->setMaximumSize(QSize(1100, 770));
        centralwidget->setStyleSheet(QString::fromUtf8("#centralwidget\n"
"{\n"
"	background-image: url(:/image/icon/ui.png);\n"
"}"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 410, 581, 341));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        lb_2 = new QLabel(layoutWidget);
        lb_2->setObjectName("lb_2");
        lb_2->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_3->addWidget(lb_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lb_3 = new QLabel(layoutWidget);
        lb_3->setObjectName("lb_3");
        lb_3->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(lb_3);

        lb_Date_Apt = new QLabel(layoutWidget);
        lb_Date_Apt->setObjectName("lb_Date_Apt");
        lb_Date_Apt->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(lb_Date_Apt);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        lb_4 = new QLabel(layoutWidget);
        lb_4->setObjectName("lb_4");
        lb_4->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(lb_4);

        lb_AvailableSize = new QLabel(layoutWidget);
        lb_AvailableSize->setObjectName("lb_AvailableSize");
        lb_AvailableSize->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(lb_AvailableSize);


        horizontalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout->addLayout(horizontalLayout_3);

        tw_AppointInfo = new QTableWidget(layoutWidget);
        tw_AppointInfo->setObjectName("tw_AppointInfo");
        tw_AppointInfo->setStyleSheet(QString::fromUtf8(" #tw_AppointInfo\n"
"{\n"
"    border: 3px solid #3dcce1;\n"
"    background: none;\n"
"\n"
"	font-size: 14px;         \n"
"	font: \"Microsoft YaHei UI\";\n"
"}\n"
"\n"
"#tw_AppointInfo::Item\n"
"{\n"
"	border:none;\n"
"    height:80px;\n"
"}\n"
"\n"
"#tw_AppointInfo::item::selected\n"
"{\n"
"	font-weight: bold;\n"
"	background: #3dcce1;\n"
"}\n"
"\n"
"QHeaderView::section           \n"
"{\n"
"    font-size:16px;               \n"
"    color:#FFFFFF;                \n"
" \n"
"    background:rgb(129, 185, 211);            \n"
"    border:none;                   \n"
" \n"
"    min-height:36px;             \n"
"    max-height:36px;                          \n"
"}"));

        verticalLayout->addWidget(tw_AppointInfo);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(20, 30, 1051, 361));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        chkb_EnableFilter = new QCheckBox(layoutWidget1);
        chkb_EnableFilter->setObjectName("chkb_EnableFilter");
        chkb_EnableFilter->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(chkb_EnableFilter);

        de_Date_Filter = new QDateEdit(layoutWidget1);
        de_Date_Filter->setObjectName("de_Date_Filter");
        de_Date_Filter->setStyleSheet(QString::fromUtf8("#de_Date_Filter\n"
"{\n"
"  font: \"Microsoft YaHei UI\";\n"
"  font-size:14px;\n"
"  font-weight: bold;\n"
"  color: #3dcce1;\n"
"  padding: 1px 15px 1px 3px;\n"
"  border:3px solid #3dcce1;;\n"
"  border-radius:5px 5px 0px 0px;\n"
"}"));
        de_Date_Filter->setButtonSymbols(QAbstractSpinBox::UpDownArrows);

        horizontalLayout->addWidget(de_Date_Filter);

        comb_Duration_Filter = new QComboBox(layoutWidget1);
        comb_Duration_Filter->setObjectName("comb_Duration_Filter");
        comb_Duration_Filter->setStyleSheet(QString::fromUtf8("#comb_Duration_Filter\n"
"{\n"
"	font: \"Microsoft YaHei UI\";\n"
"	font-size: 14px;\n"
"	font-weight: bold;\n"
"	color: #3dcce1;\n"
"	padding: 1px 15px 1px 3px;\n"
"	border:3px solid #3dcce1;\n"
"	border-radius:5px 5px 0px 0px;\n"
"}\n"
"\n"
"#comb_Duration_Filter QAbstractItemView\n"
"{\n"
"	outline: none;\n"
"	border:3px solid #3dcce1;\n"
"}\n"
"\n"
"#comb_Duration_Filter QAbstractItemView::item\n"
"{\n"
"	color: #3dcce1;\n"
"}\n"
"\n"
"#comb_Duration_Filter QAbstractItemView::item::hover\n"
"{\n"
"	color: #FFFFFF;\n"
"	background-color: #3dcce1;\n"
"}\n"
"\n"
"#comb_Duration_Filter QAbstractItemView::item::selected\n"
"{\n"
"	color: #FFFFFF;\n"
"	background-color: #3dcce1;\n"
"}"));

        horizontalLayout->addWidget(comb_Duration_Filter);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        chkb_Available = new QCheckBox(layoutWidget1);
        chkb_Available->setObjectName("chkb_Available");
        chkb_Available->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(chkb_Available);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        le_Search = new QLineEdit(layoutWidget1);
        le_Search->setObjectName("le_Search");
        le_Search->setStyleSheet(QString::fromUtf8("#le_Search\n"
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
"}\n"
""));

        horizontalLayout->addWidget(le_Search);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        lb_1 = new QLabel(layoutWidget1);
        lb_1->setObjectName("lb_1");
        lb_1->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(lb_1);

        lb_curDate = new QLabel(layoutWidget1);
        lb_curDate->setObjectName("lb_curDate");
        lb_curDate->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(lb_curDate);

        lb_curTime = new QLabel(layoutWidget1);
        lb_curTime->setObjectName("lb_curTime");
        lb_curTime->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(lb_curTime);


        verticalLayout_2->addLayout(horizontalLayout);

        tw_OutPatient = new QTableWidget(layoutWidget1);
        tw_OutPatient->setObjectName("tw_OutPatient");
        tw_OutPatient->setStyleSheet(QString::fromUtf8(" #tw_OutPatient\n"
"{\n"
"    border: 3px solid #3dcce1;\n"
"    background: none;\n"
"\n"
"	font-size: 14px;         \n"
"    font-family: \"Microsoft YaHei\";\n"
"}\n"
"\n"
"#tw_OutPatient::Item\n"
"{\n"
"	border:none;\n"
"    height:80px;\n"
"}\n"
"\n"
"#tw_OutPatient::item::selected\n"
"{\n"
"	font-weight: bold;\n"
"	background: #3dcce1;\n"
"}\n"
"\n"
"     \n"
"QHeaderView::section           \n"
"{\n"
"    font-size:16px;               \n"
"    color:#FFFFFF;                \n"
" \n"
"    background: rgb(129, 185, 211);            \n"
"    border:none;                   \n"
" \n"
"    min-height:48px;             \n"
"    max-height:48px;                          \n"
"}\n"
" \n"
"\n"
""));

        verticalLayout_2->addWidget(tw_OutPatient);

        layoutWidget_2 = new QWidget(centralwidget);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(660, 520, 132, 166));
        verticalLayout_3 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        btn_AddAppoint = new QPushButton(layoutWidget_2);
        btn_AddAppoint->setObjectName("btn_AddAppoint");
        btn_AddAppoint->setStyleSheet(QString::fromUtf8(""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/icon/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_AddAppoint->setIcon(icon1);
        btn_AddAppoint->setIconSize(QSize(20, 20));

        verticalLayout_3->addWidget(btn_AddAppoint);

        btn_EditApt = new QPushButton(layoutWidget_2);
        btn_EditApt->setObjectName("btn_EditApt");
        btn_EditApt->setStyleSheet(QString::fromUtf8(""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/icon/edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_EditApt->setIcon(icon2);

        verticalLayout_3->addWidget(btn_EditApt);

        btn_DeleteApt = new QPushButton(layoutWidget_2);
        btn_DeleteApt->setObjectName("btn_DeleteApt");
        btn_DeleteApt->setStyleSheet(QString::fromUtf8(""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/image/icon/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_DeleteApt->setIcon(icon3);

        verticalLayout_3->addWidget(btn_DeleteApt);

        layoutWidget_3 = new QWidget(centralwidget);
        layoutWidget_3->setObjectName("layoutWidget_3");
        layoutWidget_3->setGeometry(QRect(900, 520, 134, 168));
        verticalLayout_4 = new QVBoxLayout(layoutWidget_3);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        btn_AddOP = new QPushButton(layoutWidget_3);
        btn_AddOP->setObjectName("btn_AddOP");
        btn_AddOP->setMinimumSize(QSize(130, 50));
        btn_AddOP->setMaximumSize(QSize(130, 50));
        btn_AddOP->setStyleSheet(QString::fromUtf8(""));
        btn_AddOP->setIcon(icon1);
        btn_AddOP->setIconSize(QSize(20, 20));

        verticalLayout_4->addWidget(btn_AddOP);

        btn_EditOP = new QPushButton(layoutWidget_3);
        btn_EditOP->setObjectName("btn_EditOP");
        btn_EditOP->setStyleSheet(QString::fromUtf8(""));
        btn_EditOP->setIcon(icon2);

        verticalLayout_4->addWidget(btn_EditOP);

        btn_DeleteOP = new QPushButton(layoutWidget_3);
        btn_DeleteOP->setObjectName("btn_DeleteOP");
        btn_DeleteOP->setStyleSheet(QString::fromUtf8(""));
        btn_DeleteOP->setIcon(icon3);

        verticalLayout_4->addWidget(btn_DeleteOP);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1100, 25));
        menu_File = new QMenu(menubar);
        menu_File->setObjectName("menu_File");
        menu_Import = new QMenu(menu_File);
        menu_Import->setObjectName("menu_Import");
        menu_SaveAs = new QMenu(menu_File);
        menu_SaveAs->setObjectName("menu_SaveAs");
        menu_New = new QMenu(menu_File);
        menu_New->setObjectName("menu_New");
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName("menu_3");
        menu_BGM = new QMenu(menu_3);
        menu_BGM->setObjectName("menu_BGM");
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menu_File->menuAction());
        menubar->addAction(menu_3->menuAction());
        menu_File->addAction(menu_New->menuAction());
        menu_File->addAction(menu_Import->menuAction());
        menu_File->addAction(menu_SaveAs->menuAction());
        menu_File->addAction(action_Save);
        menu_Import->addAction(action_JSON_Import);
        menu_SaveAs->addAction(action_JSON_SaveAs);
        menu_New->addAction(action_JSON_New);
        menu_3->addAction(action_Admin);
        menu_3->addAction(menu_BGM->menuAction());
        menu_BGM->addAction(action_Mute);
        menu_BGM->addAction(action_BGM01);
        menu_BGM->addAction(action_BGM02);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action_Admin->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\220\257\347\256\241\347\220\206\345\221\230\346\235\203\351\231\220", nullptr));
        action_JSON_Import->setText(QCoreApplication::translate("MainWindow", "JSON\346\226\207\344\273\266(.json)", nullptr));
        action_JSON_SaveAs->setText(QCoreApplication::translate("MainWindow", "JSON\346\226\207\344\273\266(.json)", nullptr));
        action_Save->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
        action_Mute->setText(QCoreApplication::translate("MainWindow", "\345\205\263\351\227\255\350\203\214\346\231\257\351\237\263\344\271\220", nullptr));
        action_BGM01->setText(QCoreApplication::translate("MainWindow", "\351\237\263\344\271\22001", nullptr));
        action_BGM02->setText(QCoreApplication::translate("MainWindow", "\351\237\263\344\271\22002", nullptr));
        action_JSON_New->setText(QCoreApplication::translate("MainWindow", "JSON\346\226\207\344\273\266(.json)", nullptr));
        lb_2->setText(QCoreApplication::translate("MainWindow", "\345\275\223\345\211\215\351\227\250\350\257\212\351\242\204\347\272\246\350\257\246\346\203\205", nullptr));
        lb_3->setText(QCoreApplication::translate("MainWindow", "\345\275\223\345\211\215\351\242\204\347\272\246\346\227\245\346\234\237\357\274\232", nullptr));
        lb_Date_Apt->setText(QCoreApplication::translate("MainWindow", "\345\215\240\344\275\215", nullptr));
        lb_4->setText(QCoreApplication::translate("MainWindow", "\345\211\251\344\275\231\345\256\271\351\207\217\357\274\232", nullptr));
        lb_AvailableSize->setText(QCoreApplication::translate("MainWindow", "\345\215\240\344\275\215", nullptr));
        chkb_EnableFilter->setText(QCoreApplication::translate("MainWindow", "\346\214\211\346\227\266\351\227\264\347\255\233\351\200\211", nullptr));
        comb_Duration_Filter->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\351\200\211\346\213\251\346\227\266\346\256\265", nullptr));
        chkb_Available->setText(QCoreApplication::translate("MainWindow", "\345\217\252\346\230\276\347\244\272\345\217\257\351\242\204\347\272\246\351\227\250\350\257\212", nullptr));
        le_Search->setText(QString());
        le_Search->setPlaceholderText(QString());
        lb_1->setText(QCoreApplication::translate("MainWindow", "\345\275\223\345\211\215\346\227\266\351\227\264\357\274\232", nullptr));
        lb_curDate->setText(QCoreApplication::translate("MainWindow", "\346\227\266\351\227\264", nullptr));
        lb_curTime->setText(QCoreApplication::translate("MainWindow", "\346\227\266\351\227\264", nullptr));
        btn_AddAppoint->setText(QCoreApplication::translate("MainWindow", " \346\267\273\345\212\240\346\226\260\351\242\204\347\272\246", nullptr));
        btn_EditApt->setText(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271\345\275\223\345\211\215\351\242\204\347\272\246", nullptr));
        btn_DeleteApt->setText(QCoreApplication::translate("MainWindow", "\345\217\226\346\266\210\345\275\223\345\211\215\351\242\204\347\272\246", nullptr));
        btn_AddOP->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\346\226\260\351\227\250\350\257\212", nullptr));
        btn_EditOP->setText(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271\345\275\223\345\211\215\351\227\250\350\257\212", nullptr));
        btn_DeleteOP->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\345\275\223\345\211\215\351\227\250\350\257\212", nullptr));
        menu_File->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        menu_Import->setTitle(QCoreApplication::translate("MainWindow", "\345\257\274\345\205\245", nullptr));
        menu_SaveAs->setTitle(QCoreApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272", nullptr));
        menu_New->setTitle(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
        menu_BGM->setTitle(QCoreApplication::translate("MainWindow", "\350\203\214\346\231\257\351\237\263\344\271\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
