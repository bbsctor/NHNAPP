#include "runninginfocontroller.h"
#include "../../protocol/stprotocol2.h"
#include "../../dataModel/home/runninginfodatamodel.h"
#include "../../context/appcontext.h"
#include "../../modelProtocolConvert/runninginfoconverter.h"
#include <QDebug>
#include <QString>

bool RunningInfoController::isOnMeansure = false;

RunningInfoController::RunningInfoController()
{
    RunningInfoController::isOnMeansure = false;
}

void RunningInfoController::execute(RunningInfoController::Option option, QString paras)
{
    QByteArray request=NULL;
    switch(option)
    {
    case Option::GET_RUNNINGINFO:
        exeViewManger->setExecuteStatus("获取运行状态数据指令下发！");
        WorkItem item(this, 0, paras);
        pollProxy->addWork(item);
        break;
    }
}

void RunningInfoController::execute(int option, QString paras)
{
    QByteArray request=NULL;
    switch(option)
    {
    case 0:
        request=STProtocol2::getRunningInfoRequest();
        m_currentOption = Option::GET_RUNNINGINFO;
        break;
    }

    send(request);
}

bool RunningInfoController::handleResponse(const QByteArray &resp)
{

    //AppController::handleResponse(resp);
    qWarning() << "receive running info response!";
    if(Controller::handleResponse(resp) == true)
    {
        switch(m_currentOption)
        {
        case Option::GET_RUNNINGINFO:
            AppController::handleResponse(resp);
            exeViewManger->setExecuteStatus("处理运行状态数据！");
            m_modelPtr = (RunningInfoDataModel*)AppContext::get("runningInfoDataModel");
            RunningInfoConverter::parseRunningInfo(resp, m_modelPtr);
            QString curStatus = m_modelPtr->currentStatus();
            if((QString::compare(curStatus, "在线测量") == 0) ||
                    (QString::compare(curStatus, "离线测量") == 0))
            {
                isOnMeansure = true;
            }
            SetChanged();
            Notify(m_modelPtr);
            break;
        }
    }
    else
    {

    }
   // AppController::handleResponse(resp);
}

bool RunningInfoController::validate(const QByteArray &resp)
{
    return true;
}

//void RunningInfoController::updateRunningInfo(const QByteArray &resp)
//{

//}
