#ifndef MEANSUREVIEWMANAGER_H
#define MEANSUREVIEWMANAGER_H
#include "../../dataModel/meansurecontroldatamodel.h"
#include "../../../framework/viewManager/viewmanager.h"
#include "../../controller/meansure/meansurecontroller.h"

class MeansureViewManager : public ViewManager
{
    Q_OBJECT
public:
    MeansureViewManager(QObject *parent = 0);
    Q_INVOKABLE void startOnlineMeansure();
    Q_INVOKABLE void startOfflineMeansure();
private:
    void init();
    MeansureControlDataModel* m_modelPtr;
    MeansureController* m_controllerPtr;
};

#endif // MEANSUREVIEWMANAGER_H
