import QtQuick
import QtQuick.Controls.Basic
import com.library
Item {
    id:root
    property string principalFont: "Lato"
    property string secondaryFont: "Roboto"

    property color backgroundItemsLight: "White"
    property color text: "White"
    property color textDarker: "#6f6f6f"
    property color textLinks: "#A1B0FF"

    Text{
        id:title
        anchors.horizontalCenter: parent.horizontalCenter
        text:"TECH SKILLS"
        font{
            pixelSize: 24
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
            width: root.width < 970 ? 78 : 214
            height:root.width < 970 ? 37 : 61
            text:"CODING"
            font{
                pixelSize: root.width < 970 ? 12 : 24
                family: root.principalFont
            }
            background: Rectangle{
                anchors.fill: parent
                color:parent.pressed ? Qt.darker(root.backgroundItemsLight) : root.backgroundItemsLight
            }
            onClicked: controls.index = 0
        }
        Button{
            width: root.width < 970 ? 78 : 214
            height:root.width < 970 ? 37 : 61
            text:"3D ART"
            font{
                family: root.principalFont
                pixelSize: root.width < 970 ? 12 : 24
            }
            background: Rectangle{
                anchors.fill: parent
                color:parent.pressed ? Qt.darker(root.backgroundItemsLight) : root.backgroundItemsLight
            }

            onClicked: controls.index = 1
        }
        Button{
            width: root.width < 970 ? 78 : 214
            height:root.width < 970 ? 37 : 61
            text:"GRAPHICS"
            font{
                family: root.principalFont
                pixelSize: root.width < 970 ? 12 : 24
            }
            background: Rectangle{
                anchors.fill: parent
                color:parent.pressed ? Qt.darker(root.backgroundItemsLight) : root.backgroundItemsLight
            }
            onClicked: controls.index = 2
        }
        Button{
            width: root.width < 970 ? 78 : 214
            height:root.width < 970 ? 37 : 61
            text:"UE"
            font{
                family: root.principalFont
                pixelSize: root.width < 970 ? 12 : 24
            }
            background: Rectangle{
                anchors.fill: parent
                color:parent.pressed ? Qt.darker(root.backgroundItemsLight) : root.backgroundItemsLight
            }
            onClicked: controls.index = 3
        }
    }
    Item{
        id:bodycontentMobile
        enabled:root.width < 970 ? true : false
        opacity:root.width < 970 ? 1 : 0
        height:272
        anchors{
            top:controls.bottom
            topMargin: 46
            horizontalCenter: parent.horizontalCenter
            left:parent.left
            right: parent.right
        }

        ImageRounded{
            id:contentImager
            anchors.right: parent.horizontalCenter
            anchors.rightMargin: 30
            fillMode: Image.PreserveAspectCrop
            height: 135
            width: 135
            radius: 10
            source:widgetsets.set[controls.index].contentImagerPhoto
        }
        Text{
            id:contentTitle
            anchors{
                left: parent.horizontalCenter
                leftMargin: 0
                right: parent.right
            }
            height: 31
            text:widgetsets.set[controls.index].contentTitle
            color:root.text
            font{
                pixelSize: 24
                family: root.principalFont
            }
            verticalAlignment: Text.AlignVCenter
            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
            elide: Text.ElideRight
        }
        Text{
            id:contentDescription
            anchors{
                top:contentTitle.bottom
                topMargin: 15
                left: parent.horizontalCenter
                leftMargin: 0
                right: parent.right
            }
            height: 94
            //width: 218
            text:widgetsets.set[controls.index].contentDescription
            color:root.text
            font{
                pixelSize: 12
                family: root.secondaryFont
            }
            verticalAlignment: Text.AlignVCenter
            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
            elide: Text.ElideRight
        }

        ListView{
            id:projectsView
            spacing: 5
            anchors{
                bottom: parent.bottom
                right: parent.right
                left: contentImager.left
            }
            height: 111
            orientation: ListView.Horizontal
            model:widgetsets.set[controls.index].projectModel
            delegate: componentProjects
            clip: true
        }
    }

    Item{
        id:bodycontentDesktop
        enabled:root.width < 970 ? false : true
        opacity:root.width < 970 ? 0 : 1
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
            id:contentTitleDesktop
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
        }
        Text{
            id:contentDescriptionDesktop
            anchors{
                top:contentTitleDesktop.bottom
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
            id:projectsViewDesktop
            spacing: 5
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

    //-------------Data Components-------------------
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
            width: root.width < 1200 ? 127 : 163
            height: root.width < 1200 ? 106 : 135
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
                height: root.width < 1200 ? 84:108
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

    Giz hear me you can add more things like this
    Coding (index 0): widgetsets.set[0].contentTitle
                      widgetsets.set[0].contentDescription
                      widgetsets.set[0].projectModel
                      widgetsets.set[0].sourceComponent
    */
    Item {
        id:widgetsets
        width: 10
        height: 10
        property list<QtObject> set: [
            QtObject{
                property string contentTitle: "Coding"
                property string contentDescription: "Desarrollo aplicaciones de escritorio modernas con C++ y Qt, integrando interfaces en QML y flujos de trabajo organizados con CMake y Git."
                property QtObject projectModel:StorageManager.techskillsmodel
                property string contentImagerPhoto: "qrc:/images/assets/imagesLocal/CppImager.jpeg"
                property Component sourceComponent:Component{
                    Image{
                        anchors.fill: parent
                        fillMode: Image.PreserveAspectCrop
                        source: "qrc:/images/assets/imagesLocal/CppImager.jpeg"
                    }
                }


            },
            QtObject{
                property string contentTitle: "3D Art"
                property string contentDescription: "Description 2"
                property QtObject projectModel: StorageManager.techskills3dartmodel
                property string contentImagerPhoto: "qrc:/images/assets/imagesLocal/3DArtImager2.jpg"
                property Component sourceComponent:Component{
                    Image{
                        anchors.fill: parent
                        fillMode: Image.PreserveAspectCrop
                        source: "qrc:/images/assets/imagesLocal/3DArtImager2.jpg"
                    }
                }

            },
            QtObject{
                property string contentTitle: "Graphics"
                property string contentDescription: "Description 3"
                property QtObject projectModel:StorageManager.techskills3dgraphics
                property string contentImagerPhoto: "qrc:/images/assets/imagesLocal/GraphicsImager.jpg"
                property Component sourceComponent:Component{
                    Image{
                        anchors.fill: parent
                        fillMode: Image.PreserveAspectCrop
                        source: "qrc:/images/assets/imagesLocal/GraphicsImager.jpg"
                    }
                }
            },
            QtObject{
                property string contentTitle: "UE"
                property string contentDescription: "Description 4"
                property QtObject projectModel:StorageManager.techskillsUEmodel
                property string contentImagerPhoto: "qrc:/images/assets/imagesLocal/UEImager.jpg"
                property Component sourceComponent:Component{
                    Image{
                        anchors.fill: parent
                        fillMode: Image.PreserveAspectCrop
                        source: "qrc:/images/assets/imagesLocal/UEImager.jpg"
                    }
                }
            }
        ]
    }

}

