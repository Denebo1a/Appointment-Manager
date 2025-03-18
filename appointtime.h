#ifndef APPOINTTIME_H
#define APPOINTTIME_H

#include <QDate>

class AppointTime
{
public:
    AppointTime();

private:
    QDate m_dDate;
    QString m_strDuration;
};

#endif // APPOINTTIME_H
