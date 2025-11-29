import QtQuick

Item {
    id:root
    property color nameColor: "red"
    Rectangle{
        anchors.fill: parent
        color:"cyan"
    }
    Loader{
        width: root.width
        height: root.height
        active:true
        sourceComponent: root.width < 1200 ? bigband : bigbond
        asynchronous: true
    }


    Component{
        id:bigband
        Rectangle{
            anchors.fill: parent
            color:root.nameColor
        }
    }
    Component{
        id:bigbond
        Rectangle{
            anchors.fill: parent
            color:"yellow"
        }
    }
}
