#include "appointinfo.h"

AppointInfo::AppointInfo() {}

/********************
* Access Function
********************/

//设置预约各项属性
void AppointInfo::setProperties(const QString &name, const QString &gender, int age, const QDate& date, const TimeDuration& time, const QString &phoneNum)
{
    m_strName = name;
    m_strGender = gender;
    m_nAge = age;
    m_Date = date;
    m_Time = time;
    m_strPhoneNum = phoneNum;
}

//设置预约各项属性（弹窗修改时的重载版本）
void AppointInfo::setProperties(const QString &name, const QString &gender, int age, const QString &phoneNum)
{
    m_strName = name;
    m_strGender = gender;
    m_nAge = age;
    m_strPhoneNum = phoneNum;
}

//获取预约各项属性（除时间之外）
QStringList AppointInfo::getProperties()
{
    QStringList propertiesList; //属性列表
    QString age = QString::number(m_nAge); //类型转换
    propertiesList << m_strName << m_strGender<< age << m_strPhoneNum;
    return propertiesList;
}

//设置时间
void AppointInfo::setDateAndTime(const QDate &date, const TimeDuration &time)
{
    m_Date = date;
    m_Time = time;
}

//获取时间（字符串版本）
QStringList AppointInfo::getDateAndTime()
{
    QStringList DateAndTime; //日期时间列表
    //类型转换
    QString strDate = m_Date.toString("yyyy/MM/dd");
    QString strTime = m_Time.tranToString();
    DateAndTime << strDate << strTime;
    return DateAndTime;
}
