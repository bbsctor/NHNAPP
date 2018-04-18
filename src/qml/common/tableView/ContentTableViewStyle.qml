import QtQuick 2.3
import QtQuick.Window 2.2
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2

TableViewStyle {
    headerDelegate: Rectangle {
        height:60
        color: "light blue"
        Text {
            id: textItem
            anchors.fill: parent
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: styleData.textAlignment
            anchors.leftMargin: 12
            text: styleData.value
            elide: Text.ElideRight
            color: textColor
            renderType: Text.NativeRendering
            font.pointSize: 18
        }
        Rectangle {
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 1
            anchors.topMargin: 1
            width: 1
            color: "#ccc"
            border.color: "black"
            border.width: 1
        }
    }
    rowDelegate: Rectangle {
        height:60
        width: 1
        color: "#ccc"
    }
    itemDelegate: Rectangle {
        height:60
        color: "lightsteelblue"
        Text {
            id: textItem2
            anchors.fill: parent
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: styleData.textAlignment
            anchors.leftMargin: 12
            text: styleData.value
            elide: Text.ElideRight
            color: textColor
            renderType: Text.NativeRendering
            font.pointSize: 18
        }
        Rectangle {
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 1
            anchors.topMargin: 1
            width: 1
            color: "#ccc"
            border.color: "black"
            border.width: 1
        }
    }

    handle: Rectangle {
        implicitWidth: 80
        implicitHeight: 30
        color: "light blue"
    }
    scrollBarBackground: Rectangle {
        implicitWidth: 80
        implicitHeight: 30
        color: "grey"
    }
    decrementControl: Rectangle {
        implicitWidth: 80
        implicitHeight: 30
        color: "light grey"
    }
    incrementControl: Rectangle {
        implicitWidth: 80
        implicitHeight: 30
        color: "light grey"
    }
    scrollToClickedPosition: true
}
