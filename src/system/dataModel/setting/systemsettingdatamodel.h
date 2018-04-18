#ifndef SYSTEMSETTINGDATAMODEL_H
#define SYSTEMSETTINGDATAMODEL_H
#include "../../../framework/datamodel.h"

class SystemSettingDataModel : public DataModel
{
public:
    SystemSettingDataModel(QObject *parent = 0);
    QString systemDate() const;
    void setSystemDate(const QString &systemDate);

    QString systemTime() const;
    void setSystemTime(const QString &systemTime);

private:
    QString m_systemDate;
    QString m_systemTime;
};

#endif // SYSTEMSETTINGDATAMODEL_H
