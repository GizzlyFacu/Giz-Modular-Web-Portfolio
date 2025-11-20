import QtQuick

Item {
    id:root
    property color color: "white"
    property string text: "Arial"
    property color textBlack: "Black"
    property color textGray: "Gray"

    ListModel {
        id:cardModel
        ListElement {
            textInfo: "Bill Smith"
            textSubInfo: "555 3264"
            source: "qrc:/images/assets/imagesLocal/yo.jpeg"
        }
        ListElement {
            textInfo: "1Bill Smith"
            textSubInfo: "1555 3264"
            source: "qrc:/images/assets/imagesLocal/yo.jpeg"
        }
        ListElement {
            textInfo: "2Bill Smith"
            textSubInfo: "2555 3264"
            source: "qrc:/images/assets/imagesLocal/yo.jpeg"
        }
    }

    ListView{
        anchors.fill: parent
        spacing: 20
        orientation: ListView.Horizontal
        model:cardModel
        delegate:         Item{
            id:cardsItem
            width: 392
            height: 218
            required property string textInfo
            required property string textSubInfo
            required property string source
            ImageRounded{
                anchors.fill: parent
                source: cardsItem.source
                radius: 10
            }
            Text{
                id:subText
                anchors{
                    bottom: parent.bottom
                    bottomMargin: 10
                    left: parent.left
                    leftMargin: 24
                    right: parent.right
                    rightMargin: 59
                }

                text:cardsItem.textSubInfo
                font{
                    family: root.text
                    bold: true
                    pixelSize: 15
                }
                color: root.textGray
                verticalAlignment: Text.AlignBottom
                wrapMode: Text.WrapAtWordBoundaryOrAnywhere
            }
            Text{
                id:text
                anchors{
                    bottom: subText.top
                    bottomMargin: 10
                    left: parent.left
                    leftMargin: 24
                    right: parent.right
                    rightMargin: 24
                }
                text:cardsItem.textInfo
                font{
                    family: root.text
                    bold: true
                    pixelSize: 24
                }
                color:root.textBlack
                verticalAlignment: Text.AlignBottom
                wrapMode: Text.WrapAtWordBoundaryOrAnywhere
            }
        }
    }
}
