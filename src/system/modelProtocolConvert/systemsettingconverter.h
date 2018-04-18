#ifndef SYSTEMSETTINGCONVERTER_H
#define SYSTEMSETTINGCONVERTER_H
#include "../dataModel/setting/systemsettingdatamodel.h"

class SystemSettingConverter
{
public:
    SystemSettingConverter();
    static void parseDateTime(QString dtStr, SystemSettingDataModel* pModel);
    static QString genFormatableDateTime(SystemSettingDataModel* pModel);

};

#endif // SYSTEMSETTINGCONVERTER_H
