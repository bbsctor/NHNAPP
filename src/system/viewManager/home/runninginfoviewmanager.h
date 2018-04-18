#ifndef RUNNINGINFOVIEWMANAGER_H
#define RUNNINGINFOVIEWMANAGER_H
#include "../../dataModel/home/runninginfodatamodel.h"
#include "../../../framework/viewManager/viewmanager.h"
#include "../../controller/home/runninginfocontroller.h"
#include "../../../framework/observe/qobserver.h"
#include "../../context/pollproxy.h"

class RunningInfoViewManager : public ViewManager,public QObserver
{
    Q_OBJECT
    Q_PROPERTY(QString currentStatus READ currentStatus WRITE setCurrentStatus NOTIFY currentStatusChanged)
    Q_PROPERTY(QString currentAction READ currentAction WRITE setCurrentAction NOTIFY currentActionChanged)
    Q_PROPERTY(QString nextAction READ nextAction WRITE setNextAction NOTIFY nextActionChanged)
    Q_PROPERTY(QString dispelTemperature READ dispelTemperature WRITE setDispelTemperature NOTIFY dispelTemperatureChanged)
    Q_PROPERTY(QString environmentTemperature READ environmentTemperature WRITE setEnvironmentTemperature NOTIFY environmentTemperatureChanged)
    Q_PROPERTY(QString absorbance READ absorbance WRITE setAbsorbance NOTIFY absorbanceChanged)
    Q_PROPERTY(int progress READ progress WRITE setProgress NOTIFY progressChanged)

    Q_PROPERTY(QString injectBumbStatus READ injectBumbStatus WRITE setInjectBumbStatus NOTIFY injectBumbStatusChanged)
    Q_PROPERTY(QString switchValvoStatus READ switchValvoStatus WRITE setSwitchValvoStatus NOTIFY switchValvoStatusChanged)
    Q_PROPERTY(QString coolerTempearture READ coolerTempearture WRITE setCoolerTempearture NOTIFY coolerTempeartureChanged)

public:
    RunningInfoViewManager();
    Q_INVOKABLE void pullRunningInfo();
    void Update(QObservable *pObs, void *pArg = NULL);


    QString currentStatus() const
    {
        return m_currentStatus;
    }

    QString currentAction() const
    {
        return m_currentAction;
    }

    QString nextAction() const
    {
        return m_nextAction;
    }

    QString dispelTemperature() const
    {
        return m_dispelTemperature;
    }

    QString environmentTemperature() const
    {
        return m_environmentTemperature;
    }

    QString absorbance() const
    {
        return m_absorbance;
    }

    int progress() const
    {
        return m_progress;
    }

    QString injectBumbStatus() const
    {
        return m_injectBumbStatus;
    }

    QString switchValvoStatus() const
    {
        return m_switchValvoStatus;
    }

    QString coolerTempearture() const
    {
        return m_coolerTempearture;
    }

public slots:

    void setCurrentStatus(QString currentStatus)
    {
        if (m_currentStatus == currentStatus)
            return;

        m_currentStatus = currentStatus;
        emit currentStatusChanged(currentStatus);
    }

    void setCurrentAction(QString currentAction)
    {
        if (m_currentAction == currentAction)
            return;

        m_currentAction = currentAction;
        emit currentActionChanged(currentAction);
    }

    void setNextAction(QString nextAction)
    {
        if (m_nextAction == nextAction)
            return;

        m_nextAction = nextAction;
        emit nextActionChanged(nextAction);
    }

    void setDispelTemperature(QString dispelTemperature)
    {
        if (m_dispelTemperature == dispelTemperature)
            return;

        m_dispelTemperature = dispelTemperature;
        emit dispelTemperatureChanged(dispelTemperature);
    }

    void setEnvironmentTemperature(QString environmentTemperature)
    {
        if (m_environmentTemperature == environmentTemperature)
            return;

        m_environmentTemperature = environmentTemperature;
        emit environmentTemperatureChanged(environmentTemperature);
    }

    void setAbsorbance(QString absorbance)
    {
        if (m_absorbance == absorbance)
            return;

        m_absorbance = absorbance;
        emit absorbanceChanged(absorbance);
    }

    void setProgress(int progress)
    {
        if (m_progress == progress)
            return;

        m_progress = progress;
        emit progressChanged(progress);
    }

    void setInjectBumbStatus(QString injectBumbStatus)
    {
        if (m_injectBumbStatus == injectBumbStatus)
            return;

        m_injectBumbStatus = injectBumbStatus;
        emit injectBumbStatusChanged(injectBumbStatus);
    }

    void setSwitchValvoStatus(QString switchValvoStatus)
    {
        if (m_switchValvoStatus == switchValvoStatus)
            return;

        m_switchValvoStatus = switchValvoStatus;
        emit switchValvoStatusChanged(switchValvoStatus);
    }

    void setCoolerTempearture(QString coolerTempearture)
    {
        if (m_coolerTempearture == coolerTempearture)
            return;

        m_coolerTempearture = coolerTempearture;
        emit coolerTempeartureChanged(coolerTempearture);
    }

signals:

    void currentStatusChanged(QString currentStatus);

    void currentActionChanged(QString currentAction);

    void nextActionChanged(QString nextAction);

    void dispelTemperatureChanged(QString dispelTemperature);

    void environmentTemperatureChanged(QString environmentTemperature);

    void absorbanceChanged(QString absorbance);

    void progressChanged(int progress);

    void injectBumbStatusChanged(QString injectBumbStatus);

    void switchValvoStatusChanged(QString switchValvoStatus);

    void coolerTempeartureChanged(QString coolerTempearture);

private:
    void init();
    void updateViewRunningInfo(RunningInfoDataModel* pModel);
    RunningInfoDataModel* m_modelPtr;
    RunningInfoController* m_controllerPtr;
    QString m_currentStatus;
    QString m_currentAction;
    QString m_nextAction;
    QString m_dispelTemperature;
    QString m_environmentTemperature;
    QString m_absorbance;
    int m_progress;

    QString m_injectBumbStatus;
    QString m_switchValvoStatus;
    QString m_coolerTempearture;

    //PollProxy pollProxy;
    static int isNewData;
};

#endif // RUNNINGINFOVIEWMANAGER_H
