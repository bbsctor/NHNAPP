import QtQuick 2.7
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.0
import ViewManager 1.0
import "../../common/dateTime"
import "../../common/label"
import "../../common/combo"
import "../../common/textField"
import "../../common/button"

Rectangle {
    id:bcljzjSettingBlock1
    color:"light grey"
    width:parent.width
    height:parent.height
    RowLayout {
        id: rowLayout
        anchors.fill: parent

        Grid{
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Layout.fillHeight: false
            width:parent.width/2
            height:parent.height
            spacing: 5
            columns:2
            rows:5



            ContentLabel {
                id: sampleConsentrationLabel1
                text: qsTr("曲线1区间")
            }
            RowLayout{
                ContentLabel {
                    id: sampleConsentrationTextField1
                   text : qsTr("0-7")
                }

                ContentLabel {
                    text: qsTr("mg/L")
                }
            }
            ContentLabel {
                id: sampleConsentrationLabel2
                text: qsTr("曲线2区间")
            }
            RowLayout{
                ContentLabel {
                    id: sampleConsentrationTextField2
                   text : qsTr("7-30")
                }

                ContentLabel {
                    text: qsTr("mg/L")
                }
            }
            ContentLabel {
                id: sampleConsentrationLabel3
                text: qsTr("曲线3区间")
            }
            RowLayout{
                ContentLabel {
                    id: sampleConsentrationTextField3
                   text : qsTr("30-60")
                }

                ContentLabel {
                    text: qsTr("mg/L")
                }
            }
            ContentLabel {
                id: sampleConsentrationLabel4
                text: qsTr("曲线4区间")
            }
            RowLayout{
                ContentLabel {
                    id: sampleConsentrationTextField4
                   text : qsTr("60-180")
                }

                ContentLabel {
                    text: qsTr("mg/L")
                }
            }
            ContentLabel {
                id: sampleConsentrationLabel5
                text: qsTr("曲线5区间")
            }
            RowLayout{
                ContentLabel {
                    id:sampleConsentrationTextField5
                   text : qsTr("180-300")
                }

                ContentLabel {
                    text: qsTr("mg/L")
                }
            }
        }

        Grid{
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            width:parent.width/2
            height:parent.height
            spacing: 5
            columns:2
            rows:2

            ContentLabel {
                id: label1
                text: qsTr("校准曲线选择：")
            }

            ContentComboBox {
                id: selectCurveSwitchBox
                currentIndex: viewManager.selectCurveNumber
                textRole: "key"
                model: ListModel {
                    ListElement { key: "曲线1";  }
                    ListElement { key: "曲线2"; }
                    ListElement { key: "曲线3"; }
                    ListElement { key: "曲线4"; }
                    ListElement { key: "曲线5"; }
                }
            }
            ContentButton{
                id: loadButton
                text: qsTr("读取默认值")
            }
            Connections {
                target:  selectCurveSwitchBox
                onCurrentIndexChanged:getSettingSelectCurve()
            }
        }
        BCLJZJSettingViewManagerOne{
            id:viewManager
        }

    }

    function  getSettingSelectCurve()
    {
        if(selectCurveSwitchBox.currentIndex >selectCurveSwitchBox.currentIndex < 5)
        {
             viewManager.setSelectCurveNumber(selectCurveSwitchBox.currentIndex)

             viewManager.pushSelectCurveNumber();
        }
    }

    Connections {
        target: loadButton
        onClicked:{
                viewManager.loadDefault()
         }
   }


}
