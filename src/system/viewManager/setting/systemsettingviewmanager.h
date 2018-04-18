#ifndef SYSTEMSETTINGVIEWMANAGER_H
#define SYSTEMSETTINGVIEWMANAGER_H
#include "../../dataModel/setting/systemsettingdatamodel.h"
#include "../../../framework/viewManager/viewmanager.h"
#include "../../controller/setting/systemsettingcontroller.h"
#include "../../../framework/observe/qobserver.h"

class SystemSettingViewManager : public ViewManager,QObserver
{
    Q_OBJECT
    Q_PROPERTY(QString sysDate READ sysDate WRITE setSysDate NOTIFY sysDateChanged)
    Q_PROPERTY(QString sysTime READ sysTime WRITE setSysTime NOTIFY sysTimeChanged)
    Q_PROPERTY(QString alertUpper READ alertUpper WRITE setAlertUpper NOTIFY alertUpperChanged)
    Q_PROPERTY(QString alertLower READ alertLower WRITE setAlertLower NOTIFY alertLowerChanged)
    Q_PROPERTY(char fourTo20Enable READ fourTo20Enable WRITE setFourTo20Enable NOTIFY fourTo20EnableChanged)
    Q_PROPERTY(char  RS485Enable READ RS485Enable WRITE setRS485Enable NOTIFY RS485EnableChanged)
    Q_PROPERTY(uchar  slaveAddress READ slaveAddress  WRITE setSlaveAddress NOTIFY slaveAddressChanged)
public:
    SystemSettingViewManager();
    Q_INVOKABLE void loadDefault();
    Q_INVOKABLE void pushSystemDate();
    Q_INVOKABLE void pushSystemTime();
    Q_INVOKABLE void pullSystemDate();
    Q_INVOKABLE void pullSystemTime();
    Q_INVOKABLE void initDefaultValue();
    //报警上下限
    Q_INVOKABLE void setAlertUpperLowZone(QString zone);
    Q_INVOKABLE void pushAlertUpperLowZone();

        //4-20mA  RS485
    Q_INVOKABLE void pushFourTo20Enable();
//    Q_INVOKABLE void setFourTo20Enable(char fourTo20Enable);
    Q_INVOKABLE void pushRS485Enable();
//    Q_INVOKABLE void setRS485Enable(char RS485Enable);

    //从机地址设置
    Q_INVOKABLE void pushSlaveAddress();
    QString sysDate() const;
    void Update(QObservable *pObs, void *pArg = NULL);
    QString sysTime() const;

    QString alertUpper() const
    {
        return m_alertUpper;
    }

    QString alertLower() const
    {
        return m_alertLower;
    }
char fourTo20Enable() const
{
    return m_fourTo20Enable;
}

    char RS485Enable() const
    {
        return m_RS485Enable;
    }

    uchar slaveAddress() const
    {
        return m_slaveAddress;
    }

public slots:
    void setSysDate(QString sysDate);

    void setSysTime(QString sysTime);

    void setAlertUpper(QString alertUpper)
    {
        if (m_alertUpper == alertUpper)
            return;

        m_alertUpper = alertUpper;
        emit alertUpperChanged(alertUpper);
    }

    void setAlertLower(QString alertLower)
    {
        if (m_alertLower == alertLower)
            return;

        m_alertLower = alertLower;
        emit alertLowerChanged(alertLower);
    }

    void setFourTo20Enable(char fourTo20Enable)
    {
        if (m_fourTo20Enable == fourTo20Enable)
            return;

        m_fourTo20Enable = fourTo20Enable;
        emit fourTo20EnableChanged(fourTo20Enable);
    }

    void setRS485Enable(char RS485Enable)
    {
        if (m_RS485Enable == RS485Enable)
            return;

        m_RS485Enable = RS485Enable;
        emit RS485EnableChanged(RS485Enable);
    }

    void setSlaveAddress(uchar slaveAddress)
    {
        if (m_slaveAddress == slaveAddress)
            return;

        m_slaveAddress = slaveAddress;
        emit slaveAddressChanged(slaveAddress);
    }

signals:
    void sysDateChanged(QString sysDate);

    void sysTimeChanged(QString sysTime);

    void alertUpperChanged(QString alertUpper);

    void alertLowerChanged(QString alertLower);

    void fourTo20EnableChanged(char fourTo20Enable);

    void RS485EnableChanged(char  RS485Enable);

    void slaveAddressChanged(uchar slaveAddress);

private:
    void init();
    void updateViewDateTime(SystemSettingDataModel* pModel);
    void updateDefaultView(SettingDefaultInformationDataModel *pModel);
    QString genFormatableDateTime(SystemSettingDataModel* pModel);
    SystemSettingDataModel* m_modelPtr;
    SystemSettingController* m_controllerPtr;
    QString m_sysDate;
    QString m_sysTime;
      //报警上下限
    QString m_alertZone;

    //4-20mA  RS485
    //char m_4to20mAEnable
    char m_fourTo20Enable;
    char m_RS485Enable;

    QString m_alertUpper;
    QString m_alertLower;
    uchar m_slaveAddress;
};

#endif // SYSTEMSETTINGVIEWMANAGER_H
