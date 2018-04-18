import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick.Window 2.2
import "qml/top"
import "qml/content"
import "qml/bottom"

ApplicationWindow {
    visible: true
    width: Screen.width
    height: Screen.height
    //width: 800
    //height: 600
    title: qsTr(" ")

    ColumnLayout {
        id: columnLayout
        x: 0
        y: 0
        width: Screen.width
        height: Screen.height
//        width:800
//        height:600
        spacing: 0

        TopBar{
            width:parent.width
            height:parent.height/15*2
            color:"light blue"
        }

        ContentFrame{
            id:contentFrame
            z:1
            width:parent.width
            height:parent.height/15*11
            color:"light grey"
        }

        BottomBar{
            width:parent.width
            height:parent.height/15 * 2
            color:"light blue"
        }
    }
}
