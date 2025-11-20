import QtQuick 2.15
import QtQuick.Controls

Item {
    id:base
    required property bool isMobile
    property bool menuVisible: false
    signal openMenu()
    signal homeButtonPressed()
    //palette
    property color backgroundItemsDark:"gray"
    property string principalFont: "Comic Sans MS"
    property color text: "white"
    property color textDarker: Qt.darker("gray")
    Rectangle{
        anchors.fill: parent
        color:base.backgroundItemsDark
    }
    Text{
        anchors.verticalCenter: parent.verticalCenter
        verticalAlignment: Text.AlignVCenter
        text:"FACU GIZ"
        font{
            pixelSize: 40
            family:base.principalFont
            bold:false
        }
        color: base.text
        MouseArea{
            anchors.fill: parent
            onClicked: base.homeButtonPressed()
        }
    }

    Row{
        id:webMenu
        visible: base.isMobile
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.right
        spacing:2
        HeaderLetterBox{
            id:letterbox1
            backgroundItemsDark:base.backgroundItemsDark
            text:"Projects"
        }
        HeaderLetterBox{
            id:letterbox2
            backgroundItemsDark:base.backgroundItemsDark
            text:"Labs"
        }
        HeaderLetterBox{
            id:letterbox3
            backgroundItemsDark:base.backgroundItemsDark
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
