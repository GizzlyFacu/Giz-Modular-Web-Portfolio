import QtQuick 2.15

Item {


    id:root
    readonly property color background: figmadesign.background
    readonly property color backgroundItemsDark: figmadesign.backgroundItemsDark
    readonly property color backgroundItemsLight: figmadesign.backgroundItemsLight
    readonly property string principalFont:figmadesign.principalFont
    readonly property string secondaryFont:figmadesign.secondaryFont
    readonly property color text: figmadesign.text
    readonly property color textDarker: figmadesign.textDarker
    readonly property color textLinks: figmadesign.textLinks

    QtObject {
        id:figmadesign
        property color background: "#101014"
        property color backgroundItemsDark: "#3C3C3C"
        property color backgroundItemsLight: "#D9D9D9"
        property string principalFont:"Lato"
        property string secondaryFont:"Roboto"
        property color text: "#ffffff"
        property color textDarker: "#9F9F9F"
        property color textLinks: "#A1B0FF"
    }

    //fonts
    FontLoader{
        id:latoRLoader
        source:"qrc:/fonts/assets/fonts/Lato-Regular.ttf"
    }
    FontLoader{
        id:latoBLoader
        source:"qrc:/fonts/assets/fonts/Lato-Bold.ttf"
    }
    FontLoader{
        id:robotoRLoader
        source:"qrc:/fonts/assets/fonts/Roboto-Regular.ttf"
    }
    FontLoader{
        id:robotoBLoader
        source:"qrc:/fonts/assets/fonts/Roboto-Bold.ttf"
    }
}
