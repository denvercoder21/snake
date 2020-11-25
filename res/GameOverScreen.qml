import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12
import QtGraphicalEffects 1.0

Rectangle {
    id: root

    signal restartClicked
    signal highscoreClicked

    radius: 15

    color: "white"

    visible: false

    layer.enabled: true
    layer.effect: DropShadow {
        transparentBorder: true
        color: "#888888"
        samples: 32
    }

    ColumnLayout {
        id: layout

        anchors {
            fill: root
            margins: 20
        }

        spacing: 12

        Text {
            id: headline

            Layout.alignment: Qt.AlignTop
            Layout.fillWidth: true

            horizontalAlignment: Qt.AlignHCenter

            text: qsTr("Game Over")
            font {
                pixelSize: 30
            }
        }

        Item {
            id: dummy

            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        RoundButton {
            id: restartButton

            Layout.alignment: Qt.AlignTop
            Layout.fillWidth: true

            radius: 10

            text: qsTr("Restart Game")

            onClicked: restartClicked()
        }

        RoundButton {
            id: highscoreButton

            Layout.alignment: Qt.AlignTop
            Layout.fillWidth: true

            radius: 10

            text: qsTr("Highscore")

            onClicked: highscoreClicked()
        }
    }
}
