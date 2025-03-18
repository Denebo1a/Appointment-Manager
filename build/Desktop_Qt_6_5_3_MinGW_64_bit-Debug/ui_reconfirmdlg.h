/********************************************************************************
** Form generated from reading UI file 'reconfirmdlg.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECONFIRMDLG_H
#define UI_RECONFIRMDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_ReconfirmDlg
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *lb_Prompt;

    void setupUi(QDialog *ReconfirmDlg)
    {
        if (ReconfirmDlg->objectName().isEmpty())
            ReconfirmDlg->setObjectName("ReconfirmDlg");
        ReconfirmDlg->resize(400, 300);
        buttonBox = new QDialogButtonBox(ReconfirmDlg);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lb_Prompt = new QLabel(ReconfirmDlg);
        lb_Prompt->setObjectName("lb_Prompt");
        lb_Prompt->setGeometry(QRect(70, 80, 251, 81));

        retranslateUi(ReconfirmDlg);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, ReconfirmDlg, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, ReconfirmDlg, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(ReconfirmDlg);
    } // setupUi

    void retranslateUi(QDialog *ReconfirmDlg)
    {
        ReconfirmDlg->setWindowTitle(QCoreApplication::translate("ReconfirmDlg", "Dialog", nullptr));
        lb_Prompt->setText(QCoreApplication::translate("ReconfirmDlg", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReconfirmDlg: public Ui_ReconfirmDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECONFIRMDLG_H
