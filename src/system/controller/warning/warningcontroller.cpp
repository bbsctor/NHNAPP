#include "warningcontroller.h"
#include "../../protocol/stprotocol2.h"
#include "../../dataModel/warning/warningdatamodel.h"
#include "../../context/appcontext.h"
#include "../../modelProtocolConvert/warningconverter.h"
#include <QDebug>

WarningController::WarningController()
{

}

void WarningController::execute(WarningController::Option option, QString paras)
{
        switch(option)
        {
            case Option::GET_WARNINGINFO:
            WorkItem item(this, 0, paras);
            pollProxy->addWork(item);
                break;
        }
}

void WarningController::execute(int option, QString paras)
{
    QByteArray request=NULL;
        switch(option)
        {
            case 0:
                request=STProtocol2::getWarningInfoRequest();
                        m_currentOption = Option::GET_WARNINGINFO;
                break;
        }

        send(request);
}

bool WarningController::handleResponse(const QByteArray &resp)
{
    //AppController::handleResponse(resp);
    qWarning() << "receive calibration coef response!";
    if(Controller::handleResponse(resp) == true)
    {
        switch(m_currentOption)
        {
        case Option::GET_WARNINGINFO:
            //AppController::handleResponse(resp);
            m_modelPtr = (WarningDataModel*)AppContext::get("warningDataModel");
            WarningConverter::parseWarningInfo(resp, m_modelPtr);
            if(QString::compare(m_modelPtr->warningInfo(),"无故障") != 0)
            {
                dbManager->insertAlertInfo(m_modelPtr->warningInfo());
            }
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

bool WarningController::validate(const QByteArray &resp)
{
    return true;
}
