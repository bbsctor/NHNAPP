#ifndef MANUFACTUREINFOVIEWMANAGER_H
#define MANUFACTUREINFOVIEWMANAGER_H
#include "../../dataModel/query/manufactureinfodatamodel.h"
#include "../../../framework/viewManager/viewmanager.h"
#include "../../controller/query/manufactureinfocontroller.h"
#include "../../../framework/observe/qobserver.h"

class ManufactureInfoViewManager : public ViewManager,QObserver
{
    Q_OBJECT
//    Q_PROPERTY(QString sysDate READ sysDate WRITE setSysDate NOTIFY sysDateChanged)
//    Q_PROPERTY(QString sysTime READ sysTime WRITE setSysTime NOTIFY sysTimeChanged)
public:
    ManufactureInfoViewManager();
    Q_INVOKABLE void getManufactureInfo();
private:
    void init();
    void updateManufactureInfo(ManufactureInfoDataModel* pModel);
    ManufactureInfoDataModel* m_modelPtr;
    ManufactureInfoController* m_controllerPtr;
};

#endif // MANUFACTUREINFOVIEWMANAGER_H
