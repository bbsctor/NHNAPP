#ifndef EXECUTEVIEWMANAGER_H
#define EXECUTEVIEWMANAGER_H
#include "../../../framework/viewManager/viewmanager.h"
#include "../../controller/appcontroller.h"
//#include "../../../framework/observe/qobserver.h"

class ExecuteViewManager : public ViewManager// ,public QObserver
{
    Q_OBJECT
    Q_PROPERTY(QString executeStatus READ executeStatus WRITE setExecuteStatus NOTIFY executeStatusChanged)
    Q_PROPERTY(QString autoMeansure READ autoMeansure WRITE setAutoMeansure NOTIFY autoMeansureChanged)
    Q_PROPERTY(QString periodCalibration READ periodCalibration WRITE setPeriodCalibration NOTIFY periodCalibrationChanged)
public:
    ExecuteViewManager();
    QString executeStatus() const
    {
        return m_executeStatus;
    }

   // void Update(QObservable *pObs, void *pArg);


    QString autoMeansure() const
    {
        return m_autoMeansure;
    }

    QString periodCalibration() const
    {
        return m_periodCalibration;
    }

public slots:
    void setExecuteStatus(QString executeStatus)
    {
        if (m_executeStatus == executeStatus)
            return;

        m_executeStatus = executeStatus;
        emit executeStatusChanged(executeStatus);
    }

    void setAutoMeansure(QString autoMeansure)
    {
        if (m_autoMeansure == autoMeansure)
            return;

        m_autoMeansure = autoMeansure;
        emit autoMeansureChanged(autoMeansure);
    }

    void setPeriodCalibration(QString periodCalibration)
    {
        if (m_periodCalibration == periodCalibration)
            return;

        m_periodCalibration = periodCalibration;
        emit periodCalibrationChanged(periodCalibration);
    }

signals:
    void executeStatusChanged(QString executeStatus);

    void autoMeansureChanged(QString autoMeansure);

    void periodCalibrationChanged(QString periodCalibration);

private:
    void init();
    QString m_executeStatus;
    QString m_autoMeansure;
    QString m_periodCalibration;
};

#endif // EXECUTEVIEWMANAGER_H
