#include "parametersettingdatamodel.h"

ParameterSettingDataModel::ParameterSettingDataModel(QObject *parent):DataModel(parent)
{

}

QString ParameterSettingDataModel::sampleConcentration() const
{
    return m_sampleConcentration;
}

void ParameterSettingDataModel::setSampleConcentration(const QString &sampleConcentration)
{
    m_sampleConcentration = sampleConcentration;
}


char ParameterSettingDataModel::megLockAble() const
{
    return m_megLockAble;
}

void ParameterSettingDataModel::setMegLockAble(char megLockAble)
{
    m_megLockAble = megLockAble;
}

char ParameterSettingDataModel::washingAble() const
{
    return m_washingAble;
}

void ParameterSettingDataModel::setWashingAble(char washingAble)
{
    m_washingAble = washingAble;
}

char  ParameterSettingDataModel::preHandlerAble() const
{
    return m_preHandlerAble;
}

void  ParameterSettingDataModel::setPreHandlerAble(char preHandlerAble)
{
    m_preHandlerAble = preHandlerAble;
}

char ParameterSettingDataModel::bumbOnTime() const
{
    return m_bumbOnTime;
}

void ParameterSettingDataModel::setBumbOnTime(char bumbOnTime)
{
    m_bumbOnTime = bumbOnTime;
}

char ParameterSettingDataModel::dispelTime() const
{
    return m_dispelTime;
}
void ParameterSettingDataModel::setDispelTime(char dispelTime)
{
    m_dispelTime = dispelTime;
}
