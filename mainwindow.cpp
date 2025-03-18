#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "appointmanagerdlg.h"
#include "opmanagerdlg.h"

#include <QMessageBox>
#include <QDebug>

#include <QFileDialog>

#include <QFile>
#include <QDir>

#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonValue>

#include <QTimer>

#include <QActionGroup>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //其他初始化
    initTimeTable(); //初始化TimeTable
    initStrTimeTable(); //初始化TimeTable（字符串版本）
    initGenders(); //初始化性别列表
    initOthers(); //初始化其他值

    //初始化窗口
    initLeftTableWidget(); //初始化门诊信息窗口视图
    initRightTableWidget(); //初始化预约信息窗口视图
    initButtons(); //初始化界面所有按钮
    initSearchBox(); //初始化搜索框
    initCheckBox(); //初始化CheckBox
    initTimeFilter(); //初始化按时间筛选控件
    initMenu(); //初始化菜单

    initLabels(); //初始化界面文本
    initCurTimeDisplay(); //初始化实时时间显示

    initMusicPlayer(); //初始化音乐播放模块

    readFromJson("D:\\MyArticles\\MyJsonFiles\\OutPatientInfo.json"); //读取默认文件
    updateMainWindowTitle(); //更新窗口标题

    //* 连接信号与槽 *//
    //双击门诊信息表格单元格
    connect(ui->tw_OutPatient,&QTableWidget::itemDoubleClicked,this,&MainWindow::onOPItemClicked);
    //双击预约信息表格单元格
    connect(ui->tw_AppointInfo,&QTableWidget::itemDoubleClicked,this,&MainWindow::onAppointItemClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/********************
 * 初始化界面函数
********************/

//初始化门诊信息窗口视图
void MainWindow::initLeftTableWidget()
{
    //设置事件过滤器
    ui->tw_OutPatient->installEventFilter(this);
    //设置列数
    ui->tw_OutPatient->setColumnCount(8);
    //设置选择模式
    ui->tw_OutPatient->setSelectionBehavior(QAbstractItemView::SelectRows);
    //设置不可编辑
    ui->tw_OutPatient->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //设置行表头
    QStringList headers;
    headers << "门诊号" << "门诊名称" << "值班医生工号" << "门诊地址" << "联系电话" << "接诊日期" << "接诊时间" << "容量";
    ui->tw_OutPatient->setHorizontalHeaderLabels(headers);
    //设置行表头大小
    ui->tw_OutPatient->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

//初始化预约信息窗口视图
void MainWindow::initRightTableWidget()
{
    //设置事件过滤器
    ui->tw_AppointInfo->installEventFilter(this);
    //设置列数
    ui->tw_AppointInfo->setColumnCount(4);
    //设置选择模式
    ui->tw_AppointInfo->setSelectionBehavior(QAbstractItemView::SelectRows);
    //设置不可编辑
    ui->tw_AppointInfo->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //设置行表头
    QStringList headers;
    headers << "姓名"  << "性别" << "年龄" << "电话";
    ui->tw_AppointInfo->setHorizontalHeaderLabels(headers);
    //设置行表头大小
    ui->tw_AppointInfo->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

//初始化界面所有按钮
void MainWindow::initButtons()
{
    //禁用所有按钮
    ui->btn_DeleteOP->setDisabled(true);
    ui->btn_EditOP->setDisabled(true);
    ui->btn_AddOP->setDisabled(true);

    ui->btn_AddAppoint->setDisabled(true);
    ui->btn_EditApt->setDisabled(true);
    ui->btn_DeleteApt->setDisabled(true);
}

//初始化搜索框
void MainWindow::initSearchBox()
{
    //初始化外观与组件
    ui->le_Search->setPlaceholderText("请输入信息以查询");
    //设置图标
    QAction* action_Search = new QAction(ui->le_Search);
    QIcon icon_Search(":/image/icon/search.png");
    action_Search->setIcon(icon_Search);
    ui->le_Search->addAction(action_Search,QLineEdit::LeadingPosition);
    //连接信号与槽
    connect(ui->le_Search,&QLineEdit::textChanged,this,&MainWindow::search);
}

//初始化CheckBox
void MainWindow::initCheckBox()
{
    //连接“只显示可预约门诊”信号与槽
    connect(ui->chkb_Available,&QCheckBox::stateChanged,this,&MainWindow::onlyShowAvailable);
    //连接“按时间筛选”信号与槽
    connect(ui->chkb_EnableFilter,&QCheckBox::stateChanged,this,&MainWindow::filtByTime);
}

//初始化按时间筛选控件
void MainWindow::initTimeFilter()
{
    //获取当前时间
    QDateTime curDateTime = QDateTime::currentDateTime();
    QDate curDate = curDateTime.date();
    //将默认选项设为当前时间
    ui->de_Date_Filter->setDate(curDate);
    //初始化时段Combo box
    ui->comb_Duration_Filter->addItems(strTimeTable);
    ui->comb_Duration_Filter->addItem("不指定时段");
    //连接信号与槽
    connect(ui->de_Date_Filter,&QDateTimeEdit::dateChanged,this,&MainWindow::filtByTime);
    connect(ui->comb_Duration_Filter,&QComboBox::currentIndexChanged,this,&MainWindow::filtByTime);
}

//初始化界面文本
void MainWindow::initLabels()
{
    ui->lb_AvailableSize->setText("尚未选择");
    ui->lb_Date_Apt->setText("尚未选择");
}

//初始化实时时间显示
void MainWindow::initCurTimeDisplay()
{
    //在堆中创建计数器对象
    QTimer* timer = new QTimer(this);
    //连接信号与槽
    connect(timer,&QTimer::timeout,this,&MainWindow::updateCurTime);
    //让计时器开始计时，每一秒发送一个timeout信号，更新当前时间文本
    timer->start(1000);
}

//初始化菜单
void MainWindow::initMenu()
{
    //连接新建、导入、另存为、保存的信号与槽
    connect(ui->action_JSON_New,&QAction::triggered,this,&MainWindow::newJsonFile);
    connect(ui->action_JSON_Import,&QAction::triggered,this,&MainWindow::importJsonFile);
    connect(ui->action_JSON_SaveAs,&QAction::triggered,this,&MainWindow::saveAsJsonFile);
    connect(ui->action_Save,&QAction::triggered,this,&MainWindow::saveJsonFile);
    //连接开启管理员权限的信号与槽
    connect(ui->action_Admin,&QAction::toggled,this,&MainWindow::setAdminMode);
    //默认不勾选开启管理员权限
    ui->action_Admin->setCheckable(true);
    ui->action_Admin->setChecked(false);
    //创建ActionGroup以实现单选菜单选项组
    QActionGroup* BGMSettings = new QActionGroup(this);
    BGMSettings->addAction(ui->action_Mute);
    BGMSettings->addAction(ui->action_BGM01);
    BGMSettings->addAction(ui->action_BGM02);
    ui->action_Mute->setCheckable(true);
    ui->action_BGM01->setCheckable(true);
    ui->action_BGM02->setCheckable(true);
    //默认开启背景音乐
    ui->action_BGM01->setChecked(true);
    //连接设置BGM选项的信号与槽
    connect(BGMSettings,&QActionGroup::triggered,this,&MainWindow::setBGM);
}

/********************
 * 其他初始化函数
********************/

//初始化TimeTable
void MainWindow::initTimeTable()
{
    //预设时段
    QStringList duration;
    duration << "07:00" << "09:00" << "09:00" << "11:30" << "14:00" << "16:00" << "16:00" << "17:30";
    int count = duration.size();
    for (int i = 0;i < count;i = i + 2)
    {
        TimeDuration tempDuration(duration[i],duration[i + 1]);
        TimeTable.append(tempDuration);
    }
}

//初始化TimeTable（字符串版本）
void MainWindow::initStrTimeTable()
{
    QStringList duration;
    duration << "07:00" << "09:00" << "09:00" << "11:30" << "14:00" << "16:00" << "16:00" << "17:30";
    int count = duration.size();
    for (int i = 0;i < count;i = i + 2)
    {
        QString tempStrDuration = (duration[i] + '-' + duration[i + 1]);
        strTimeTable.append(tempStrDuration);
    }
}

//初始化性别列表
void MainWindow::initGenders()
{
    genders << "男" << "女";
}

//初始化其他值
void MainWindow::initOthers()
{
    adminOrNot = false;
}

//初始化音乐播放器模块
void MainWindow::initMusicPlayer()
{
    //初始化播放器模块
    mediaPlayer = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    mediaPlayer->setAudioOutput(audioOutput);
    audioOutput->setVolume(0.5);
    //初始化播放列表
    playList.append(QUrl::fromLocalFile(QDir::currentPath() + "\\debug\\playList\\For Elise.mp3"));
    playList.append(QUrl::fromLocalFile(QDir::currentPath() + "\\debug\\playList\\MARIAGE D'AMOUR.mp3"));
    //设定第一首为默认背景音乐
    int defaultIndex = 0;
    mediaPlayer->setSource(playList[defaultIndex]);
    mediaPlayer->play();
}

/********************
 * 事件过滤器函数
********************/
////经调试，事件过滤器功能无法达到预期效果

//MainWindow的事件过滤器函数重载实现
bool MainWindow::eventFilter(QObject *object, QEvent *event)
{
    qInfo() << "01";
    //检测当前事件是否为鼠标事件
    QMouseEvent* mouseEvent = static_cast <QMouseEvent*> (event);
    //若不是，则传递其他事件给过滤器
    if (mouseEvent == nullptr)
    {
        qInfo() << "02";
        return false;
    }
    //若是鼠标事件，则检查是否为按下或松开
    if (mouseEvent->type() == QEvent::MouseButtonPress || mouseEvent->type() == QEvent::MouseButtonRelease)
    {
        qInfo() << "03";
        return deselectItem(object,mouseEvent);
    }
    //继续将事件传递给部件
    qInfo() << "04";
    return false;
}

//取消选择表格单元格
bool MainWindow::deselectItem(QObject* object, QMouseEvent *mouseEvent)
{
    //获取当前事件所属的部件
    QTableWidget* tableWidgetPtr = static_cast <QTableWidget*> (object);
    //获取鼠标坐标
    QPoint point = mouseEvent->pos();
    //根据鼠标坐标，获取此时鼠标按下时所在的行、列
    QModelIndex index = tableWidgetPtr->indexAt(point);
    QTableWidgetItem* itemPtr = tableWidgetPtr->item(index.row(), index.column());
    //判断该单元格是否是空单元格
    if (itemPtr == nullptr)
    {
        //取消选中
        tableWidgetPtr->setCurrentItem(nullptr);
        updateButtons();
        return true;
    }
    else
    {
        return false;
    }
}

/********************
 * 刷新界面函数
********************/

//刷新门诊信息窗口视图
void MainWindow::updateLeftTableWidget()
{
    //门诊列表不为空，则遍历OutPaitentInfoTable
    if (!OutPatientInfoTable.empty())
    {
        //设置表格行数
        int count = OutPatientInfoTable.size();
        ui->tw_OutPatient->setRowCount(count);

        //遍历OutPatientInfoTable
        for (int i = 0;i < count;++i)
        {
            int propertiesCount = ui->tw_OutPatient->columnCount();
            QStringList properties = OutPatientInfoTable[i].getProperties();

            for (int j = 0;j < propertiesCount;++j)
            {
                QString property = properties[j];
                ui->tw_OutPatient->setItem(i,j,new QTableWidgetItem(property));
                 //设置单元格文本水平居中与垂直居中
                ui->tw_OutPatient->item(i,j)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            }
        }
    }
    else //门诊列表为空,则清空表格
    {
        ui->tw_OutPatient->setRowCount(0);
    }
}

//刷新预约信息窗口视图
void MainWindow::updateRightTableWidget()
{
    //获取当前选中行序数
    int row = ui->tw_OutPatient->currentRow();
    //预约列表不为空，则遍历Appoint
    if (!OutPatientInfoTable[row].Appoint.empty())
    {
        //设置表格行数
        int count = OutPatientInfoTable[row].Appoint.size();
        ui->tw_AppointInfo->setRowCount(count);
        int propertiesCount = ui->tw_AppointInfo->columnCount();

        //遍历OutPatientInfo的Appoint成员中的元素
        for (int i = 0;i < count;++i)
        {
            QStringList properties = OutPatientInfoTable[row].Appoint[i].getProperties();

            for (int j = 0;j < propertiesCount;++j)
            {
                QString property = properties[j];
                ui->tw_AppointInfo->setItem(i,j,new QTableWidgetItem(property));
                //设置单元格文本水平居中与垂直居中
                ui->tw_AppointInfo->item(i,j)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            }
        }
    }
    else //预约列表为空,则清空表格
    {
        ui->tw_AppointInfo->setRowCount(0);
    }
}

//刷新所有按钮状态
void MainWindow::updateButtons()
{
    //先禁用所有按钮
    ui->btn_AddOP->setDisabled(true);
    ui->btn_EditOP->setDisabled(true);
    ui->btn_DeleteOP->setDisabled(true);
    ui->btn_AddAppoint->setDisabled(true);
    ui->btn_EditApt->setDisabled(true);
    ui->btn_DeleteApt->setDisabled(true);
    qInfo() << "here";
    //刷新相关按钮
    //若为管理员，启用“添加新门诊”
    if (adminOrNot)
    {
        ui->btn_AddOP->setEnabled(true);
    }
    //若当前已选中门诊
    if (ui->tw_OutPatient->currentItem() != nullptr)
    {
        //启用“添加新预约”
        ui->btn_AddAppoint->setEnabled(true);
        //若为管理员，启用“修改当前门诊”&“删除当前门诊”
        if (adminOrNot)
        {
            ui->btn_EditOP->setEnabled(true);
            ui->btn_DeleteOP->setEnabled(true);
        }
        //若当前已选中预约，启用“修改当前预约”&“删除当前预约”
        if (ui->tw_AppointInfo->currentItem() != nullptr)
        {
            ui->btn_EditApt->setEnabled(true);
            ui->btn_DeleteApt->setEnabled(true);
        }
    }
}

//刷新所有文本
void MainWindow::updateLabels()
{
    //获取当前选中门诊行序数
    int row = ui->tw_OutPatient->currentRow();
    //显示当前门诊日期
    QString strDate = OutPatientInfoTable[row].getStrDate();
    //设置门诊日期文本
    ui->lb_Date_Apt->setText(strDate);
    //计算当前门诊剩余容量
    int capacity = OutPatientInfoTable[row].getCapacity();
    int queueSize = OutPatientInfoTable[row].Appoint.size();
    int availableSize = capacity - queueSize;
    //显示当前门诊剩余容量
    ui->lb_AvailableSize->setText(QString::number(availableSize));
}

//刷新当前时间
void MainWindow::updateCurTime()
{
    //获取当前时间
    QDateTime curDateTime = QDateTime::currentDateTime();
    QString strCurDate = curDateTime.toString("yyyy/MM/dd");
    QString strCurTime = curDateTime.toString("hh:mm:ss");
    //显示当前时间
    ui->lb_curDate->setText(strCurDate);
    ui->lb_curTime->setText(strCurTime);
}

//刷新当前窗口标题
void MainWindow::updateMainWindowTitle()
{
    //设置窗口标题
    this->setWindowTitle(QString("医院门诊信息管理系统 | 当前门诊表：" + CurJsonFileName));
}

/********************
 * 自定义槽函数
********************/

//双击门诊信息表格单元格
void MainWindow::onOPItemClicked()
{
    /*若处于管理员模式，启用部分按钮
    if (adminOrNot)
    {
        qInfo() << adminOrNot;
        ui->btn_EditOP->setEnabled(true);
        ui->btn_DeleteOP->setEnabled(true);
    }
    ui->btn_AddAppoint->setEnabled(true);
    */
    //刷新按钮
    updateButtons();
    //刷新预约日期与剩余容量
    updateLabels();
    //刷新门诊预约视图
    updateRightTableWidget();
}

//双击预约信息表格单元格
void MainWindow::onAppointItemClicked()
{
    /*启用部分按钮
    ui->btn_EditApt->setEnabled(true);
    ui->btn_DeleteApt->setEnabled(true);
    */
    //刷新按钮
    updateButtons();
}

//搜索功能
void MainWindow::search()
{
    QString input = ui->le_Search->text();
    int row = ui->tw_OutPatient->rowCount();
    //判断搜索栏是否为空
    if (input == "")
    {
        //显示所有单元格
        for (int i = 0;i < row;++i)
        {
            ui->tw_OutPatient->setRowHidden(i,false);
        }
    }
    else
    {
        //找到符合条件的单元格
        QList <QTableWidgetItem*> matchedItems = ui->tw_OutPatient->findItems(input,Qt::MatchContains);
        //隐藏所有单元格
        for (int i = 0;i < row;++i)
        {
            ui->tw_OutPatient->setRowHidden(i,true);
        }
        //判断是否没有符合要求项
        if (!matchedItems.empty())
        {
            //显示符合要求的行
            for (auto item : matchedItems)
            {
                int index = item->row();
                ui->tw_OutPatient->setRowHidden(index,false);
            }
        }
    }
}

//只显示可预约项目
void MainWindow::onlyShowAvailable(int state)
{
    //显示所有单元格
    int row = ui->tw_OutPatient->rowCount();
    for (int i = 0;i < row;++i)
    {
        ui->tw_OutPatient->setRowHidden(i,false);
    }

    if (state == Qt::Checked)
    {
        //遍历OutPatientInfoTable，找到可预约项目行序数
        QList <int> availableItemsIndex;

        for (int i = 0;i < row;++i)
        {
            if (OutPatientInfoTable[i].ifAvailable())
            {
                availableItemsIndex.append(i);
            }
        }
        //隐藏所有单元格
        for (int j = 0;j < row;++j)
        {
            ui->tw_OutPatient->setRowHidden(j,true);
        }
        //判断是否没有符合要求项
        if (!availableItemsIndex.empty())
        {
            //显示符合要求的行
            for (int index : availableItemsIndex)
            {
                ui->tw_OutPatient->setRowHidden(index,false);
            }
        }
        //禁用按时间筛选
        ui->chkb_EnableFilter->setDisabled(true);
    }
    else if (state == Qt::Unchecked)
    {
        //启用按时间筛选
        ui->chkb_EnableFilter->setEnabled(true);
    }
}

//按时间筛选
void MainWindow::filtByTime()
{
    //从控件处获取当前筛选条件
    QString strDate = ui->de_Date_Filter->date().toString("yyyy/MM/dd");
    QString time = ui->comb_Duration_Filter->currentText();

    //显示所有单元格
    int row = ui->tw_OutPatient->rowCount();
    for (int i = 0;i < row;++i)
    {
        ui->tw_OutPatient->setRowHidden(i,false);
    }
    //若用户勾选“按时间筛选”选项
    if (ui->chkb_EnableFilter->isChecked())
    {
        //禁用只显示可预约
        ui->chkb_Available->setDisabled(true);
        //找到符合日期条件的单元格
        QList <QTableWidgetItem*> dateMatchedItems = ui->tw_OutPatient->findItems(strDate,Qt::MatchContains);
        //隐藏所有单元格
        for (int i = 0;i < row;++i)
        {
            ui->tw_OutPatient->setRowHidden(i,true);
        }
        //判断是否有符合要求项
        if (!dateMatchedItems.empty())
        {
            //判断是否不指定时段
            if (time == "" || time == "不指定时段")
            {
                //显示符合日期要求的行
                for (auto item : dateMatchedItems)
                {
                    //获取对应单元格所在的行数
                    int index = item->row();
                    ui->tw_OutPatient->setRowHidden(index,false);
                }
            }
            //若指定时段
            else
            {
                QList <QTableWidgetItem*> bothMatchedItems; //既符合日期，又符合时段的单元格列表
                //遍历已经符合日期的单元格，寻找时间也符合的单元格
                for (auto item : dateMatchedItems)
                {
                    int index = item->row();
                    QTableWidgetItem* t_ItemPtr = ui->tw_OutPatient->item(index,6);
                    if (t_ItemPtr->text() == time)
                    {
                        bothMatchedItems.append(t_ItemPtr);
                    }
                }
                //显示既符合日期，又符合时段的行
                for (auto item : bothMatchedItems)
                {
                    int index = item->row();
                    ui->tw_OutPatient->setRowHidden(index,false);
                }
            }
            //禁用只显示可预约
        }
    }
    else
    {
        //启用只显示可预约
        ui->chkb_Available->setEnabled(true);
    }
}

//新建.json文件菜单选项
void MainWindow::newJsonFile()
{
    clearAllOutPatient(); //清空当前门诊成员
    ui->tw_OutPatient->setRowCount(0); //清空门诊表格视图
    ui->tw_AppointInfo->setRowCount(0); //清空预约表格视图
    //设置当前打开的.json文件名为空
    CurJsonFileName = "";
    //刷新主窗口标题
    updateMainWindowTitle();
}

//导入.json文件菜单选项
void MainWindow::importJsonFile()
{
    //弹出一个file dialog,并返回所打开JSON文件的绝对路径
    QString jsonFileName = QFileDialog::getOpenFileName(this,"导入JSON文件",QDir::currentPath() + "\\debug\\jsonFiles","JSON Files (*.json)");
    readFromJson(jsonFileName);
}

//另存为.json文件菜单选项
void MainWindow::saveAsJsonFile()
{
    //弹出一个file dialog,并返回JSON文件的绝对路径
    QString jsonFileName = QFileDialog::getSaveFileName(this,"另存为JSON文件",QDir::currentPath() + "\\debug\\jsonFiles","JSON Files (*.json)");
    if (!jsonFileName.isEmpty())
        writeToJson(jsonFileName);
}

//保存菜单选项
void MainWindow::saveJsonFile()
{
    //若当前未打开任何JSON文件，则弹出另存为窗口
    if (CurJsonFileName == "")
    {
        saveAsJsonFile();
    }
    //若当前打开了JSON文件，则正常保存
    else
    {
        //写入当前打开的JSON文件
        writeToJson(CurJsonFileName);
    }
}

//设置管理员权限
void MainWindow::setAdminMode(bool ifAdmin)
{
    adminOrNot = ifAdmin;
    /*决定是否启用添加门诊
    ui->btn_AddOP->setEnabled(adminOrNot);
    ui->btn_EditOP->setEnabled(adminOrNot);
    ui->btn_DeleteOP->setEnabled(adminOrNot);*/
    //更新按钮
    updateButtons();
}

void MainWindow::setBGM()
{
    //用户选择关闭背景音乐
    if (ui->action_Mute->isChecked() == true)
    {
        //将音频输出静音
        audioOutput->setMuted(true);
    }
    //用户选择BGM01
    else if (ui->action_BGM01->isChecked() == true)
    {
        //设置BGM01
        audioOutput->setMuted(false);
        mediaPlayer->setSource(playList[0]);
        mediaPlayer->play();
    }
    //用户选择BGM02
    else if (ui->action_BGM02->isChecked() == true)
    {
        //设置BGM02
        audioOutput->setMuted(false);
        mediaPlayer->setSource(playList[1]);
        mediaPlayer->play();
    }
}

/********************
 * 维护数据成员
********************/

//追加门诊成员
void MainWindow::addNewOutPatient(const QString& number,const QString& name,const QString& ID,const QString& address,
                                  const QString& phoneNum,const QDate& date,const TimeDuration& duration,int capacity)
{
    OutPatientInfo t_OutPatient;
    t_OutPatient.setProperties(number,name,ID,address,phoneNum,date,duration,capacity);

    OutPatientInfoTable.append(t_OutPatient);
}

//清空门诊成员
void MainWindow::clearAllOutPatient()
{
    OutPatientInfoTable.clear();
    OutPatientInfoTable.squeeze();
}

/********************
 * 文件读写函数
********************/

void MainWindow::readFromJson(const QString& jsonFileName)
{
    //打开.json文件
    QFile jsonFile(jsonFileName);
    //判断文件是否存在
    if (jsonFile.exists())
    {
        qInfo() << "exist";
        //以只读模式打开IO，读取，并关闭IO
        jsonFile.open(QIODevice::ReadOnly);
        QByteArray jsonData = jsonFile.readAll();
        jsonFile.close();

        //错误反馈对象
        QJsonParseError jsonParseError;
        //读取到QJsonDocument对象中
        QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonData,&jsonParseError);
        qInfo() << jsonParseError.errorString();
        //若无错误，进一步操作
        if (jsonParseError.error == QJsonParseError::NoError)
        {
            //清空当前维护的门诊对象
            clearAllOutPatient();
            qInfo() << "fromJson ok";
            QJsonArray jsonArray = jsonDocument.array();

            //临时存储数据的变量
            QString number_OP; //门诊号
            QString name_OP; //门诊名称
            QString ID_OP; //值班医生工号
            QString address_OP; //门诊地址
            QString phoneNumber_OP; //联系电话
            QDate date_OP; //接诊日期
            TimeDuration timeDuration_OP; //接诊时间
            int capacity_OP; //容量

            QString name_Apt; //预约患者姓名
            QString gender_Apt; //预约患者性别
            int age_Apt; //预约患者年龄
            QDate date_Apt; //预约日期
            TimeDuration time_Apt; //预约时段
            QString phoneNum_Apt; //预约患者手机号码

            //遍历json数组（门诊列表）
            for (int i = 0;i < jsonArray.size();++i)
            {
                //读取数组中的json对象元素（门诊对象）
                QJsonObject jsonOPObject = jsonArray.at(i).toObject();
                qInfo() << "array items to Object";
                //读取门诊各项信息
                number_OP = jsonOPObject.value("number").toString();
                name_OP = jsonOPObject.value("name").toString();
                ID_OP = jsonOPObject.value("ID").toString();
                address_OP = jsonOPObject.value("address").toString();
                phoneNumber_OP = jsonOPObject.value("phoneNumber").toString();
                date_OP = QDate::fromString(jsonOPObject.value("date").toString(),"yyyy/MM/dd");
                timeDuration_OP = TimeDuration::tranFromString(jsonOPObject.value("time").toString());
                capacity_OP = jsonOPObject.value("capacity").toInt();

                //添加数据成员
                addNewOutPatient(number_OP,name_OP,ID_OP,address_OP,phoneNumber_OP,date_OP,timeDuration_OP,capacity_OP);

                //读取门诊预约列表
                QJsonArray subJsonArray = jsonOPObject.value("appointments").toArray();
                //遍历json数组（预约列表）
                for (int j = 0;j < subJsonArray.size();++j)
                {
                    //读取子数组中的json对象元素（预约对象）
                    QJsonObject jsonAptObject = subJsonArray.at(j).toObject();
                    qInfo() << "subArray items to Object";
                    name_Apt = jsonAptObject.value("name").toString();
                    gender_Apt = jsonAptObject.value("gender").toString();
                    age_Apt = jsonAptObject.value("age").toInt();
                    qInfo() << jsonAptObject.value("age").type();
                    date_Apt = QDate::fromString(jsonAptObject.value("date").toString(),"yyyy/MM/dd");
                    time_Apt = TimeDuration::tranFromString(jsonAptObject.value("time").toString());
                    phoneNum_Apt = jsonAptObject.value("phoneNumber").toString();

                    //添加门诊成员
                    OutPatientInfoTable[i].addNewAppoint(name_Apt,gender_Apt,age_Apt,date_Apt,time_Apt,phoneNum_Apt);
                }
            }
            //刷新门诊表格视图
            updateLeftTableWidget();
            //清空预约表格
            ui->tw_AppointInfo->setRowCount(0);
            //设置当前打开的.json文件名
            CurJsonFileName = jsonFileName;
            //刷新主窗口标题
            updateMainWindowTitle();
        }
        //若打开失败（例如.json文件是空的，或不符合规范，则弹窗提示）
        else if (jsonParseError.error == QJsonParseError::IllegalValue)
        {
            QMessageBox msgBox;
            msgBox.setWindowTitle("提示");
            msgBox.setText("导入失败。");
            msgBox.setInformativeText("您导入的.json文件为空或不符合规范。");
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.addButton("确认",QMessageBox::AcceptRole);
            msgBox.exec();
        }
    }
}

void MainWindow::writeToJson(const QString& jsonFileName)
{
    //构建json数组（门诊对象数组）
    QJsonArray jsonArray;
    //遍历当前OutPatientInfoTable
    for (int i = 0;i < OutPatientInfoTable.size();++i)
    {
        QStringList propertiesList_OP = OutPatientInfoTable[i].getProperties();
        QJsonObject jsonOPObject;
        jsonOPObject.insert("number",propertiesList_OP[0]);
        jsonOPObject.insert("name",propertiesList_OP[1]);
        jsonOPObject.insert("ID",propertiesList_OP[2]);
        jsonOPObject.insert("address",propertiesList_OP[3]);
        jsonOPObject.insert("phoneNumber",propertiesList_OP[4]);
        jsonOPObject.insert("date",propertiesList_OP[5]);
        jsonOPObject.insert("time",propertiesList_OP[6]);
        jsonOPObject.insert("capacity",propertiesList_OP[7].toInt());


        //构建json对象的子数组（预约对象数组）
        QJsonArray subJsonArray;
        //遍历当前OutPatient的预约列表
        for (int j = 0;j < OutPatientInfoTable[i].Appoint.size();++j)
        {
            QStringList propertiesList_Apt = OutPatientInfoTable[i].Appoint[j].getProperties();
            QStringList DateAndTime = OutPatientInfoTable[i].Appoint[j].getDateAndTime();
            QJsonObject jsonAptObject;
            jsonAptObject.insert("name",propertiesList_Apt[0]);
            jsonAptObject.insert("gender",propertiesList_Apt[1]);
            jsonAptObject.insert("age",propertiesList_Apt[2].toInt());
            qInfo() << propertiesList_Apt[2];
            jsonAptObject.insert("date",DateAndTime[0]);
            qInfo() << DateAndTime[0];
            jsonAptObject.insert("time",DateAndTime[1]);
            jsonAptObject.insert("phoneNumber",propertiesList_Apt[3]);
            //在子数组（预约对象数组）中追加json对象（预约对象）
            subJsonArray.append(jsonAptObject);
        }
        //在json对象中添加预约键值对
        jsonOPObject.insert("appointments",subJsonArray);
        //在json数组（门诊对象数组）中追加json对象（门诊对象）
        jsonArray.append(jsonOPObject);
        qInfo() << "OutPatient" << i;
    }


    //创建临时QJsonDocument
    QJsonDocument jsonDocument;
    jsonDocument.setArray(jsonArray);

    QByteArray jsonData = jsonDocument.toJson();
    //打开.json文件
    QFile jsonFile(jsonFileName);

    //若指定路径不存在，则创建该路径
    QDir dir = QFileInfo(jsonFile).dir();
    if (!dir.exists())
    {
        dir.mkpath(dir.path());
    }
    //以只写模式打开IO,写入，并关闭IO
    jsonFile.open(QIODevice::WriteOnly);
    jsonFile.write(jsonData);
    jsonFile.close();

    //设置当前打开的.json文件名
    CurJsonFileName = jsonFileName;
    //刷新主窗口标题
    updateMainWindowTitle();
}

/********************
 * 按钮槽函数
********************/

void MainWindow::on_btn_AddAppoint_clicked() //添加新预约
{
    //获取当前选中行序数
    int row = ui->tw_OutPatient->currentRow();
    //检查所选门诊是否可预约
    if (OutPatientInfoTable[row].ifAvailable())
    {
        //若门诊正在进行，弹窗提示
        if (OutPatientInfoTable[row].ifBusy())
        {
            QMessageBox msgBox;
            msgBox.setWindowTitle("提示");
            msgBox.setText("您选定的门诊正在进行。");
            msgBox.setInformativeText("若仍要预约，请点击确认。");
            msgBox.setIcon(QMessageBox::Information);
            msgBox.addButton("确认",QMessageBox::AcceptRole);
            msgBox.exec();
        }
        //初始化弹出窗口
        AppointManagerDlg newAppointDlg(this);
        //初始化预约日期与时间
        QString strDate = ui->tw_OutPatient->item(row,5)->text();
        QString strDuration = ui->tw_OutPatient->item(row,6)->text();
        //初始化“添加新预约”窗口
        newAppointDlg.initNewAppointView(strDate,strDuration);

        //读取输入信息
        int dlgCode = newAppointDlg.exec();
        if (dlgCode == QDialog::Accepted)
        {
            QString name = newAppointDlg.m_strName;

            int index_Comb = newAppointDlg.m_index_Comb;
            QString gender = genders[index_Comb];

            int age = newAppointDlg.m_nAge;

            QDate date = QDate::fromString(strDate,"yyyy/MM/dd");

            TimeDuration time = TimeDuration::tranFromString(strDuration);

            QString phoneNum = newAppointDlg.m_strPhoneNum;
            //追加新预约成员
            OutPatientInfoTable[row].addNewAppoint(name,gender,age,date,time,phoneNum);
            //刷新门诊表格视图
            updateRightTableWidget();
            //刷新剩余容量
            updateLabels();
        }
    }
    //如果不可预约，则弹窗提示
    else
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("提示");
        msgBox.setText("抱歉，您选定的门诊预约已满或时间已过。");
        msgBox.setInformativeText("请选择其他可预约门诊。");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.addButton("确认",QMessageBox::AcceptRole);
        msgBox.exec();
    }
}

//修改当前预约
void MainWindow::on_btn_EditApt_clicked()
{
    //获取当前选中行序数
    int row_OP = ui->tw_OutPatient->currentRow();
    int row_Apt = ui->tw_AppointInfo->currentRow();

    QStringList propertiesList = OutPatientInfoTable[row_OP].Appoint[row_Apt].getProperties();
    QString strDate = ui->tw_OutPatient->item(row_OP,5)->text();
    QString strDuration = ui->tw_OutPatient->item(row_OP,6)->text();

    //初始化弹出窗口
    AppointManagerDlg editAppointDlg;
    editAppointDlg.initEditAppointView(propertiesList,strDate,strDuration);
    //弹出窗口
    int dlgCode = editAppointDlg.exec();
    if (dlgCode == QDialog::Accepted)
    {
        QString name = editAppointDlg.m_strName;

        int index_Comb = editAppointDlg.m_index_Comb;
        QString gender = genders[index_Comb];

        int age = editAppointDlg.m_nAge;

        QString phoneNum = editAppointDlg.m_strPhoneNum;
        //修改当前预约成员
        OutPatientInfoTable[row_OP].Appoint[row_Apt].setProperties(name,gender,age,phoneNum);
        //刷新门诊表格视图
        updateRightTableWidget();
    }
}

//删除当前预约
void MainWindow::on_btn_DeleteApt_clicked()
{
    //弹窗提示再次确认
    QMessageBox msgBox(this);
    msgBox.setWindowTitle("提示");
    msgBox.setText("确定要取消当前预约吗？");
    msgBox.setIcon(QMessageBox::Question);
    QAbstractButton* btn_Ok_MsgBox = msgBox.addButton("确认",QMessageBox::AcceptRole);
    msgBox.addButton("取消",QMessageBox::RejectRole);
    msgBox.exec();
    if (msgBox.clickedButton() == btn_Ok_MsgBox)
    {
        //获取当前选中行序数
        int row_OP = ui->tw_OutPatient->currentRow();
        int row_Apt = ui->tw_AppointInfo->currentRow();
        //删除门诊成员
        OutPatientInfoTable[row_OP].Appoint.remove(row_Apt);
        //刷新门诊表格视图
        updateRightTableWidget();
        //刷新剩余容量
        updateLabels();
    }
}

//添加门诊信息
void MainWindow::on_btn_AddOP_clicked()
{
    OPManagerDlg newOPDlg(this);
    newOPDlg.initNewOPView();
    int dlgCode = newOPDlg.exec();

    //读取输入信息
    if (dlgCode == QDialog::Accepted)
    {
        QString number = newOPDlg.m_strNumber_new;
        QString name = newOPDlg.m_strName_new;
        QString ID = newOPDlg.m_strID_new;
        QString address = newOPDlg.m_strAddress_new;
        QString phoneNum = newOPDlg.m_strPhoneNum_new;

        QString strDate = newOPDlg.m_strDate_new;
        QDate date = QDate::fromString(strDate,"yyyy/MM/dd");

        TimeDuration duration = TimeTable[newOPDlg.m_index_comb_new];

        int capacity = newOPDlg.m_nCapacity_new;

        //追加新门诊成员
        addNewOutPatient(number,name,ID,address,phoneNum,date,duration,capacity);
        //刷新门诊表格视图
        updateLeftTableWidget();
    }
}

//修改当前门诊信息
void MainWindow::on_btn_EditOP_clicked()
{
    //获取当前选中行序数
    int row = ui->tw_OutPatient->currentRow();

    //获取表格一行的内容
    QString number = ui->tw_OutPatient->item(row,0)->text();
    QString name = ui->tw_OutPatient->item(row,1)->text();
    QString ID = ui->tw_OutPatient->item(row,2)->text();
    QString address = ui->tw_OutPatient->item(row,3)->text();
    QString phoneNum = ui->tw_OutPatient->item(row,4)->text();
    QString strDate = ui->tw_OutPatient->item(row,5)->text();
    QString strDuration = ui->tw_OutPatient->item(row,6)->text();
    QString strCapacity = ui->tw_OutPatient->item(row,7)->text();

    QStringList infoList;
    infoList << number << name << ID << address << phoneNum << strDate << strDuration << strCapacity;
    //读取到弹出的输入框中
    OPManagerDlg editOPDlg(this);
    editOPDlg.initEditOPView(infoList);
    //弹出窗口
    int dlgCode = editOPDlg.exec();

    if (dlgCode == QDialog::Accepted)
    {
        QString number = editOPDlg.m_strNumber_new;
        QString name = editOPDlg.m_strName_new;
        QString ID = editOPDlg.m_strID_new;
        QString address = editOPDlg.m_strAddress_new;
        QString phoneNum = editOPDlg.m_strPhoneNum_new;

        QString strDate = editOPDlg.m_strDate_new;
        QDate date = QDate::fromString(strDate,"yyyy/MM/dd");

        TimeDuration duration = TimeTable[editOPDlg.m_index_comb_new];

        int capacity = editOPDlg.m_nCapacity_new;
        //更新门诊成员
        OutPatientInfoTable[row].setProperties(number,name,ID,address,phoneNum,date,duration,capacity);
        //刷新门诊表格视图
        updateLeftTableWidget();
    }
}

void MainWindow::on_btn_DeleteOP_clicked() //删除当前门诊信息
{
    //弹窗提示再次确认
    QMessageBox msgBox(this);
    msgBox.setWindowTitle("提示");
    msgBox.setText("确定要删除当前门诊吗？");
    msgBox.setIcon(QMessageBox::Question);
    QAbstractButton* btn_Ok_MsgBox = msgBox.addButton("确认",QMessageBox::AcceptRole);
    msgBox.addButton("取消",QMessageBox::RejectRole);
    msgBox.exec();
    if (msgBox.clickedButton() == btn_Ok_MsgBox)
    {
        //获取当前选中行序数
        int row = ui->tw_OutPatient->currentRow();
        //删除门诊成员
        OutPatientInfoTable.remove(row);
        //刷新门诊表格视图
        updateLeftTableWidget();
        //清空预约表格
        ui->tw_AppointInfo->setRowCount(0);
    }
}





