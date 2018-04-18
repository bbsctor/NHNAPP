#ifndef SETTINGDEFAULTINFORMATIONCONVERTER_H
#define SETTINGDEFAULTINFORMATIONCONVERTER_H
#include "../dataModel/setting/settingdefaultinformationdatamodel.h"
#include"../protocol/stprotocol2.h"

class SettingDefaultInformationConverter
{
public:
    SettingDefaultInformationConverter();
   static void parseSystermDefaultSettingInfo(QByteArray byteArray, SettingDefaultInformationDataModel* pModel);
   static void parseParameterDefaultSettingInfo(QByteArray byteArray,SettingDefaultInformationDataModel* pModel);
   static void parsePeriodDefaultSettingInfo(QByteArray byteArray,SettingDefaultInformationDataModel* pModel);
   static void parseCalibrationDefaultSettingInfo(QByteArray byteArray, SettingDefaultInformationDataModel *pModel);
   static ushort bytesToUshort(QByteArray bytes) ;
};

#endif // SETTINGDEFAULTINFORMATIONCONVERTER_H
