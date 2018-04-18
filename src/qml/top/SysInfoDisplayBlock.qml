import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

Rectangle {
    id: rectangle
    color:"light blue"

    ColumnLayout {
        spacing: 10
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        Label {
            id: label
            x: 0
            text: qsTr("2017-04-01")
            transformOrigin: Item.Center
            anchors.horizontalCenter: parent.horizontalCenter
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pointSize: 18
        }

        Label {
            id: label1
            x: 0
//            text:qsTr("12:33")
//            text: qsTr("12:54 17℃")
            anchors.horizontalCenter: parent.horizontalCenter
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pointSize: 18
        }
    }

    function timeChanged() {
        var date = new Date;
       label.text = date.toDateString();
        label1.text = date.toTimeString();
    }

    Timer {
        interval: 100; running: true; repeat: true;
        onTriggered: timeChanged()
    }

}
