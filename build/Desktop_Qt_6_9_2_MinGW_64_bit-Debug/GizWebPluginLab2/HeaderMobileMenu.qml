import QtQuick 2.15
import QtQuick.Controls.Basic
Item {
    Column{
        id:rootColumn
        property int buttonsHeight: 50
        property string buttonFontFamily:"Comic Sans MS"
        anchors.fill: parent
        Button{
            id:but1
            anchors.left: parent.left
            anchors.right: parent.right
            height: parent.buttonsHeight
            contentItem: Text {
                text: "Projects"
                font: rootColumn.buttonFontFamily
                color: "white"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter }
            background: Rectangle{
                color:but1.down ? Qt.lighter("gray"):Qt.darker("gray")
            }
            onClicked: console.log("ir al pdf pero mobile")
        }
        Button{
            id:but2
            anchors.left: parent.left
            anchors.right: parent.right
            height: parent.buttonsHeight
            contentItem: Text {
                text: "Labs"
                font: rootColumn.buttonFontFamily
                color: "white"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter }
            background: Rectangle{
                color:but2.down ? Qt.lighter("gray"):Qt.darker("gray")
            }
            onClicked: console.log("ir al pdf pero mobile")
        }
        Button{
            id:but3
            anchors.left: parent.left
            anchors.right: parent.right
            height: parent.buttonsHeight
            contentItem: Text {
                text: "Contact"
                font: rootColumn.buttonFontFamily
                color: "white"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter }
            background: Rectangle{
                color:but3.down ? Qt.lighter("gray"):Qt.darker("gray")
            }
            onClicked: console.log("ir al pdf pero mobile")
        }
    }
}
