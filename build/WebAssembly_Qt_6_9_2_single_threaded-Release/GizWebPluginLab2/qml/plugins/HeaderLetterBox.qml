import QtQuick 2.15

Item {
    id:root
    property string text: "Default"
    property color backgroundItemsDark: "black"
    width:139
    height:50
    Rectangle{
        id:backgroundRect
        anchors.fill: parent
        color:page1.pressed ?
                  Qt.lighter(root.backgroundItemsLight) : root.backgroundItemsLight ||
              page1.containsMouse ?
                  Qt.lighter(root.backgroundItemsDark) : root.backgroundItemsDark
        radius: 10
    }
    Text{
        anchors.centerIn: parent
        text: parent.text
        font.family: "Roboto"
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pointSize: 24
        color: "white"
    }
    MouseArea{
        id:page1
        anchors.fill: parent
        onClicked: {
            console.log("*ir al pdf de "+parent.text);
        }
        hoverEnabled: true
    }
}
