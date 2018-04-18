#include "functiontestcontroller.h"
#include "../../protocol/stprotocol2.h"
#include "../../context/appcontext.h"
#include <QDebug>

FunctionTestController::FunctionTestController()
{

}

void FunctionTestController::execute(FunctionTestController::Option option, QString paras)
{
        WorkItem item;
        switch(option)
        {
            case Option::INJECTBUMBVALVE:
                item.fill(this, 0, paras);
                pollProxy->addWork(item);
                break;
            case Option::MIXINGBUMB:
                item.fill(this, 1, paras);
                pollProxy->addWork(item);
                break;
            case Option::DISPELFAN:
                item.fill(this, 2, paras);
                pollProxy->addWork(item);
                break;
            case Option::BOXFAN:
                item.fill(this, 3, paras);
                pollProxy->addWork(item);
                break;
            case Option::INWATER:
                item.fill(this, 4, paras);
                pollProxy->addWork(item);
                break;
            case Option::INZERO:
                item.fill(this, 5, paras);
                pollProxy->addWork(item);
                break;
            case Option::INSTDSAMPLE:
                item.fill(this, 6, paras);
                pollProxy->addWork(item);
                break;
            case Option::INREAGENTTHREE:
                item.fill(this, 7, paras);
                pollProxy->addWork(item);
                break;
            case Option::INREAGENTFOUR:
                 item.fill(this, 8, paras);
                pollProxy->addWork(item);
                break;
            case Option::INREAGENTFIVE:
                item.fill(this, 9, paras);
                pollProxy->addWork(item);
                break;
        }
}

void FunctionTestController::execute(int option, QString paras)
{
    QByteArray request=NULL;
        switch(option)
        {
            case 0:
                request=STProtocol2::getInjectBumbValveRequest();
                m_currentOption = Option::INJECTBUMBVALVE;
                break;
            case 1:
                request=STProtocol2::getMixingBumbRequest();
                m_currentOption = Option::MIXINGBUMB;
                break;
            case 2:
                request=STProtocol2::getDispelFanRequest();
                m_currentOption = Option::DISPELFAN;
                break;
            case 3:
                request=STProtocol2::getBoxFanRequest();
                m_currentOption = Option::BOXFAN;
                break;
            case 4:
                request=STProtocol2::getInWaterRequest();
                m_currentOption = Option::INWATER;
                break;
            case 5:
                request=STProtocol2::getInZeroRequest();
                m_currentOption = Option::INZERO;
                break;
            case 6:
                request=STProtocol2::getInStdSampleRequest();
                m_currentOption = Option::INSTDSAMPLE;
                break;
            case 7:
                request=STProtocol2::getInReagentThreeRequest();
                m_currentOption = Option::INREAGENTTHREE;
                break;
            case 8:
                request=STProtocol2::getInReagentFourRequest();
                m_currentOption = Option::INREAGENTFOUR;
                break;
            case 9:
                request=STProtocol2::getInReagentFiveRequest();
                m_currentOption = Option::INREAGENTFIVE;
                break;
        }
        send(request);
}

bool FunctionTestController::handleResponse(const QByteArray &resp)
{
    qWarning() << "recerve system maintain response!";
    AppController::handleResponse(resp);
            if(Controller::handleResponse(resp) == true)
                {
                    switch(m_currentOption)
                    {
//                    case Option::IN_WATERSAMPLE:

//                                    break;
//                                case Option::IN_ZEROSAMPLE:

//                                                break;
//                                case Option::IN_STDONE:

//                                                break;
//                                case Option::IN_STDTWO:

//                                                break;
//                                case Option::IN_TESTONE:

//                                                break;
//                                case Option::IN_TESTTWO:

//                                                break;
//                                case Option::BUBBLE:

//                                                break;
//                                case Option::HEATER:

//                                                break;
//                                case Option::INITFILL:

//                                                break;
//                                case Option::WASH_MEANSURETUBE:

//                                                break;
//                                case Option::WASH_DISPELJAR:
//                                                break;
                    case Option::INJECTBUMBVALVE:
                        exeViewManger->setExecuteStatus("下发测试注射泵指令成功！");
                        break;
                    case Option::MIXINGBUMB:
                        exeViewManger->setExecuteStatus("下发测试搅拌泵指令成功！");
                        break;
                    case Option::DISPELFAN:
                         exeViewManger->setExecuteStatus("下发消解管风扇指令成功！");
                        break;
                    case Option::BOXFAN:
                        exeViewManger->setExecuteStatus("下发机柜风扇指令成功！");
                        break;
                    case Option::INWATER:
                        exeViewManger->setExecuteStatus("下发消进水样指令成功！");
                        break;
                    case Option::INZERO:
                        exeViewManger->setExecuteStatus("下发进零样指令成功！");
                        break;
                    case Option::INSTDSAMPLE:
                        exeViewManger->setExecuteStatus("下发进标样指令成功！");
                        break;
                    case Option::INREAGENTTHREE:
                        exeViewManger->setExecuteStatus("下发进试剂3指令成功！");
                        break;
                    case Option::INREAGENTFOUR:
                        exeViewManger->setExecuteStatus("下发进试剂4指令成功！");
                        break;
                    case Option::INREAGENTFIVE:
                        exeViewManger->setExecuteStatus("下发进试剂5指令成功！");
                        break;
                    }
                }
                else
                {

                }
            //AppController::handleResponse(resp);
}

bool FunctionTestController::validate(const QByteArray &resp)
{
    switch(m_currentOption)
            {
//                case Option::IN_WATERSAMPLE:

//                    break;
//                case Option::IN_ZEROSAMPLE:

//                    break;
//                case Option::IN_STDONE:

//                    break;
//                case Option::IN_STDTWO:

//                    break;
//                case Option::IN_TESTONE:

//                    break;
//                case Option::IN_TESTTWO:

//                    break;
//                case Option::BUBBLE:

//                    break;
//                case Option::HEATER:

//                    break;
//                case Option::INITFILL:

//                    break;
//                case Option::WASH_MEANSURETUBE:

//                    break;
//                case Option::WASH_DISPELJAR:
//                    break;
                case Option::INJECTBUMBVALVE:
                    break;
                case Option::MIXINGBUMB:
                    break;
                case Option::DISPELFAN:
                    break;
                case Option::BOXFAN:
                    break;
                case Option::INWATER:
                    break;
                case Option::INZERO:
                    break;
                case Option::INSTDSAMPLE:
                    break;
                case Option::INREAGENTTHREE:
                    break;
                case Option::INREAGENTFOUR:
                    break;
                case Option::INREAGENTFIVE:
                    break;
            }
}
