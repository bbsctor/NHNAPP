#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QtWidgets/QApplication>
#include <QtQuick/QQuickView>
#include <QtCore/QDir>
#include <QtQml/QQmlEngine>

#include "system/viewManager/meansure/meansureviewmanager.h"
#include "system/viewManager/query/historydataqueryviewmanager.h"
#include "system/viewManager/query/historygraphqueryviewmanager.h"
#include "system/viewManager/query/alertinfoqueryviewmanager.h"
#include "system/viewManager/query/loginfoqueryviewmanager.h"
#include "system/viewManager/setting/systemsettingviewmanager.h"
#include "system/viewManager/setting/parametersettingviewmanager.h"
#include "system/viewManager/setting/periodsettingviewmanager.h"
#include "system/viewManager/setting/bcljzjsettingviewmanagerone.h"
#include "system/viewManager/maintain/systemmaintainviewmanager.h"
#include "system/viewManager/maintain/functiontestviewmanager.h"
#include "system/viewManager/home/runninginfoviewmanager.h"
#include "system/viewManager/home/valuedisplayviewmanager.h"
#include "system/viewManager/maintain/maintaindataviewmanager.h"
#include "system/viewManager/home/controlviewmanager.h"


#include "system/context/appcontext.h"
#include "system/database/appdbmanager.h"
#include "framework/database/sqlquerymodel.h"
#include "system/authority/userstate.h"
#include"system/viewManager/warning/warningviewmanager.h"
#include"system/viewManager/status/executeviewmanager.h"
#include "framework/serialPort/masterthread.h"
#include "system/dataModel/setting/settingdefaultinformationdatamodel.h"
#include  "system/controller/meansure/meansurecontroller.h"
#include "system/controller/maintain/systemmaintaincontroller.h"
#include "system/controller/home/homecontroller.h"

void registType();
void initDataModel();
void initController();
void initTimer();
void readDefaultPara();
void readCalibrationDefault();
void readParameterSettingDefault();
void readPeriodSettingDefault();
void readSystemSettingDefault();
void autoMeansureAndCalibrationStart();

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    registType();

    initDataModel();
    initController();

#ifdef Q_OS_WIN
    QString extraImportPath(QStringLiteral("%1/../../../../%2"));
#else
    QString extraImportPath(QStringLiteral("%1/../../../%2"));
#endif

    QQmlApplicationEngine engine;
    engine.addImportPath(extraImportPath.arg(QGuiApplication::applicationDirPath(),
                                                 QString::fromLatin1("qml")));
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    PollProxy* pollProxy = PollProxy::getInstance();
    pollProxy->startPoll();

    readDefaultPara();

    HomeController* hController = (HomeController*)AppContext::get("homeController");
    QTimer::singleShot(10000, hController,SLOT(autoMeansureAndCalibrationStart()));

    return app.exec();
}

void registType()
{
    qmlRegisterType<MeansureViewManager>("ViewManager", 1,0, "MeansureViewManager");
    qmlRegisterType<HistoryDataQueryViewManager>("ViewManager", 1,0, "HistoryDataQueryViewManager");
    qmlRegisterType<HistoryGraphQueryViewManager>("ViewManager", 1,0, "HistoryGraphQueryViewManager");
    qmlRegisterType<AlertInfoQueryViewManager>("ViewManager", 1,0, "AlertInfoQueryViewManager");
    qmlRegisterType<LogInfoQueryViewManager>("ViewManager", 1,0, "LogInfoQueryViewManager");
    qmlRegisterType<SystemSettingViewManager>("ViewManager", 1,0, "SystemSettingViewManager");
    qmlRegisterType<SqlQueryModel>("SqlModel", 1,0, "SqlQueryModel");
    qmlRegisterType<ParameterSettingViewManager>("ViewManager", 1,0, "ParameterSettingViewManager");
    qmlRegisterType<PeriodSettingViewManager>("ViewManager", 1,0, "PeriodSettingViewManager");
    qmlRegisterType<SystemMaintainViewManager>("ViewManager", 1,0, "SystemMaintainViewManager");
    qmlRegisterType<FunctionTestViewManager>("ViewManager", 1,0, "FunctionTestViewManager");
    qmlRegisterType<RunningInfoViewManager>("ViewManager", 1,0, "RunningInfoViewManager");
    qmlRegisterType<ValueDisplayViewManager>("ViewManager", 1,0, "ValueDisplayViewManager");
    qmlRegisterType<BCLJZJSettingViewManagerOne>("ViewManager", 1,0, "BCLJZJSettingViewManagerOne");
    qmlRegisterType<MaintainDataViewManager>("ViewManager", 1,0, "MaintainDataViewManager");
    qmlRegisterType<HomeControlViewManager>("ViewManager", 1,0, "HomeControlViewManager");
    qmlRegisterType<WarningViewManager>("ViewManager",1,0,"WarningViewManager");
    qmlRegisterType<ExecuteViewManager>("ViewManager",1,0,"ExecuteViewManager");

    qmlRegisterType<UserState>("Authority", 1,0, "UserState");
}

void initDataModel()
{
    AppContext::initDataModel();
}
void initController()
{
    AppContext::initController();
}

void readDefaultPara()
{
    //readCalibrationDefault();
    //readParameterSettingDefault();
    readPeriodSettingDefault();
    //readSystemSettingDefault();
}

void readCalibrationDefault()
{
    BCLJZJSettingOneController* m_controllerPtr = (BCLJZJSettingOneController*)AppContext::get("bcljzjSettingOneController");
    m_controllerPtr->execute(BCLJZJSettingOneController::Option::INIT,NULL);
}

void readParameterSettingDefault()
{

    ParameterSettingController* m_controllerPtr = (ParameterSettingController*)AppContext::get("parameterSettingController");
    m_controllerPtr->execute(ParameterSettingController::Option::INIT, NULL);
}

void readPeriodSettingDefault()
{
    PeriodSettingController* m_controllerPtr = (PeriodSettingController*)AppContext::get("periodSettingController");
    m_controllerPtr->execute(PeriodSettingController::Option::INIT, NULL);
}
void readSystemSettingDefault()
{
    SystemSettingController* m_controllerPtr = (SystemSettingController*)AppContext::get("systemSettingController");
    m_controllerPtr->execute(SystemSettingController::Option::INIT, NULL);
}

