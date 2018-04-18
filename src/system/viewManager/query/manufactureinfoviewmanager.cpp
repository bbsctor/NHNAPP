#include "manufactureinfoviewmanager.h"
#include <QDebug>
#include "../../context/appcontext.h"
#include "../../controller/query/manufactureinfocontroller.h"

ManufactureInfoViewManager::ManufactureInfoViewManager()
{
    ManufactureInfoController* cptr = (ManufactureInfoController*)AppContext::get("manufactureInfoController");
    cptr->Attach(this);
    init();
}

void ManufactureInfoViewManager::getManufactureInfo()
{
    qWarning() << "init default value!";
    m_controllerPtr->execute(ManufactureInfoController::Option::GET_INFO, NULL);
}

void ManufactureInfoViewManager::init()
{
    getManufactureInfo();
}
