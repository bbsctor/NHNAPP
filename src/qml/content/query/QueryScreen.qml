import QtQuick 2.7
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.0
import ViewManager 1.0
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.4
import SqlModel 1.0
import "../../common/tab"

Rectangle {
    id: rectangle
    width:parent.width
    height:parent.height


    TabView{
            id: tabs
            width:parent.width
            height:parent.height
            anchors.fill: parent

            style: ContentTabViewStyle{
            }

            Tab {
                title: "历史数据"
                anchors.fill: parent

                HistoryDataBlock{
                    id:histortDataBlock
                    width:parent.width
                    height:parent.height
                }

            }

//            Tab {
//                title: "历史曲线"
//                anchors.fill: parent

//                HistoryGraphBlock{
//                    id:historyGraphBlock
//                    width:parent.width
//                    height:parent.height
//                }
//            }

            Tab {
                title: "报警信息"
                anchors.fill: parent

                AlertInfoBlock{
                    id:alertInfoBlock
                    width:parent.width
                    height:parent.height
                }
            }

            Tab {
                title: "日志信息"
                anchors.fill: parent

                LogInfoBlock{
                    id:logInfoBlock
                    width:parent.width
                    height:parent.height
                }
            }

            Tab {
                title: "系统信息"
                anchors.fill: parent

                SystemInfoBlock{
                    id:systemInfoBlock
                    width:parent.width
                    height:parent.height
                }
            }
    }

    function updateAuthority()
    {
        console.assert("update authority!");
    }
}
