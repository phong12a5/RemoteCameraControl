import QtQuick 2.10
import QtQuick.Window 2.10

Window {
    visible: true
    width: 550
    height: 250
    minimumHeight: height
    maximumHeight: height
    minimumWidth: width
    maximumWidth: width
    x:  500
    y: 300
    title: qsTr("Remote control")

    CameraOption{
        id: cameraOption
        width: parent.width
        height: 50
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.top: parent.top
        anchors.topMargin: 40
        isActived: (MyModel.currentCamera >= 0 &&
                    MyModel.currentCamera < MyModel.listCameraSetting.length)?
                       MyModel.listCameraSetting[MyModel.currentCamera].connectionStatus: false
        cameraList: creatCameraModel()
        onActive:
        {
            isActived = true
        }
        onDeactive:
        {
            isActived = false
        }
        onChangeCamera: {
            MyModel.currentCamera = index
        }

    }

    SettingPosition{
        width: parent.width
        height: 50
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.top: cameraOption.bottom
        anchors.topMargin: 40
        enabled: cameraOption.isActived
        activedIndex:(MyModel.currentCamera >= 0 &&
                      MyModel.currentCamera < MyModel.listCameraSetting.length)?
                         MyModel.listCameraSetting[MyModel.currentCamera].activedIndex: 0
        onSetPositionChange: {
            MyModel.setPosition(MyModel.listCameraSetting[MyModel.currentCamera].idx,index)
        }
    }

    InitPoup{
        anchors.fill: parent
        connectedServer: MyModel.connectedServer
    }

    ConnectNetworkPopup{
        anchors.fill: parent
        visible: MyModel.showPopupCheckConn
    }

    function creatCameraModel()
    {
        var cameraListTmp = [];
        for(var i = 0; i < MyModel.listCameraSetting.length; i ++)
        {
            cameraListTmp.push(MyModel.listCameraSetting[i].label)
        }
        return cameraListTmp
    }
}
