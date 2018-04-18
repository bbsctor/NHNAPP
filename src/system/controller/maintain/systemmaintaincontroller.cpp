#include "systemmaintaincontroller.h"
#include "../../protocol/stprotocol2.h"
#include "../../context/appcontext.h"
#include "../../controller/maintain/maintaindatacontroller.h"
#include <QDebug>
#include <QTimer>

SystemMaintainController::SystemMaintainController()
{
    AppContext::set("periodCalibrationTimer",new QTimer(this));
    calibrationTimer = (QTimer*)AppContext::get("periodCalibrationTimer");
    calibrationTimer->connect(calibrationTimer,SIGNAL(timeout()),this,SLOT(calibrationWrapper()));
}

void SystemMaintainController::execute(SystemMaintainController::Option option, QString paras)
{
        WorkItem item;
        switch(option)
        {
            case Option::MEANSURE:
                item.fill(this, 0, paras);
                pollProxy->addWork(item);
                break;
            case Option::CALIBRATION:
                item.fill(this, 1, paras);
                pollProxy->addWork(item);
                break;
            case Option::INIT:
                item.fill(this, 2, paras);
                pollProxy->addWork(item);
                break;
            case Option::CLEANBUBBLE:
                item.fill(this, 3, paras);
                pollProxy->addWork(item);
                break;
            case Option::WASHCUVETTE:
                item.fill(this, 4, paras);
                pollProxy->addWork(item);
                break;
            case Option::REVGENTWASHCUVETTE:
                item.fill(this,5, paras);
                pollProxy->addWork(item);
                break;
            case Option::FINISHDISPOSE:
                item.fill(this, 6, paras);
                pollProxy->addWork(item);
                break;
            case Option::ZEROMEANSURE:
                item.fill(this, 7, paras);
                pollProxy->addWork(item);
                break;
            case Option::URGENCYSTOP:
                item.fill(this, 8, paras);
                pollProxy->addWork(item);
                break;
            case Option::SEARCHSTATUS:
                item.fill(this, 9, paras);
                pollProxy->addWork(item);
                break;
            case Option::ZEROCALIBRATION:
                item.fill(this, 10, paras);
                pollProxy->addWork(item);
                break;
            case Option::SPANCALIBRATION:
                item.fill(this, 11, paras);
                pollProxy->addWork(item);
                break;
        }
}

void SystemMaintainController::execute(int option, QString paras)
{
    QByteArray request=NULL;
        switch(option)
        {
            case 0:
                request=STProtocol2::getMeansureModeRequest();
                m_currentOption = Option::MEANSURE;
                break;
            case 1:
                request=STProtocol2::getCalibrationRequest();
                m_currentOption = Option::CALIBRATION;
                break;
            case 2:
                request=STProtocol2::getInitialRequest();
                m_currentOption = Option::INIT;
                break;
            case 3:
                request=STProtocol2::getCleanBubbleRequest();
                m_currentOption = Option::CLEANBUBBLE;
                break;
            case 4:
                request=STProtocol2::getWashCuvetteRequest();
                m_currentOption = Option::WASHCUVETTE;
                break;
            case 5:
                request=STProtocol2::getReagentWashCuvetteRequest();
                m_currentOption = Option::REVGENTWASHCUVETTE;
                break;
            case 6:
                request=STProtocol2::getFinishDisposeRequest();
                m_currentOption = Option::FINISHDISPOSE;
                break;
            case 7:
                request=STProtocol2::getZeroMeansureRequest();
                m_currentOption = Option::ZEROMEANSURE;
                break;
            case 8:
                request=STProtocol2::getUrgencyStopRequest();
                m_currentOption = Option::URGENCYSTOP;
                break;
            case 9:
                request=STProtocol2::getSearchStatusRequest();
                m_currentOption = Option::SEARCHSTATUS;
                break;
            case 10:
                request=STProtocol2::getZeroCalibrationRequest();
                m_currentOption = Option::ZEROCALIBRATION;
                break;
            case 11:
                request=STProtocol2::getSpanCalibrationRequest();
                m_currentOption = Option::SPANCALIBRATION;
                break;
        }

        send(request);
}




bool SystemMaintainController::handleResponse(const QByteArray &resp)
{
   AppController::handleResponse(resp);
    qWarning() << "recerve system maintain response!";
        if(Controller::handleResponse(resp) == true)
            {
                switch(m_currentOption)
                {
                    case Option::MEANSURE:
                        break;
                    case Option::CALIBRATION:
                        //timer->start(5000);
                        break;
                    case Option::INIT:
                        break;
                    case Option::CLEANBUBBLE:
                        break;
                    case Option::WASHCUVETTE:
                        break;
                    case Option::REVGENTWASHCUVETTE:
                        break;
                    case Option::FINISHDISPOSE:
                        break;
                    case Option::ZEROMEANSURE:
                        break;
                    case Option::URGENCYSTOP:
                        break;
                    case Option::SEARCHSTATUS:
                        break;
                    case Option::ZEROCALIBRATION:
                        break;
                    case Option::SPANCALIBRATION:
                        break;
                }
            }
            else
            {

            }
        //AppController::handleResponse(resp);
}

bool SystemMaintainController::validate(const QByteArray &resp)
{
    switch(m_currentOption)
    {
        case Option::MEANSURE:
            break;
        case Option::CALIBRATION:
            break;
        case Option::INIT:
            break;
        case Option::CLEANBUBBLE:
            break;
        case Option::WASHCUVETTE:
            break;
        case Option::REVGENTWASHCUVETTE:
            break;
        case Option::FINISHDISPOSE:
            break;
        case Option::ZEROMEANSURE:
            break;
        case Option::URGENCYSTOP:
            break;
        case Option::SEARCHSTATUS:
            break;
        case Option::ZEROCALIBRATION:
            break;
        case Option::SPANCALIBRATION:
            break;
    }
}

void SystemMaintainController::updateCalibrationCoef()
{
    MaintainDataController* controllerPtr = (MaintainDataController*)AppContext::get("maintainDataController");
    controllerPtr->execute(MaintainDataController::Option::GET_CALIBRATIONCOEF, NULL);
}

void SystemMaintainController::periodCalibrationOn(int interval)
{
    if(calibrationTimer->interval() != interval)
    {
        calibrationTimer->setInterval(interval);
    }
    if(calibrationTimer->isActive() == false)
    {
        calibrationTimer->start();
    }
    QString temp = "下次周期校准时间：";
    QDateTime dt = QDateTime::currentDateTime().addMSecs(calibrationTimer->interval());
    temp.append(dt.toString("yyyy.MM.dd hh:mm:ss"));
    exeViewManger->setPeriodCalibration(temp);
}

void SystemMaintainController::periodCalibrationOff()
{
    if(calibrationTimer->isActive() == true)
    {
        calibrationTimer->stop();
    }
    exeViewManger->setPeriodCalibration("");
}

void SystemMaintainController::calibrationWrapper()
{
    execute(SystemMaintainController::Option::CALIBRATION,NULL);
    QString temp = "下次周期校准时间：";
    QDateTime dt = QDateTime::currentDateTime().addMSecs(calibrationTimer->interval());
    temp.append(dt.toString("yyyy.MM.dd hh:mm:ss"));
    exeViewManger->setPeriodCalibration(temp);
}
