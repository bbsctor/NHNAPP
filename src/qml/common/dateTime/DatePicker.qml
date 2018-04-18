import QtQuick 2.0
import QtQuick.Controls 1.2

TextField
{
    property string dateValue
    width: 180
    height: 60
    Calendar{
        id: calendar
        style:ContentCalendarStyle{}

        width:400
        height:400

        z: 0
        opacity: 1
        anchors.topMargin: 0
        anchors.top: parent.bottom
        visible: false
        activeFocusOnTab: true
        onReleased: {
            text = date;
            text = text.substr(0, 10);
            dateValue = text;
            visible = false;
        }
    }

    Button{
        id: downBtn
        width: 60
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0
        //iconSource: "../../images/arrow_down.png"
        text:"..."
        onClicked: calendar.visible = !calendar.visible
    }

    onDateValueChanged: {
        text = dateValue;
        calendar.selectedDate = dateValue;
        textChanged();
    }

}
