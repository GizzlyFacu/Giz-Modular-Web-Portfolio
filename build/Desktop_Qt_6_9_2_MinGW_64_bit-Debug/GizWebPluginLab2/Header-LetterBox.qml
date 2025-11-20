import QtQuick 2.15

Item {
    property string text: "Default"
    width:139
    height:50
    Rectangle{
        anchors.fill: parent
        color:"black"
    }
    Text{
        anchors.centerIn: parent
        text: parent.text
        font.family: "Comic Sans MS"
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pointSize: 24
        color: "white"
    }
    MouseArea{
        id:page1
        anchors.fill: parent
        onClicked: {
            console.log("*ir al pdf de "+parent.text)
        }
    }
}
