#ifndef RUNNINGINFODATAMODEL_H
#define RUNNINGINFODATAMODEL_H
#include "../../../framework/datamodel.h"

class RunningInfoDataModel : public DataModel
{
public:
    RunningInfoDataModel(QObject *parent = 0);
    QString currentAction() const;
    void setCurrentAction(const QString &currentAction);

    QString nextAction() const;
    void setNextAction(const QString &nextAction);

    QString dispelTemperature() const;
    void setDispelTemperature(const QString &dispelTemperature);

    QString environmentTemperature() const;
    void setEnvironmentTemperature(const QString &environmentTemperature);

    QString absorbance() const;
    void setAbsorbance(const QString &absorbance);

    int progress() const;
    void setProgress(int progress);

    QString currentStatus() const;
    void setCurrentStatus(const QString &currentStatus);

    QString coolerTempearture() const;
    void setCoolerTempearture(const QString &coolerTempearture);

    QString switchValvoStatus() const;
    void setSwitchValvoStatus(const QString &switchValvoStatus);

    QString injectBumbStatus() const;
    void setInjectBumbStatus(const QString &injectBumbStatus);

private:
    QString m_currentStatus;
    QString m_currentAction;
    QString m_nextAction;
    QString m_dispelTemperature;
    QString m_environmentTemperature;

    QString m_injectBumbStatus;
    QString m_switchValvoStatus;
    QString m_coolerTempearture;

    QString m_absorbance;
    int m_progress;
};

#endif // RUNNINGINFODATAMODEL_H
