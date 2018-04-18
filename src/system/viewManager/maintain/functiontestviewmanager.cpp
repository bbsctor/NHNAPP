#include "functiontestviewmanager.h"
#include <QDebug>
#include "../../context/appcontext.h"

FunctionTestViewManager::FunctionTestViewManager()
{
    init();
}

void FunctionTestViewManager::injectBumbValve()
{
    m_controllerPtr->execute(FunctionTestController::Option::INJECTBUMBVALVE, NULL);
}

void FunctionTestViewManager::mixingBumb()
{
    m_controllerPtr->execute(FunctionTestController::Option::MIXINGBUMB, NULL);
}

void FunctionTestViewManager::dispelFan()
{
    m_controllerPtr->execute(FunctionTestController::Option::DISPELFAN, NULL);
}

void FunctionTestViewManager::boxFan()
{
    m_controllerPtr->execute(FunctionTestController::Option::BOXFAN, NULL);
}

void FunctionTestViewManager::inWater()
{
    m_controllerPtr->execute(FunctionTestController::Option::INWATER, NULL);
}

void FunctionTestViewManager::inZero()
{
    m_controllerPtr->execute(FunctionTestController::Option::INZERO, NULL);
}

void FunctionTestViewManager::inStdSample()
{
    m_controllerPtr->execute(FunctionTestController::Option::INSTDSAMPLE, NULL);
}

void FunctionTestViewManager::inReagentThree()
{
    m_controllerPtr->execute(FunctionTestController::Option::INREAGENTTHREE, NULL);
}

void FunctionTestViewManager::inReagentFour()
{
    m_controllerPtr->execute(FunctionTestController::Option::INREAGENTFOUR, NULL);
}

void FunctionTestViewManager::inReagentFive()
{
    m_controllerPtr->execute(FunctionTestController::Option::INREAGENTFIVE, NULL);
}

//void FunctionTestViewManager::inWaterSample()
//{
//    m_controllerPtr->execute(FunctionTestController::Option::IN_WATERSAMPLE, NULL);
//}

//void FunctionTestViewManager::inZeroSample()
//{
//    m_controllerPtr->execute(FunctionTestController::Option::IN_ZEROSAMPLE, NULL);
//}

//void FunctionTestViewManager::inStdOne()
//{
//    m_controllerPtr->execute(FunctionTestController::Option::IN_STDONE, NULL);
//}

//void FunctionTestViewManager::inStdTwo()
//{
//    m_controllerPtr->execute(FunctionTestController::Option::IN_STDTWO, NULL);
//}

//void FunctionTestViewManager::inTestOne()
//{
//    m_controllerPtr->execute(FunctionTestController::Option::IN_TESTONE, NULL);
//}

//void FunctionTestViewManager::inTestTwo()
//{
//    m_controllerPtr->execute(FunctionTestController::Option::IN_TESTTWO, NULL);
//}

//void FunctionTestViewManager::bubble()
//{
//    m_controllerPtr->execute(FunctionTestController::Option::BUBBLE, NULL);
//}

//void FunctionTestViewManager::heater()
//{
//    m_controllerPtr->execute(FunctionTestController::Option::HEATER, NULL);
//}

//void FunctionTestViewManager::initFill()
//{
//    m_controllerPtr->execute(FunctionTestController::Option::INITFILL, NULL);
//}

//void FunctionTestViewManager::washMeansureTube()
//{
//    m_controllerPtr->execute(FunctionTestController::Option::WASH_MEANSURETUBE, NULL);
//}

//void FunctionTestViewManager::washDispelJar()
//{
//    m_controllerPtr->execute(FunctionTestController::Option::WASH_DISPELJAR, NULL);
//}

void FunctionTestViewManager::init()
{
    m_controllerPtr = (FunctionTestController*)AppContext::get("functionTestController");
    if (m_controllerPtr == NULL)
    {
        qWarning() << "FunctionTestViewManager init failed!";
    }
}
