import QtQuick 2.0

Rectangle {
    id: rectangle
    width: 180
    height: 60
    property alias text: text1.text
    color:"light grey"

    Text {
        id: text1
        text: qsTr("Text")
        wrapMode: Text.NoWrap
        elide: Text.ElideNone
        anchors.fill: parent
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignLeft
        font.pointSize: 18
    }

}
