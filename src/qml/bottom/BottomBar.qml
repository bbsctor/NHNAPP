import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import ViewManager 1.0
Rectangle {
    id: rectangle
    RowLayout {
        id: rowLayout

        anchors.top: parent
        width:parent.width
        Text {
            id: text1
            anchors.top: parent
            width:parent.width/3
            height:parent.height
            text:viewManger.executeStatus
            font.pixelSize: 18
        }
        Text {
            id: text2
            anchors.top: parent
            width:parent.width/3
            height:parent.height
            text:viewManger.autoMeansure
            font.pixelSize: 18
        }
        Text {
            id: text3
            anchors.top: parent
            width:parent.width/3
            height:parent.height
            text:viewManger.periodCalibration
            font.pixelSize: 18
        }
        ExecuteViewManager{
            id:viewManger
        }
    }

}
