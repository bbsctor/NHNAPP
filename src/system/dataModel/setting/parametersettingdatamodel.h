#ifndef PARAMETERSETTINGDATAMODEL_H
#define PARAMETERSETTINGDATAMODEL_H
#include "../../../framework/datamodel.h"
#include "../../dataModel/setting/settingdefaultinformationdatamodel.h"

class ParameterSettingDataModel : public DataModel
{
public:
    ParameterSettingDataModel(QObject *parent = 0);

    QString sampleConcentration() const;
    void setSampleConcentration(const QString &sampleConcentration);

    //bcl移植
    char megLockAble() const;
    void setMegLockAble(char megLockAble);

    char washingAble() const;
    void setWashingAble(char washingAble);

    char preHandlerAble() const;
    void setPreHandlerAble(char preHandlerAble);

    char bumbOnTime() const;
    void setBumbOnTime(char bumbOnTime);

    char dispelTime() const;
    void setDispelTime(char dispelTime);

    char m_megLockAble;
    char m_washingAble;

    char m_preHandlerAble;
    char m_bumbOnTime;
    char m_dispelTime;

private:
    QString m_sampleConcentration;

};

#endif // PARAMETERSETTINGDATAMODEL_H
