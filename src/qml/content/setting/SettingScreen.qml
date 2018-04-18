import QtQuick 2.7
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.0
import ViewManager 1.0
import QtQuick.Controls 1.2
import "../../common/tab"

Rectangle {
    anchors.fill:parent

    TabView{
            id: tabs
            width:parent.width
            height:parent.height
            anchors.fill: parent

            style: ContentTabViewStyle{
            }

            Tab {
                title: "周期设置"
                anchors.fill: parent

                PeriodSettingBlock{
                    id:periodSettingBlock
                    width:parent.width
                    height:parent.height
                }
            }

            Tab {
                title: "参数设置"
                anchors.fill: parent

                ParameterSettingBlock{
                    id:parameterSettingBlock
                    width:parent.width
                    height:parent.height
                }
            }

            Tab {
                title: "系统设置"
                anchors.fill: parent

                SystemSettingBlock{
                    id:systemSettingBlock
                    width:parent.width
                    height:parent.height
                }

            }



            Tab {
                title: "校准设置"
                anchors.fill: parent

                BCLJZJSettingBlock1{
                    id:bcljzjSettingBlock1
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
