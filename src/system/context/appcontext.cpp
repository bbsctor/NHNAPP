#include "appcontext.h"
#include "../controller/meansure/meansurecontroller.h"
#include "../controller/setting/systemsettingcontroller.h"
#include "../controller/setting/periodsettingcontroller.h"
#include "../controller/maintain/systemmaintaincontroller.h"
#include "../controller/maintain/functiontestcontroller.h"
#include "../controller/home/runninginfocontroller.h"
#include "../controller/home/currentvaluecontroller.h"
#include "../controller/setting/bcljzjsettingonecontroller.h"
#include "../controller/maintain/maintaindatacontroller.h"
#include "../controller/home/homecontroller.h"
#include "../dataModel/meansurecontroldatamodel.h"
#include "../dataModel/setting/systemsettingdatamodel.h"
#include "../dataModel/setting/periodsettingdatamodel.h"
#include "../dataModel/home/runninginfodatamodel.h"
#include "../dataModel/home/currentvaluedatamodel.h"
#include "../dataModel/setting/bcljzjsettingdatamodelone.h"
#include "../dataModel/maintain/calibrationcoefdatamodel.h"
#include "../database/historydatadbhelper.h"
#include "../database/appdbmanager.h"
#include "../authority/userstate.h"
#include"../dataModel/warning/warningdatamodel.h"
#include"../controller/warning/warningcontroller.h"

#include"../controller/setting/parametersettingcontroller.h"
#include"../dataModel/setting/parametersettingdatamodel.h"
#include"../dataModel/setting/periodsettingdatamodel.h"
#include"../controller/setting/periodsettingcontroller.h"
#include"../dataModel/setting/systemsettingdatamodel.h"
#include"../controller/setting/systemsettingcontroller.h"

#include"../dataModel/setting/settingdefaultinformationdatamodel.h"
#include "../dataModel/status/executestatusdatamodel.h"


QMap<QString, void*> AppContext::map;
AppContext::AppContext(QObject *parent) : QObject(parent)
{

}

bool AppContext::set(QString name, void* obj)
{
    map.insert(name, obj);
    return true;
}

void* AppContext::get(QString name)
{
    return map.value(name);
}

bool AppContext::initDataModel()
{
    set("systemSettingDataModel", new SystemSettingDataModel());
    set("periodSettingDataModel", new PeriodSettingDataModel());
    set("runningInfoDataModel", new RunningInfoDataModel());
    set("currentValueDataModel", new CurrentValueDataModel());
    set("bcljzjSettingDataModelOne", new BCLJZJSettingDataModelOne());
    set("parameterSettingDataModel",new ParameterSettingDataModel());
    set("periodSettingDataModel",new PeriodSettingDataModel());
    set("maintainDataDataModel", new MaintainDataDataModel());
    set("systemSettingDataModel",new SystemSettingDataModel());
    set("meansureControlDataModel", new MeansureControlDataModel());
    set("warningDataModel",new WarningDataModel());
    set("settingdefaultinformationdatamodel",new SettingDefaultInformationDataModel());
    set("executeResultDataModel",new ExecuteStatusDataModel());
}

bool AppContext::initController()
{
    set("appDBManager", new AppDBManager());

    set("systemSettingController", new SystemSettingController());
    set("periodSettingController", new PeriodSettingController());
    set("systemMaintainController", new SystemMaintainController());
    set("functionTestController", new FunctionTestController());
    set("runningInfoController", new RunningInfoController());
    set("homeController", new HomeController());
    set("currentValueController", new CurrentValueController());

    set("bcljzjSettingOneController", new BCLJZJSettingOneController());
    set("parameterSettingController",new ParameterSettingController());
    set("periodSettingController",new PeriodSettingController());
    set("maintainDataController", new MaintainDataController());
    set("systemSettingController",new SystemSettingController());
    set("meansureController", new MeansureController());
    set("warningController",new WarningController());
}
