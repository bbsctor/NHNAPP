/**************************************
  *文件名：TimeEdit.qml
  ***************************************/
import QtQuick 2.3
import QtQuick.Window 2.2
import QtQuick.Controls 1.3
import QtQml 2.2
import QtQuick.Controls.Styles 1.1

//TimeEdit组件
Rectangle {
    width: 100
    height: 25
    /**********************************自定义属性***********************************/
    property alias text: textEdit.strTime     //保存当前的时间文本
    property date currentDate: new Date()
    /***********************************对象树*************************************/
    //自定义的时间输入框组件
    TimeInput{
        id:textEdit
        width: parent.width
        height: parent.height
        anchors.top: parent.top
        anchors.left: parent.left
    }
    //日历控件
    Calendar{
        id:calendarItem
        frameVisible: true
        weekNumbersVisible: true
        width: 300
        height: 250
        anchors.top: textEdit.bottom
        anchors.left: textEdit.left
        visible: false
        onClicked: {
            visible:false
        }

    }



    Component.onCompleted: {
        //日历点击信号的信号与槽的连接
        calendarItem.clicked.connect(calendarClicked)
        textEdit.clicked.connect(showCalendar)
        //初始的默认时间为当前时间
        textEdit.strTime = currentDate.toLocaleDateString("yyyy/M/d")+" "+currentDate.toLocaleTimeString("H:mm")
        textEdit.oldTime = textEdit.strTime
    }
    /***************************************方法*******************************************/
    //显示日历界面的
    function showCalendar()
    {
        calendarItem.visible = !calendarItem.visible
    }
    //点击日历选择时间后的处理函数
    function calendarClicked(date)
    {
        var year = date.getFullYear()
        var month =date.getMonth()+1
        var day = date.getDate()

        var selectDate = year+"/"+month+"/"+day
        var timeSplit =textEdit.strTime.split(" ")
        textEdit.strTime = selectDate+" "+timeSplit[1]
        textEdit.oldTime = textEdit.strTime
    }
}
