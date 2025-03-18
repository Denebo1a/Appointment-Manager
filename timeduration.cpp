#include "timeduration.h"

//重载相等运算符
bool TimeDuration::operator==(const TimeDuration &duration)
{
    bool result = ((this->m_BeginTime == duration.m_BeginTime) && (this->m_EndTime == duration.m_EndTime));
    return result;
}


TimeDuration::TimeDuration() {}

//重载构造函数
TimeDuration::TimeDuration(const QString &begin, const QString &end)
{
    m_BeginTime = QTime::fromString(begin,"hh:mm");
    m_EndTime = QTime::fromString(end,"hh:mm");

}

/********************
* 与字符串的相互转换
********************/

//将TimeDuration类对象转换为字符串
QString TimeDuration::tranToString()
{
    QString begin = m_BeginTime.toString("hh:mm");
    QString end = m_EndTime.toString("hh:mm");
    QString result = QString(begin + "-" + end);

    return result;
}

//将字符串转换为TimeDuration类对象
TimeDuration TimeDuration::tranFromString(const QString &duration)
{
    QStringList timePoints = duration.split('-');

    TimeDuration result(timePoints[0],timePoints[1]);

    return result;
}

/********************
* Access Function
********************/

//获取开始时间
QTime TimeDuration::getBeginTime() const
{
    return m_BeginTime;
}

//设置开始时间
void TimeDuration::setBeginTime(const QTime &newBeginTime)
{
    m_BeginTime = newBeginTime;
}

//获取结束时间
QTime TimeDuration::getEndTime() const
{
    return m_EndTime;
}

//设置结束时间
void TimeDuration::setEndTime(const QTime &newEndTime)
{
    m_EndTime = newEndTime;
}

