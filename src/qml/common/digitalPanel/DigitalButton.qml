/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

import QtQuick 2.0

Rectangle {
    id: button
    property alias text: textItem.text
    property color color: "dark grey"

    property bool operator: false
    property bool dimmable: false
    property bool dimmed: false

    width: 60
    height: 60
    border.width: 1

    states: [
        State {
            name: "pressed"
            when: mouse.pressed && !dimmed
            PropertyChanges {
                target: button
                color: "blue"
            }
        }
    ]
    PropertyAnimation {id: animateColor; target: button; properties: "color"; to: "dark grey"; duration: 100}

    Text {
        id: textItem
        font.pointSize: 18
        wrapMode: Text.WordWrap
        lineHeight: 0.75
        color: "black"
        Behavior on color { ColorAnimation { duration: 120; easing.type: Easing.OutElastic} }
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter

    }

    MouseArea {
        id: mouse
        anchors.fill: parent
        anchors.margins: -5
        onClicked: {
            button.state == "pressed" ? button.state = "" : button.state = "pressed'";
            if(parent.text!="C")
            {
                textField1.text += parent.text
            }
            else
            {
                textField1.text = textField1.text.substring(0, textField1.text.length - 1)
            }
            animateColor.start()
            button.state = "";
        }
    }
}
