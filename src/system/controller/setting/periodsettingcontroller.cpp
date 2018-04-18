#include "periodsettingcontroller.h"
#include "../../protocol/stprotocol1.h"
#include "../../context/appcontext.h"
#include <QDebug>
#include"../../dataModel/setting/settingdefaultinformationdatamodel.h"
#include"../../modelProtocolConvert/settingdefaultinformationconverter.h"
PeriodSettingController::PeriodSettingController()
{
    //init();
}

void PeriodSettingController::execute(PeriodSettingController::Option option, QString paras)
{
    WorkItem item;
    switch(option)
    {
    case Option::INIT:
       exeViewManger->setExecuteStatus("准备读取默认周期设置参数！");
       item.fill(this, 0, paras);
       pollProxy->addWork(item);
        break;
    case Option::SET_MEANSUREMODE:
        exeViewManger->setExecuteStatus("测量模式指令下发！");
        item.fill(this, 1, paras);
        pollProxy->addWork(item);
        break;
    case Option::SET_CALIBRATIONPERIOD:
        exeViewManger->setExecuteStatus("设置校准周期指令下发！");
        item.fill(this, 2, paras);
        pollProxy->addWork(item);
        break;
    case Option::SET_MEASUREINTERVAL:
        exeViewManger->setExecuteStatus("设置测量间隔指令下发！");
        item.fill(this, 3, paras);
        pollProxy->addWork(item);
        break;

    }
}

void PeriodSettingController::execute(int option, QString paras)
{
    QByteArray request=NULL;
    char temp;
    switch(option)
    {
    case 0:
       exeViewManger->setExecuteStatus("准备读取默认周期设置参数！");
        request=STProtocol2::getPeriodSettingDefaultInfoRequest();
            m_currentOption = Option::INIT;
        break;
    case 1:
        exeViewManger->setExecuteStatus("测量模式指令下发！");
        temp=(char)(paras.toInt());
        request=STProtocol2::getSettingMeasureModeRequest(temp);
            m_currentOption = Option::SET_MEANSUREMODE;
        break;
    case 2:
        exeViewManger->setExecuteStatus("设置校准周期指令下发！");
        temp=(char)(paras.toInt());
        request=STProtocol2::getSettingCalibrationgPeriodRequest(temp);
            m_currentOption = Option::SET_CALIBRATIONPERIOD;
        break;
    case 3:
        exeViewManger->setExecuteStatus("设置测量间隔指令下发！");
        temp=(char)(paras.toInt());
        request=STProtocol2::getSettingMeasureIntervalRequest(temp);
            m_currentOption = Option::SET_MEASUREINTERVAL;
        break;

    }

    send(request);
}

bool PeriodSettingController::handleResponse(const QByteArray &resp)
{
    //AppController::handleResponse(resp);
    if(Controller::handleResponse(resp) == true && AppController::validateResponse(req, resp) == true)
    {
        switch(m_currentOption)
        {
        case Option::INIT:
            AppController::handleResponse(resp);
             exeViewManger->setExecuteStatus("读取默认周期设置参数成功！");
            m_modelPtr = (SettingDefaultInformationDataModel*)AppContext::get("settingdefaultinformationdatamodel");
            SettingDefaultInformationConverter::parsePeriodDefaultSettingInfo(resp,m_modelPtr);
            qWarning() << "controller handle !";
            SetChanged();
            Notify(m_modelPtr);

            break;
        case Option::SET_MEANSUREMODE:
            exeViewManger->setExecuteStatus("测量模式指令下发成功！");
            dbManager->insertLogInfo("变更测量模式成功！");
            break;
        case Option::SET_CALIBRATIONPERIOD:
            exeViewManger->setExecuteStatus("设置校准周期指令下发成功！");
            dbManager->insertLogInfo("变更校准周期成功！");
            break;
        case Option::SET_MEASUREINTERVAL:
            exeViewManger->setExecuteStatus("设置测量间隔指令下发成功！");
            dbManager->insertLogInfo("变更测量间隔成功！");
            break;


        }
    }
    else
    {
        exeViewManger->setExecuteStatus("响应错误！");
    }
    return true;
}

void PeriodSettingController::init()
{

}

void PeriodSettingController::readDefaultParameters()
{

}
