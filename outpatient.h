#ifndef OUTPATIENT_H
#define OUTPATIENT_H

#include <QString>
#include <QDateTime>


class OutPatient
{
public:
    OutPatient();

    QString strNumber() const;
    void setStrNumber(const QString &newStrNumber);

    QString strDepartment() const;
    void setStrDepartment(const QString &newStrDepartment);

    QString strAddress() const;
    void setStrAddress(const QString &newStrAddress);

private:
    QString m_strNumber;
    QString m_strDepartment;
    QString m_strAddress;
};

#endif // OUTPATIENT_H
