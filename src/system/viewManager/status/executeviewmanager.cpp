#include "executeviewmanager.h"
#include "../../controller/appcontroller.h"
#include "../../context/appcontext.h"
#include "../../datamodel/status/executestatusdatamodel.h"

ExecuteViewManager::ExecuteViewManager()
{
    init();
}

void ExecuteViewManager::init()
{
    AppController* cptr = (AppController*)AppContext::get("systemSettingController");
    cptr->registerExeViewManger(this);
    cptr = (AppController*)AppContext::get("meansureController");
    cptr->registerExeViewManger(this);
    cptr = (AppController*)AppContext::get("periodSettingController");
    cptr->registerExeViewManger(this);
    cptr = (AppController*)AppContext::get("systemMaintainController");
    cptr->registerExeViewManger(this);
    cptr = (AppController*)AppContext::get("functionTestController");
    cptr->registerExeViewManger(this);
    cptr = (AppController*)AppContext::get("runningInfoController");
    cptr->registerExeViewManger(this);
    cptr = (AppController*)AppContext::get("homeController");
    cptr->registerExeViewManger(this);
    cptr = (AppController*)AppContext::get("currentValueController");
    cptr->registerExeViewManger(this);
    cptr = (AppController*)AppContext::get("bcljzjSettingOneController");
    cptr->registerExeViewManger(this);
    cptr = (AppController*)AppContext::get("parameterSettingController");
    cptr->registerExeViewManger(this);
    cptr = (AppController*)AppContext::get("maintainDataController");
    cptr->registerExeViewManger(this);
    cptr = (AppController*)AppContext::get("warningController");
    cptr->registerExeViewManger(this);

}

