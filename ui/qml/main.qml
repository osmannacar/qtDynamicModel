import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.0
import QtQuick.Dialogs 1.3
import oscar.qmltypes 1.0

Rectangle {
    property int screenWidth: controller.width
    property int screenHeight: controller.height
    id: root
    visible: true
    anchors.centerIn: parent
    width: screenWidth
    height: screenHeight

    //Custom ListModel
    Errors{
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        height: parent.height / 2
    }
    //Custom ListTuple
    //    qml VariantContainer listTuple
    ListTuple{
        id: listTuple
    }
    Component {
        id: myComponent

        ListTuple {

        }
    }

    signal aaaa(var ttt)

    onAaaa: {
        console.log("row:", ttt.getRowData(1))
    }

    Button{
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.bottomMargin: 50
        width: 300
        height: 50
        text: "Pass qml tuple list object to cpp"
        onClicked: {
            //create listTuple qml Object
            //first
            var dynamicObject = myComponent.createObject(root)
            console.log("dynamicObject:", dynamicObject)


            dynamicObject.append([11, "oscar1", 10.1]);
            dynamicObject.append([12, "oscar2", 10.2]);
            dynamicObject.append([13, "oscar3", 10.3, Qt.point(125, 75)]);
            console.log("row:", dynamicObject.getRowData(1))
            controller.printListTuple(dynamicObject);
            aaaa(dynamicObject)

            //second

            listTuple.append([21, "oscar4", 10.1]);
            listTuple.append([22, "oscar5", 10.2]);
            listTuple.append([23, "oscar6", 10.3, Qt.point(125, 75)]);

            console.log("row:", listTuple.getRowData(1))

            listTuple.remove([22, "oscar5", 10.2])
            console.log("row:", listTuple.getRowData(1))
            console.log("listTuple:", listTuple)
            controller.printListTuple(listTuple);
            aaaa(listTuple)

        }
    }

}
