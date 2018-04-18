#ifndef BCLJZJSETTINGDATAMODELONE_H
#define BCLJZJSETTINGDATAMODELONE_H
#include "../../../framework/datamodel.h"

class BCLJZJSettingDataModelOne : public DataModel
{
public:
    BCLJZJSettingDataModelOne();
    char megLockAble() const;
    void setMegLockAble(char megLockAble);

    char washingAble() const;
    void setWashingAble(char washingAble);

    char bumbOnTime() const;
    void setBumbOnTime(char bumbOnTime);

    char preHandlerAble() const;
    void setPreHandlerAble(char preHandlerAble);

    ushort dilute() const;
    void setDilute(const ushort &dilute);

    char dispelTime() const;
    void setDispelTime(char dispelTime);

    int calibrationCurveNumber() const;
    void setCalibrationCurveNumber(const int calibrationCurveNumber);



public:
    char m_megLockAble;
    char m_washingAble;
    char m_bumbOnTime;
    char m_preHandlerAble;
    ushort m_dilute;
    char m_dispelTime;
    int m_calibrationCurveNumber;

};

#endif // BCLJZJSETTINGDATAMODELONE_H
