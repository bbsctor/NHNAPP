#ifndef PERIODSETTINGVIEWMANAGER_H
#define PERIODSETTINGVIEWMANAGER_H
#include "../../dataModel/setting/periodsettingdatamodel.h"
#include "../../../framework/viewManager/viewmanager.h"
#include "../../controller/setting/periodsettingcontroller.h"
#include "../../../framework/observe/qobserver.h"
#include  "../../controller/meansure/meansurecontroller.h"
#include"../../controller/maintain/systemmaintaincontroller.h"
#include <QTimer>
#include "../../dataModel/setting/settingdefaultinformationdatamodel.h"

class PeriodSettingViewManager : public ViewManager,QObserver
{
    Q_OBJECT
    Q_PROPERTY(uchar calibrationPeriod READ calibrationPeriod WRITE setCalibrationPeriod NOTIFY calibrationPeriodChanged)
    Q_PROPERTY(int meansureMode READ meansureMode WRITE setMeansureMode NOTIFY meansureModeChanged)
    Q_PROPERTY(uchar AutoMeasureTime READ AutoMeasureTime WRITE setAutoMeasureTime NOTIFY autoMeasureTimeChanged)
public:
    PeriodSettingViewManager();
    Q_INVOKABLE void loadDefault();
    Q_INVOKABLE void pushCalibrationPeriod();
    Q_INVOKABLE void pullCalibrationPeriod();
    Q_INVOKABLE void initDefaultValue();
    Q_INVOKABLE void pushMeansureMode();
    Q_INVOKABLE void pushMeasureInterval();
    void Update(QObservable *pObs, void *pArg = NULL);
    void innerMeansure();
    void innerCalibration();
    int meansureMode() const
    {
        return m_meansureMode;
    }
    void measureModeAuto();
    void measureModeOnTime();
    void measureModeMannual();

    Q_INVOKABLE  void jugeMeasureMode(int modeIndex);
    void updateDefaultView(SettingDefaultInformationDataModel *pModel);
    uchar AutoMeasureTime() const
    {
        return m_AutoMeasureTime;
    }

    uchar calibrationPeriod() const
    {
        return m_calibrationPeriod;
    }

public slots:
    void setMeansureMode(int meansureMode);
    void setAutoMeasureTime(uchar AutoMeasureTime);
    void setCalibrationPeriod(uchar calibrationPeriod);

signals:
    void meansureModeChanged(int meansureMode);
    void autoMeasureTimeChanged(uchar AutoMeasureTime);
    void calibrationPeriodChanged(uchar calibrationPeriod);

private:
    void init();
    PeriodSettingDataModel* m_modelPtr;
    PeriodSettingController* m_controllerPtr;
    MeansureController* m_controllerMeasurePtr;
    SystemMaintainController* m_controllerSystemMaintain;

    int m_meansureMode;
    uchar m_AutoMeasureTime;

    uchar m_calibrationPeriod;
};

#endif // PERIODSETTINGVIEWMANAGER_H
