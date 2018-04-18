#ifndef SYSTEMMAINTAINVIEWMANAGER_H
#define SYSTEMMAINTAINVIEWMANAGER_H
#include "../../../framework/viewManager/viewmanager.h"
#include "../../controller/maintain/systemmaintaincontroller.h"

class SystemMaintainViewManager : public ViewManager
{
    Q_OBJECT
public:
    SystemMaintainViewManager();
    Q_INVOKABLE void meansure();
    Q_INVOKABLE void calibration();
    Q_INVOKABLE void initial();
    Q_INVOKABLE void cleanBubble();
    Q_INVOKABLE void washCuvette();
    Q_INVOKABLE void reagentWashCuvette();
    Q_INVOKABLE void finishDispose();
    Q_INVOKABLE void zeroMeansure();
    Q_INVOKABLE void urgencyStop();
    Q_INVOKABLE void searchStatus();
    Q_INVOKABLE void zeroCalibration();
    Q_INVOKABLE void spanCalibration();

private:
    void init();
    SystemMaintainController* m_controllerPtr;
};

#endif // SYSTEMMAINTAINVIEWMANAGER_H
