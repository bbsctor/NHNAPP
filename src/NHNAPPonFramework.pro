QT += charts qml quick serialport sql
CONFIG += c++11

SOURCES += main.cpp \
    framework/controller.cpp \
    framework/datamodel.cpp \
    framework/operation.cpp \
    framework/protocoldef.cpp \
    system/communication/communicationserver.cpp \
    system/controller/appcontroller.cpp \
    system/dataModel/meansurecontroldatamodel.cpp \
    framework/observe/qobservable.cpp \
    system/context/appcontext.cpp \
    framework/database/dbhelper.cpp \
    framework/database/dbmanager.cpp \
    system/database/appdbmanager.cpp \
    framework/database/sqlquerymodel.cpp \
    system/modelProtocolConvert/systemsettingconverter.cpp \
    system/dataModel/setting/periodsettingdatamodel.cpp \
    system/controller/setting/periodsettingcontroller.cpp \
    system/dataModel/setting/parametersettingdatamodel.cpp \
    system/dataModel/setting/systemsettingdatamodel.cpp \
    system/controller/setting/parametersettingcontroller.cpp \
    system/controller/setting/systemsettingcontroller.cpp \
    system/viewManager/setting/parametersettingviewmanager.cpp \
    system/viewManager/setting/periodsettingviewmanager.cpp \
    system/viewManager/setting/systemsettingviewmanager.cpp \
    system/viewManager/query/historydataqueryviewmanager.cpp \
    system/viewManager/query/historygraphqueryviewmanager.cpp \
    system/database/alertinfodbhelper.cpp \
    system/viewManager/query/alertinfoqueryviewmanager.cpp \
    system/viewManager/query/basequeryviewmanager.cpp \
    system/viewManager/query/loginfoqueryviewmanager.cpp \
    system/database/loginfodbhelper.cpp \
    framework/crc/JQChecksum.cpp \
    system/authority/userstate.cpp \
    system/protocol/stprotocol1.cpp \
    system/viewManager/maintain/systemmaintainviewmanager.cpp \
    system/controller/maintain/systemmaintaincontroller.cpp \
    system/viewManager/maintain/functiontestviewmanager.cpp \
    system/controller/maintain/functiontestcontroller.cpp \
    framework/viewManager/viewmanager.cpp \
    system/controller/query/manufactureinfocontroller.cpp \
    system/dataModel/query/manufactureinfodatamodel.cpp \
    system/viewManager/query/manufactureinfoviewmanager.cpp \
    system/dataModel/home/runninginfodatamodel.cpp \
    system/viewManager/home/runninginfoviewmanager.cpp \
    system/controller/home/runninginfocontroller.cpp \
    system/modelProtocolConvert/runninginfoconverter.cpp \
    system/protocol/stprotocol2.cpp \
    system/controller/home/currentvaluecontroller.cpp \
    system/dataModel/home/currentvaluedatamodel.cpp \
    system/modelProtocolConvert/currentvalueconverter.cpp \
    system/viewManager/home/valuedisplayviewmanager.cpp \
    system/controller/meansure/meansurecontroller.cpp \
    system/viewManager/meansure/meansureviewmanager.cpp \
    system/viewManager/setting/bcljzjsettingviewmanagerone.cpp \
    system/dataModel/setting/bcljzjsettingdatamodelone.cpp \
    system/controller/setting/bcljzjsettingonecontroller.cpp \
    system/controller/maintain/maintaindatacontroller.cpp \
    system/dataModel/maintain/calibrationcoefdatamodel.cpp \
    system/modelProtocolConvert/calibrationcoefconverter.cpp \
    system/context/pollproxy.cpp \
    system/viewManager/home/controlviewmanager.cpp \
    system/controller/home/homecontroller.cpp \
    system/viewManager/maintain/maintaindataviewmanager.cpp \
    system/database/historydatadbhelper.cpp \
    system/dataModel/warning/warningdatamodel.cpp \
    system/modelProtocolConvert/warningconverter.cpp \
    system/controller/warning/warningcontroller.cpp \
    system/viewManager/warning/warningviewmanager.cpp \
    system/dataModel/setting/settingdefaultinformationdatamodel.cpp \
    system/modelProtocolConvert/settingdefaultinformationconverter.cpp \
    system/dataModel/status/executestatusdatamodel.cpp \
    system/viewManager/status/executeviewmanager.cpp \
    system/communication/serveritem.cpp \
    system/context/workitem.cpp \
    system/communication/operateserialport.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    framework/controller.h \
    framework/datamodel.h \
    framework/operation.h \
    framework/protocoldef.h \
    system/controller/appcontroller.h \
    system/dataModel/meansurecontroldatamodel.h \
    framework/observe/qobservable.h \
    system/context/appcontext.h \
    framework/observe/qobserver.h \
    framework/database/dbhelper.h \
    framework/database/dbmanager.h \
    system/database/appdbmanager.h \
    framework/database/sqlquerymodel.h \
    system/dataModel/setting/periodsettingdatamodel.h \
    system/dataModel/setting/parametersettingdatamodel.h \
    system/dataModel/setting/systemsettingdatamodel.h \
    system/controller/setting/parametersettingcontroller.h \
    system/viewManager/setting/parametersettingviewmanager.h \
    system/viewManager/setting/periodsettingviewmanager.h \
    system/viewManager/setting/systemsettingviewmanager.h \
    system/viewManager/query/historydataqueryviewmanager.h \
    system/viewManager/query/historygraphqueryviewmanager.h \
    system/database/alertinfodbhelper.h \
    system/viewManager/query/basequeryviewmanager.h \
    system/viewManager/query/alertinfoqueryviewmanager.h \
    system/viewManager/query/loginfoqueryviewmanager.h \
    system/database/loginfodbhelper.h \
    framework/crc/JQChecksum.h \
    system/authority/userstate.h \
    system/protocol/stprotocol1.h \
    system/controller/setting/periodsettingcontroller.h \
    system/controller/maintain/systemmaintaincontroller.h \
    system/viewManager/maintain/systemmaintainviewmanager.h \
    system/viewManager/maintain/functiontestviewmanager.h \
    system/controller/maintain/functiontestcontroller.h \
    framework/viewManager/viewmanager.h \
    system/viewManager/query/manufactureinfoviewmanager.h \
    system/controller/query/manufactureinfocontroller.h \
    system/dataModel/query/manufactureinfodatamodel.h \
    system/dataModel/home/runninginfodatamodel.h \
    system/viewManager/home/runninginfoviewmanager.h \
    system/controller/home/runninginfocontroller.h \
    system/protocol/stprotocol2.h \
    system/controller/home/currentvaluecontroller.h \
    system/dataModel/home/currentvaluedatamodel.h \
    system/viewManager/home/valuedisplayviewmanager.h \
    system/viewManager/meansure/meansureviewmanager.h \
    system/viewManager/setting/bcljzjsettingviewmanagerone.h \
    system/dataModel/setting/bcljzjsettingdatamodelone.h \
    system/controller/setting/bcljzjsettingonecontroller.h \
    system/controller/maintain/maintaindatacontroller.h \
    system/dataModel/maintain/calibrationcoefdatamodel.h \
    system/context/pollproxy.h \
    system/viewManager/home/controlviewmanager.h \
    system/viewManager/maintain/maintaindataviewmanager.h \
    system/database/historydatadbhelper.h \
    system/modelProtocolConvert/calibrationcoefconverter.h \
    system/modelProtocolConvert/currentvalueconverter.h \
    system/modelProtocolConvert/runninginfoconverter.h \
    system/modelProtocolConvert/systemsettingconverter.h \
    system/dataModel/warning/warningdatamodel.h \
    system/modelProtocolConvert/warningconverter.h \
    system/controller/warning/warningcontroller.h \
    system/viewManager/warning/warningviewmanager.h \
    system/dataModel/setting/settingdefaultinformationdatamodel.h \
    system/modelProtocolConvert/settingdefaultinformationconverter.h \
    system/dataModel/status/executestatusdatamodel.h \
    system/viewManager/status/executeviewmanager.h \
    system/communication/serveritem.h \
    system/communication/communicationserver.h \
    system/context/workitem.h \
    system/communication/operateserialport.h \
    system/controller/meansure/meansurecontroller.h \
    system/controller/home/homecontroller.h \
    system/controller/setting/systemsettingcontroller.h

DISTFILES +=
