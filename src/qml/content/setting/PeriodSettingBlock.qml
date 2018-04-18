import QtQuick 2.7
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.0
import ViewManager 1.0
import QtQuick.Dialogs 1.2
import "../../common/dateTime"
import "../../common/label"
import "../../common/combo"
import "../../common/textField"
import "../../common/button"

Rectangle {
    id:periodSettingBlock
    color:"light grey"
    //property alias textField: textField
    MessageDialog {
        id:alertMessageDialog
        title: "输入异常"
    }

    MessageDialog {
        id:autoMeansureMessageDialog
        title: "输入提示"
    }

    RowLayout {
        id: rowLayout4
        anchors.fill: parent

        Grid {
            id: grid
            spacing: 25
            rows: 4
            columns: 2
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Layout.fillHeight: false
            width:parent.width
            height:parent.height




            ContentLabel {
                id: label2

                text: qsTr("测量模式选择：")
            }

            ContentComboBox {
                id: meansureModeSwitchBox
                currentIndex: viewManager.meansureMode
                textRole: "key"
                model: ListModel {
                      ListElement { key: "自动"; value: "auto" }
                     ListElement { key: "手动"; value: "manual" }
                     ListElement { key: "整点"; value: "complete" }
                }
            }
            ContentLabel {
                id: label

                text: qsTr("自动校准周期：")
            }

            RowLayout{
                ContentTextField {
                    id: autoCalibrationPeriodTextField
                    text:viewManager.calibrationPeriod
                }
                ContentLabel{
                    text: "天"
                }
            }


            ContentLabel {
                id: label3
                text: qsTr("自动测量间隔时间：")
            }


            RowLayout{
                ContentTextField {
                    id: autoMeansureTextField
                    text:viewManager.AutoMeasureTime
                }
                ContentLabel{
                    text: "分钟"
                }
            }
            ContentButton{
                id: loadButton
                text: qsTr("读取默认值")
            }
        }



        Connections {
            target: autoCalibrationPeriodTextField
            onInputChanged:setPeriodCalibration(autoCalibrationPeriodTextField.text)
        }


        PeriodSettingViewManager{
            id:viewManager
        }

        Connections {
            target: autoMeansureTextField
            onInputChanged:setMeansureInterval(autoMeansureTextField.text)

        }

        Connections {
            target: meansureModeSwitchBox
            onCurrentIndexChanged: setMeansureMode1(meansureModeSwitchBox.currentIndex)

        }

        Connections {
            target: loadButton
            onClicked:{
                    viewManager.loadDefault()
        }
    }



}
    function setPeriodCalibration(text)
    {
//        if(text!=""&&text>0 && autoMeansureTextField.text > 0)
//        {
//                validateAutoMeansure(autoMeansureTextField.text, text)
//        }
        if(text!=""&&text>0)
        {
            viewManager.setCalibrationPeriod(text)
            viewManager.pushCalibrationPeriod()
        }
    }
    function setMeansureMode1(mode)
    {
        viewManager.setMeansureMode(mode);
        viewManager.pushMeansureMode();
        viewManager.jugeMeasureMode(mode);
    }
    function setMeansureInterval(text)
    {
//        if(text!=""&&text>15 && autoCalibrationPeriodTextField.text > 0)
//        {
//                validateAutoMeansure(text, autoCalibrationPeriodTextField.text)
//        }

        if((text!="")&&(text>15))
        {
            viewManager.setAutoMeasureTime(text);
            viewManager.pushMeasureInterval();
        }
        else
        {
            alertMessageDialog.text="请输入正确值(大于15)！"
            alertMessageDialog.open();
        }
    }

    function validateAutoMeansure(mPara, cPara)
    {
            var temp1 = cPara * 24*60*60*1000;
            var temp2 = mPara * 60 *1000;
            if(temp1 % temp2 < 15 * 60 * 1000)
            {
                autoMeansureMessageDialog.text = "测量时间与自动校准时间可能冲突"
                autoMeansureMessageDialog.open()
            }
    }

}
