#include "bcljzjsettingviewmanagerone.h"
#include <QDebug>
#include "../../context/appcontext.h"
#include "../../controller/setting/bcljzjsettingonecontroller.h"
//#include "../../datamodel/setting/bcljzjsettingdatamodelone.h"
#include"../../dataModel/setting/settingdefaultinformationdatamodel.h"
#include <typeinfo>

BCLJZJSettingViewManagerOne::BCLJZJSettingViewManagerOne()
{
    BCLJZJSettingOneController* cptr = (BCLJZJSettingOneController*)AppContext::get("bcljzjSettingOneController");
    cptr->Attach(this);

    init();
}

void BCLJZJSettingViewManagerOne::pushMegLockAble()
{
    QString str;
    qWarning() << "set megLock able!";
    char i = m_modelPtr->megLockAble();
    if(i == 0x01)
    {
        str = "enable";
    }
    else
    {
        str = "disable";
    }
    m_controllerPtr->execute(BCLJZJSettingOneController::Option::SET_MEGLOCKABLE, str);
}

void BCLJZJSettingViewManagerOne::pushWashingAble()
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
    m_controllerPtr->execute(BCLJZJSettingOneController::Option::SET_WASHINGABLE, str);
}

void BCLJZJSettingViewManagerOne::pushBumbOnTime()
{
    qWarning() << "set bumb on time!";
    char i = m_modelPtr->bumbOnTime();

    m_controllerPtr->execute(BCLJZJSettingOneController::Option::SET_BUMBONTIME, QString::number(i));
}

void BCLJZJSettingViewManagerOne::pushPreHandlerAble()
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
    m_controllerPtr->execute(BCLJZJSettingOneController::Option::SET_PREHANDLERABLE, str);
}

void BCLJZJSettingViewManagerOne::pushDilute()
{
    qWarning() << "set dilute!";
    ushort i = m_modelPtr->dilute();

    m_controllerPtr->execute(BCLJZJSettingOneController::Option::SET_DILUTE, QString::number(i));
}

void BCLJZJSettingViewManagerOne::pushDispelTime()
{
    qWarning() << "set dispel time!";
    char i = m_modelPtr->dispelTime();

    m_controllerPtr->execute(BCLJZJSettingOneController::Option::SET_DISPELTIME, QString::number(i));
}

void BCLJZJSettingViewManagerOne::pullMegLockAble()
{

}

void BCLJZJSettingViewManagerOne::pullWashingAble()
{

}

void BCLJZJSettingViewManagerOne::pullBumbOnTime()
{

}

void BCLJZJSettingViewManagerOne::pullPreHandlerAble()
{

}

void BCLJZJSettingViewManagerOne::pullDilute()
{

}

void BCLJZJSettingViewManagerOne::pullDispelTime()
{

}

//void BCLJZJSettingViewManagerOne::initDefaultValue()
//{

//}


char BCLJZJSettingViewManagerOne::megLockAble() const
{
    return m_megLockAble;
}

char BCLJZJSettingViewManagerOne::washingAble() const
{
    return m_washingAble;
}

char BCLJZJSettingViewManagerOne::bumbOnTime() const
{
    return m_bumbOnTime;
}

char BCLJZJSettingViewManagerOne::preHandlerAble() const
{
    return m_preHandlerAble;
}

ushort BCLJZJSettingViewManagerOne::dilute() const
{
    return m_dilute;
}

char BCLJZJSettingViewManagerOne::dispelTime() const
{
    return m_dispelTime;
}

void BCLJZJSettingViewManagerOne::setMegLockAble(char megLockAble)
{   
    if (m_modelPtr->megLockAble()==megLockAble)
        return;

    m_modelPtr->setMegLockAble(megLockAble);
    emit megLockAbleChanged(megLockAble);
}

void BCLJZJSettingViewManagerOne::setWashingAble(char washingAble)
{
    if (m_modelPtr->washingAble()==washingAble)
        return;

    m_modelPtr->setWashingAble(washingAble);
    emit washingAbleChanged(washingAble);
}

