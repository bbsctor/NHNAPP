import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.4

CalendarStyle {
    gridVisible: true
    dayDelegate: Rectangle {
        width: 100
        height:100
        gradient: Gradient {
            GradientStop {
                position: 0.00
                color: styleData.selected ? "#111" : (styleData.visibleMonth && styleData.valid ? "#444" : "#666");
            }
            GradientStop {
                position: 1.00
                color: styleData.selected ? "#444" : (styleData.visibleMonth && styleData.valid ? "#111" : "#666");
            }
            GradientStop {
                position: 1.00
                color: styleData.selected ? "#777" : (styleData.visibleMonth && styleData.valid ? "#111" : "#666");
            }

        }


        Label {
            text: styleData.date.getDate()
            anchors.centerIn: parent
            color: styleData.valid ? "yellow" : "blue"
            font.pointSize: 24
        }

        Rectangle {
            width: parent.width
            height: 1
            color: "red"
            anchors.bottom: parent.bottom
        }

        Rectangle {
            width: 1
            height: parent.height
            color: "green"
            anchors.right: parent.right
        }
    }
}
