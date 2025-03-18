#ifndef APPOINTINFO_H
#define APPOINTINFO_H

#include <QDate>
#include "timeduration.h"

class AppointInfo
{
public:
    AppointInfo();
    //*Access Function*//
    //设置预约各项属性
    void setProperties(const QString& name,const QString& gender,int age,const QDate& date,
                       const TimeDuration& time,const QString& phoneNum);
    //设置预约各项属性（弹窗修改时的重载版本）
    void setProperties(const QString& name,const QString& gender,int age,const QString& phoneNum);

    void setDateAndTime(const QDate& date,const TimeDuration& time); //设置时间属性
    QStringList getDateAndTime(); //获取时间属性（字符串版本）

    //获取预约各项属性（除时间之外）
    QStringList getProperties();

private:
    QString m_strName; //预约患者姓名
    QString m_strGender; //预约患者性别
    int m_nAge; //预约患者年龄
    QDate m_Date; //预约日期
    TimeDuration m_Time; //预约时间
    QString m_strPhoneNum; //预约患者电话号码
};

#endif // APPOINTINFO_H
