import QtQuick 2.15
import QtQuick.Controls

Item {
    id:base
    required property bool isMobile
    property bool menuVisible: false
    signal openMenu()
    Rectangle{
        anchors.fill: parent
        color:Qt.darker("gray")
    }
    Text{
        anchors.verticalCenter: parent.verticalCenter
        verticalAlignment: Text.AlignVCenter
        text:"Facu Giz"
        font.pointSize: 40
        color: "white"
    }

    Row{
        id:webMenu
        visible: base.isMobile
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.right
        spacing:2
        HeaderLetterBox{
            id:letterbox1
            text:"Projects"
        }
        HeaderLetterBox{
            id:letterbox2
            text:"Labs"
        }
        HeaderLetterBox{
            id:letterbox3
            text:"Contact"
        }
    }

    //---------------Mobile--------------------------
    Rectangle{
        visible: !base.isMobile
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.right
        color:"white"
        radius:10
        height: 50
        width: 50
        MouseArea{
            id:page1
            anchors.fill: parent
            onClicked: {
                base.menuVisible = !base.menuVisible;
                base.openMenu();
            }
        }
    }
}