void BCLJZJSettingViewManagerOne::setBumbOnTime(char bumbOnTime)
{
    if (m_modelPtr->bumbOnTime()==bumbOnTime)
        return;

    m_modelPtr->setBumbOnTime(bumbOnTime);
    emit bumbOnTimeChanged(bumbOnTime);
}

void BCLJZJSettingViewManagerOne::setPreHandlerAble(char preHandlerAble)
{
    if (m_modelPtr->preHandlerAble()==preHandlerAble)
        return;

    m_modelPtr->setPreHandlerAble(preHandlerAble);
    emit preHandlerAbleChanged(preHandlerAble);
}

void BCLJZJSettingViewManagerOne::setDilute(ushort dilute)
{
    if (m_modelPtr->dilute()==dilute)
        return;

    m_modelPtr->setDilute(dilute);
    emit diluteChanged(dilute);
}

void BCLJZJSettingViewManagerOne::setDispelTime(char dispelTime)
{
    if (m_modelPtr->dispelTime()==dispelTime)
        return;

    m_modelPtr->setDispelTime(dispelTime);
    emit dispelTimeChanged(dispelTime);
}

void BCLJZJSettingViewManagerOne::init()
{
    m_modelPtr = (BCLJZJSettingDataModelOne*)AppContext::get("bcljzjSettingDataModelOne");
    m_controllerPtr = (BCLJZJSettingOneController*)AppContext::get("bcljzjSettingOneController");
    if (m_modelPtr == NULL || m_controllerPtr == NULL)
    {
        qWarning() << "BCLJZJSettingViewManager init failed!";
    }
   loadDefault();
}

int BCLJZJSettingViewManagerOne::selectCurveNumber() const
{
    return m_selectCurveNumber;
}

void BCLJZJSettingViewManagerOne::setSelectCurveNumber(int selectCurveNumber)
{
    if(m_selectCurveNumber==selectCurveNumber)
        return;
    m_selectCurveNumber=selectCurveNumber;
    emit selectCurveNumberChanged(selectCurveNumber);
}

void BCLJZJSettingViewManagerOne::pushSelectCurveNumber()
{
    qWarning() << "set selectCurveNumber!";
//    int i = m_modelPtr->calibrationCurveNumber();
    if(m_selectCurveNumber > -1 && m_selectCurveNumber < 5)
    {
        int i=m_selectCurveNumber;
        m_controllerPtr->execute(BCLJZJSettingOneController::Option::SET_CALIBRATIONCURVENUMBER, QString::number(i+1));
    }


}
void BCLJZJSettingViewManagerOne::pullSelectCurveNumber()
{

}

void BCLJZJSettingViewManagerOne::Update(QObservable *pObs, void *pArg)
{
    SettingDefaultInformationDataModel* pContent = static_cast<SettingDefaultInformationDataModel*>(pArg);
    // 观察目标
    if(dynamic_cast <BCLJZJSettingOneController*>(pObs))
    {
         updateDefaultView(pContent);
    }
}

void BCLJZJSettingViewManagerOne::updateDefaultView(SettingDefaultInformationDataModel *pModel)
{
  uchar i=pModel->currentSelectCurve();
  setSelectCurveNumber(i-1);
}

//设置标样浓度值
QString BCLJZJSettingViewManagerOne::sampleConcentration() const
{
    return m_sampleConcentration;
}
void BCLJZJSettingViewManagerOne::setSampleConcentration(QString sampleConcentration)
{
//    if(m_sampleConcentration==sampleConcentration)
//        return;
    m_sampleConcentration=sampleConcentration;
}
void BCLJZJSettingViewManagerOne::pushSampleConcentration()
{
    int slc=m_sampleConcentration.toInt();
    m_controllerPtr->execute(BCLJZJSettingOneController::Option::SET_SAMPLECONCENTRATION,QString::number(slc));
}
void BCLJZJSettingViewManagerOne::pullSampleConcentration()
{

}
void BCLJZJSettingViewManagerOne::loadDefault()
{
    BCLJZJSettingViewManagerOne::initDefaultValue();
}
void BCLJZJSettingViewManagerOne::initDefaultValue()
{
    m_controllerPtr->execute(BCLJZJSettingOneController::Option::INIT,NULL);
}
