#include "homecontroller.h"
#include "../../protocol/stprotocol2.h"
#include "../../controller/warning/warningcontroller.h"
#include "../../controller/home/runninginfocontroller.h"
#include "../../context/appcontext.h"
#include "../../dataModel/setting/settingdefaultinformationdatamodel.h"
#include  "../../controller/meansure/meansurecontroller.h"
#include "../../controller/maintain/systemmaintaincontroller.h"

HomeController::HomeController()
{


}

void HomeController::updateRunningInfo()
{
    qWarning() << "get running info!";
    RunningInfoController* controllerPtr = (RunningInfoController*)AppContext::get("runningInfoController");
    controllerPtr->execute(RunningInfoController::Option::GET_RUNNINGINFO, NULL);
}

void HomeController::updateWarningInfo()
{
    qWarning() << "get current warning value!";
    WarningController* controllerPtr = (WarningController*)AppContext::get("warningController");
    controllerPtr->execute(WarningController::Option::GET_WARNINGINFO, NULL);
}

void HomeController::updateLoop()
{
    updateRunningInfo();
    updateWarningInfo();
}

void HomeController::execute(HomeController::Option option, QString paras)
{
        switch(option)
        {
            case Option::URGENCYSTOP:
                WorkItem item(this, 0, paras);
                pollProxy->addWork(item);
                break;
        }
}

void HomeController::execute(int option, QString paras)
{
    QByteArray request=NULL;
        switch(option)
        {
            case 0:
                request=STProtocol2::getUrgencyStopRequest();
                m_currentOption = Option::URGENCYSTOP;
                break;
        }

        send(request);
}

bool HomeController::handleResponse(const QByteArray &resp)
{
        AppController::handleResponse(resp);
         exeViewManger->setExecuteStatus("紧急停止指令下发成功！");
         //AppController::handleResponse(resp);
}

bool HomeController::validate(const QByteArray &resp)
{

}

void HomeController::autoMeansureAndCalibrationStart()
{

    SettingDefaultInformationDataModel* pModel = (SettingDefaultInformationDataModel*) AppContext::get("settingdefaultinformationdatamodel");
    int mode = pModel->measureMode();
    int mInterval = pModel->autoMeasurePeriod();
    int cInterval = pModel->autoCalibrationPeriod();
    MeansureController* mControllerPtr =(MeansureController*)AppContext::get("meansureController");
    SystemMaintainController* cControllerPtr=(SystemMaintainController*)AppContext::get("systemMaintainController");

    if(mode == 0)
    {
        QString temp;
        QString mStr ="(" ;
        mStr.append(QString::number(mInterval));
        mStr.append(")");

        QString cStr ="(" ;
        cStr.append(QString::number(cInterval));
        cStr.append(")");

        if(mInterval > 0)
        {
              mControllerPtr->autoMeansureOn(mInterval * 60 * 1000);
              temp = "初始化启动自动测量成功！";
              temp.append(mStr);

        }
        else
        {
              temp = "自动测量默认参数读取异常！！";
              temp.append(mStr);
        }
        dbManager->insertLogInfo(temp);

        if(cInterval > 0)
        {
              cControllerPtr->periodCalibrationOn(cInterval * 24 * 60 * 60 * 1000);
              temp = "初始化启动周期校准成功！";
              temp.append(cStr);
        }
        else
        {
             temp = "周期校准默认参数读取异常！！！";
             temp.append(cStr);
        }
        dbManager->insertLogInfo(temp);
    }
}
