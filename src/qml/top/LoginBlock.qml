import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import Authority 1.0

Rectangle {
    id: loginBlock
    width:parent.width
    height:parent.height
    color:"light blue"

    TopBarButton{
        id:loginButton
        width:parent.width / 2
        source:"../../pic/login.png"
        text:"登 录"
        anchors.horizontalCenter: parent.horizontalCenter
    }


    Connections {
        target: loginButton.actionArea
        onClicked:buttonHandle()
    }

    function buttonHandle()
    {
        if(loginButton.text == "登 录")
        {
            loginDialog.open()
        }
        else if(loginButton.text == "注 销")
        {
            userState.setCurrentState(UserState.COMMON);
        }
    }

    UserState{
        id:userState
        onCurrentStateChanged:
            setUserState();
    }

    function setUserState()
    {
        if(userState.currentState == UserState.COMMON)
        {
           loginButton.text = "登 录";
           contentFrame.updateAuthority();
        }
        else if(userState.currentState == UserState.ADMIN)
        {
           loginButton.text = "注 销";
           contentFrame.updateAuthority();
        }
        else if(userState.currentState == UserState.OPERATE)
        {
           loginButton.text = "注 销";
           contentFrame.updateAuthority();
        }
    }
}
