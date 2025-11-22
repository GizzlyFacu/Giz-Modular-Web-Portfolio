import QtQuick 2.15
import QtQuick.Controls.Basic
import QtQuick.Layouts


Item {
    id:root
    property string image: "qrc:/images/assets/imagesLocal/loader.jpg"
    property string principalFont: "Comic Sans MS"

    property color backgroundItemsDark: "#2f2f2f"
    property color backgroundItemsLight: "White"
    property color text: "White"
    property color textDarker: "#6f6f6f"
    property color textLinks: "#A1B0FF"

    Rectangle{
        id:background
        anchors.fill: parent
        color:root.backgroundItemsLight
        radius:10
    }
    Rectangle{
        id:corredor
        property int offset: parent.width - 300

        color: root.backgroundItemsDark
        radius:10
        height: parent.height
        width: parent.width
        x:parent.x + offset

        Item{
            height: parent.height
            width: 238
            anchors.left: parent.left
            anchors.leftMargin: 31
            ImageRounded{
                id:imagerounded
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: parent.top
                anchors.topMargin: 32
                width: 133
                height: 124
                source:root.image
                radius:10
            }
            Text{
                id:nameInfo
                anchors{
                    top: imagerounded.bottom
                    topMargin: 8
                    horizontalCenter: parent.horizontalCenter
                }
                color: root.text
                text:"Facu Giz"
                font{
                    family: root.principalFont
                    bold: true
                    pixelSize: 24
                }
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignBottom
            }
            Text{
                id:subInfo
                anchors{
                    top: nameInfo.bottom
                    horizontalCenter: parent.horizontalCenter
                }
                text:"Tech Artist"
                color: root.textDarker
                font{
                    family: root.principalFont
                    pixelSize: 14
                }
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignBottom
            }
            Text{
                id:locationInfo
                anchors{
                    top: subInfo.bottom
                    topMargin: 30
                    horizontalCenter: parent.horizontalCenter
                }
                text:"• Cordoba  Capital Argentina"
                color: root.textDarker
                font{
                    family: root.principalFont
                    pixelSize: 14
                }
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
            Text{
                id:buzzwordsInfo
                width: parent.width
                anchors{
                    top: locationInfo.bottom
                    topMargin: 30
                    horizontalCenter: parent.horizontalCenter
                }
                text:"Descripcion lore impsum etc zzz me encantan las bananas ricas pero solo para licuado sisi ajsdjasdja asdasas sadasd...."
                color: root.text
                font{
                    family: root.principalFont
                    pixelSize: 14
                }
                horizontalAlignment: Text.AlignJustify
                verticalAlignment: Text.AlignVCenter
                wrapMode: Text.WrapAtWordBoundaryOrAnywhere
            }
            Text{
                id:moreaboutmeInfo
                width: parent.width
                anchors{
                    top: buzzwordsInfo.bottom
                    topMargin: 8
                    horizontalCenter: parent.horizontalCenter
                }
                text:"More about me"
                color: root.textLinks
                font{
                    family: root.principalFont
                    pixelSize: 14
                }
                horizontalAlignment: Text.AlignJustify
                verticalAlignment: Text.AlignVCenter
                wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                MouseArea{
                    property bool flipflop: true
                    anchors.fill: parent
                    onClicked: flipflopOn()

                    function flipflopOn(){
                        if(flipflop){
                            transitionCorridor.start();
                            moreaboutmeInfo.text="Less about me"
                        }
                        else{
                            transitionCorridorback.start();
                            moreaboutmeInfo.text="More about me";
                        }
                        flipflop = !flipflop;
                    }
                }
            }
            Rectangle{
                id:separator
                anchors{
                    top: moreaboutmeInfo.bottom
                    topMargin: 16
                    horizontalCenter: parent.horizontalCenter
                }
                color:"#6f6f6f"
                width: parent.width
                height: 1
            }
            Text{
                id:socialsInfo
                width: parent.width
                anchors{
                    top: separator.bottom
                    topMargin: 16
                    horizontalCenter: parent.horizontalCenter
                }
                text:"Follow on social"
                color: root.textDarker
                font{
                    family: root.principalFont
                    pixelSize: 14
                }
                horizontalAlignment: Text.AlignJustify
                verticalAlignment: Text.AlignVCenter
                wrapMode: Text.WrapAtWordBoundaryOrAnywhere
            }
            Row{
                anchors{
                    top: socialsInfo.bottom
                    topMargin: 8
                }
                spacing: 16
                ImageRounded{
                    id:social1
                    width: 32
                    height: 32
                    source:"qrc:/icons/assets/icons/linkedin.png"
                    radius:10
                    MouseArea{
                        anchors.fill: parent
                        onClicked: Qt.openUrlExternally("https://www.linkedin.com/in/facugizzly/")
                    }
                }
                ImageRounded{
                    id:social2
                    width: 32
                    height: 32
                    source:"qrc:/icons/assets/icons/steam.png"
                    radius:10
                    MouseArea{
                        anchors.fill: parent
                        onClicked: Qt.openUrlExternally("https://steamcommunity.com/id/gizzlyfacu")
                    }
                }
                ImageRounded{
                    id:social3
                    width: 32
                    height: 32
                    source:"qrc:/icons/assets/icons/plus.png"
                    radius:10
                    MouseArea{
                        anchors.fill: parent
                        onClicked: Qt.openUrlExternally("https://linktr.ee/facugizzly")
                    }
                }
            }
        }

        NumberAnimation on offset{
            id:transitionCorridor
            running: false
            to: 0
            duration: 500
            easing.type: Easing.OutBounce
        }
        NumberAnimation on offset{
            id:transitionCorridorback
            running: false
            to: root.width - 300
            duration: 500
            easing.type: Easing.OutQuad
        }
    }
}
