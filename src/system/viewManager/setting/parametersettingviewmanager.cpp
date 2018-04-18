#include "parametersettingviewmanager.h"
#include <QDebug>
#include "../../context/appcontext.h"
#include "../../controller/setting/parametersettingcontroller.h"
#include "../../datamodel/setting/parametersettingdatamodel.h"
#include"../../dataModel/setting/settingdefaultinformationdatamodel.h"
#include<typeinfo>
ParameterSettingViewManager::ParameterSettingViewManager()
{
//        ParameterSettingController* cptr = (ParameterSettingController*)AppContext::get("parameterSettingController");
//        cptr->Attach(this);
    init();
}

void ParameterSettingViewManager::loadDefault()
{
       ParameterSettingViewManager::initDefaultValue();
}
void ParameterSettingViewManager::init()
{
    m_modelPtr = (ParameterSettingDataModel*)AppContext::get("parameterSettingDataModel");
    m_controllerPtr = (ParameterSettingController*)AppContext::get("parameterSettingController");
    m_controllerPtr->Attach(this);
    if (m_modelPtr == NULL || m_controllerPtr == NULL)
    {
        qWarning() << "ParameterSettingViewManager init failed!";
    }
   ParameterSettingViewManager::initDefaultValue();
}

void ParameterSettingViewManager::pushSampleConcentration()
{

}

void ParameterSettingViewManager::pullSampleConcentration()
{

}

void ParameterSettingViewManager::initDefaultValue()
{
    qWarning() << "init default value!";
    m_controllerPtr->execute(ParameterSettingController::Option::INIT, NULL);
}

void ParameterSettingViewManager::Update(QObservable *pObs, void *pArg)
{
    SettingDefaultInformationDataModel* pContent = static_cast<SettingDefaultInformationDataModel*>(pArg);
    // 观察目标
    if(dynamic_cast <ParameterSettingController*>(pObs))
    {
        updateDefaultView(pContent);
    }
    else
    {

    }
}
void ParameterSettingViewManager::updateDefaultView(SettingDefaultInformationDataModel *pModel)
{
  uchar i=pModel->dispelTime();
  setDispelTime(i);
  uchar j=pModel->pumpStartTime();
  setBumbOnTime(j);
}
void ParameterSettingViewManager::updateView(ParameterSettingDataModel *pModel)
{
    char i=pModel->m_megLockAble;
    setMegLockAble(i);

    char j=pModel->m_preHandlerAble;
    setPreHandlerAble(j);

    char k=pModel->m_washingAble;
    setWashingAble(k);
}

QString ParameterSettingViewManager::sampleConcentration() const
{
    return m_sampleConcentration;
}

void ParameterSettingViewManager::setSampleConcentration(const QString &sampleConcentration)
{
    m_sampleConcentration = sampleConcentration;
}

//BCL移植过来
char ParameterSettingViewManager::megLockAble() const
{
    return m_megLockAble;
}

char ParameterSettingViewManager::washingAble() const
{
    return m_washingAble;
}

char ParameterSettingViewManager::preHandlerAble() const
{
    return m_preHandlerAble;
}

void ParameterSettingViewManager::setMegLockAble(char megLockAble)
{
    //    if (m_modelPtr->megLockAble()==megLockAble)
    if(m_megLockAble==megLockAble)
        return;
    m_megLockAble=megLockAble;
    emit megLockAbleChanged(megLockAble);
}

void ParameterSettingViewManager::setWashingAble(char washingAble)
{
    if (m_modelPtr->washingAble()==washingAble)
        return;

    m_modelPtr->setWashingAble(washingAble);
    emit washingAbleChanged(washingAble);
}

void ParameterSettingViewManager::setPreHandlerAble(char preHandlerAble)
{
    if (m_modelPtr->preHandlerAble()==preHandlerAble)
        return;

    m_modelPtr->setPreHandlerAble(preHandlerAble);
    emit preHandlerAbleChanged(preHandlerAble);
}
void ParameterSettingViewManager::pushMegLockAble()
{
    QString str;
    qWarning() << "set megLock able!";
    //    char i = m_modelPtr->megLockAble();
    char i = m_megLockAble;
    if(i == 0x01)
    {
        str = "enable";
    }
    else
    {
        str = "disable";
    }
    m_controllerPtr->execute(ParameterSettingController::Option::SET_MEGLOCKABLE, str);
}

void ParameterSettingViewManager::pushWashingAble()
{
    QString str;
    qWarning() << "set washing able!";
    char i = m_modelPtr->washingAble();
    if(i == 0x01)
    {
        str = "enable";
    }
    else
    {
        str = "disable";
    }
    m_controllerPtr->execute(ParameterSettingController::Option::SET_WASHINGABLE, str);
}


void ParameterSettingViewManager::pushPreHandlerAble()
{
    QString str;
    qWarning() << "set preHandler able!";
    char i = m_modelPtr->preHandlerAble();
    if(i == 0x01)
    {
        str = "enable";
    }
    else
    {
        str = "disable";
    }
    m_controllerPtr->execute(ParameterSettingController::Option::SET_PREHANDLERABLE, str);
}



void ParameterSettingViewManager::pullMegLockAble()
{

}

void ParameterSettingViewManager::pullWashingAble()
{

}



void ParameterSettingViewManager::pullPreHandlerAble()
{

}

//增加消解时间和采样泵时间

void ParameterSettingViewManager::pushBumbOnTime()
{
    qWarning() << "set bumb on time!";
//    char i = m_modelPtr->bumbOnTime();
    char i=m_bumbOnTime;

    m_controllerPtr->execute(ParameterSettingController::Option::SET_BUMBONTIME, QString::number(i));
}

void ParameterSettingViewManager::pushDispelTime()
{
    qWarning() << "set dispel time!";

//    char i=m_modelPtr->dispelTime();
    char i=m_dispelTime;
    m_controllerPtr->execute(ParameterSettingController::Option::SET_DISPELTIME, QString::number(i));
}
void ParameterSettingViewManager::pullBumbOnTime()
{

}
void ParameterSettingViewManager::pullDispelTime()
{

}
