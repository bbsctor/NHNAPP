import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import "meansure"
import "display"
import "query"
import "setting"
import "maintain"

Rectangle {
    id:contentFrame
    state:"display"
    states: [
        State {
            name: "display"
            PropertyChanges {
                target: displayScreen; visible: true
            }
        },
        State {
            name: "meansure"
            PropertyChanges {
                target: meansureScreen; visible: true
            }
        },
        State {
            name: "query"
            PropertyChanges {
                target: queryScreen; visible: true
            }
        },
        State {
            name: "setting"
            PropertyChanges {
                target: settingScreen; visible: true
            }
        },
        State {
            name: "maintain"
            PropertyChanges {
                target: maintainScreen; visible: true
            }
        }
    ]

//    SettingScreen{
//        id:settingScreen
//        visible: false
//    }

    MeansureScreen{
        id:meansureScreen
        visible: false
    }
    RealTimeDisplayScreen{
        id:displayScreen
        visible: false
    }
    QueryScreen{
        id:queryScreen
        visible: false
    }

    SettingScreen{
        id:settingScreen
        visible: false
    }

    MaintainScreen{
        id:maintainScreen
        visible: false
    }

    function updateAuthority()
    {
        meansureScreen.updateAuthority();
        displayScreen.updateAuthority();
        queryScreen.updateAuthority();
        settingScreen.updateAuthority();
        maintainScreen.updateAuthority();
    }
}
