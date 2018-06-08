import QtQuick 2.0

Item {
    id: root
    anchors.fill: parent

    property bool actived: true
    property bool connectedServer: true
    property bool initDataCompleted: true
    property int countTimer: 0
    property string labelPopup2: "Đang kết nối đến máy chủ "
    property string labelPopup1: "Đang khởi tạo dữ liệu "
    property string labelPoint:  ""
    property int intervalTimer: 100

    Rectangle{
        anchors.fill: parent
        color: "black"
        opacity: 0.5
    }
    Rectangle{
        id: bodyPopup
        width: 300
        height: 130
        color: "black"
        border.width: 1
        opacity: 1
        border.color: "white"
        anchors.centerIn: parent

        QText{
            id: initData
            anchors.verticalCenter: parent.verticalCenter
            anchors.verticalCenterOffset: animation1Timer.running? 0: -20
            anchors.left: parent.left
            anchors.leftMargin: 10
            labelText: labelPopup1 + (animation1Timer.running? labelPoint: "")
            labelFontSize: 15
            labelColor: "white"
            verticalAlignment: Text.AlignVCenter
            Component.onCompleted: {
                animation1Timer.start();
            }
        }

        Image{
            id: initDataStatus
            source: initDataCompleted? "qrc:/completedIcon.png" : "qrc:/failIcon.png"
            visible: !animation1Timer.running
            anchors.verticalCenter: initData.verticalCenter
            anchors.right: parent.right
            anchors.rightMargin: 20
            width: 20
            height: 20
        }

        QText{
            id: connectServer
            visible: false
            anchors.top: initData.top
            anchors.topMargin: 30
            anchors.left: parent.left
            anchors.leftMargin: 10
            labelText: labelPopup2 + " " + labelPoint
            labelFontSize: 15
            labelColor: "white"
            verticalAlignment: Text.AlignVCenter
        }
        Image{
            id: connectServerStatus
            source: connectedServer? "qrc:/completedIcon.png" : "qrc:/failIcon.png"
            visible: !animation2Timer.running && connectServer.visible
            anchors.verticalCenter: connectServer.verticalCenter
            anchors.right: parent.right
            anchors.rightMargin: 20
            width: 20
            height: 20
        }
    }

    Timer{
        id: animation1Timer
        interval: intervalTimer
        repeat: true
        onTriggered: {
            countTimer++
            if(countTimer == 20)
            {
                labelPoint = ""
                countTimer = 0
                animation1Timer.stop()

                connectServer.visible = true
                animation2Timer.start()

            }else
            {
                labelPoint += "."
            }
        }
    }

    Timer{
        id: animation2Timer
        interval: intervalTimer
        repeat: true
        onTriggered: {
            countTimer++
            if(countTimer == 20)
            {
                labelPoint = ""
                countTimer = 0
                animation2Timer.stop()
                if(connectedServer)
                {
                    closePopup.start()
                }
            }else
            {
                labelPoint += "."
            }
        }
    }

    Timer{
        id: closePopup
        interval: 3000
        onTriggered: {
            root.visible = false
        }
    }

    MouseArea{
        anchors.fill: parent
        propagateComposedEvents: false
        onClicked: {
            if(connectedServer) root.destroy()
        }
    }

}
