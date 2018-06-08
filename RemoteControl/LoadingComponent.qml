import QtQuick 2.0

Image {
    id: root
    source: "qrc:/LoadingIcon.png"
    width: 30
    height: 30
    Timer{
        interval: 50
        running: true
        repeat: true
        onTriggered:
        {
            root.rotation += 30
            if(root.rotation == 360)
            {
                root.rotation = 0
            }
        }
    }
}
