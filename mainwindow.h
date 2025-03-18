#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "outpatientinfo.h"

#include <QMainWindow>
#include <QTableWidgetItem>

#include <QEvent>
#include <QMouseEvent>

#include <QMediaPlayer>
#include <QAudioOutput>

#include <QUrl>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots: //槽函数
    //*按钮槽函数*//
    void on_btn_AddOP_clicked(); //添加门诊
    void on_btn_EditOP_clicked(); //修改门诊
    void on_btn_DeleteOP_clicked(); //删除门诊
    void on_btn_AddAppoint_clicked(); //添加预约
    void on_btn_EditApt_clicked(); //修改预约
    void on_btn_DeleteApt_clicked(); //取消预约

    //*其他槽函数*//
    void onOPItemClicked(); //双击门诊信息表格单元格
    void onAppointItemClicked(); //双击预约信息表格单元格

    void search(); //搜索函数
    void onlyShowAvailable(int state); //只显示可预约项目
    void filtByTime(); //按时间筛选

    void newJsonFile(); //新建.json文件菜单选项
    void importJsonFile(); //导入.json文件菜单选项
    void saveAsJsonFile(); //另存为.json文件菜单选项
    void saveJsonFile(); //保存.json文件菜单选项

    void setAdminMode(bool ifAdmin); //设置管理员模式
    void setBGM(); //设置BGM

private:
    Ui::MainWindow *ui;

private://其他函数

    //*初始化界面函数*//
    void initLeftTableWidget(); //初始化门诊信息窗口视图
    void initRightTableWidget(); //初始化预约信息窗口视图

    void initButtons(); //初始化界面所有按钮
    void initSearchBox(); //初始化搜索框
    void initCheckBox(); //初始化CheckBox
    void initTimeFilter(); //初始化按时间筛选控件
    void initMenu(); //初始化菜单

    void initLabels(); //初始化界面文本
    void initCurTimeDisplay(); //初始化实时时间显示

    //*其他初始化函数*//
    void initTimeTable(); //初始化TimeTable
    void initStrTimeTable(); //初始化TimeTable（字符串版本）
    void initGenders(); //初始化性别列表
    void initOthers(); //初始化其他值
    void initMusicPlayer(); //初始化音乐播放模块

    //*事件过滤器相关*//
    bool eventFilter(QObject* object, QEvent *event); //重载事件过滤器函数
    bool deselectItem(QObject* object, QMouseEvent *mouseEvent); //取消选择表格单元格
    ////经调试，事件过滤器功能无法达到预期效果

    //*刷新界面函数*//
    void updateLeftTableWidget(); //刷新门诊信息窗口视图
    void updateRightTableWidget(); //刷新预约信息窗口视图
    void updateButtons(); //刷新所有按钮状态
    void updateLabels(); //刷新所有文本
    void updateCurTime(); //刷新当前时间
    void updateMainWindowTitle(); //刷新当前窗口标题

    //*数据成员维护*//
    //追加门诊成员
    void addNewOutPatient(const QString& number,const QString& name,const QString& ID,const QString& address,
                          const QString& phoneNum,const QDate& date,const TimeDuration& duration,int capacity);
    void clearAllOutPatient(); //清空当前门诊成员

    //*文件读写函数*//
    void readFromJson(const QString& jsonFileName); //从.json文件中读取
    void writeToJson(const QString& jsonFileName); //向.json文件中写入


private: //数据成员
    QVector <OutPatientInfo> OutPatientInfoTable; //维护门诊信息

    //*程序中使用到的常量*//
    QVector <TimeDuration> TimeTable; //维护所有可能的门诊时段
    QStringList strTimeTable; //维护所有可能的门诊时段（字符串版本）
    QStringList genders; //维护性别列表

    //*程序目前的状态*//
    QString CurJsonFileName; //当前打开的Json文件名
    bool adminOrNot; //当前是否具有管理员权限

    //*音乐播放模块*//
    QMediaPlayer* mediaPlayer;
    QAudioOutput* audioOutput; //QAudioOutput为incomplete type，只能以指针形式声明
    QList<QUrl> playList; //可选的播放列表
};

#endif // MAINWINDOW_H
