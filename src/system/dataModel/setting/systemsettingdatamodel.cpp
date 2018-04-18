#include "systemsettingdatamodel.h"

SystemSettingDataModel::SystemSettingDataModel(QObject *parent):DataModel(parent)
{

}

QString SystemSettingDataModel::systemDate() const
{
    return m_systemDate;
}

void SystemSettingDataModel::setSystemDate(const QString &systemDate)
{
    m_systemDate = systemDate;
}

QString SystemSettingDataModel::systemTime() const
{
    return m_systemTime;
}

void SystemSettingDataModel::setSystemTime(const QString &systemTime)
{
    m_systemTime = systemTime;
}
