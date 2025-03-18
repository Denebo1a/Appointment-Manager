#include "outpatient.h"

OutPatient::OutPatient() {}

QString OutPatient::strNumber() const
{
    return m_strNumber;
}

void OutPatient::setStrNumber(const QString &newStrNumber)
{
    m_strNumber = newStrNumber;
}

QString OutPatient::strDepartment() const
{
    return m_strDepartment;
}

void OutPatient::setStrDepartment(const QString &newStrDepartment)
{
    m_strDepartment = newStrDepartment;
}

QString OutPatient::strAddress() const
{
    return m_strAddress;
}

void OutPatient::setStrAddress(const QString &newStrAddress)
{
    m_strAddress = newStrAddress;
}

