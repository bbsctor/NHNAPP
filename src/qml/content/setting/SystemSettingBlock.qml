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
    id:systemSettingBlock
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
            z: 1
            spacing: 5
            columns:2
            rows:6

            ContentLabel {
                id: _4to20mAlabel
                text: qsTr("4-20mA使能")
            }

            ContentComboBox {
                id: _4to20mAComboBox
                //currentIndex:1
                currentIndex:viewManager.fourTo20Enable
                model: ["关闭", "开启"]
            }
            ContentLabel {
                id: label2
                text: qsTr("报警开关")
            }

            ContentComboBox {
                id: alertSwitchBox
                currentIndex:0
                model: ["关闭", "开启"]
            }

            ContentLabel {
                id: label3
                text: qsTr("报警上限")
            }

            RowLayout{
                ContentTextField{
                    id:textField3
                    //text:qsTr("100")
                    text:viewManager.alertUpper
                }
                ContentLabel{
                    text: "mg/L"
                }
            }


            ContentLabel {
                id: label4
                text: qsTr("报警下限")
            }

            RowLayout{
                ContentTextField {
                    id: textField4
                   // text:qsTr("1")
                    text:viewManager.alertLower
                }
                ContentLabel{
                    text: "mg/L"
                }
            }
            //从站地址
            ContentLabel {
                id: slaveAddressLabel

                text: qsTr("从站地址：")
            }

            RowLayout{
                ContentTextField {
                    id: slaveAddressTextField
                    text:viewManager.slaveAddress
                }
                ContentLabel {
                    text: qsTr("(1-31)")
                }
            }

        }

        Grid{
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            spacing: 5
            width:parent.width/2
            height:parent.height
            columns:2
            rows:6

            ContentLabel {
                id: rs485label
                text: qsTr("RS485通讯使能")
            }

            ContentComboBox {
                id: rs485ComboBox
                //currentIndex:1
                currentIndex: viewManager.RS485Enable
                model: ["关闭","开启" ]
            }
            ContentLabel {
                id: label8
                text: qsTr("开关量输入1功能")
            }

            ContentComboBox {
                id: switchingValue1Box
                currentIndex:1
                model: ["开启", "关闭"]
            }

            ContentLabel {
                id: label9
                text: qsTr("开关量输入2功能")
            }

            ContentComboBox {
                id: switchingValue2Box
                currentIndex:1
                model: ["开启", "关闭"]
            }

            ContentLabel {
                id: label11
                text: qsTr("自动注销时间")
            }

            ContentComboBox {
                id: autoLogoutBox
                currentIndex:0
                model: ["关闭", "5分钟", "15分钟", "30分钟"]
            }

            ContentButton{
                id: loadButton
                height: 60
                text: qsTr("读取默认值")
            }

        }
    }



    SystemSettingViewManager{
        id:viewManager
    }



    //4到20mA组合框
    Connections{
        target: _4to20mAComboBox
       onCurrentIndexChanged:set4to20mAswich()
    }


    //rs485组合框
    Connections{
        target: rs485ComboBox
        onCurrentIndexChanged:setRS485switch()
    }



    Connections {
        target:alertSwitchBox
        onCurrentIndexChanged:setAlertZone(textField3.text,textField4.text)
    }

    Connections {
        target: loadButton
        onClicked:{
                viewManager.loadDefault()
         }
   }
    Connections{
        target: slaveAddressTextField
        onInputChanged:setSlaveAddress()
    }
    function setSlaveAddress()
    {
          var txt =  slaveAddressTextField.text
        viewManager.setSlaveAddress(txt)
        viewManager.pushSlaveAddress()
    }
    function set4to20mAswich()
    {
        var txt = _4to20mAComboBox.model[_4to20mAComboBox.currentIndex]
        if (txt == "开启")
        {
            viewManager.setFourTo20Enable(1)
        }
        else
        {
            viewManager.setFourTo20Enable(0)
        }
        viewManager.pushFourTo20Enable()
    }
    function setRS485switch()
    {
        var txt = rs485ComboBox.model[rs485ComboBox.currentIndex]
        if (txt == "开启")
        {
            viewManager.setRS485Enable(1)
        }
        else
        {
            viewManager.setRS485Enable(0)
        }
        viewManager.pushRS485Enable()
    }
    function setAlertZone(text1,text2)
    {
        var txt = alertSwitchBox.model[alertSwitchBox.currentIndex]
        if (txt == "开启")
        {
            if(text1>text2)
            {
                var txt=text1+","+text2;
                viewManager.setAlertUpperLowZone(txt)
                viewManager.pushAlertUpperLowZone()
            }
            else
            {
                alertMessageDialog.text="请输入正确值(上限大于下限)！"
                alertMessageDialog.open();
            }
            }
        }



    }


