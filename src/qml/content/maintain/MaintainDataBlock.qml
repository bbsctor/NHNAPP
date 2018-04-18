import QtQuick 2.7
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.0
import ViewManager 1.0
import "../../common/label"
import "../../common/button"

Rectangle {
    id:maintainDataBlock
    color:"light grey"
    ColumnLayout {
        id: columnLayout1
        width: 600
        spacing: 30
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter

//        Grid {
//            id: grid
//            spacing: 10
//            rows: 4
//            columns: 2


//            ContentLabel {
//                id: label
//                text: qsTr("零样标定： ")
//            }

//            ContentLabel {
//                id: label1
//                text: qsTr("52300， 51896， 2017-04-22， 16：12")
//            }


//            ContentLabel {
//                id: label2
//                text: qsTr("标一标定： ")
//            }

//            ContentLabel {
//                id: label3
//                text: qsTr("52600， 51556， 2017-04-21， 13：12")
//            }


//            ContentLabel {
//                id: label4
//                text: qsTr("最后清洗： ")
//            }

//            ContentLabel {
//                id: label5
//                text: qsTr("2017-04-18， 11：36")
//            }

//            ContentLabel {
//                id: label6
//                text: qsTr("最后冲洗： ")
//            }

//            ContentLabel {
//                id: label7
//                text: qsTr("2017-04-18， 11：38")
//            }
//        }

        Grid {
            id: grid1
            spacing: 10
            columns: 10
            rows: 2
            ContentLabel {
                id: label8
                width:40
                text: qsTr("K1: ")
            }

            ContentLabel {
                id: label9
                width:80
                text: viewManager.calibrationCoefK1
            }


            ContentLabel {
                id: label10
                width:40
                text: qsTr("K2:")
            }

            ContentLabel {
                id: label11
                width:80
                text: viewManager.calibrationCoefK2
            }

            ContentLabel {
                id: label12
                width:40
                text: qsTr("K3:")
            }

            ContentLabel {
                id: label13
                width:80
                text: viewManager.calibrationCoefK3
            }

            ContentLabel {
                id: label14
                width:40
                text: qsTr("K4:")
            }

            ContentLabel {
                id: label15
                width:80
                text: viewManager.calibrationCoefK4
            }

            ContentLabel {
                id: label16
                width:40
                text: qsTr("K5: ")
            }

            ContentLabel {
                id: label17
                width:80
                text: viewManager.calibrationCoefK5
            }

            ContentLabel {
                id: label18
                width:40
                text: qsTr("B1: ")
            }

            ContentLabel {
                id: label19
                width:80
                text: viewManager.calibrationCoefB1
            }


            ContentLabel {
                id: label20
                width:40
                text: qsTr("B2:")
            }

            ContentLabel {
                id: label21
                width:80
                text: viewManager.calibrationCoefB2
            }

            ContentLabel {
                id: label22
                width:40
                text: qsTr("B3:")
            }

            ContentLabel {
                id: label23
                width:80
                text: viewManager.calibrationCoefB3
            }

            ContentLabel {
                id: label24
                width:40
                text: qsTr("B4:")
            }

            ContentLabel {
                id: label25
                width:80
                text: viewManager.calibrationCoefB4
            }

            ContentLabel {
                id: label26
                width:40
                text: qsTr("B5: ")
            }

            ContentLabel {
                id: label27
                width:80
                text: viewManager.calibrationCoefB5
            }


        }

        ContentButton{
            id:button
            text:"刷新"
            onClicked: updateCalibrationCoef()
        }
    }

    onFocusChanged:updateCalibrationCoef()
    function updateCalibrationCoef()
    {
        viewManager.pullCalibrationCoef();
    }

    MaintainDataViewManager{
        id:viewManager
    }
}
