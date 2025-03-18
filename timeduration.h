#ifndef TIMEDURATION_H
#define TIMEDURATION_H

#include <QTime>

class TimeDuration
{
public:
    //运算符重载
    bool operator==(const TimeDuration& duration);

    TimeDuration();
    //重载构造函数
    TimeDuration(const QString& begin,const QString& end);

    //*Access Function*//
    QTime getBeginTime() const; //获取开始时间
    void setBeginTime(const QTime &newBeginTime); //设置开始时间

    QTime getEndTime() const; //获取结束时间
    void setEndTime(const QTime &newEndTime); //设置结束时间

    //*与字符串的相互转换*//
    QString tranToString(); //将时段转化为字符串
    static TimeDuration tranFromString(const QString& duration); //将字符串转化为时段

private:
    QTime m_BeginTime; //接诊开始时间
    QTime m_EndTime; //接诊结束时间



};

#endif // TIMEDURATION_H
