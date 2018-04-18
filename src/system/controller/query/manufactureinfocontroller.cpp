#include "manufactureinfocontroller.h"
#include "../../protocol/stprotocol1.h"
#include "../../context/appcontext.h"
#include <QDebug>

ManufactureInfoController::ManufactureInfoController()
{

}

void ManufactureInfoController::execute(ManufactureInfoController::Option option, QString paras)
{
    switch(option)
    {
        case Option::GET_INFO:
        WorkItem item(this, 0, paras);
        pollProxy->addWork(item);
            break;
    }
}

void ManufactureInfoController::execute(int option, QString paras)
{
    QByteArray request=NULL;
    switch(option)
    {
        case 0:
            request=STProtocol1::getManufactureInfoRequest();
            m_currentOption = Option::GET_INFO;
            break;
    }

    send(request);
}

bool ManufactureInfoController::handleResponse(const QByteArray &resp)
{
    //AppController::handleResponse(resp);
    qWarning() << "recerve manufacture info response!";
    if(Controller::handleResponse(resp) == true)
        {
            switch(m_currentOption)
            {
                case Option::GET_INFO:
                AppController::handleResponse(resp);
                    m_modelPtr = (ManufactureInfoDataModel*)AppContext::get("manufactureInfoDataModel");
                    //m_modelPtr->setMeansureMode(2);
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

bool ManufactureInfoController::validate(const QByteArray &resp)
{

}

void ManufactureInfoController::updateManufactureInfo()
{

}
