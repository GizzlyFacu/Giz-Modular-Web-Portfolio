import QtQuick 2.15
import QtQuick.Effects

Item {
    id:root
    required property string source;
    required property int radius;
    property alias fillMode: sourceAnimatedItem.fillMode

    AnimatedImage{
        id: sourceAnimatedItem
        source: parent.source
        anchors.centerIn: parent
        width: parent.width
        height: parent.height
        visible: false
        asynchronous: true
        playing: true
    }
    MultiEffect {
        source: sourceAnimatedItem
        anchors.fill: sourceAnimatedItem
        maskEnabled: true
        maskSource: mask
    }

    Item {
        id: mask
        width: sourceAnimatedItem.width
        height: sourceAnimatedItem.height
        layer.enabled: true
        visible: false

        Rectangle {
            width: sourceAnimatedItem.width
            height: sourceAnimatedItem.height
            radius: root.radius
            color: "#3C3C3C"
        }
    }

}
