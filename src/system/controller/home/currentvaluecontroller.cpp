#include "currentvaluecontroller.h"
#include "../../protocol/stprotocol2.h"
#include "../../dataModel/home/runninginfodatamodel.h"
#include "../../context/appcontext.h"
#include "../../modelProtocolConvert/currentvalueconverter.h"
#include <QDebug>

CurrentValueController::CurrentValueController()
{

}

void CurrentValueController::execute(CurrentValueController::Option option, QString paras)
{

    switch(option)
    {
    case Option::GET_CURRENTVALUE:
        exeViewManger->setExecuteStatus("查询实时监测数据！");
        dbManager->insertLogInfo("查询实时监测数据！");
        WorkItem item(this, 0, paras);
        pollProxy->addWork(item);
        break;
    }
}

void CurrentValueController::execute(int option, QString paras)
{
    QByteArray request=NULL;
    switch(option)
    {
    case 0:
        request=STProtocol2::getCurrentMeansureValueRequest();
        m_currentOption = Option::GET_CURRENTVALUE;
        break;
    }

    send(request);
}

bool CurrentValueController::handleResponse(const QByteArray &resp)
{
    if(Controller::handleResponse(resp) == true)
    {
        switch(m_currentOption)
        {
        case Option::GET_CURRENTVALUE:
            AppController::handleResponse(resp);
            exeViewManger->setExecuteStatus("查询实时监测数据成功！");
            dbManager->insertLogInfo("查询实时监测数据成功！");
            m_modelPtr = (CurrentValueDataModel*)AppContext::get("currentValueDataModel");
            CurrentValueConverter::parseCurrentValue(resp, m_modelPtr);
            dbManager->insertHistoryData(m_modelPtr);
            SetChanged();
            Notify(m_modelPtr);
            break;
        }
    }
    else
    {

    }
    //AppController::handleResponse(resp);
}

bool CurrentValueController::validate(const QByteArray &resp)
{

}
