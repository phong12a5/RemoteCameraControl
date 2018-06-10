import QtQuick 2.0

Rectangle{
    id: switchBtn

    property bool isActived: true
    property bool enableMouse: false
    signal actived()
    signal deactived()

    color: isActived?  "#7FFF00" :"#EDEDED"
    width: 80
    height: 30
    radius: width/2
    border.width: 2
    border.color: "gray"

    QText{
        id: on
        labelText: "ON"
        visible: isActived && onStae.running == false
        labelFontSize: 15
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: 5
    }
    QText{
        id: off
        labelText: "OFF"
        visible: !isActived && offStae.running == false
        labelFontSize: 15
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.right
        anchors.rightMargin: 5
    }

    Rectangle{
        id: pointer
        width: switchBtn.height - switchBtn.border.width * 2
        height: switchBtn.height - switchBtn.border.width * 2
        anchors.verticalCenter: parent.verticalCenter
        color: "white"
        radius: width/2

        NumberAnimation on x {
            id: onStae
            running: isActived
            from: switchBtn.border.width; to: switchBtn.width - pointer.width - switchBtn.border.width
            duration: 300
        }

        NumberAnimation on x {
            id: offStae
            running: !isActived
            from: switchBtn.width - pointer.width - switchBtn.border.width; to: switchBtn.border.width
            duration: 300
        }
    }

    MouseArea{
        id:  offArea
        width: parent.width/2
        height: parent.height
        z: 10
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        onClicked: {
            if(!enableMouse) return
            deactived()
            console.log("CLick OFF")
        }
    }
    MouseArea{
        id:  onArea
        width: parent.width/2
        height: parent.height
        z: 10
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.right
        onClicked: {
            if(!enableMouse) return
            actived()
            console.log("CLick ON")
        }
    }
}
