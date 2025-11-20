import QtQuick

Item {
    id:root
    property color color:"gray"
    height: 1
    Rectangle{
        anchors.fill: parent
        color:root.color
    }
}
