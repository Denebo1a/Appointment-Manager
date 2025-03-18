#include "appointmanagerdlg.h"
#include "ui_appointmanagerdlg.h"

#include <QMessageBox>

AppointManagerDlg::AppointManagerDlg(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AppointManagerDlg)
{
    ui->setupUi(this);
    initGenders(); //初始化性别列表
}

AppointManagerDlg::~AppointManagerDlg()
{
    delete ui;
}

/********************
* 初始化界面函数
********************/

//初始化添加新预约界面
void AppointManagerDlg::initNewAppointView(const QString& date,const QString& duration)
{
    //设置窗口标题
    this->setWindowTitle("添加新预约");
    //将所选预约日期于时段同步至窗口
    ui->lb_Date_Apt->setText(date);
    ui->lb_Duration_Apt->setText(duration);
    //初始化性别combo box
    ui->comb_Gender_Apt->addItems(genders);
}

//初始化修改当前预约界面
void AppointManagerDlg::initEditAppointView(const QStringList &list,const QString& date,const QString& duration)
{
    //设置窗口标题
    this->setWindowTitle("修改当前预约");
    //将所选预约日期于时段同步至窗口
    ui->lb_Date_Apt->setText(date);
    ui->lb_Duration_Apt->setText(duration);
    //初始化性别combo box
    ui->comb_Gender_Apt->addItems(genders);
    //将信息读取到框中
    ui->le_Name_Apt->setText(list[0]);
    ui->spb_Age_Apt->setValue(list[2].toInt());
    ui->le_PhoneNum_Apt->setText(list[3]);

    QString gender = list[1];
    //根据读取到的性别来确定Combo Box的当前Index
    int index_Comb;
    for (int i = 0;i < genders.size();++i)
    {
        if (gender == genders[i])
            index_Comb = i;
    }
    ui->comb_Gender_Apt->setCurrentIndex(index_Comb);
}

/********************
* 其他初始化函数
********************/

//初始化性别列表
void AppointManagerDlg::initGenders()
{
    genders << "男" << "女";
}

/********************
* 按钮槽函数
********************/

//点击“确定”按钮
void AppointManagerDlg::on_btn_Ok_clicked()
{
    //弹窗提示再次确认
    //构造并初始化弹窗
    QMessageBox msgBox(this);
    msgBox.setWindowTitle("提示"); //设置窗弹窗标题
    msgBox.setText("确定要" + this->windowTitle() + "吗？"); //设置弹窗文本
    msgBox.setIcon(QMessageBox::Question); //设置弹窗图标
    QAbstractButton* btn_Ok_MsgBox = msgBox.addButton("确认",QMessageBox::AcceptRole); //添加“确定”按钮
    msgBox.addButton("取消",QMessageBox::RejectRole); //添加“取消”按钮
    //弹出窗口
    msgBox.exec();
    //确认点击了弹窗的哪个按钮
    //若点击“确认”，执行相应的操作
    if (msgBox.clickedButton() == btn_Ok_MsgBox)
    {
        //从输入框读取信息
        m_strName = ui->le_Name_Apt->text();
        m_index_Comb = ui->comb_Gender_Apt->currentIndex();
        m_nAge = ui->spb_Age_Apt->value();
        m_strPhoneNum = ui->le_PhoneNum_Apt->text();
        //关闭管理窗口并将DialogCode置为Accepted
        this->accept();
    }
    //点击“取消”则什么也不做
}

//点击“取消”按钮
void AppointManagerDlg::on_btn_Cancel_clicked()
{
    //关闭窗口并将AppointManagerDlg的DialogCode置为Rejected
    this->reject();
}

