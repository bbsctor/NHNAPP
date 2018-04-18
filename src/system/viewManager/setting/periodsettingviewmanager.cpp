#include "periodsettingviewmanager.h"
#include <QDebug>
#include "../../context/appcontext.h"
#include "../../context/pollproxy.h"
#include <QTimer>
#include  "../../controller/meansure/meansurecontroller.h"
#include  "../../controller/home/runninginfocontroller.h"
#include"../../controller/maintain/systemmaintaincontroller.h"
#include "../../dataModel/setting/settingdefaultinformationdatamodel.h"
PeriodSettingViewManager::PeriodSettingViewManager()
{
    PeriodSettingController* cptr = (PeriodSettingController*)AppContext::get("periodSettingController");
    cptr->Attach(this);
    init();
}

void PeriodSettingViewManager::loadDefault()
{
     PeriodSettingViewManager::initDefaultValue();
}

void PeriodSettingViewManager::pushCalibrationPeriod()
{
    m_controllerPtr->execute(PeriodSettingController::Option::SET_CALIBRATIONPERIOD,QString::number(m_calibrationPeriod));
}

void PeriodSettingViewManager::pullCalibrationPeriod()
{

}
void PeriodSettingViewManager::pushMeasureInterval()
{
    m_controllerPtr->execute(PeriodSettingController::Option::SET_MEASUREINTERVAL,QString::number(m_AutoMeasureTime));
}
void PeriodSettingViewManager::initDefaultValue()
{
    m_controllerPtr->execute(PeriodSettingController::Option::INIT, NULL);
    qWarning() << "view maneger init !";
}

void PeriodSettingViewManager::pushMeansureMode()
{  
    m_controllerPtr->execute(PeriodSettingController::Option::SET_MEANSUREMODE,QString::number( m_meansureMode));
}

void PeriodSettingViewManager::Update(QObservable *pObs, void *pArg)
{
    SettingDefaultInformationDataModel* pContent = static_cast<SettingDefaultInformationDataModel*>(pArg);
    // 观察目标
    if(dynamic_cast <PeriodSettingController*>(pObs))
    {
        updateDefaultView(pContent);
    }
}



void PeriodSettingViewManager::updateDefaultView(SettingDefaultInformationDataModel *pModel)
{

    char m_meansureMode1=pModel->measureMode();
    uchar m_calibrationPeriod1=pModel->autoCalibrationPeriod();
    uchar m_AutoMeasureTime1=pModel->autoMeasurePeriod();
    setCalibrationPeriod(m_calibrationPeriod1);
    setAutoMeasureTime(m_AutoMeasureTime1);
    setMeansureMode( m_meansureMode1);

}
void PeriodSettingViewManager::setMeansureMode(int meansureMode)
{
    m_meansureMode = meansureMode;
    jugeMeasureMode(m_meansureMode);
    emit meansureModeChanged(meansureMode);

}
void PeriodSettingViewManager::jugeMeasureMode(int modeIndex)
{
    switch (modeIndex) {
    case 0: PeriodSettingViewManager::measureModeAuto();
        break;
    case 1:  PeriodSettingViewManager::measureModeMannual();
        break;
    case 2: PeriodSettingViewManager::measureModeOnTime();
        break;
    default:
        break;
    }
}

//定时器判断
void PeriodSettingViewManager::measureModeAuto()
{
    int mInterval = m_AutoMeasureTime*60*1000;
    int cInterval = m_calibrationPeriod*24*60*60*1000;
    //int cInterval = m_calibrationPeriod*60*1000;
    if(m_AutoMeasureTime!=0 && m_meansureMode == 0)
    {
         m_controllerMeasurePtr->autoMeansureOn(mInterval);
    }

    if(m_calibrationPeriod!=0 && m_meansureMode == 0)
    { 
         //m_controllerSystemMaintain->periodCalibrationOn(cInterval + cInterval%mInterval + 20 * 60 * 1000);
        m_controllerSystemMaintain->periodCalibrationOn(cInterval);
    }
}
void PeriodSettingViewManager::measureModeMannual()
{
    m_controllerMeasurePtr->autoMeansureOff();
    m_controllerSystemMaintain->periodCalibrationOff();
}
void PeriodSettingViewManager::measureModeOnTime()
{
    m_controllerMeasurePtr->autoMeansureOff();
    m_controllerSystemMaintain->periodCalibrationOff();
}

void PeriodSettingViewManager::init()
{
    m_modelPtr = (PeriodSettingDataModel*)AppContext::get("periodSettingDataModel");
    m_controllerPtr = (PeriodSettingController*)AppContext::get("periodSettingController");
    m_controllerMeasurePtr =(MeansureController*)AppContext::get("meansureController");
    m_controllerSystemMaintain=(SystemMaintainController*)AppContext::get("systemMaintainController");
    if (m_modelPtr == NULL || m_controllerPtr == NULL)
    {
        qWarning() << "PeriodSettingViewManager init failed!";
    }
    PeriodSettingViewManager::initDefaultValue();
}

void PeriodSettingViewManager::setAutoMeasureTime(uchar AutoMeasureTime)
{
    if (m_AutoMeasureTime == AutoMeasureTime)
        return;

    m_AutoMeasureTime = AutoMeasureTime;
    if(m_meansureMode == 0)
    {
            m_controllerMeasurePtr->autoMeansureOn(m_AutoMeasureTime*60*1000);
            m_controllerSystemMaintain->periodCalibrationOn(m_calibrationPeriod*24*60*60*1000);
    }
    emit autoMeasureTimeChanged(AutoMeasureTime);
}



void PeriodSettingViewManager::setCalibrationPeriod(uchar calibrationPeriod)
{
    if (m_calibrationPeriod == calibrationPeriod)
        return;

    m_calibrationPeriod = calibrationPeriod;
    emit calibrationPeriodChanged(calibrationPeriod);
}
