import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

Rectangle{
    id:btn
    width: 180
    height: 90
    color:"dark grey"
    property alias text:funcText.text
    property alias pointSize:funcText.font.pointSize
    property MouseArea actionArea: mouseArea

    /**********************************自定义信号*******************************/
    signal clicked()

    Text{
        id:funcText
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pointSize: 18
        anchors.fill: parent
    }
    MouseArea{
        id:mouseArea
        anchors.fill: parent
        onClicked:{
            parent.clicked()
            btn.state == 'clicked' ? btn.state = "" : btn.state = 'clicked';
            animateColor.start()
            btn.state = "";
        }
    }

    states: [
                State {
                    name: "clicked"
                    PropertyChanges { target: btn; color: "blue" }

                }
            ]
    PropertyAnimation {id: animateColor; target: btn; properties: "color"; to: "dark grey"; duration: 100}

}
