import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1
import QtQuick.Window 2.0
import "../digitalPanel"

Rectangle {
    id: rectangle
    width: 180
    height: 60
    property alias text: textField1.text
    property alias enable:textField1.enabled
    color:"light grey"

    /**********************************自定义信号*******************************/
    signal inputChanged()
    TextField {
        id: textField1
        anchors.fill: parent
        font.pointSize: 12

        //property string dateValue

        onEditingFinished: parent.inputChanged()

        Dialog{
            id:numDialog
            DigitalPanel{
                anchors.fill: parent
            }
            onButtonClicked: {
                if (clickedButton === StandardButton.Ok)
                {
                    rectangle.inputChanged()
                }
                else{

                }
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
            onClicked: numDialog.visible = !numDialog.visible
        }

//        onDateValueChanged: {
//            text = dateValue;
//            calendar.selectedDate = dateValue;
//            textChanged();
//        }
    }
}
