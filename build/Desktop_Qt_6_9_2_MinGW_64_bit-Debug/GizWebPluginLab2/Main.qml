import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Basic
import GizWebPluginLab2
import com.library
Window {
    id:principalWindow
    width: 420//1366
    height: 800
    visible: true
    title: qsTr("Hello World")
    color:theme.background
    property bool isMobile: principalWindow.width < 1200 ? false : true


    Item{
        id:windowInterface
        anchors.fill: parent
    }
    Theme{
        id:theme
    }

    Flickable {
        id: flick
        anchors.fill: parent
        contentWidth: plugins.implicitWidth
        contentHeight: plugins.implicitHeight+100
        clip: true

        // Esto permite que la rueda del mouse mueva el contenido
        interactive: true
        boundsMovement: Flickable.StopAtBounds
        acceptedButtons: Qt.MiddleButton

        ColumnLayout{
            id:plugins
            //debug mode
            width: windowInterface.width-(windowInterface.width*0.0958*2)
            x:windowInterface.width*0.0958
            y:100
            clip: true
            spacing:32
            /*
            BoxIntroduction{
                id:boxIntro
                Layout.fillWidth: true
                Layout.preferredHeight: 600
                //internal properties
                principalFont: theme.principalFont
                backgroundItemsDark: theme.backgroundItemsDark
                backgroundItemsLight: theme.backgroundItemsLight
                text: theme.text
                textDarker: theme.textDarker
                textLinks: theme.textLinks
                image:Qt.url(StorageManager.boxintroduction.PhotoLink)
            }

            BlogCards{
                Layout.fillWidth: true
                Layout.preferredHeight: 224
                Layout.alignment: Qt.AlignVCenter
                principalFont:theme.principalFont
                text:theme.text
            }

            Separator{
                Layout.fillWidth: true
                color:theme.backgroundItemsLight
            }
            */
            TechSkills{
                Layout.fillWidth: true
                Layout.preferredHeight: 580
                //internal properties
                principalFont: theme.principalFont
                secondaryFont: theme.secondaryFont

                backgroundItemsLight: theme.backgroundItemsLight
                text: theme.text
                textDarker: theme.textDarker
                textLinks: theme.textLinks
            }
            /*
            Separator{
                Layout.fillWidth: true
                color:theme.backgroundItemsLight
            }
            Footer{
                id:footer
                Layout.fillWidth: true
                Layout.preferredHeight: 59

                backgroundItemsDark: theme.backgroundItemsDark
                textDarker: theme.textDarker
                secondaryFont:theme.secondaryFont
            }
            */
        }
    }



    StackLayout{
        id: pages
        anchors{
            top: windowInterface.top
            right: windowInterface.right
            left: windowInterface.left
            bottom: windowInterface.bottom
            topMargin: 98
            leftMargin: windowInterface.width*0.0958
            rightMargin: windowInterface.width*0.0958
        }
        currentIndex: 4

        HeaderMobileMenu{
            visible: !principalWindow.isMobile && header1.menuVisible
            Layout.fillHeight: true
            Layout.fillWidth: true
        }


        Rectangle {
            color: 'green'
            implicitWidth: 300
            implicitHeight: 200
        }
    }

    Header{
        id:header1
        isMobile: principalWindow.width < 1200 ? false : true
        width: windowInterface.width
        height: 98
        anchors{
            horizontalCenter: windowInterface.horizontalCenter
        }

        //internal properties
        principalFont: theme.principalFont
        backgroundItemsDark: theme.background
        text: theme.text
        textDarker: theme.textDarker
        //internal signals
        onOpenMenu: {
            pages.currentIndex = menuVisible ? 0 : 4;
        }
        onHomeButtonPressed: plugins.y = 0
    }
}
