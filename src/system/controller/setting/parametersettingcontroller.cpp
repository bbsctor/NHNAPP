#include "parametersettingcontroller.h"
#include "../../protocol/stprotocol2.h"
#include "../../context/appcontext.h"
#include <QDebug>
#include"../../dataModel/setting/settingdefaultinformationdatamodel.h"
#include"../../modelProtocolConvert/settingdefaultinformationconverter.h"
ParameterSettingController::ParameterSettingController()
{
//execute(Option::INIT,NULL);
}

void ParameterSettingController::execute(ParameterSettingController::Option option, QString paras)
{
    WorkItem item;
    switch (option)
    {
    case Option::INIT:
        exeViewManger->setExecuteStatus("准备读取默认参数！");
        item.fill(this, 0, paras);
        pollProxy->addWork(item);
        break;
    case Option::SET_MEGLOCKABLE:
        if(QString::compare(paras,"enable") == 0)
        {
            item.fill(this, 1, paras);
            pollProxy->addWork(item);
        }

        else
        {
            item.fill(this, 1, paras);
            pollProxy->addWork(item);
        }

        break;
    case Option::SET_WASHINGABLE:
        if(QString::compare(paras,"enable") == 0)
        {
            item.fill(this, 2, paras);
            pollProxy->addWork(item);
        }

        else
        {
            item.fill(this, 2, paras);
            pollProxy->addWork(item);
        }

        break;
    case Option::SET_PREHANDLERABLE:
        if(QString::compare(paras,"enable") == 0)
        {
            item.fill(this, 3, paras);
            pollProxy->addWork(item);
        }

        else
        {
            item.fill(this, 3, paras);
            pollProxy->addWork(item);
        }

        break;
    case Option::SET_DISPELTIME:
        item.fill(this, 4, paras);
        pollProxy->addWork(item);
        break;
    case Option::SET_BUMBONTIME:
         item.fill(this, 5, paras);
        pollProxy->addWork(item);
        break;
    }
}

void ParameterSettingController::execute(int option, QString paras)
{
    QByteArray request=NULL;
    int i;
    switch (option)
    {
    case 0:
        exeViewManger->setExecuteStatus("准备读取默认参数！");
        request=STProtocol2::getParameterSettingDefaultInfoRequest();
           m_currentOption=Option::INIT;
        break;
    case 1:
        if(QString::compare(paras,"enable") == 0)
        {
            request=STProtocol2::getMegLockAbleRequest(0x01);
           m_currentOption=Option::SET_MEGLOCKABLE;
        }
        else
        {
            request=STProtocol2::getMegLockAbleRequest(0x00);
               m_currentOption=Option::SET_MEGLOCKABLE;
        }

        break;
    case 2:
        if(QString::compare(paras,"enable") == 0)
        {
            request=STProtocol2::getWashingAbleRequest(0x01);
           m_currentOption=Option::SET_WASHINGABLE;
        }

        else
        {
            request=STProtocol2::getWashingAbleRequest(0x00);
               m_currentOption=Option::SET_WASHINGABLE;
        }

        break;
    case 3:
        if(QString::compare(paras,"enable") == 0)
        {
            request=STProtocol2::getPreHandlerWashingAbleRequest(0x01);
           m_currentOption=Option::SET_PREHANDLERABLE;
        }

        else
        {
            request=STProtocol2::getPreHandlerWashingAbleRequest(0x00);
               m_currentOption=Option::SET_PREHANDLERABLE;
        }

        break;
    case 4:
        i = paras.toInt();
        request=STProtocol2::getSettingDispelTimeRequest((char)i);
           m_currentOption=Option::SET_DISPELTIME;
        break;
    case 5:
        i = paras.toInt();
        request=STProtocol2::getSettingBumbOnTimeRequest((char)i);
           m_currentOption=Option::SET_BUMBONTIME;
        break;
    }
   send(request);
}

//bool ParameterSettingController::handleResponse(const QString &resp)
//{

//}
bool  ParameterSettingController::handleResponse(const QByteArray &resp)
{
    //AppController::handleResponse(resp);
    if(Controller::handleResponse(resp) == true && AppController::validateResponse(req, resp) == true)
    {
        switch(m_currentOption)
        {
        case Option::INIT:
            AppController::handleResponse(resp);
             exeViewManger->setExecuteStatus("读取默认参数设置成功！");
            m_modelPtr = (SettingDefaultInformationDataModel*)AppContext::get("settingdefaultinformationdatamodel");
            SettingDefaultInformationConverter::parseParameterDefaultSettingInfo(resp, m_modelPtr);
            SetChanged();
            Notify(m_modelPtr);

            break;
        case Option::SET_MEGLOCKABLE:
            AppController::handleResponse(resp);
             exeViewManger->setExecuteStatus("磁力锁开关设置指令下发成功！");
            break;
        case Option::SET_WASHINGABLE:
            AppController::handleResponse(resp);
             exeViewManger->setExecuteStatus("自来水冲洗开关设置指令下发成功！");
            break;
        case Option::SET_PREHANDLERABLE:
            AppController::handleResponse(resp);
            exeViewManger->setExecuteStatus("预处理开关设置指令下发成功！");
            break;
        case Option::SET_DISPELTIME:
            AppController::handleResponse(resp);
            exeViewManger->setExecuteStatus("消解时间设置指令下发成功！");
            break;
        case Option::SET_BUMBONTIME:
            AppController::handleResponse(resp);
           exeViewManger->setExecuteStatus("采样泵启动时间设置指令下发成功！");
            break;
        }
    }
    else
    {
        exeViewManger->setExecuteStatus("响应错误！");
    }
    return true;
}

//bool ParameterSettingController::validate(const QString &resp)
//{

//}

void ParameterSettingController::readDefaultParameters()
{

}
