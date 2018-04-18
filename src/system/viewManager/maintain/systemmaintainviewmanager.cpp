#include "systemmaintainviewmanager.h"
#include <QDebug>
#include "../../context/appcontext.h"

SystemMaintainViewManager::SystemMaintainViewManager()
{
    init();
}

void SystemMaintainViewManager::meansure()
{
    m_controllerPtr->execute(SystemMaintainController::Option::MEANSURE, NULL);
}

void SystemMaintainViewManager::calibration()
{
    m_controllerPtr->execute(SystemMaintainController::Option::CALIBRATION, NULL);
}

void SystemMaintainViewManager::initial()
{
    m_controllerPtr->execute(SystemMaintainController::Option::INIT, NULL);
}

void SystemMaintainViewManager::cleanBubble()
{
    m_controllerPtr->execute(SystemMaintainController::Option::CLEANBUBBLE, NULL);
}

void SystemMaintainViewManager::washCuvette()
{
    m_controllerPtr->execute(SystemMaintainController::Option::WASHCUVETTE, NULL);
}

void SystemMaintainViewManager::reagentWashCuvette()
{
    m_controllerPtr->execute(SystemMaintainController::Option::REVGENTWASHCUVETTE, NULL);
}

void SystemMaintainViewManager::finishDispose()
{
    m_controllerPtr->execute(SystemMaintainController::Option::FINISHDISPOSE, NULL);
}

void SystemMaintainViewManager::zeroMeansure()
{
    m_controllerPtr->execute(SystemMaintainController::Option::ZEROMEANSURE, NULL);
}

void SystemMaintainViewManager::urgencyStop()
{
    m_controllerPtr->execute(SystemMaintainController::Option::URGENCYSTOP, NULL);
}

void SystemMaintainViewManager::searchStatus()
{
    m_controllerPtr->execute(SystemMaintainController::Option::SEARCHSTATUS, NULL);
}

void SystemMaintainViewManager::zeroCalibration()
{
    m_controllerPtr->execute(SystemMaintainController::Option::ZEROCALIBRATION, NULL);
}

void SystemMaintainViewManager::spanCalibration()
{
    m_controllerPtr->execute(SystemMaintainController::Option::SPANCALIBRATION, NULL);
}

//void SystemMaintainViewManager::makeSample()
//{
//    m_controllerPtr->execute(SystemMaintainController::Option::MAKE_SAMPLE, NULL);
//}

//void SystemMaintainViewManager::zeroMeansure()
//{
//    m_controllerPtr->execute(SystemMaintainController::Option::ZEROMEANSURE, NULL);
//}

//void SystemMaintainViewManager::stdOneMeansure()
//{
//    m_controllerPtr->execute(SystemMaintainController::Option::STDONEMEANSURE, NULL);
//}

//void SystemMaintainViewManager::stdTwoMeansure()
//{
//    m_controllerPtr->execute(SystemMaintainController::Option::STDTWOMEANSURE, NULL);
//}

//void SystemMaintainViewManager::zeroSetting()
//{
//    m_controllerPtr->execute(SystemMaintainController::Option::ZEROSETTING, NULL);
//}

//void SystemMaintainViewManager::stdOneDemarcate()
//{
//    m_controllerPtr->execute(SystemMaintainController::Option::STDONEDEMARCATE, NULL);
//}

//void SystemMaintainViewManager::stdTwoDemarcate()
//{
//    m_controllerPtr->execute(SystemMaintainController::Option::STDTWODEMARCATE, NULL);
//}

//void SystemMaintainViewManager::calibration()
//{
//    m_controllerPtr->execute(SystemMaintainController::Option::CALIBRATION, NULL);
//}

//void SystemMaintainViewManager::washing()
//{
//    m_controllerPtr->execute(SystemMaintainController::Option::WASHING, NULL);
//}

//void SystemMaintainViewManager::flushing()
//{
//    m_controllerPtr->execute(SystemMaintainController::Option::FLUSHING, NULL);
//}

//void SystemMaintainViewManager::initFill()
//{
//    m_controllerPtr->execute(SystemMaintainController::Option::INITFILL, NULL);
//}

void SystemMaintainViewManager::init()
{
       m_controllerPtr = (SystemMaintainController*)AppContext::get("systemMaintainController");
       if (m_controllerPtr == NULL)
       {
           qWarning() << "SystemMaintainViewManager init failed!";
       }
}
