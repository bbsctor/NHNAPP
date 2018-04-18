#include "systemsettingcontroller.h"
#include "../../context/appcontext.h"
#include "../../modelProtocolConvert/systemsettingconverter.h"
#include <QDebug>
#include "../../protocol/stprotocol2.h"
#include"../../dataModel/setting/settingdefaultinformationdatamodel.h"
#include"../../modelProtocolConvert/settingdefaultinformationconverter.h"
SystemSettingController::SystemSettingController()
{
    //execute(Option::INIT,NULL);
}

void SystemSettingController::execute(SystemSettingController::Option option, QString paras)
{
    WorkItem item;
    switch (option) {
    case Option::INIT:
        exeViewManger->setExecuteStatus("准备读取默认系统设置参数！");
        item.fill(this, 0, paras);
        pollProxy->addWork(item);
        break;
    case Option::SET_4TO20MAABLE:
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
    case Option::SET_RS485ABLE:
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
    case Option::SET_ALEATUPPERLOWZONE:
        item.fill(this, 3, paras);
        pollProxy->addWork(item);
        break;
    case Option::SET_SLAVEADDRESS:
        item.fill(this, 4, paras);
        pollProxy->addWork(item);
        break;

    }
}

void SystemSettingController::execute(int option, QString paras)
{
    QByteArray request=NULL;
    int i,j,k;
    QStringList list;
    QString str1;
    QString str2;

    switch (option) {
    case 0:
        exeViewManger->setExecuteStatus("准备读取默认系统设置参数！");
        request=STProtocol2::getSystemSettingDefaultInfoRequest();
        m_currentOption=Option::INIT;
        break;
    case 1:
        if(QString::compare(paras,"enable") == 0)
        {
            request=STProtocol2::get4to20mAAbleRequest(0x01);
            m_currentOption=Option::SET_4TO20MAABLE;
        }

        else
        {

            request=STProtocol2::get4to20mAAbleRequest(0x00);
            m_currentOption=Option::SET_4TO20MAABLE;
        }

        break;
    case 2:
        if(QString::compare(paras,"enable") == 0)
        {
            request=STProtocol2::getRS485AbleRequest(0x01);
            m_currentOption=Option::SET_RS485ABLE;
        }

        else
        {
            request=STProtocol2::getRS485AbleRequest(0x00);
            m_currentOption=Option::SET_RS485ABLE;
        }

        break;
    case 3:
//        QStringList list=paras.split(',');
//        QString str1=list.at(0);
//        QString str2=list.at(1);
        list=paras.split(',');
        str1=list.at(0);
        str2=list.at(1);
        i=str1.toInt();
        j=str2.toInt();
        request=STProtocol2::getAlertUpperLowZoneRequest(i,j);
        m_currentOption=Option::SET_ALEATUPPERLOWZONE;
        break;
    case 4:
        k = paras.toInt();
        request=STProtocol2::getSettingSlaveAddressRequest((char)k);
        m_currentOption=Option::SET_SLAVEADDRESS;
        break;

    }

    send(request);
}

bool SystemSettingController::handleResponse(const QByteArray &resp)
{
    //AppController::handleResponse(resp);
    if(Controller::handleResponse(resp) == true && AppController::validateResponse(req, resp) == true)
    {
        switch(m_currentOption)
        {
        case Option::INIT:
            // AppController::handleResponse(resp);
            exeViewManger->setExecuteStatus("读取默认系统设置参数成功！");
            m_modelPtr = (SettingDefaultInformationDataModel*)AppContext::get("settingdefaultinformationdatamodel");
            SettingDefaultInformationConverter::parseSystermDefaultSettingInfo(resp,m_modelPtr);
            SetChanged();
            Notify(m_modelPtr);

            break;
        case Option::SET_4TO20MAABLE:
            //AppController::handleResponse(resp);
            exeViewManger->setExecuteStatus("设置4到20mA使能指令下发成功！");
            break;

        case Option::SET_RS485ABLE:
            // AppController::handleResponse(resp);
            exeViewManger->setExecuteStatus("设置RS485使能指令下发成功！");
            break;
        case Option::SET_ALEATUPPERLOWZONE:
            //AppController::handleResponse(resp);
            exeViewManger->setExecuteStatus("设置报警上下限指令下发成功！");

            break;
        case Option::SET_SLAVEADDRESS:
            //AppController::handleResponse(resp);
            exeViewManger->setExecuteStatus("设置从站地址指令下发成功！");

            break;

        }
    }
    else
    {
        exeViewManger->setExecuteStatus("响应错误！");
    }
    return true;
}

