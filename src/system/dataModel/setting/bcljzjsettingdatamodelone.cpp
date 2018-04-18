#include "bcljzjsettingdatamodelone.h"

BCLJZJSettingDataModelOne::BCLJZJSettingDataModelOne()
{

}

char BCLJZJSettingDataModelOne::megLockAble() const
{
    return m_megLockAble;
}

void BCLJZJSettingDataModelOne::setMegLockAble(char megLockAble)
{
    m_megLockAble = megLockAble;
}

char BCLJZJSettingDataModelOne::washingAble() const
{
    return m_washingAble;
}

void BCLJZJSettingDataModelOne::setWashingAble(char washingAble)
{
    m_washingAble = washingAble;
}

char BCLJZJSettingDataModelOne::bumbOnTime() const
{
    return m_bumbOnTime;
}

void BCLJZJSettingDataModelOne::setBumbOnTime(char bumbOnTime)
{
    m_bumbOnTime = bumbOnTime;
}

char BCLJZJSettingDataModelOne::preHandlerAble() const
{
    return m_preHandlerAble;
}

void BCLJZJSettingDataModelOne::setPreHandlerAble(char preHandlerAble)
{
    m_preHandlerAble = preHandlerAble;
}

ushort BCLJZJSettingDataModelOne::dilute() const
{
    return m_dilute;
}

void BCLJZJSettingDataModelOne::setDilute(const ushort &delute)
{
    m_dilute = delute;
}

char BCLJZJSettingDataModelOne::dispelTime() const
{
    return m_dispelTime;
}
void BCLJZJSettingDataModelOne::setDispelTime(char dispelTime)
{
    m_dispelTime = dispelTime;
}

int BCLJZJSettingDataModelOne::calibrationCurveNumber() const
{
    return m_calibrationCurveNumber;
}
void BCLJZJSettingDataModelOne::setCalibrationCurveNumber(int calibrationCurveNumber)
{
    m_calibrationCurveNumber=calibrationCurveNumber;
}
