import QtQuick 2.15
import QtQuick.Effects
Item {
    id:root
    required property string source;
    required property int radius;
    Image {
        id: sourceItem
        source: parent.source
        anchors.centerIn: parent
        width: parent.width
        height: parent.height
        visible: false
    }

    MultiEffect {
        source: sourceItem
        anchors.fill: sourceItem
        maskEnabled: true
        maskSource: mask
    }

    Item {
        id: mask
        width: sourceItem.width
        height: sourceItem.height
        layer.enabled: true
        visible: false

        Rectangle {
            width: sourceItem.width
            height: sourceItem.height
            radius: root.radius
            color: "black"
        }
    }
}
