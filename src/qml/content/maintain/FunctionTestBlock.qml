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
            id: button
//            pointSize: 12
            text: qsTr("泵阀初始化")
        }

//        ContentButton {
//            id: button1
//            text: qsTr("搅拌泵")
//        }

        ContentButton {
            id: button2
            text: qsTr("消解管风扇")
        }

        ContentButton {
            id: button3
            text: qsTr("机柜风扇")
        }

        ContentButton {
            id: button4
            text: qsTr("进水样")
        }

        ContentButton {
            id: button5
            text: qsTr("进零样")
        }

        ContentButton {
            id: button6
            text: qsTr("进标样")
        }

        ContentButton {
            id: button7
            text: qsTr("进试剂3")
        }

        ContentButton {
            id: button8
            text: qsTr("进试剂4")
        }

        ContentButton {
            id: button9
            text: qsTr("进试剂5")
        }
    }
    FunctionTestViewManager{
        id:viewManager
    }

    Connections {
        target: button
        onClicked: viewManager.injectBumbValve()
    }

    Connections {
        target: button1
        onClicked: viewManager.mixingBumb()
    }

    Connections {
        target: button2
        onClicked: viewManager.dispelFan()
    }

    Connections {
        target: button3
        onClicked:viewManager.boxFan()
    }

    Connections {
        target: button4
        onClicked:viewManager.inWater()
    }

    Connections {
        target: button5
        onClicked: viewManager.inZero()
    }

    Connections {
        target: button6
        onClicked: viewManager.inStdSample()
    }

    Connections {
        target: button7
        onClicked: viewManager.inReagentThree()
    }

    Connections {
        target: button8
        onClicked: viewManager.inReagentFour()
    }

    Connections {
        target: button9
        onClicked: viewManager.inReagentFive()
    }
}
