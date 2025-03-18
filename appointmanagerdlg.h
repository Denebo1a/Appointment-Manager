#ifndef APPOINTMANAGERDLG_H
#define APPOINTMANAGERDLG_H

#include <QDialog>

namespace Ui {
class AppointManagerDlg;
}

class AppointManagerDlg : public QDialog
{
    Q_OBJECT

public:
    explicit AppointManagerDlg(QWidget *parent = nullptr);
    ~AppointManagerDlg();

    //初始化界面函数
    void initNewAppointView(const QString& date,const QString& duration); //初始化添加新预约界面
    void initEditAppointView(const QStringList& list,const QString& date,const QString& duration); //初始化修改预约界面

    //其他初始化函数
    void initGenders(); //初始化性别列表

    //临时维护的预约数据成员
    QString m_strName; //患者名字
    int m_index_Comb; //下拉选框的序数（对应性别）
    int m_nAge; //患者年龄
    QString m_strPhoneNum; //患者手机号码


private slots: //按钮槽函数
    void on_btn_Ok_clicked(); //点击确定按钮
    void on_btn_Cancel_clicked(); //点击取消按钮

private:
    Ui::AppointManagerDlg *ui;

private: //使用到的常量
    QStringList genders; //性别列表
};

#endif // APPOINTMANAGERDLG_H
