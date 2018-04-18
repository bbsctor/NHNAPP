#include "warningviewmanager.h"
#include <QDebug>
#include "../../context/appcontext.h"
#include "../../controller/warning/warningcontroller.h"
#include "../../modelProtocolConvert/warningconverter.h"
#include <typeinfo>

WarningViewManager::WarningViewManager()
{
    WarningController* cptr = (WarningController*)AppContext::get("warningController");
    cptr->Attach(this);
    init();
}

void WarningViewManager:: pullCurrentWarningValue()
{
    qWarning() << "get current value!";
    m_controllerPtr->execute(WarningController::Option::GET_WARNINGINFO, NULL);
}

void WarningViewManager::Update(QObservable *pObs, void *pArg)
{
    WarningDataModel* pContent = static_cast<WarningDataModel*>(pArg);
        // 观察目标
        if(dynamic_cast <WarningController*>(pObs))
        {
            updateViewCurrentWarningValue(pContent);
        }
        else
        {

        }
}

void WarningViewManager::init()
{
    m_modelPtr = (WarningDataModel*)AppContext::get("warningDataModel");
    m_controllerPtr = (WarningController*)AppContext::get("warningController");
    if (m_modelPtr == NULL || m_controllerPtr == NULL)
    {
        qWarning() << "WarningViewManager init failed!";
    }
}

void WarningViewManager::updateViewCurrentWarningValue(WarningDataModel *pModel)
{
    WarningViewManager::setCurrentWarningValue(pModel->warningInfo());
    qWarning() << pModel->warningInfo();
}
