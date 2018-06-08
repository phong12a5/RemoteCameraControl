import QtQuick 2.0

Item {
    id : root
    property int activedIndex: 0
    property int currentIndex: 0
    property int nodeWidth: 30
    property int space : 30


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
        anchors.verticalCenter: root.verticalCenter
        anchors.left: titleComp.right
        anchors.leftMargin: 10
        Rectangle
        {
            id: node

            property bool isClicked : false

            x: position.x + index * (nodeWidth + space)
            anchors.verticalCenter: parent.verticalCenter
            radius: nodeWidth/2
            width: nodeWidth
            height: nodeWidth
            color: index === activedIndex? "#7FFF00" :(mouseArea.pressed? "gray" : "#EDEDED")
            border.width: 2
            border.color: "black"
            opacity: root.enabled? 1: 0.5

            LoadingComponent{
                id: loading
                visible: root.enabled && isClicked && currentIndex == index && activedIndex != index
            }

            Timer{
                id: timer
                interval: 5000
                running: false
                onTriggered: {
                    isClicked = false
                }
            }

            MouseArea{
                id: mouseArea
                anchors.fill: parent
                onReleased: {
                    if(activedIndex === index) return
                    currentIndex = index
                    isClicked = true
                    timer.start()
                    setPositionChange(currentIndex)
                }
            }
        }
    }
}
