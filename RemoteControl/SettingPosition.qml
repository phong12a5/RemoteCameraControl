import QtQuick 2.0

Item {
    id : root
    property int activedIndex: 0
    property int currentIndex: 0
    property int nodeWidth: 30
    property int space : 30
    readonly property int _FACTOR: 5
    readonly property int _INTERVAL: 10000


    signal setPositionChange(var index)

    QText{
        id: titleComp
        text: "Tùy chọn vị trí: "
        anchors.verticalCenter: root.verticalCenter
        opacity: root.enabled? 1: 0.5
    }

    Repeater{
        id: position

        model: 5
        width: parent.width
        anchors.verticalCenter: root.verticalCenter
        anchors.left: titleComp.right
        anchors.leftMargin: 10
        Item{
            height: parent.height
            anchors.verticalCenter: parent.verticalCenter
            property bool isClicked : false

            Rectangle{
                id: node

                property int actualIndex: index

                x: position.x + index * (nodeWidth + space)
                anchors.verticalCenter: parent.verticalCenter
                radius: nodeWidth/2
                width: nodeWidth
                height: nodeWidth
                color: actualIndex === activedIndex? "#7FFF00" :(mouseArea.pressed? "gray" : "#EDEDED")
                border.width: 2
                border.color: "black"
                opacity: root.enabled? 1: 0.5

                LoadingComponent{
                    id: loading
                    visible: root.enabled && isClicked && currentIndex == node.actualIndex && activedIndex != node.actualIndex
                }
                QText {
                    text: node.actualIndex + 1
                    anchors.centerIn: parent
                    color: "black"
                    opacity: 0.8
                    font.pixelSize: 15
                }

                Timer{
                    id: timer
                    interval: _INTERVAL
                    running: false
                    onTriggered: {
                        isClicked = false
                    }
                }

                MouseArea{
                    id: mouseArea
                    anchors.fill: parent
                    onReleased: {
                        if(activedIndex === node.actualIndex) return
                        currentIndex = node.actualIndex
                        isClicked = true
                        timer.start()
                        setPositionChange(currentIndex)
                    }
                }
            }

            Rectangle{
                id: node2

                property int actualIndex: index + _FACTOR

                x: position.x + index * (nodeWidth + space)
                anchors.verticalCenter: parent.verticalCenter
                anchors.verticalCenterOffset: 50
                radius: nodeWidth/2
                width: nodeWidth
                height: nodeWidth
                color: actualIndex === activedIndex? "#7FFF00" :(mouseArea2.pressed? "gray" : "#EDEDED")
                border.width: 2
                border.color: "black"
                opacity: root.enabled? 1: 0.5

                LoadingComponent{
                    id: loading2
                    visible: root.enabled && isClicked && currentIndex == node2.actualIndex && activedIndex !=  node2.actualIndex
                }
                QText {
                    text: node2.actualIndex + 1
                    anchors.centerIn: parent
                    color: "black"
                    opacity: 0.8
                    font.pixelSize: 15
                }

                Timer{
                    id: timer2
                    interval: _INTERVAL
                    running: false
                    onTriggered: {
                        isClicked = false
                    }
                }

                MouseArea{
                    id: mouseArea2
                    anchors.fill: parent
                    onReleased: {
                        if(activedIndex ===  node2.actualIndex) return
                        currentIndex =  node2.actualIndex
                        isClicked = true
                        timer.start()
                        setPositionChange(currentIndex)
                    }
                }
            }
        }
    }
}
