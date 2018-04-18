#ifndef PERIODSETTINGDATAMODEL_H
#define PERIODSETTINGDATAMODEL_H
#include "../../../framework/datamodel.h"

class PeriodSettingDataModel : public DataModel
{
public:
    PeriodSettingDataModel(QObject *parent = 0);
    QString calibrationPeriod() const;
    void setCalibrationPeriod(const QString &calibrationPeriod);

    QString washingPeriod() const;
    void setWashingPeriod(const QString &washingPeriod);


    int meansureMode();
    void setMeansureMode(int meansureMode);
    int m_meansureMode;
private:
    QString m_calibrationPeriod;
    QString m_washingPeriod;


};

#endif // PERIODSETTINGDATAMODEL_H
