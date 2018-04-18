#include "warningdatamodel.h"

 WarningDataModel::WarningDataModel(QObject *parent):DataModel(parent)
{

}

QString WarningDataModel::warningInfo() const
{
    return m_warningInfo;
}

void WarningDataModel::setWarningInfo(const QString &warningInfo)
{
    m_warningInfo=warningInfo;
}

//QString WarningDataModel::colorTempeartureWarning() const
//{
//    return m_colorTemperatureWarning;
//}

//void WarningDataModel::setColorTempeartureWarning(const QString &colorTemperatureWarning)
//{
//    m_colorTemperatureWarning=colorTemperatureWarning;
//}

//QString WarningDataModel::fridgeTemperatureWarning() const
//{
//    return m_fridgeTemperatureWarning;
//}

//void WarningDataModel::setFridgeTemperatureWarning(const QString &fridgeTemperatureWarning)
//{
//    m_fridgeTemperatureWarning=fridgeTemperatureWarning;
//}

//QString WarningDataModel::injectBumbStatusWarning() const
//{
//    return m_injectBumbStatusWarning;
//}

//void WarningDataModel::setInjectBumbStatusWarning(const QString &injectBumbStatusWarning)
//{
//    m_injectBumbStatusWarning=injectBumbStatusWarning;
//}

//QString WarningDataModel::switchValvoStatusWarning() const
//{
//    return m_switchValvoStatusWarning;
//}

//void WarningDataModel:: setSwitchValvoStatusWarning(const QString &switchValvoStatusWarning)
//{
//    m_switchValvoStatusWarning=switchValvoStatusWarning;
//}




