import QtQuick 2.15

Item {
    id:root
    property string textString: "Default"
    property color backgroundItemsDark: "black"
    property color text: "red"
    property string principalFont: "Arial"
    signal clicked();
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
    Rectangle{
        id:rectangleTop
        height: 1
        width: parent.width*0.5

        anchors{
            top: parent.top
            horizontalCenter: parent.horizontalCenter
        }
        color: root.text
    }

    Text{
        anchors.centerIn: parent
        text: parent.textString
        font.family: root.principalFont
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pointSize: 24
        color: root.text
    }
    MouseArea{
        id:page1
        anchors.fill: parent
        onClicked: root.clicked()
        hoverEnabled: true
    }
    Rectangle{
        id:rectangleBot
        height: 1
        width: parent.width*0.5

        anchors{
            bottom: parent.bottom
            horizontalCenter: parent.horizontalCenter
        }
        color: root.text
    }
}
