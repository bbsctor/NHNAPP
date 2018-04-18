#ifndef PARAMETERSETTINGVIEWMANAGER_H
#define PARAMETERSETTINGVIEWMANAGER_H
#include "../../dataModel/setting/parametersettingdatamodel.h"
#include "../../../framework/viewManager/viewmanager.h"
#include "../../controller/setting/parametersettingcontroller.h"
#include "../../../framework/observe/qobserver.h"
#include"../../dataModel/setting/settingdefaultinformationdatamodel.h"

class ParameterSettingViewManager : public ViewManager,QObserver
{
    Q_OBJECT
    Q_PROPERTY(QString sampleConcentration READ sampleConcentration WRITE setSampleConcentration NOTIFY SampleConcentrationChanged)

    Q_PROPERTY(char megLockAble READ megLockAble WRITE setMegLockAble NOTIFY megLockAbleChanged)
    Q_PROPERTY(char washingAble READ washingAble WRITE setWashingAble NOTIFY washingAbleChanged)
    //    Q_PROPERTY(char bumbOnTime READ bumbOnTime WRITE setBumbOnTime NOTIFY bumbOnTimeChanged)
    Q_PROPERTY(char preHandlerAble READ preHandlerAble WRITE setPreHandlerAble NOTIFY preHandlerAbleChanged)
    Q_PROPERTY(uchar dispelTime READ dispelTime WRITE setDispelTime NOTIFY dispelTimeChanged)
    Q_PROPERTY(uchar bumbOnTime READ bumbOnTime WRITE setBumbOnTime NOTIFY bumbOnTimeChanged)
public:
    ParameterSettingViewManager();
    Q_INVOKABLE void loadDefault();
    Q_INVOKABLE void pushSampleConcentration();
    Q_INVOKABLE void pullSampleConcentration();
    Q_INVOKABLE void initDefaultValue();

    //BCL移植过来的功能
    Q_INVOKABLE void pushMegLockAble();
    Q_INVOKABLE void pushWashingAble();
    Q_INVOKABLE void pushPreHandlerAble();
    Q_INVOKABLE void pullMegLockAble();
    Q_INVOKABLE void pullWashingAble();
    Q_INVOKABLE void pullPreHandlerAble();

    Q_INVOKABLE void pushDispelTime();
    Q_INVOKABLE void pullDispelTime();

    Q_INVOKABLE void pushBumbOnTime();
    Q_INVOKABLE void pullBumbOnTime();
    void Update(QObservable *pObs, void *pArg = NULL);

    QString sampleConcentration() const;
    void setSampleConcentration(const QString &sampleConcentration);

    //BCL移植过来
    char megLockAble() const;
    char washingAble() const;
    char preHandlerAble() const;

//    char dispelTime() const;
//    char bumbOnTime() const;

    uchar dispelTime() const
    {
        return m_dispelTime;
    }

    uchar bumbOnTime() const
    {
        return m_bumbOnTime;
    }

public slots:
    //BCL移植过来
    void setMegLockAble(char megLockAble);
    void setWashingAble(char washingAble);
    void setPreHandlerAble(char preHandlerAble);
//    void setDispelTime(char dispelTime);
//    void setBumbOnTime(char bumbOnTime);

    void setDispelTime(uchar dispelTime)
    {
        if (m_dispelTime == dispelTime)
            return;

        m_dispelTime = dispelTime;
        emit dispelTimeChanged(dispelTime);
    }

    void setBumbOnTime(uchar bumbOnTime)
    {
        if (m_bumbOnTime == bumbOnTime)
            return;

        m_bumbOnTime = bumbOnTime;
        emit bumbOnTimeChanged(bumbOnTime);
    }

signals:

    void SampleConcentrationChanged(QString sampleConcentration);


    //BCL移植过来
    void megLockAbleChanged(char megLockAble);
    void washingAbleChanged(char washingAble);
    void preHandlerAbleChanged(char preHandlerAble);

//    void dispelTimeChanged(char dispelTime);
    //    void bumbOnTimeChanged(char bumbOnTime);
    void dispelTimeChanged(uchar dispelTime);

    void bumbOnTimeChanged(uchar bumbOnTime);

private:
    void init();
    ParameterSettingDataModel* m_modelPtr;
    ParameterSettingController* m_controllerPtr;
    QString m_sampleConcentration;
    //BCL移植过来
    void updateView( ParameterSettingDataModel* pModel);
    void updateDefaultView(SettingDefaultInformationDataModel *pModel);
    char m_megLockAble;
    char m_washingAble;
    char m_preHandlerAble;

//    char m_dispelTime;
//    char m_bumbOnTime;
//    uchar m_dispelTime;
    //    uchar m_bumbOnTime;
    uchar m_dispelTime;
    uchar m_bumbOnTime;
};

#endif // PARAMETERSETTINGVIEWMANAGER_H
