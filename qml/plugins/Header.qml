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
        anchors{
            verticalCenter: parent.verticalCenter
            left: parent.left
            leftMargin: base.width*0.0958
        }

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
        anchors{
            verticalCenter: parent.verticalCenter
            right: parent.right
            rightMargin: 85
        }
        spacing:2
        HeaderLetterBox{
            id:letterbox1
            backgroundItemsDark:base.backgroundItemsDark
            textString:"Projects"
            text:base.text
            principalFont:base.principalFont
        }
        HeaderLetterBox{
            id:letterbox2
            backgroundItemsDark:base.backgroundItemsDark
            textString:"Labs"
            text:base.text
            principalFont:base.principalFont
        }
        HeaderLetterBox{
            id:letterbox3
            backgroundItemsDark:base.backgroundItemsDark
            textString:"Contact"
            text:base.text
            principalFont:base.principalFont
            onClicked: Qt.openUrlExternally("https://www.linkedin.com/in/facugizzly/")
        }
    }

    //---------------Mobile--------------------------
    Rectangle{
        id:menuButton
        visible: !base.isMobile
        anchors{
            verticalCenter: parent.verticalCenter
            right: parent.right
            rightMargin: base.width*0.0958
        }

        color:base.text
        radius:10
        height: 40
        width: 40
        MouseArea{
            id:page1
            anchors.fill: parent
            onClicked: {
                base.menuVisible = !base.menuVisible;
                base.openMenu();
            }
        }
        Column{
            spacing: 6
            anchors{
                verticalCenter: menuButton.verticalCenter
                horizontalCenter: menuButton.horizontalCenter
            }

            Repeater {
                model: 3
                Rectangle{
                    height: 4
                    radius: 2
                    width: menuButton.width*0.7
                    anchors{
                        horizontalCenter: parent.horizontalCenter
                    }
                    color: base.backgroundItemsDark
                }
            }
        }
    }
}
