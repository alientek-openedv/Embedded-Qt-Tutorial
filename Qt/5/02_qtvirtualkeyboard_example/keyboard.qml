/******************************************************************
Copyright © Deng Zhimao Co., Ltd. 1990-2021. All rights reserved.
* @projectName   02_qtvirtualkeyboard_example
* @brief         keyboard.qml
* @author        Deng Zhimao
* @email         1252699831@qq.com
* @net           www.openedv.com
* @date          2021-06-15
*******************************************************************/
import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.VirtualKeyboard 2.2

Item {
    Rectangle {
        id: inputRow
        width: parent.width
        height: parent.height - inputPanel.height
        anchors.bottom: inputPanel.top
        anchors.bottomMargin: Qt.inputMethod.visible ? 0 : -(inputRow.height - 40)
        color: "black"
        TextField {
            id: lineEditor
            height: 40
            placeholderText: "输入内容"
            focus: false
            width: parent.width * 0.8
        }

        Button{
            text: "确认"
            height: 40
            width: parent.width * 0.2
            anchors.right: parent.right
            onClicked: {
            }
        }
    }

    InputPanel {
        id: inputPanel
        y: Qt.inputMethod.visible ? parent.height - inputPanel.height : parent.height
        anchors.left: parent.left
        anchors.right: parent.right
        visible: true
        states: State {
            name: "visible"
            when: inputPanel.active
            PropertyChanges {
                target: inputPanel
                y: parent.height - inputPanel.height
            }
        }
        transitions: Transition {
            from: ""
            to: "visible"
            reversible: true
            ParallelAnimation {
                NumberAnimation {
                    properties: "y"
                    duration: 250
                    easing.type: Easing.InOutQuad
                }
            }
        }
    }
}
