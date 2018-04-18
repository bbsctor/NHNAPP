import QtQuick 2.7
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.0
import ViewManager 1.0
import "../../common/button"

Rectangle {
    id:systemMaintainBlock
    color:"light grey"

    Grid {
        id: grid
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        spacing: 25
        rows: 3
        columns: 4

        ContentButton {
            id: button1

            text: qsTr("校准")
        }

        ContentButton {
            id: button2

            text: qsTr("初始化")
        }

        ContentButton {
            id: button3

            text: qsTr("除气泡")
        }

        ContentButton {
            id: button4

            text: qsTr("清洗比色皿")
        }

        ContentButton {
            id: button5
//            pointSize: 12
            text: qsTr("试剂清洗比色皿")
        }

        ContentButton {
            id: button6

            text: qsTr("结束处理")
        }

        ContentButton {
            id: button7

            text: qsTr("注射泵零点检测")
        }

//        ContentButton {
//            id: button9

//            text: qsTr("查询状态")
//        }

        ContentButton {
            id: button10

            text: qsTr("零点校准")
        }

        ContentButton {
            id: button11

            text: qsTr("量程校准")
        }
    }

//    MaintainDataViewManager{
//        id:maintainDataViewManager
//    }

    SystemMaintainViewManager
    {
        id:viewManager
    }


    Connections {
        target: button1
        onClicked:{
            viewManager.calibration();
            //timer.running = true;
        }
    }

//    Timer
//    {
//        id:timer
//        interval: 5000; running: false; repeat: false
//        onTriggered:tabs.updateCalibrationCoef();
//    }


    Connections {
        target: button2
        onClicked:viewManager.initial();
    }

    Connections {
        target: button3
        onClicked: viewManager.cleanBubble();
    }

    Connections {
        target: button4
        onClicked:viewManager.washCuvette();
    }

    Connections {
        target: button5
        onClicked:viewManager.reagentWashCuvette();
    }

    Connections {
        target: button6
        onClicked:viewManager.finishDispose();
    }

    Connections {
        target: button7
        onClicked:viewManager.zeroMeansure();
    }

    Connections {
        target: button9
        onClicked: viewManager.searchStatus();
    }

    Connections {
        target: button10
        onClicked: viewManager.zeroCalibration();
    }

    Connections {
        target: button11
        onClicked: viewManager.spanCalibration();
    }
}
