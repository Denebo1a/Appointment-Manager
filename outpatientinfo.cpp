#include "outpatientinfo.h"

OutPatientInfo::OutPatientInfo() {}

/********************
* Access Function
********************/

//设置门诊各项属性
void OutPatientInfo::setProperties(const QString &number, const QString &name, const QString &ID, const QString &address,
                                   const QString &phoneNum, const QDate &date, const TimeDuration &duration, int capacity)
{
    m_strNumber = number;
    m_strName = name;
    m_strID = ID;
    m_strAddress = address;
    m_strPhoneNumber = phoneNum;
    m_Date = date;
    m_TimeDuration = duration;
    m_nCapacity = capacity;
    //遍历当前门诊预约列表，修改预约时间
    for (int i = 0;i < Appoint.size();++i)
    {
        Appoint[i].setDateAndTime(date,duration);
    }
}

//获取门诊各项属性
QStringList OutPatientInfo::getProperties()
{
    QStringList propertiesList; //属性列表

    //类型转换
    QString date = m_Date.toString("yyyy/MM/dd");
    QString duration = m_TimeDuration.tranToString();

    propertiesList << m_strNumber << m_strName <<  m_strID << m_strAddress
                   << m_strPhoneNumber << date << duration << QString::number(m_nCapacity);
    return propertiesList;
}

//获取门诊容量
int OutPatientInfo::getCapacity()
{
    return m_nCapacity;
}

//获取日期字符串
QString OutPatientInfo::getStrDate()
{
    return m_Date.toString("yyyy/MM/dd");
}

//检查门诊是否可以预约
bool OutPatientInfo::ifAvailable()
{
    //检查容量是否允许
    bool ifCapacityIsAllowed = this->Appoint.size() < m_nCapacity;
    //检查时间是否允许
    //获取当前时间
    QDateTime curDateTime = QDateTime::currentDateTime();
    QDate curDate = curDateTime.date();
    QTime curTime = curDateTime.time();

    bool ifTimeIsAllowed = false;
    //若门诊日期在今天后
    if (curDate < m_Date)
        ifTimeIsAllowed = true;
    //若门诊时间为今天，进一步判断时间是否允许
    else if (curDate == m_Date)
    {
        if (curTime < m_TimeDuration.getEndTime())
            ifTimeIsAllowed = true;
    }
    bool result = ifCapacityIsAllowed && ifTimeIsAllowed;
    return result;
}

bool OutPatientInfo::ifBusy()
{
    //检查是否门诊是否正在进行
    //获取当前时间
    QDateTime curDateTime = QDateTime::currentDateTime();
    QDate curDate = curDateTime.date();
    QTime curTime = curDateTime.time();

    //是否是今天
    bool ifDateIsToday = curDate == m_Date;
    //是否正处于门诊时段中
    bool ifIsGoingNow =  (curTime >= m_TimeDuration.getBeginTime()) && (curTime <= m_TimeDuration.getEndTime());
    bool result = ifDateIsToday && ifIsGoingNow;
    return result;
}

//追加预约信息
void OutPatientInfo::addNewAppoint(const QString &name, const QString &gender, int age, const QDate &date,
                               const TimeDuration &time, const QString &phoneNum)
{
    AppointInfo t_appointInfo;
    t_appointInfo.setProperties(name,gender,age,date,time,phoneNum);

    Appoint.append(t_appointInfo);
}



