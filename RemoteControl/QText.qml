import QtQuick 2.0

Text {
    id: title

    property alias labelText: title.text
    property alias labelColor: title.color
    property alias labelFontSize: title.font.pixelSize
    property alias labelFontFamily: title.font.family

    color: "black"
    font.pixelSize: 20
    font.family: "Helvetica"
}
