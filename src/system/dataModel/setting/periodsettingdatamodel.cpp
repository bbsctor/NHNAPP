#include "periodsettingdatamodel.h"

PeriodSettingDataModel::PeriodSettingDataModel(QObject *parent):DataModel(parent)
{

}

QString PeriodSettingDataModel::calibrationPeriod() const
{
    return m_calibrationPeriod;
}

void PeriodSettingDataModel::setCalibrationPeriod(const QString &calibrationPeriod)
{
    m_calibrationPeriod = calibrationPeriod;
}

QString PeriodSettingDataModel::washingPeriod() const
{
    return m_washingPeriod;
}

void PeriodSettingDataModel::setWashingPeriod(const QString &washingPeriod)
{
    m_washingPeriod = washingPeriod;
}

int PeriodSettingDataModel::meansureMode()
{
    return m_meansureMode;
}

void PeriodSettingDataModel::setMeansureMode(int meansureMode)
{
    m_meansureMode = meansureMode;
}
