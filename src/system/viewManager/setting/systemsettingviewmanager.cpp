#include "systemsettingviewmanager.h"
#include <QDebug>
#include "../../context/appcontext.h"
#include "../../controller/setting/systemsettingcontroller.h"
#include "../../modelProtocolConvert/systemsettingconverter.h"
#include "../../dataModel/setting/settingdefaultinformationdatamodel.h"

SystemSettingViewManager::SystemSettingViewManager()
{

    SystemSettingController* cptr = (SystemSettingController*)AppContext::get("systemSettingController");
    cptr->Attach(this);
    init();
}

void SystemSettingViewManager::loadDefault()
{
    SystemSettingViewManager::initDefaultValue();
}

void SystemSettingViewManager::pushSystemDate()
{
    qWarning() << "set system date!";
    QString dtStr= SystemSettingConverter::genFormatableDateTime(m_modelPtr);
    m_controllerPtr->execute(SystemSettingController::Option::SET_DEVICEDATETIME, dtStr);
}

void SystemSettingViewManager::pushSystemTime()
{
    qWarning() << "set system time!";
    pushSystemDate();
}

void SystemSettingViewManager::pullSystemDate()
{
    qWarning() << "read system date!";
    m_controllerPtr->execute(SystemSettingController::Option::GET_DEVICEDATETIME, NULL);
}

void SystemSettingViewManager::pullSystemTime()
{
    qWarning() << "read system time!";
    pullSystemDate();
}

void SystemSettingViewManager::initDefaultValue()
{
    m_controllerPtr->execute(SystemSettingController::Option::INIT, NULL);
}

QString SystemSettingViewManager::sysDate() const
{
    return m_modelPtr->systemDate();
}
void SystemSettingViewManager::Update(QObservable *pObs, void *pArg)
{
     SettingDefaultInformationDataModel* pContent = static_cast< SettingDefaultInformationDataModel*>(pArg);
    // 观察目标
    if(dynamic_cast <SystemSettingController*>(pObs))
    {
       updateDefaultView(pContent);
    }
}
void SystemSettingViewManager::updateDefaultView(SettingDefaultInformationDataModel *pModel)
{
  char i=pModel->_4to20mAStatus();
  setFourTo20Enable(i);
  char j=pModel->RS485Status();
  setRS485Enable(j);
  ushort k=pModel->alertUpper();
  setAlertUpper(QString::number(k));
  k=pModel->alertLower();
  setAlertLower(QString::number(k));
  uchar temp=pModel->slaveAddress();
  setSlaveAddress(temp);
}

QString SystemSettingViewManager::sysTime() const
{
    return m_modelPtr->systemTime();
}

void SystemSettingViewManager::setSysDate(QString sysDate)
{
    if (m_modelPtr->systemDate().compare(sysDate)==0)
        return;

    m_modelPtr->setSystemDate(sysDate);
    emit sysDateChanged(sysDate);
}

void SystemSettingViewManager::setSysTime(QString sysTime)
{
    if (m_modelPtr->systemTime().compare(sysTime)==0)
        return;

    m_modelPtr->setSystemTime(sysTime);
    emit sysTimeChanged(sysTime);

}

void SystemSettingViewManager::updateViewDateTime(SystemSettingDataModel* pModel)
{
    SystemSettingViewManager::setSysDate(pModel->systemDate());
    SystemSettingViewManager::setSysTime(pModel->systemTime());
    qWarning() << pModel->systemDate() << pModel-> systemTime();
}

void SystemSettingViewManager::init()
{
    m_modelPtr = (SystemSettingDataModel*)AppContext::get("systemSettingDataModel");
    m_controllerPtr = (SystemSettingController*)AppContext::get("systemSettingController");
    if (m_modelPtr == NULL || m_controllerPtr == NULL)
    {
        qWarning() << "SystemSettingViewManager init failed!";
    }

    SystemSettingViewManager::initDefaultValue();
}

    //报警上下限
void SystemSettingViewManager::setAlertUpperLowZone(QString zone)
{
    m_alertZone=zone;
}
    //报警上下限
void SystemSettingViewManager::pushAlertUpperLowZone()
{
    QString str;
    qWarning() << "set washing able!";
    char i = m_fourTo20Enable;
    if(i == 0x01)
    {
        str = "enable";
    }
    else
    {
        str = "disable";
    }
    m_controllerPtr->execute(SystemSettingController::Option::SET_ALEATUPPERLOWZONE,m_alertZone);
}

 //4-20mA  RS485
void SystemSettingViewManager::pushFourTo20Enable()
{
    QString str;
    qWarning() << "set washing able!";
    char i = m_fourTo20Enable;
    if(i == 0x01)
    {
        str = "enable";
    }
    else
    {
        str = "disable";
    }
    m_controllerPtr->execute(SystemSettingController::Option::SET_4TO20MAABLE,str);
}

//void SystemSettingViewManager::setRS485Enable(char RS485Enable)
//{
//    m_RS485Enable=RS485Enable;
//}
void SystemSettingViewManager::pushRS485Enable()
{
    QString str;
    qWarning() << "set washing able!";
    char i =m_RS485Enable;
    if(i == 0x01)
    {
        str = "enable";
    }
    else
    {
        str = "disable";
    }
    m_controllerPtr->execute(SystemSettingController::Option::SET_RS485ABLE,str);
}

//从站地址设置
void SystemSettingViewManager::pushSlaveAddress()
{
    qWarning() << "set Slave Address!";

    char i=m_slaveAddress;

    m_controllerPtr->execute(SystemSettingController::Option::SET_SLAVEADDRESS, QString::number(i));
}
