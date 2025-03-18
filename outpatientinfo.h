#ifndef OUTPATIENTINFO_H
#define OUTPATIENTINFO_H

#include "appointinfo.h"
#include "timeduration.h"

#include <QVector>

class OutPatientInfo
{
public:
    OutPatientInfo();

    //*Access Function*//
    //设置门诊各项属性
    void setProperties(const QString& number,const QString& name,const QString& ID,const QString& address,
                       const QString& phoneNum,const QDate& date,const TimeDuration& duration,int capacity);

    QStringList getProperties(); //获取门诊各项属性
    int getCapacity(); //获取门诊容量
    QString getStrDate(); //获取日期字符串

    bool ifAvailable(); //检查门诊是否可预约
    bool ifBusy(); //检查门诊是否正在进行

    //追加预约信息
    void addNewAppoint(const QString& name,const QString& gender,int age,const QDate& date,
                       const TimeDuration& time,const QString& phoneNum);

    QVector <AppointInfo> Appoint; //相应门诊的预约信息
private:
    QString m_strNumber; //门诊号
    QString m_strName; //门诊名称
    QString m_strID; //值班医生工号
    QString m_strAddress; //门诊地址
    QString m_strPhoneNumber; //联系电话
    QDate m_Date; //接诊日期
    TimeDuration m_TimeDuration; //接诊时间
    int m_nCapacity; //容量
};

#endif // OUTPATIENTINFO_H
