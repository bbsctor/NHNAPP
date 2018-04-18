#include "bcljzjsettingonecontroller.h"
#include "../../protocol/stprotocol2.h"
#include "../../context/appcontext.h"
#include <QDebug>

BCLJZJSettingOneController::BCLJZJSettingOneController()
{

}

void BCLJZJSettingOneController::execute(BCLJZJSettingOneController::Option option, QString paras)
{
    WorkItem item;
    switch(option)
    {
         case Option::INIT:
            item.fill(this, 0, paras);
            pollProxy->addWork(item);
            break;
        case Option::SET_CALIBRATIONCURVENUMBER:
            item.fill(this, 1, paras);
            pollProxy->addWork(item);
            break;

    }
}

void BCLJZJSettingOneController::execute(int option, QString paras)
{
    QByteArray request=NULL;
    int i;
    switch(option)
    {
         case 0:
                exeViewManger->setExecuteStatus("准备读取默认校准曲线！");
                request=STProtocol2::getSelectedCurveRequest();
                m_currentOption = Option::INIT;
          break;
         case 1:
            i=paras.toInt();
            exeViewManger->setExecuteStatus("设置选择曲线指令下发！");
            request=STProtocol2::getSettingCalibrationCurveNumberRequest(i);
            m_currentOption = Option::SET_CALIBRATIONCURVENUMBER;
            break;

    }

    send(request);
}

bool BCLJZJSettingOneController::handleResponse(const QByteArray &resp)
{
    if(Controller::handleResponse(resp) == true && AppController::validateResponse(req, resp) == true)
      {
            switch(m_currentOption)
            {
                 case Option::INIT:
                  exeViewManger->setExecuteStatus("读取默认校准曲线成功！");
                 m_modelPtr = (SettingDefaultInformationDataModel*)AppContext::get("settingdefaultinformationdatamodel");
                 SettingDefaultInformationConverter::parseCalibrationDefaultSettingInfo(resp, m_modelPtr);
                 SetChanged();
                 Notify(m_modelPtr);

                 break;
            case Option::SET_CALIBRATIONCURVENUMBER:
                AppController::handleResponse(resp);
                exeViewManger->setExecuteStatus("设置选择曲线指令下发成功！");

                break;
    }
    }else
            {
                exeViewManger->setExecuteStatus("响应错误！");
    }
}
