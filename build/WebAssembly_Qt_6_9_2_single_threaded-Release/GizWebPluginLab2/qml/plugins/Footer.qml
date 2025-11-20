import QtQuick

Item {
    id:root
    property color backgroundItemsDark: Qt.darker("gray")
    property color textDarker: "gray"
    property string secondaryFont:"Roboto"
    Rectangle{
        anchors.fill: parent
        color:root.backgroundItemsDark
    }
    Text{
        anchors.fill: parent
        text:"MADE WITH QT"
        color: root.textDarker
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font{
            pixelSize:14
            family:root.secondaryFont
        }
    }
}
