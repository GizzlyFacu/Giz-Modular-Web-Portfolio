import QtQuick
import QtQuick.Controls.Basic
import com.library
Item {
    id:root
    property string principalFont: "Comic Sans MS"
    property string secondaryFont: "Arial"

    property color backgroundItemsLight: "White"
    property color text: "White"
    property color textDarker: "#6f6f6f"
    property color textLinks: "#A1B0FF"

    Text{
        id:title
        anchors.horizontalCenter: parent.horizontalCenter
        text:"TECH SKILLS"
        font{
            pixelSize: 40
            family: root.principalFont
        }
        color:root.text
        horizontalAlignment: Text.AlignHCenter
    }
    Row{
        id:controls
        property int index: 0
        anchors{
            top:title.bottom
            topMargin:25
            horizontalCenter: parent.horizontalCenter
        }

        spacing: 0
        Button{
            width: 214
            height: 61
            text:"CODING"
            font{
                pixelSize: 24
                family: root.principalFont
            }
            background: Rectangle{
                anchors.fill: parent
                color:parent.pressed ? Qt.darker(root.backgroundItemsLight) : root.backgroundItemsLight
            }
            onClicked: controls.index = 0
        }
        Button{
            width: 214
            height: 61
            text:"3D ART"
            font{
                family: root.principalFont
                pixelSize: 24
            }
            background: Rectangle{
                anchors.fill: parent
                color:parent.pressed ? Qt.darker(root.backgroundItemsLight) : root.backgroundItemsLight
            }

            onClicked: controls.index = 1
        }
        Button{
            width: 214
            height: 61
            text:"3D GRAPHICS"
            font{
                family: root.principalFont
                pixelSize: 24
            }
            background: Rectangle{
                anchors.fill: parent
                color:parent.pressed ? Qt.darker(root.backgroundItemsLight) : root.backgroundItemsLight
            }
            onClicked: controls.index = 2
        }
        Button{
            width: 214
            height: 61
            text:"UE"
            font{
                family: root.principalFont
                pixelSize: 24
            }
            background: Rectangle{
                anchors.fill: parent
                color:parent.pressed ? Qt.darker(root.backgroundItemsLight) : root.backgroundItemsLight
            }
            onClicked: controls.index = 3
        }

    }
    Item{
        id:bodycontent
        height:340
        width: 977
        anchors{
            top:controls.bottom
            topMargin: 46
            horizontalCenter: parent.horizontalCenter
        }
        Loader{
            id:contentloader
            anchors.left: parent.left
            height: parent.height
            width: 401
            sourceComponent: widgetsets.set[controls.index].sourceComponent
            //componentInteractive
        }
        Text{
            id:contentTitle
            anchors.left: contentloader.right
            anchors.leftMargin: 45
            anchors.right: parent.right
            height: 33
            text:widgetsets.set[controls.index].contentTitle
            color:root.text
            font{
                pixelSize: 32
                family: root.principalFont
            }
            verticalAlignment: Text.AlignVCenter
            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
            elide: Text.ElideRight
            /*
            Rectangle{
                anchors.fill: parent
                color:"black"
            }
            */
        }
        Text{
            id:contentDescription
            anchors{
                top:contentTitle.bottom
                topMargin: 38
                left: contentloader.right
                leftMargin: 45
            }
            height: 133
            width: 400
            text:widgetsets.set[controls.index].contentDescription
            color:root.text
            font{
                pixelSize: 14
                family: root.secondaryFont
            }
            verticalAlignment: Text.AlignVCenter
            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
            elide: Text.ElideRight

        }

        ListView{
            id:projectsView
            anchors{
                bottom: parent.bottom
                right: parent.right
                left: contentloader.right
                leftMargin: 45
            }
            height: 135
            orientation: ListView.Horizontal
            model:widgetsets.set[controls.index].projectModel
            delegate: componentProjects
            clip: true
        }
    }

    //-------------Components-------------------
    Component{
        id:componentInteractive
        Rectangle{
            anchors.fill: parent
            color:"red"
        }
    }

    Component{
        id:componentProjects
        Item{
            id:base
            width: 163
            height: 135
            required property string title
            required property string photoLink
            required property string link
            Text{
                anchors{
                    right: parent.right
                    left:parent.left
                    top:parent.top
                }
                height: 16
                text:base.title
                color:root.textDarker
                font{
                    pixelSize: 14
                    family: root.secondaryFont
                }
                wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                elide: Text.ElideRight
            }
            ImageRounded{
                source: base.photoLink
                anchors{
                    right: parent.right
                    left:parent.left
                    bottom: parent.bottom
                }
                height: 108
                radius:10
            }
            MouseArea{
                anchors.fill: parent
                onClicked: Qt.openUrlExternally(base.link)
            }
        }
    }
    //-------------Structs----------------------
    /*

    Giz hear me you can add motto things like this
    Coding (index 0): widgetsets.set[0].contentTitle
                      widgetsets.set[0].contentDescription
                      widgetsets.set[0].projectModel
                      widgetsets.set[0].sourceComponent
    to do: add this to the principal project an
    add a ImageRounded to the componentdelegate
    */
    Item {
        id:widgetsets
        width: 10
        height: 10
        property list<QtObject> set: [
            QtObject{
                property string contentTitle: "Coding"
                property string contentDescription: "Description"
                property QtObject projectModel:StorageManager.techskillsmodel
                property Component sourceComponent:Component{
                    Rectangle{
                        anchors.fill: parent
                        color:"Yellow"
                    }
                }

            },
            QtObject{
                property string contentTitle: "3D Art"
                property string contentDescription: "Description 2"
                property QtObject projectModel: StorageManager.techskills3dartmodel
                property Component sourceComponent:Component{
                    Rectangle{
                        anchors.fill: parent
                        color:"Black"
                    }
                }

            },
            QtObject{
                property string contentTitle: "3D Graphics"
                property string contentDescription: "Description 3"
                property QtObject projectModel:StorageManager.techskills3dgraphics
                property Component sourceComponent:Component{
                    Rectangle{
                        anchors.fill: parent
                        color:"Green"
                    }
                }

            },
            QtObject{
                property string contentTitle: "UE"
                property string contentDescription: "Description 4"
                property QtObject projectModel:StorageManager.techskillsUEmodel
                property Component sourceComponent:Component{
                    Rectangle{
                        anchors.fill: parent
                        color:"Blue"
                    }
                }

            }
        ]
    }

}

