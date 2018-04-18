import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

Rectangle {
    id: rectangle

    Grid {
        id: grid
        spacing: 40
        anchors.fill: parent
        layoutDirection: Qt.LeftToRight
            flow: Grid.LeftToRight
            columns: 7
            rows: 1

            LoginBlock{
                id: loginBlock
                width:parent.width / 8 * 1.5
                height:parent.height
            }

            TopBarButton{
                id:displayButton
                source:"../../pic/home.png"
                text:"主 页"
            }

            Connections {
                target: displayButton.actionArea
                onClicked: contentFrame.state = "display"
            }

            TopBarButton{
                id:meansureButton
                mouseAreaEnabled: false
                source:"../../pic/meansure.png"
                text:"测 量"
            }

            Connections {
                target: meansureButton.actionArea
                onClicked: contentFrame.state = "meansure"
            }


            TopBarButton{
                id:settingButton
                mouseAreaEnabled: false
                source:"../../pic/settings.png"
                text:"设 置"
            }

            Connections {
                target: settingButton.actionArea
                onClicked: contentFrame.state = "setting"
            }

            TopBarButton{
                id:maintainButton
                mouseAreaEnabled: false
                source:"../../pic/maintain.png"
                text:"维 护"
            }

            Connections {
                target: maintainButton.actionArea
                onClicked: contentFrame.state = "maintain"
            }


            TopBarButton{
                id:queryButton
                mouseAreaEnabled: false
                source:"../../pic/query.png"
                text:"查 询"
            }

            Connections {
                target: queryButton.actionArea
                onClicked: contentFrame.state = "query"
            }
            SysInfoDisplayBlock{
                width: parent.width / 8 * 1.5
                height: parent.height

            }

        }



    LoginDialog{
        id:loginDialog
    }
}
