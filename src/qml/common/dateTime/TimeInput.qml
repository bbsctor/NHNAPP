
/**************************************
  *文件名：TimeInput.qml
  ***************************************/
import QtQuick 2.0
import QtQml 2.2
import QtQuick.Controls 1.3
import QtQuick.Controls.Styles 1.3
//时间编辑框组件
Rectangle
{
    id:rect
    width: parent.width
    height: parent.height
    border.width: 1
    border.color: "#333"
    /*******************************自定义属性*********************************/
    property var locale: Qt.locale()
    property alias strTime: textEdit.text
    property string oldTime: ""
    /**********************************自定义信号*******************************/
    signal clicked()
    /*******************************对象树*************************************/
    Row{
        id:row
        anchors.top: parent.top
        anchors.topMargin: 1
        anchors.left: parent.left
        anchors.leftMargin: 1
        width: children.width
        height: children.height
        spacing: 2
        //文本编辑框
        TextField{
            id:textEdit
            width:rect.width-25
            height:rect.height-2
            style:TextFieldStyle{
                background: Rectangle{
                    radius: 2
                    width: rect.width-25
                    height: rect.height-2
                }
            }
            onEditingFinished:{
                //编辑完成进行格式判断
                if(rect.checkTimeFomat() === false)
                {
                    textEdit.text = oldTime
                }
                else
                {
                    oldTime = textEdit.text
                }
            }
        }
        //日历小图标
        Image{
            width: 16
            height: 16
            anchors.top:parent.top
            anchors.topMargin: 4
            source: "picture/calendar.png"
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    rect.clicked()
                    mouse.accepted = false
                }
            }
        }
    }
    /************************************方法***********************************/
    //检查输入的时间的合法性。原理就是把文本按照合法的格式解析出各个部分，再都在出日期Date,
    //把Date转换为string之后判断和原来的文本是否一致
    function checkTimeFomat()
    {
        var strDateTimeSplit = strTime.split(" ")
        var strDateSplit = strDateTimeSplit[0].split("/")
        var strTimeSplit = strDateTimeSplit[1].split(":")
        var date = new Date(strDateSplit[0],strDateSplit[1]-1,strDateSplit[2],strTimeSplit[0],strTimeSplit[1],0)

        var strDate2 = date.toLocaleString("yyyy/M/d H:mm")
        console.log(strDate2)
        if(strDate2  !== strTime)
            return false
        else
            return true

    }
}
