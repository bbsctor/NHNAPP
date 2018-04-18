#include "systemsettingconverter.h"

SystemSettingConverter::SystemSettingConverter()
{

}

void SystemSettingConverter::parseDateTime(QString dtStr, SystemSettingDataModel *pModel)
{
    QString year = "20" + dtStr.mid(0, 2);
    QString month = dtStr.mid(4, 2);
    QString day = dtStr.mid(8, 2);
    QString hour = dtStr.mid(12, 2);
    QString minute = dtStr.mid(16, 2);
    QString second = dtStr.mid(20, 2);

    QString date = year + "-" + month + "-" + day;
    QString time = hour + ":" + minute + ":" + second;
    pModel->setSystemDate(date);
    pModel->setSystemTime(time);
}

QString SystemSettingConverter::genFormatableDateTime(SystemSettingDataModel *pModel)
{
    QString result = pModel->systemDate().mid(2, 2);
    result.append(pModel->systemDate().mid(5, 2));
    result.append(pModel->systemDate().mid(8, 2));
    result.append(pModel->systemTime().mid(0, 2));
    result.append(pModel->systemTime().mid(3, 2));
    result.append(pModel->systemTime().mid(6, 2));

    return result;
}
