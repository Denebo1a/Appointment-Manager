#ifndef OPMANAGERDLG_H
#define OPMANAGERDLG_H

#include <QDialog>

namespace Ui {
class OPManagerDlg;
}

class OPManagerDlg : public QDialog
{
    Q_OBJECT

public:
    explicit OPManagerDlg(QWidget *parent = nullptr);
    ~OPManagerDlg();

    //临时维护的数据成员
    QString m_strNumber_new; //门诊号
    QString m_strName_new; //门诊名称
    QString m_strID_new; //值班医生工号
    QString m_strAddress_new; //门诊地址
    QString m_strPhoneNum_new; //联系电话
    QString m_strDate_new; //接诊日期字符串
    int m_index_comb_new; //接诊时间combo box序号
    int m_nCapacity_new; //容量


    //*初始化界面函数*//
    void initNewOPView(); //初始化添加新门诊界面
    void initEditOPView(const QStringList& list); //初始化修改门诊界面

    //*其他初始化函数*//
    void initStrTimeTable_Dlg();//初始化时段表

private slots: //按钮槽函数
    void on_btn_Ok_clicked(); //点击确定按钮
    void on_btn_Cancel_clicked(); //点击取消按钮

private:
    Ui::OPManagerDlg *ui;

private: //使用到的常量
    QStringList strTimeTable_Dlg; //时段表

};

#endif // OPMANAGERDLG_H
