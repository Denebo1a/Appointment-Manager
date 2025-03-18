#include "opmanagerdlg.h"
#include "qmessagebox.h"
#include "ui_opmanagerdlg.h"

#include <QMessageBox>
#include <QDebug>


OPManagerDlg::OPManagerDlg(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::OPManagerDlg)
{
    ui->setupUi(this);

    initStrTimeTable_Dlg();
}

OPManagerDlg::~OPManagerDlg()
{
    delete ui;
}

/********************
* 初始化界面函数
********************/

void OPManagerDlg::initNewOPView() //初始化添加门诊界面
{
    this->setWindowTitle("添加新门诊");

    //将默认选项设为当前日期
    QDateTime curDatetTime = QDateTime::currentDateTime();
    QDate curDate = curDatetTime.date();
    ui->de_Date_OP->setDate(curDate);

    ui->comb_Duration_OP->addItems(strTimeTable_Dlg);
}

void OPManagerDlg::initEditOPView(const QStringList& list) //初始化修改门诊界面
{
    this->setWindowTitle("修改当前门诊");
    ui->comb_Duration_OP->addItems(strTimeTable_Dlg);

    ui->le_Number_OP->setText(list[0]);
    ui->le_Name_OP->setText(list[1]);
    ui->le_ID_OP->setText(list[2]);
    ui->le_Address_OP->setText(list[3]);
    ui->le_PhoneNum_OP->setText(list[4]);
    ui->de_Date_OP->setDate(QDate::fromString(list[5],"yyyy/MM/dd"));
    ui->spb_Capacity_OP->setValue(list[7].toInt());

    int index_comb;
    for (int i = 0;i < strTimeTable_Dlg.size();++i)
    {
        if (list[6] == strTimeTable_Dlg[i])
            index_comb = i;
    }
    ui->comb_Duration_OP->setCurrentIndex(index_comb);
}

/********************
* 其他初始化函数
********************/

void OPManagerDlg::initStrTimeTable_Dlg() //初始化时段表
{
    strTimeTable_Dlg << "07:00-09:00" << "09:00-11:30" << "14:00-16:00" << "16:00-17:30";
}

/********************
* 按钮槽函数
********************/

void OPManagerDlg::on_btn_Ok_clicked() //点击“确认”按钮
{
    //弹窗提示再次确认
    //构造并初始化弹窗
    QMessageBox msgBox(this);
    msgBox.setWindowTitle("提示"); //设置弹窗标题
    msgBox.setText("确定要" + this->windowTitle() + "吗？"); //设置弹窗文本
    msgBox.setIcon(QMessageBox::Question); //设置弹窗图标
    QAbstractButton* btn_Ok_MsgBox = msgBox.addButton("确认",QMessageBox::AcceptRole); //添加“确定”按钮
    msgBox.addButton("取消",QMessageBox::RejectRole); //添加“取消”按钮
    msgBox.exec(); //弹窗
    //确认点击了弹窗的哪个按钮
    //点击“确认”，执行相应的操作
    if (msgBox.clickedButton() == btn_Ok_MsgBox)
    {
        //获取输入框信息
        m_strNumber_new = ui->le_Number_OP->text();
        m_strName_new = ui->le_Name_OP->text();
        m_strID_new = ui->le_ID_OP->text();
        m_strAddress_new = ui->le_Address_OP->text();
        m_strPhoneNum_new = ui->le_PhoneNum_OP->text();

        m_nCapacity_new = ui->spb_Capacity_OP->value();

        m_index_comb_new = ui->comb_Duration_OP->currentIndex();

        m_strDate_new = ui->de_Date_OP->date().toString("yyyy/MM/dd");
        //关闭OPManagerDlg并将dialogCode置为Accepted
        this->accept();
    }
    //点击“取消”则什么也不做
}

void OPManagerDlg::on_btn_Cancel_clicked() //点击“取消”按钮
{
    //关闭OPManagerDlg并将dialogCode置为Rejected
    this->reject();
}

