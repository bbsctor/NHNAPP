import QtQuick 2.7
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.0
import ViewManager 1.0
import "../../common/label"

Rectangle {
    id:maintainDataBlock
    color:"light grey"
    ColumnLayout {
        id: columnLayout1
        spacing: 30
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter

        Grid {
            id: grid
            spacing: 10
            rows: 7
            columns: 2


            ContentLabel {
                id: label
                text: qsTr("公司标识： ")
            }

            ContentLabel {
                id: label1
                text: qsTr("SITAN")
            }


            ContentLabel {
                id: label2
                text: qsTr("设备识别信息： ")
            }

            ContentLabel {
                id: label3
                text: qsTr("DEV20170401001")
            }


            ContentLabel {
                id: label4
                text: qsTr("固件版本号： ")
            }

            ContentLabel {
                id: label5
                text: qsTr("V1.0")
            }

            ContentLabel {
                id: label6
                text: qsTr("硬件版本号： ")
            }

            ContentLabel {
                id: label7
                text: qsTr("V1.2")
            }

            ContentLabel {
                id: label8
                text: qsTr("产品序列号： ")
            }

            ContentLabel {
                id: label9
                text: qsTr("ST000001")
            }


            ContentLabel {
                id: label10
                text: qsTr("配置ID： ")
            }

            ContentLabel {
                id: label11
                text: qsTr("CFG23654")
            }


            ContentLabel {
                id: label12
                text: qsTr("HMI版本号： ")
            }

            ContentLabel {
                id: label13
                text: qsTr("V1.0")
            }
        }

    }

    function updateAuthority()
    {
        console.assert("update authority!");
    }
}
