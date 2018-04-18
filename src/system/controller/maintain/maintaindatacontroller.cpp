#include "maintaindatacontroller.h"
#include "../../protocol/stprotocol2.h"
#include "../../dataModel/maintain/calibrationcoefdatamodel.h"
#include "../../context/appcontext.h"
#include "../../modelProtocolConvert/calibrationcoefconverter.h"
#include <QDebug>

MaintainDataController::MaintainDataController()
{

}

void MaintainDataController::execute(MaintainDataController::Option option, QString paras)
{
        switch(option)
        {
            case Option::GET_CALIBRATIONCOEF:
                WorkItem item(this, 0, paras);
                pollProxy->addWork(item);
                break;
        }
}

void MaintainDataController::execute(int option, QString paras)
{
    QByteArray request=NULL;
        switch(option)
        {
            case 0:
                request=STProtocol2::getCalibrationCoefRequest(paras.toInt(NULL, 16));
                m_currentOption = Option::GET_CALIBRATIONCOEF;
                break;
        }

        send(request);
}

bool MaintainDataController::handleResponse(const QByteArray &resp)
{
    qWarning() << "receive calibration coef response!";
   //AppController::handleResponse(resp);
    if(Controller::handleResponse(resp) == true)
    {
        switch(m_currentOption)
        {
        case Option::GET_CALIBRATIONCOEF:
            AppController::handleResponse(resp);
            m_modelPtr = (MaintainDataDataModel*)AppContext::get("maintainDataDataModel");
            CalibrationCoefConverter::parseCalibrationCoef(resp, m_modelPtr);
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

//bool MaintainDataController::validate(const QByteArray &resp)
//{
//    return true;
//}
