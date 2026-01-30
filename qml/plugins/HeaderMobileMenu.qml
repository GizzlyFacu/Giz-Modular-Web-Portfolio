import QtQuick 2.15
import QtQuick.Controls.Basic
Item {
    id:root
    property string buttonFontFamily:"Roboto"
    Column{
        id:rootColumn
        property int buttonsHeight: 50
        anchors.fill: parent
        Button{
            id:but1
            anchors.left: parent.left
            anchors.right: parent.right
            height: parent.buttonsHeight
            contentItem: Text {
                text: "Projects"
                font: root.buttonFontFamily
                color: "white"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter }
            background: Rectangle{
                color:but1.down ? Qt.lighter("gray"):Qt.darker("gray")
            }
        }
        Button{
            id:but2
            anchors.left: parent.left
            anchors.right: parent.right
            height: parent.buttonsHeight
            contentItem: Text {
                text: "Labs"
                font: root.buttonFontFamily
                color: "white"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter }
            background: Rectangle{
                color:but2.down ? Qt.lighter("gray"):Qt.darker("gray")
            }
        }
        Button{
            id:but3
            anchors.left: parent.left
            anchors.right: parent.right
            height: parent.buttonsHeight
            contentItem: Text {
                text: "Contact"
                font: root.buttonFontFamily
                color: "white"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter }
            background: Rectangle{
                color:but3.down ? Qt.lighter("gray"):Qt.darker("gray")
            }
            onClicked: Qt.openUrlExternally("https://www.linkedin.com/in/facugizzly/")
        }
    }
}
