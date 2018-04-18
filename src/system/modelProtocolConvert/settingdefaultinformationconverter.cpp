#include "settingdefaultinformationconverter.h"
#include "../dataModel/setting/settingdefaultinformationdatamodel.h"
#include "../protocol/stprotocol2.h"
#include <QDebug>

SettingDefaultInformationConverter::SettingDefaultInformationConverter()
{

}
ushort SettingDefaultInformationConverter::bytesToUshort(QByteArray bytes) {
    ushort addr = bytes[1] & 0x000000FF;
    addr |= ((bytes[0] << 8) & 0x0000FF00);
    return addr;
}
void SettingDefaultInformationConverter::parseSystermDefaultSettingInfo(QByteArray byteArray, SettingDefaultInformationDataModel *pModel)
{
     QByteArray alertUpperArray;
     alertUpperArray.resize(2);
     alertUpperArray[0]=byteArray[4];
     alertUpperArray[1]=byteArray[5];
     ushort alertUpper=bytesToUshort(alertUpperArray);

      qWarning() << "alert upper" <<alertUpper;

     alertUpperArray[0]=byteArray[6];
     alertUpperArray[1]=byteArray[7];
    ushort alertLower=bytesToUshort(alertUpperArray);
    qWarning() << "alert lower" <<alertLower;
    pModel->set4to20mAStatus(byteArray[2]);
    pModel->setRS485Status(byteArray[3]);
    pModel->setAlertUpper(alertUpper);
    pModel->setAlertLower(alertLower);
    pModel->setSlaveAddress(byteArray[8]);
}
void SettingDefaultInformationConverter::parseParameterDefaultSettingInfo(QByteArray byteArray, SettingDefaultInformationDataModel *pModel)
{
    QByteArray tempArray;
    tempArray.resize(2);
    tempArray[0]=byteArray[2];
    tempArray[1]=byteArray[3];
    pModel->setDispelTime( tempArray[0]);
    qWarning() << "dispel time" <<(uint)tempArray[0];
    pModel->setPumpStartTime(tempArray[1]);
    qWarning() << "pump time" <<(uint)tempArray[1];

}
void SettingDefaultInformationConverter::parsePeriodDefaultSettingInfo(QByteArray byteArray, SettingDefaultInformationDataModel *pModel)
{
    QByteArray tempArray;
    tempArray.resize(3);
    tempArray[0]=byteArray[2];
    tempArray[1]=byteArray[3];
    tempArray[2]=byteArray[4];
    pModel->setMeasureMode(tempArray[0]);
    pModel->setAutoCalibrationPeriod( tempArray[1]);
    pModel->setAutoMeasurePeriod( tempArray[2]);

}

void SettingDefaultInformationConverter::parseCalibrationDefaultSettingInfo(QByteArray byteArray, SettingDefaultInformationDataModel *pModel)
{

    pModel->setCurrentSelectCurve(byteArray[2]);

}
