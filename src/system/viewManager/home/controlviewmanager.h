#ifndef CONTROLVIEWMANAGER_H
#define CONTROLVIEWMANAGER_H
#include <QDebug>
#include "../../context/pollproxy.h"
#include "../../../framework/viewManager/viewmanager.h"
#include "../../controller/home/homecontroller.h"

class HomeControlViewManager : public ViewManager
{
    Q_OBJECT

public:
    HomeControlViewManager();
    Q_INVOKABLE void startMonitor();
    Q_INVOKABLE void stopMonitor();
    Q_INVOKABLE void urgencyStop();
public slots:
    void updateLoop();
private:
    //PollProxy* pollProxy;
    void init();
    HomeController* m_controllerPtr;
    QTimer* timer;
};

#endif // CONTROLVIEWMANAGER_H
