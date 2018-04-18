#ifndef BCLJZJSETTINGVIEWMANAGERONE_H
#define BCLJZJSETTINGVIEWMANAGERONE_H
#include "../../dataModel/setting/bcljzjsettingdatamodelone.h"
#include "../../../framework/viewManager/viewmanager.h"
#include "../../controller/setting/bcljzjsettingonecontroller.h"
#include "../../../framework/observe/qobserver.h"
#include"../../dataModel/setting/settingdefaultinformationdatamodel.h"

class BCLJZJSettingViewManagerOne : public ViewManager, public QObserver
{
    Q_OBJECT
    Q_PROPERTY(char megLockAble READ megLockAble WRITE setMegLockAble NOTIFY megLockAbleChanged)
    Q_PROPERTY(char washingAble READ washingAble WRITE setWashingAble NOTIFY washingAbleChanged)
    Q_PROPERTY(char bumbOnTime READ bumbOnTime WRITE setBumbOnTime NOTIFY bumbOnTimeChanged)
    Q_PROPERTY(char preHandlerAble READ preHandlerAble WRITE setPreHandlerAble NOTIFY preHandlerAbleChanged)
    Q_PROPERTY(ushort dilute READ dilute WRITE setDilute NOTIFY diluteChanged)
    Q_PROPERTY(char dispelTime READ dispelTime WRITE setDispelTime NOTIFY dispelTimeChanged)

    //曲线选择
    Q_PROPERTY(int selectCurveNumber READ selectCurveNumber WRITE setSelectCurveNumber NOTIFY selectCurveNumberChanged)

    //标样浓度
    Q_PROPERTY(QString sampleConcentration READ sampleConcentration WRITE setSampleConcentration NOTIFY SampleConcentrationChanged)
public:
    BCLJZJSettingViewManagerOne();
    Q_INVOKABLE void pushMegLockAble();
    Q_INVOKABLE void pushWashingAble();
    Q_INVOKABLE void pushBumbOnTime();
    Q_INVOKABLE void pushPreHandlerAble();
    Q_INVOKABLE void pushDilute();
    Q_INVOKABLE void pushDispelTime();
    Q_INVOKABLE void pushSampleConcentration();
    Q_INVOKABLE void pullSampleConcentration();
    //初始化选择曲线
    Q_INVOKABLE void loadDefault();
     void initDefaultValue();

//    void updateDefaultView(SettingDefaultInformationDataModel *pModel);
        //曲线选择
    Q_INVOKABLE void pushSelectCurveNumber();

    Q_INVOKABLE void pullMegLockAble();
    Q_INVOKABLE void pullWashingAble();
    Q_INVOKABLE void pullBumbOnTime();
    Q_INVOKABLE void pullPreHandlerAble();
    Q_INVOKABLE void pullDilute();
    Q_INVOKABLE void pullDispelTime();

    //曲线选择
    Q_INVOKABLE void pullSelectCurveNumber();

//    Q_INVOKABLE void initDefaultValue();
    void Update(QObservable *pObs, void *pArg = NULL);

    char megLockAble() const;

    char washingAble() const;

    char bumbOnTime() const;

    char preHandlerAble() const;

    ushort dilute() const;

    char dispelTime() const;

    int selectCurveNumber() const;

    QString sampleConcentration() const;   //增加标样浓度


public slots:

    void setMegLockAble(char megLockAble);

    void setWashingAble(char washingAble);

    void setBumbOnTime(char bumbOnTime);

    void setPreHandlerAble(char preHandlerAble);

    void setDilute(ushort dilute);

    void setDispelTime(char dispelTime);

    void setSelectCurveNumber(int selectCurveNumber);//增加曲线选择

    void setSampleConcentration(QString sampleConcentration);   //增加标样浓度


signals:

    void megLockAbleChanged(char megLockAble);

    void washingAbleChanged(char washingAble);

    void bumbOnTimeChanged(char bumbOnTime);

    void preHandlerAbleChanged(char preHandlerAble);

    void diluteChanged(ushort dilute);

    void dispelTimeChanged(char dispelTime);

    void selectCurveNumberChanged(int selectCurveNumber);//增加曲线选择


    void SampleConcentrationChanged(QString sampleConcentration);//增加标样浓度

private:
    void init();
    //void updateView(BCLJZJSettingDataModelOne* pModel);
    void updateDefaultView(SettingDefaultInformationDataModel *pModel);
    BCLJZJSettingDataModelOne* m_modelPtr;
    BCLJZJSettingOneController* m_controllerPtr;
    char m_megLockAble;
    char m_washingAble;
    char m_bumbOnTime;
    char m_preHandlerAble;
    ushort m_dilute;
    char m_dispelTime;
    int m_selectCurveNumber;//增加曲线选择
    QString m_sampleConcentration;  //增加标样浓度
};

#endif // BCLJZJSETTINGVIEWMANAGERONE_H
