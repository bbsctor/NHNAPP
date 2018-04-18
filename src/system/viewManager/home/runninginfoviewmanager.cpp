#include "runninginfoviewmanager.h"
#include <QDebug>
#include "../../context/appcontext.h"
#include "../../controller/home/runninginfocontroller.h"
#include "../../controller/home/currentvaluecontroller.h"
#include "../../modelProtocolConvert/runninginfoconverter.h"
#include <typeinfo>
int RunningInfoViewManager::isNewData=1;
RunningInfoViewManager::RunningInfoViewManager()
{
    RunningInfoController* cptr = (RunningInfoController*)AppContext::get("runningInfoController");
    cptr->Attach(this);
    init();
}

void RunningInfoViewManager::pullRunningInfo()
{
    qWarning() << "get running info!";
    m_controllerPtr->execute(RunningInfoController::Option::GET_RUNNINGINFO, NULL);
}

void RunningInfoViewManager::Update(QObservable *pObs, void *pArg)
{
    RunningInfoDataModel* pContent = static_cast<RunningInfoDataModel*>(pArg);
        // 观察目标
        if(dynamic_cast <RunningInfoController*>(pObs))
        {
            updateViewRunningInfo(pContent);
        }
        else
        {

        }
}

void RunningInfoViewManager::init()
{
    m_modelPtr = (RunningInfoDataModel*)AppContext::get("runningInfoDataModel");
    m_controllerPtr = (RunningInfoController*)AppContext::get("runningInfoController");
    if (m_modelPtr == NULL || m_controllerPtr == NULL)
    {
        qWarning() << "RunningInfoViewManager init failed!";
    }
}

void RunningInfoViewManager::updateViewRunningInfo(RunningInfoDataModel *pModel)
{
    RunningInfoViewManager::setCurrentStatus(pModel->currentStatus());
    RunningInfoViewManager::setCurrentAction(pModel->currentAction());
    RunningInfoViewManager::setNextAction(pModel->nextAction());
    RunningInfoViewManager::setDispelTemperature(pModel->dispelTemperature());
    RunningInfoViewManager::setEnvironmentTemperature(pModel->environmentTemperature());
    RunningInfoViewManager::setAbsorbance(pModel->absorbance());
    RunningInfoViewManager::setProgress(pModel->progress());

    RunningInfoViewManager::setCoolerTempearture(pModel->coolerTempearture());
    RunningInfoViewManager::setInjectBumbStatus(pModel->injectBumbStatus());
    RunningInfoViewManager::setSwitchValvoStatus(pModel->switchValvoStatus());

    QString currentStatus = pModel->currentStatus();
    QString currentAction = pModel->currentAction();
    QString nextAction = pModel->nextAction();

    if((QString::compare(currentStatus, "在线测量") == 0 || QString::compare(currentStatus, "离线测量") == 0)  &&
            QString::compare(currentAction, "测量后管路清洗") == 0 && QString::compare(nextAction, "结束")==0  )
    {
        if(isNewData==1)
        {
            CurrentValueController* controllerPtr = (CurrentValueController*)AppContext::get("currentValueController");
            controllerPtr->execute(CurrentValueController::Option::GET_CURRENTVALUE, NULL);
            isNewData=0;
        }

    }
    else
    {
        isNewData=1;
    }
}


