#ifndef WARNINGDATAMODEL_H
#define WARNINGDATAMODEL_H
#include "../../../framework/datamodel.h"
class WarningDataModel : public DataModel
{
public:
    WarningDataModel(QObject *parent = 0);
    QString warningInfo() const;
    void setWarningInfo(const QString &warningInfo);

//    QString colorTempeartureWarning() const;
//    void setColorTempeartureWarning(const QString &colorTempeartureWarning);

//    QString fridgeTemperatureWarning() const;
//    void setFridgeTemperatureWarning(const QString &fridgeTemperatureWarning);

//    QString switchValvoStatusWarning() const;
//    void setSwitchValvoStatusWarning(const QString &switchValvoStatusWarning);

//    QString injectBumbStatusWarning() const;
//    void setInjectBumbStatusWarning(const QString &injectBumbStatusWarning);

private:
    QString m_warningInfo;
//    QString m_noWarning;                               //0
//    QString m_colorTemperatureWarning;       //1
//    QString m_fridgeTemperatureWarning;       //2
//    QString m_injectBumbStatusWarning;        //3
//    QString m_switchValvoStatusWarning;       //4




};
#endif // WARNINGDATAMODEL_H
