import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import ViewManager 1.0
import QtQuick.Dialogs 1.2
import "../../common/label"
import "../../common/button"

Rectangle {
    id:root
    width:parent.width
    height:parent.height
    color:"light grey"
    RowLayout {
        id: rowLayout

        anchors.fill: parent


        Rectangle {
            id:valueDisplayBlock

            width: parent.width/2
            height: parent.height

            color:"light grey"
            ColumnLayout {
                id: columnLayout
                width: parent.width
                height: parent.height
                spacing: 3


                ContentLabel {
                    id: label
                    text: qsTr("NHN3:")
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                }

                RowLayout {
                    id: rowLayout1
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    ContentLabel {
                        id: label1
                        text: valueDisplayViewManager.currentValue
                    }

                    ContentLabel {
                        id: label2
                        text: qsTr("mg/L")
                    }
                }
                ContentLabel {
                    id: label3
                    text: qsTr("  ")
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                }
                ContentLabel {
                    id: label18
                    text: warningViewManager.currentWarningValue
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                }
            }

            ValueDisplayViewManager{
                id:valueDisplayViewManager
            }
        }

        Divider {
            id: divider
            x: parent.width/2
            y: 0
            width: 0
            height: parent.height / 6 * 4
        }
        ColumnLayout{

            Rectangle {
                id:runningInfoDisplayBlock
                width: root.width/2
                height: root.height / 6 * 5
                color:"light grey"
                ColumnLayout {
                    id: columnLayout1

                    width: parent.width
                    height: parent.height
                    spacing: 10
                    Grid {
                        id: grid
                        width: parent.width
                        height: parent.height
                        Layout.fillHeight: false
                        Layout.fillWidth: false
                        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                        rows: 7
                        columns: 2

                        ContentLabel {
                            id: label12
                            text: qsTr("当前状态：")
                        }

                        ContentLabel {
                            id: label13
                            text: runningInfoViewManager.currentStatus
                        }

                        ContentLabel {
                            id: label14
                            text: qsTr("当前动作：")
                        }

                        ContentLabel {
                            id: label15
                            text: runningInfoViewManager.currentAction
                        }

                        ContentLabel {
                            id: label4
                            text: qsTr("后续动作：")
                        }

                        ContentLabel {
                            id: label5
                            text: runningInfoViewManager.nextAction
                        }


                        ContentLabel {
                            id: label6
                            text: qsTr("消解温度：")
                        }

                        RowLayout{
                            ContentLabel {
                                id: label7
                                text: runningInfoViewManager.dispelTemperature
                            }

                        }
                        ContentLabel {
                            id: label8
                            text: qsTr("环境温度：")
                        }

                        RowLayout{
                            ContentLabel {
                                id: label9
                                text: runningInfoViewManager.environmentTemperature
                            }
                        }

                        ContentLabel {
                            id: label16
                            text: qsTr("制冷器温度：")
                        }

                        RowLayout{
                         ContentLabel {
                                id: label17
                                text:runningInfoViewManager.coolerTempearture
                            }

                        }

                        ContentLabel {
                            id: label10
                            text: qsTr("吸光度：")
                        }

                        ContentLabel {
                            id: label11
                            text: runningInfoViewManager.absorbance
                        }
                    }
                    ProgressBar {
                        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                        id: progressBar
                        width: 400
                        height: 30
                        padding: 1
                        Layout.fillHeight: false
                        Layout.fillWidth: false
                        value: runningInfoViewManager.progress/100
                    }
                }

                RunningInfoViewManager{
                    id:runningInfoViewManager
                }

            }


            Rectangle {
                id: rectangle

                width:parent.width
                height:root.height / 6

                color:"light grey"
                Grid {
                    id: grid2
                    anchors.horizontalCenter: parent.horizontalCenter
                    flow: Grid.LeftToRight
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    spacing: 20
                    rows: 1
                    columns: 2

//                    ContentButton{
//                        id: monitorButton
//                        text: qsTr("监控")
//                    }

                    ContentButton{
                        id: urgencyStopButton
                        text: qsTr("紧急停止")
                    }

                    Dialog {
                          id: confirmDialog
                          title: "紧急停止确认"
                          standardButtons: Dialog.Ok | Dialog.Cancel

                          onAccepted: console.log("Ok clicked")
                          onRejected: console.log("Cancel clicked")

                          onButtonClicked: {
                              if (clickedButton === StandardButton.Ok)
                              {
                                   controlViewManager.urgencyStop()
                              }

                          }
                      }


//                    Connections {
//                        target: monitorButton
//                        onClicked:{
//                            if(monitorButton.text == "监控")
//                            {
//                                monitorButton.text = "暂停";
//                                controlViewManager.startMonitor()
//                            }
//                            else if(monitorButton.text == "暂停")
//                            {
//                                monitorButton.text = "监控";
//                                controlViewManager.stopMonitor();
//                            }
//                        }
//                    }
                    Connections {
                        target: urgencyStopButton
                        onClicked:{
                            confirmDialog.open()
                                //controlViewManager.urgencyStop()
                        }
                    }
                }

                HomeControlViewManager{
                    id:controlViewManager
                }

        }

    }

    function updateAuthority()
    {
        console.assert("update authority!");
    }
WarningViewManager{
    id:warningViewManager
}

}
}
