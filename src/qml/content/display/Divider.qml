import QtQuick 2.0

Row {
    spacing: 5
    height: parent.height
    property alias label: textLabel.text

    Rectangle {
        border.width: 1
        width: 2
        height: parent.height
        anchors.margins: 20
        border.color: "#2d2b19"
    }
    Text {
        id: textLabel
        height: parent.height
        horizontalAlignment: Text.AlignVCenter
        font.bold: true
    }
}
