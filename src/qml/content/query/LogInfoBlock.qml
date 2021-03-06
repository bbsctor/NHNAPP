import QtQuick 2.7
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.0
import ViewManager 1.0
import QtQuick.Controls 1.2
import SqlModel 1.0
import "../../common/button"
import "../../common/tableView"
import "../../common/dateTime"
import "../../common/label"
import "../../common/combo"
import "../../common/textField"

Rectangle {
    id: rectangle
    anchors.fill: parent
    GridLayout {
        id: gridLayout
        anchors.fill: parent
        rows:5
        flow: GridLayout.TopToBottom


        ContentLabel {
            id: label2
            text: qsTr("查询时间：")
        }
        ContentTextField {
            id:searchTimeTextField
            //                text:qsTr("55")
            //                enable:false
        }

        ContentLabel {
            text: qsTr("格式:2017.01.01")
        }
        ContentButton {
            id: button

            text: qsTr("查询一天数据")
        }
        ContentButton {
            id: buttonSearchAll

            text: qsTr("查询所有数据")
        }

//        ContentButton {
//            id: button1

//            text: qsTr("当天")
//        }

//        ContentButton {
//            id: button2

//            text: qsTr("前一天")
//        }

//        ContentButton {
//            id: button3
//            text: qsTr("后一天")
//        }

        TableView{
            id: tableView
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.rowSpan: 5
            frameVisible: true
            sortIndicatorVisible: true

            style:ContentTableViewStyle{}

            TableViewColumn {
                id: datetimeColumn
                title: "DateTime"
                role: "datetime"
                movable: false
                resizable: false
                width: tableView.viewport.width - valueColumn.width
            }

            TableViewColumn {
                id: valueColumn
                title: "Info"
                role: "info"
                movable: false
                resizable: false
                width: tableView.viewport.width / 2
            }
        }


    }

    Connections {
        target: button
        onClicked: query()
    }

//    function query()
//    {
//        viewManager.searchLogInfo();
//        tableView.model = viewManager.pModel;
//    }
    function query()
    {
        var text=searchTimeTextField.text
        viewManager.searchLogInfo(text)
        tableView.model = viewManager.pModel;
    }
    LogInfoQueryViewManager{
        id:viewManager
    }
    Connections {
        target: buttonSearchAll
        onClicked: querySearchAll()
    }
    function querySearchAll()
    {
       viewManager.searchLogInfoAll()
        tableView.model = viewManager.pModel;
    }
}
