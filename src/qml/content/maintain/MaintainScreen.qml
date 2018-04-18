import QtQuick 2.7
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.0
import ViewManager 1.0
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.4
import "../../common/tab"

Rectangle {
    id:maintainScreen
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
                title:  "系统维护"
                anchors.fill: parent

                SystemMaintainBlock{
                    id:systemMaintainBlock
                    width:parent.width
                    height:parent.height
                }


            }

            Tab {
                id:tab2
                title: "维护数据"
                active: true
                anchors.fill: parent

                MaintainDataBlock{
                    id:maintainDataBlock
                    width:parent.width
                    height:parent.height
                }


            }

            Tab {
                title: "功能测试"
                anchors.fill: parent

                FunctionTestBlock{
                    id:functionTestBlock
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
