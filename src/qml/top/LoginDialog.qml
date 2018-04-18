import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.2
//import QtQuick.VirtualKeyboard 2.1
import Authority 1.0
import "../common/combo"
import "../common/label"
import "../common/textField"
import "../common/button"


Dialog {
    id:loginDialog
    width:parent.width/4
    height:parent.height/4
    title: "登录"
    standardButtons:StandardButton.Ok

    onButtonClicked: {
        if (clickedButton === StandardButton.Ok)
        {
            confirm();
        }
        else{

        }
    }

    function confirm()
    {
        if (userTypeBox.currentIndex == 0 && pwdBox.text == "12345")
        {
            userState.setCurrentState(UserState.OPERATE);
            operatorAuthorization();
        }
        else if (userTypeBox.currentIndex == 1 && pwdBox.text == "54321")
        {
            userState.setCurrentState(UserState.ADMIN);
            adminAuthorization();
        }
        else
        {
            noLoginAuthorization();
        }
    }
    function operatorAuthorization()
    {
        displayButton.mouseAreaEnabled=true;
        meansureButton.mouseAreaEnabled=true;
        settingButton.mouseAreaEnabled=false;
        maintainButton.mouseAreaEnabled=true;
        queryButton.mouseAreaEnabled=true;
    }
    function adminAuthorization()
    {
        displayButton.mouseAreaEnabled=true;
        meansureButton.mouseAreaEnabled=true;
        settingButton.mouseAreaEnabled=true;
        maintainButton.mouseAreaEnabled=true;
        queryButton.mouseAreaEnabled=true;
    }
    function noLoginAuthorization()
    {
        displayButton.mouseAreaEnabled=true;
        meansureButton.mouseAreaEnabled=false;
        settingButton.mouseAreaEnabled=false;
        maintainButton.mouseAreaEnabled=false;
        queryButton.mouseAreaEnabled=false;
    }


    UserState{
        id:userState
        onCurrentStateChanged:
            loginBlock.setUserState();
    }



    Grid{
        anchors.fill:parent
        columns: 2
        rows: 3
        ContentLabel {
            text: "用户: "
            width:100
            height:userTypeBox.height
        }
        ContentComboBox {
            id: userTypeBox
            width: parent.width/2
            model: ["操作员", "管理员"]
        }

        ContentLabel {
            text: "密码: "
            width:100
            height:pwdBox.height
        }

        ContentTextField {
            id: pwdBox

        }
//        ContentButton{
//            id:okButton
//            height: 60
//            text:"OK"
//        }

//        Connections{
//            target:okButton
//            onClicked:confirm()
//        }


    }
}
