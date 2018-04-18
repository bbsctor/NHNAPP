#ifndef SETTINGDEFAULTINFORMATIONDATAMODEL_H
#define SETTINGDEFAULTINFORMATIONDATAMODEL_H
#include "../../../framework/datamodel.h"


class SettingDefaultInformationDataModel: public DataModel
{
public:
    SettingDefaultInformationDataModel();

//    char alertUpper() const;

//    void setAlertUpper(char alertUpper);

//    char alertLower() const;

//    void setAlertLower(char alertLower);

    char _4to20mAStatus() const;

    void set4to20mAStatus(char _4to20mAStatus);

    char RS485Status() const;

    void setRS485Status(char RS485Status);

    char autoMeasurePeriod() const;

    void setAutoMeasurePeriod(char autoMeasurePeriod);

    char autoCalibrationPeriod() const;

    void setAutoCalibrationPeriod(char autoCalibrationPeriod);

    char measureMode() const;

    void setMeasureMode(char measureMode);

    char pumpStartTime() const;

    char dispelTime() const;

    void setDispelTime(char dispelTime);

    void setPumpStartTime(char pumpStartTime);

    ushort alertUpper() const;
    void setAlertUpper(const ushort &alertUpper);

    ushort alertLower() const;
    void setAlertLower(const ushort &alertLower);

    char currentSelectCurve() const;
    void setCurrentSelectCurve(char currentSelectCurve);



    char slaveAddress() const;
    void setSlaveAddress(char slaveAddress);

private:
    char m_4to20mAStatus;
    char m_RS485Status;
    //    char m_alertUpper;
//    char m_alertLower;
    ushort m_alertUpper;
    ushort m_alertLower;

    char m_slaveAddress;

    char m_dispelTime;
    char m_pumpStartTime;

    char m_measureMode;
    char m_autoCalibrationPeriod;
    char m_autoMeasurePeriod;

    char m_currentSelectCurve;
};

#endif // SETTINGDEFAULTINFORMATIONDATAMODEL_H
