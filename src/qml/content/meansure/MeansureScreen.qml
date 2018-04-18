import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import ViewManager 1.0
import "../../common/button"

Rectangle {
    id: rectangle
    width:parent.width
    height:parent.height
    color:"light grey"
    RowLayout {
        id: rowLayout
        width: parent.width
        height: parent.height
        spacing: 10
        ContentButton {
            id: button
            text: qsTr("在线测量")
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }

        ContentButton {
            id: button1
            text: qsTr("离线测量")
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }

    }

    Connections {
        target: button
        onClicked:startOnlineMeansure()
    }

    MeansureViewManager
    {
        id:viewManager
    }

    Timer
    {
        id:timer
        interval: 2000; running: false; repeat: true
       onTriggered:viewManager.readMeansureValue()


    }

    Connections {
        target: button1
        onClicked: startOfflineMeansure()
    }

    function startOnlineMeansure()
    {
        viewManager.startOnlineMeansure();
        //timer.running = true;
    }

    function startOfflineMeansure()
    {
        viewManager.startOfflineMeansure();
        //timer.running = true;
    }

    function updateAuthority()
    {
        console.assert("update authority!");
    }
}
