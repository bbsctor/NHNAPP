import QtQuick 2.7
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.0
import ViewManager 1.0
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Private 1.0

Rectangle {
    id: rectangle
    width: 180
    height: 60
    property alias model: combo1.model
    property alias currentIndex: combo1.currentIndex
    property alias textRole: combo1.textRole
    color:"light grey"

    /**********************************自定义信号*******************************/
    signal indexChanged()

    ComboBox {
        id: combo1
        anchors.fill: parent
        onCurrentIndexChanged:parent.indexChanged()
        style: ComboBoxStyle {
            id: comboBox
            background: Rectangle {
                id: rectCategory
                //radius: 5
                border.width: 2
                //color: "#fff"
                color: "dark grey"
            }
            label: Text {
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pointSize: 18
                font.family: "Courier"
                font.capitalization: Font.SmallCaps
                color: "black"
                text: control.currentText
            }

            // drop-down customization here
            property Component __dropDownStyle: MenuStyle {
                __maxPopupHeight: 600
                __menuItemType: "comboboxitem"

                frame: Rectangle {              // background
                    color: "#fff"
                    border.width: 2
                    //radius: 5
                }

                itemDelegate.label:             // an item text
                    Text {
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    font.pointSize: 40
                    font.family: "Courier"
                    font.capitalization: Font.SmallCaps
                    color: styleData.selected ? "white" : "black"
                    text: styleData.text
                }

                itemDelegate.background: Rectangle {  // selection of an item
                    //radius: 2
                    color: styleData.selected ? "darkGray" : "transparent"
                }

                __scrollerStyle: ScrollViewStyle { }
            }

            property Component __popupStyle: Style {
                property int __maxPopupHeight: 400
                property int submenuOverlap: 0

                property Component frame: Rectangle {
                    width: (parent ? parent.contentWidth : 0)
                    height: (parent ? parent.contentHeight : 0) + 2
                    //height:60
                    border.color: "black"
                    property real maxHeight: 500
                    property int margin: 1
                }

                property Component menuItemPanel: Text {
                    text: "NOT IMPLEMENTED"
                    color: "red"
                    font {
                        pixelSize: 18
                        bold: true
                    }
                }

                property Component __scrollerStyle: null
            }
        }
    }
}
