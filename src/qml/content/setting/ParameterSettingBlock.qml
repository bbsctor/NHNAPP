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
    id:parameterSettingBlock
    color:"light grey"
    width:parent.width
    height:parent.height
    RowLayout {
        id: rowLayout
        anchors.fill: parent

        Grid{



            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

            spacing: 5
            width:parent.width/2
            height:parent.height
            columns:2
            rows:6





            ContentLabel {
                id: label2
                text: qsTr("消解温度")
            }
            RowLayout{
                ContentTextField {
                    id: dispelTempTextField
                    text:qsTr("55")
                    enable:false
                }

                ContentLabel {
                    text: qsTr("℃")
                }

            }


            ContentLabel {
                id: label3

                text: qsTr("消解时间")
            }

            RowLayout{
                ContentTextField {
                    id: dispelTimeTextField
                    text:viewManager.dispelTime
                }
                ContentLabel {
                    text: qsTr("分钟")
                }
            }
            ContentLabel {
                id: label7
                text: qsTr("采样泵启动时间")
            }
            RowLayout{
                ContentTextField {
                    id: bumbOnTimeTextField
                    text:viewManager.bumbOnTime
                }
                ContentLabel {
                    text: qsTr("分钟")
                }
            }

            ContentButton{
                id: loadButton
                text: qsTr("读取默认值")
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
                id: label4
                text: qsTr("预处理器冲洗")
            }

            ContentComboBox {
                id: preHandlerSwitchBox
                currentIndex: 1
                model: ["开启", "关闭"]
            }

            ContentLabel {
                id: label5
                text: qsTr("磁力锁")
            }

            ContentComboBox {
                id: megLockSwitchBox
                currentIndex: 1
                model: ["开启", "关闭"]
            }

            ContentLabel {
                id: label6
                text: qsTr("自来水冲洗")
            }

            ContentComboBox {
                id: washingSwitchBox
                currentIndex: 1
                model: ["开启", "关闭"]
            }



            Connections {
                target: megLockSwitchBox

                onCurrentIndexChanged: setMegLockAble()
            }

            Connections {
                target: washingSwitchBox
                onCurrentIndexChanged: setWashingAble()
            }



            Connections {
                target: bumbOnTimeTextField
                onInputChanged: setBumbOnTime()
            }


            Connections {
                target: preHandlerSwitchBox
                onCurrentIndexChanged: setPreHandlerAble()
            }



            Connections {
                target: dispelTimeTextField
                onInputChanged: setDispelTime()
            }



            Connections {
                target: dispelTempTextField
                onInputChanged: setDispelTemp()
            }

            Connections {
                target: loadButton
                onClicked:{
                        viewManager.loadDefault()
                 }
           }

            function setDispelTemp()
            {
                var txt =  dispelTempTextField.text
                viewManager.setDispelTemp(txt)
                viewManager.pushDispelTemp()
            }

            ParameterSettingViewManager{
                id:viewManager
            }
        }
    }



    function setMegLockAble()
    {
        var txt = megLockSwitchBox.model[megLockSwitchBox.currentIndex]
        if (txt == "开启")
        {
//            viewManager.setMegLockAble(1)
            viewManager.setMegLockAble(1)

        }
        else
        {
            viewManager.setMegLockAble(0)
        }
        viewManager.pushMegLockAble()
    }
    function setWashingAble()
    {
        var txt = washingSwitchBox.model[washingSwitchBox.currentIndex]
        if (txt == "开启")
        {
            viewManager.setWashingAble(1)
        }
        else
        {
            viewManager.setWashingAble(0)
        }
        viewManager.pushWashingAble()
    }
    function setPreHandlerAble()
    {
        var txt = preHandlerSwitchBox.model[preHandlerSwitchBox.currentIndex]
        if (txt == "开启")
        {
            viewManager.setPreHandlerAble(1)

        }
        else
        {
            viewManager.setPreHandlerAble(0)

        }
        viewManager.pushPreHandlerAble();
    }

    function setDispelTime()
    {
        var txt = dispelTimeTextField.text
        if(txt>0)
        {
            viewManager.setDispelTime(txt)
            viewManager.pushDispelTime()
        }

    }
    function setBumbOnTime()
    {
        var txt = bumbOnTimeTextField.text
        if(txt>0)
        {
            viewManager.setBumbOnTime(txt)
            viewManager.pushBumbOnTime()
        }

    }


}
