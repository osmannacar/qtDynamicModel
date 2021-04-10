import QtQuick 2.0
import oscar.qmltypes 1.0

Rectangle{
    ListView {
        id:listView
        anchors.fill: parent
        model: controller.model()
        onModelChanged:{
            listView.currentIndex = -1
        }

        header: Rectangle {
            color: "transparent"
            width: parent.width
            height: 20
            Row{
                anchors.fill: parent
                Text {
                    width: parent.width / 5
                    height: parent.height
                    text: "IMPORTANCE"
                    color: "orange"
                }
                Text {
                    width: parent.width / 5
                    height: parent.height
                    text: "SOURCE"
                    color: "orange"
                }
                Text {
                    width: parent.width * 3 / 5
                    height: parent.height
                    text: "ERROR DEFINITION"
                    color: "orange"
                }
            }
        }

        delegate: Rectangle {
            color: (listView.currentIndex === model.index) ? "orange" : "transparent"
            property var txtColor: (listView.currentIndex === model.index) ? "red" : "Black"
            width: parent.width
            height: 20
            Row{
                anchors.fill: parent
                Text {
                    id:importance
                    width: parent.width  / 5
                    height: parent.height
                    text: model.importance
                    color: txtColor
                }
                Text {
                    id:source
                    width: parent.width / 5
                    height: parent.height
                    text: model.source
                    color: txtColor
                }

                Text {
                    id:errorDefinition
                    width: parent.width * 3 / 5
                    height: parent.height
                    text: model.errorDefinition
                    color: txtColor
                }
            }

            MouseArea{
                anchors.fill: parent
                onClicked: {
                    console.log("importance:", importance.text, "source:", source.text, "errorDefinition:", errorDefinition.text)
                    listView.currentIndex = model.index
                    controller.model().updateData(5, Enums.ImportanceRole, "Kritik")
                }
            }
        }
    }
}

