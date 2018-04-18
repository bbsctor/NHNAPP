#include "valuedisplayviewmanager.h"
#include <QDebug>
#include "../../context/appcontext.h"
#include "../../controller/home/currentvaluecontroller.h"
#include "../../modelProtocolConvert/currentvalueconverter.h"

ValueDisplayViewManager::ValueDisplayViewManager()
{
    CurrentValueController* cptr = (CurrentValueController*)AppContext::get("currentValueController");
    cptr->Attach(this);
    init();
}

void ValueDisplayViewManager::pullCurrentValue()
{
    qWarning() << "get current value!";
    m_controllerPtr->execute(CurrentValueController::Option::GET_CURRENTVALUE, NULL);
}

void ValueDisplayViewManager::Update(QObservable *pObs, void *pArg)
{
    CurrentValueDataModel* pContent = static_cast<CurrentValueDataModel*>(pArg);
        // 观察目标
        if(dynamic_cast <CurrentValueController*>(pObs))
        {
            updateViewCurrentValue(pContent);
        }
        else
        {

        }
}

void ValueDisplayViewManager::init()
{
    m_modelPtr = (CurrentValueDataModel*)AppContext::get("currentValueDataModel");
    m_controllerPtr = (CurrentValueController*)AppContext::get("currentValueController");
    if (m_modelPtr == NULL || m_controllerPtr == NULL)
    {
        qWarning() << "CurrentValueViewManager init failed!";
    }
}

void ValueDisplayViewManager::updateViewCurrentValue(CurrentValueDataModel *pModel)
{
    ValueDisplayViewManager::setCurrentValue(pModel->currentValue());
    qWarning() << pModel->currentValue();
}
