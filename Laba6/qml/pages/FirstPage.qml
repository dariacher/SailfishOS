import QtQuick 2.0
import Sailfish.Silica 1.0
import custom.Counter 1.0
import custom.CustomMap 1.0

Page {
    id: page
    allowedOrientations: Orientation.All
    Counter{
        id: myCounter
        count: 0
    }
    CustomMap{
        id:myMap
    }

    SilicaFlickable {
        anchors.fill: parent


        // Tell SilicaFlickable the height of its content.
        contentHeight: column.height

        Column {
            id: column

            width: page.width
            spacing: Theme.paddingLarge
           anchors.fill: parent
           Label{
               text: myCounter.count
               x:350
           }
           Button{
            id: incButton
            width: parent.width
            text: "Увеличить"
            onClicked: myCounter.increment()
           }

           Button{
            id: nullButton
            width: parent.width
            text: "Сбросить"
            onClicked: myCounter.toNull()
           }

           TextField {
            id: mytext
            text: ""
            width: parent.width
           }
           Button{
            id: addstr
            width: parent.width
            text: "Добавить строку"
            onClicked:{
            myMap.add(mytext.text);
            }
           }
           Button{
            id: delstr
            width: parent.width
            text: "Удалить строку"
            onClicked: myMap.deleteLast()
           }
           Label{
            id:myarea
            text: myMap.mystr
           }

        }
    }
}
