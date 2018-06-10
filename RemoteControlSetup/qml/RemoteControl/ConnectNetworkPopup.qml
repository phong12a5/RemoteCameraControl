import QtQuick 2.0

Item {
    id: root
    anchors.fill: parent
    property string labelPopup: "Không thể kết nối đến máy chủ.
Vui lòng kiểm tra lại kết nối mạng!"

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
            anchors.centerIn: parent
            labelText: labelPopup
            labelFontSize: 15
            labelColor: "white"
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }
    }
    MouseArea{
        anchors.fill: parent
        propagateComposedEvents: false
    }
}
