import QtQuick 2.0
import QtQuick.Controls 2.0

Item {
    id: root
    property alias cameraList: cameraOption.model
    property alias isActived: statusButton.isActived

    signal active()
    signal deactive()
    signal changeCamera(var index)

    QText{
        id: titleComp
        text: "Chọn camera: "
        anchors.verticalCenter: root.verticalCenter
    }

    ComboBox {
        id: cameraOption
        anchors.verticalCenter: titleComp.verticalCenter
        anchors.left: titleComp.right
        anchors.leftMargin: 10
        width: 150
        onActivated: {
            changeCamera(index)
        }
    }
    QText{
        id: status
        labelText: "Trạng thái:"
        labelFontSize: 20
        anchors.left: cameraOption.right
        anchors.leftMargin: 20
        anchors.verticalCenter: cameraOption.verticalCenter
    }

    SwitchButton{
        id: statusButton
        anchors.left: status.right
        anchors.leftMargin: 20
        anchors.verticalCenter: status.verticalCenter
        width: 80
        height: 30
        onActived: active()
        onDeactived: deactive()
    }

}
