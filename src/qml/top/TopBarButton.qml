import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

Rectangle{
    width: height
    height: parent.height
    color:"light blue"
    property alias source:image.source
    property alias text:funcText.text
    property MouseArea actionArea: mouseArea
    property alias mouseAreaEnabled:mouseArea.enabled
    Image {
        id: image
        anchors.top: parent.top
        anchors.topMargin: 3
        width:parent.width / 3 * 2
        height: width
        anchors.horizontalCenter: parent.horizontalCenter
    }
    Text{
        id:funcText
        font.pointSize: 18
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 3
    }
    MouseArea{
        id:mouseArea
        anchors.fill: parent
    }
}
