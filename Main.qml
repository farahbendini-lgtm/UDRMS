import QtQuick
import QtQuick.Controls.Basic
import QtQuick.Layouts

ApplicationWindow {
    id: window
    width: 900
    height: 600
    minimumWidth: 700
    minimumHeight: 500
    visible: true
    title: "University Dormitory & Restaurant Management System"

    property color bgDark: "#121417"
    property color panelDark: "#1c1f24"
    property color fieldDark: "#262a31"
    property color lightBlue: "#5fa8e0"
    property color accentBlue: "#2d4a63"
    property color textLight: "#e8e8e8"
    property color textGray: "#9aa0a6"
    property color borderGray: "#33373d"
    property color sidebarBg: "#181a1e"

    property int currentPage: 0

    color: bgDark

    RowLayout {
        anchors.fill: parent
        spacing: 0

        Rectangle {
            Layout.fillHeight: true
            Layout.preferredWidth: 200
            color: sidebarBg
            border.color: borderGray
            border.width: 1

            ColumnLayout {
                anchors.fill: parent
                anchors.topMargin: 20
                spacing: 4

                Label {
                    text: "UDRMS"
                    font.pixelSize: 20
                    font.bold: true
                    color: lightBlue
                    Layout.alignment: Qt.AlignHCenter
                    Layout.bottomMargin: 20
                }

                Repeater {
                    model: ["Students", "Dormitories", "Rooms", "Restaurant"]

                    delegate: Rectangle {
                        Layout.fillWidth: true
                        Layout.preferredHeight: 44
                        color: currentPage === index ? accentBlue : "transparent"
                        border.color: currentPage === index ? lightBlue : "transparent"
                        border.width: currentPage === index ? 1 : 0

                        Label {
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.left: parent.left
                            anchors.leftMargin: 16
                            text: modelData
                            font.pixelSize: 15
                            color: currentPage === index ? lightBlue : textGray
                        }

                        MouseArea {
                            anchors.fill: parent
                            cursorShape: Qt.PointingHandCursor
                            onClicked: currentPage = index
                        }
                    }
                }

                Item { Layout.fillHeight: true }
            }
        }

        Rectangle {
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: bgDark

            ColumnLayout {
                anchors.fill: parent
                anchors.margins: 24
                spacing: 16
                visible: currentPage === 0

                Label {
                    text: "Student Management"
                    font.pixelSize: 22
                    font.bold: true
                    color: textLight
                }

                Rectangle {
                    Layout.fillWidth: true
                    Layout.preferredHeight: 360
                    color: panelDark
                    radius: 8
                    border.color: borderGray
                    border.width: 1

                    ColumnLayout {
                        anchors.fill: parent
                        anchors.margins: 16
                        spacing: 8

                        TextField {
                            id: stuId
                            placeholderText: "ID"
                            Layout.fillWidth: true
                            color: textLight
                            placeholderTextColor: textGray
                            validator: IntValidator { bottom: 0 }
                            background: Rectangle { color: fieldDark; radius: 6; border.color: borderGray; border.width: 1 }
                        }
                        TextField {
                            id: stuName
                            placeholderText: "Full Name"
                            Layout.fillWidth: true
                            color: textLight
                            placeholderTextColor: textGray
                            background: Rectangle { color: fieldDark; radius: 6; border.color: borderGray; border.width: 1 }
                        }
                        TextField {
                            id: stuYear
                            placeholderText: "Year"
                            Layout.fillWidth: true
                            color: textLight
                            placeholderTextColor: textGray
                            validator: IntValidator { bottom: 0 }
                            background: Rectangle { color: fieldDark; radius: 6; border.color: borderGray; border.width: 1 }
                        }
                        TextField {
                            id: stuDorm
                            placeholderText: "Dormitory Name"
                            Layout.fillWidth: true
                            color: textLight
                            placeholderTextColor: textGray
                            background: Rectangle { color: fieldDark; radius: 6; border.color: borderGray; border.width: 1 }
                        }
                        TextField {
                            id: stuRoom
                            placeholderText: "Room No."
                            Layout.fillWidth: true
                            color: textLight
                            placeholderTextColor: textGray
                            validator: IntValidator { bottom: 0 }
                            background: Rectangle { color: fieldDark; radius: 6; border.color: borderGray; border.width: 1 }
                        }

                        Button {
                            text: "Add Student"
                            Layout.fillWidth: true
                            background: Rectangle { color: lightBlue; radius: 6 }
                            contentItem: Text {
                                text: parent.text
                                color: "#0d1117"
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                font.bold: true
                            }
                            onClicked: {
                                if (stuId.text !== "" && stuName.text !== "") {
                                    backend.addStudent(parseInt(stuId.text), stuName.text,
                                                        parseInt(stuYear.text || "0"),
                                                        stuDorm.text, parseInt(stuRoom.text || "0"))
                                    stuId.text = ""; stuName.text = ""; stuYear.text = "";
                                    stuDorm.text = ""; stuRoom.text = "";
                                    studentListView.model = backend.getStudentList()
                                }
                            }
                        }

                        TextField {
                            id: searchId
                            placeholderText: "Search by ID"
                            Layout.fillWidth: true
                            color: textLight
                            placeholderTextColor: textGray
                            validator: IntValidator { bottom: 0 }
                            background: Rectangle { color: fieldDark; radius: 6; border.color: borderGray; border.width: 1 }
                        }

                        RowLayout {
                            spacing: 8
                            Layout.fillWidth: true

                            Button {
                                text: "Search"
                                Layout.fillWidth: true
                                background: Rectangle { color: fieldDark; radius: 6; border.color: lightBlue; border.width: 1 }
                                contentItem: Text {
                                    text: parent.text
                                    color: lightBlue
                                    horizontalAlignment: Text.AlignHCenter
                                    verticalAlignment: Text.AlignVCenter
                                }
                                onClicked: {
                                    searchResultLabel.text = backend.searchStudent(parseInt(searchId.text || "-1"))
                                }
                            }

                            Button {
                                text: "Refresh List"
                                Layout.fillWidth: true
                                background: Rectangle { color: fieldDark; radius: 6; border.color: borderGray; border.width: 1 }
                                contentItem: Text {
                                    text: parent.text
                                    color: textGray
                                    horizontalAlignment: Text.AlignHCenter
                                    verticalAlignment: Text.AlignVCenter
                                }
                                onClicked: studentListView.model = backend.getStudentList()
                            }
                        }
                    }
                }

                Label {
                    id: searchResultLabel
                    text: ""
                    color: lightBlue
                    font.pixelSize: 14
                    wrapMode: Text.WordWrap
                    Layout.fillWidth: true
                }

                Label {
                    text: "All Students"
                    font.pixelSize: 16
                    font.bold: true
                    color: textGray
                }

                ListView {
                    id: studentListView
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    clip: true
                    model: []
                    delegate: Rectangle {
                        width: studentListView.width
                        height: 36
                        color: index % 2 === 0 ? panelDark : fieldDark
                        Label {
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.left: parent.left
                            anchors.leftMargin: 10
                            text: modelData
                            color: textLight
                            font.pixelSize: 13
                        }
                    }
                }
            }

            ColumnLayout {
                anchors.fill: parent
                anchors.margins: 24
                spacing: 16
                visible: currentPage === 1

                Label {
                    text: "Dormitory Management"
                    font.pixelSize: 22
                    font.bold: true
                    color: textLight
                }

                Rectangle {
                    Layout.fillWidth: true
                    Layout.preferredHeight: 200
                    color: panelDark
                    radius: 8
                    border.color: borderGray
                    border.width: 1

                    ColumnLayout {
                        anchors.fill: parent
                        anchors.margins: 16
                        spacing: 8

                        TextField {
                            id: dormName
                            placeholderText: "Dormitory Name"
                            Layout.fillWidth: true
                            color: textLight
                            placeholderTextColor: textGray
                            background: Rectangle { color: fieldDark; radius: 6; border.color: borderGray; border.width: 1 }
                        }
                        TextField {
                            id: dormCapacity
                            placeholderText: "Capacity"
                            Layout.fillWidth: true
                            color: textLight
                            placeholderTextColor: textGray
                            validator: IntValidator { bottom: 0 }
                            background: Rectangle { color: fieldDark; radius: 6; border.color: borderGray; border.width: 1 }
                        }
                        Button {
                            text: "Add Dormitory"
                            Layout.fillWidth: true
                            background: Rectangle { color: lightBlue; radius: 6 }
                            contentItem: Text {
                                text: parent.text
                                color: "#0d1117"
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                font.bold: true
                            }
                            onClicked: {
                                if (dormName.text !== "") {
                                    backend.addDormitory(dormName.text, parseInt(dormCapacity.text || "0"))
                                    dormName.text = ""; dormCapacity.text = "";
                                    dormListView.model = backend.getDormitoryList()
                                }
                            }
                        }
                        Button {
                            text: "Refresh"
                            Layout.fillWidth: true
                            background: Rectangle { color: fieldDark; radius: 6; border.color: borderGray; border.width: 1 }
                            contentItem: Text {
                                text: parent.text
                                color: textGray
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                            }
                            onClicked: dormListView.model = backend.getDormitoryList()
                        }
                    }
                }

                Label {
                    text: "All Dormitories"
                    font.pixelSize: 16
                    font.bold: true
                    color: textGray
                }

                ListView {
                    id: dormListView
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    clip: true
                    model: []
                    delegate: Rectangle {
                        width: dormListView.width
                        height: 36
                        color: index % 2 === 0 ? panelDark : fieldDark
                        Label {
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.left: parent.left
                            anchors.leftMargin: 10
                            text: modelData
                            color: textLight
                            font.pixelSize: 13
                        }
                    }
                }
            }

            ColumnLayout {
                anchors.fill: parent
                anchors.margins: 24
                spacing: 16
                visible: currentPage === 2

                Label {
                    text: "Room Management"
                    font.pixelSize: 22
                    font.bold: true
                    color: textLight
                }

                Rectangle {
                    Layout.fillWidth: true
                    Layout.preferredHeight: 240
                    color: panelDark
                    radius: 8
                    border.color: borderGray
                    border.width: 1

                    ColumnLayout {
                        anchors.fill: parent
                        anchors.margins: 16
                        spacing: 8

                        ComboBox {
                            id: roomDormCombo
                            Layout.fillWidth: true
                            model: backend.getDormitoryNames()
                            background: Rectangle { color: fieldDark; radius: 6; border.color: borderGray; border.width: 1 }
                            contentItem: Text {
                                text: roomDormCombo.displayText
                                color: textLight
                                verticalAlignment: Text.AlignVCenter
                                leftPadding: 8
                            }
                        }
                        TextField {
                            id: roomNumber
                            placeholderText: "Room Number"
                            Layout.fillWidth: true
                            color: textLight
                            placeholderTextColor: textGray
                            validator: IntValidator { bottom: 0 }
                            background: Rectangle { color: fieldDark; radius: 6; border.color: borderGray; border.width: 1 }
                        }
                        TextField {
                            id: roomCapacity
                            placeholderText: "Capacity"
                            Layout.fillWidth: true
                            color: textLight
                            placeholderTextColor: textGray
                            validator: IntValidator { bottom: 0 }
                            background: Rectangle { color: fieldDark; radius: 6; border.color: borderGray; border.width: 1 }
                        }
                        Button {
                            text: "Add Room"
                            Layout.fillWidth: true
                            background: Rectangle { color: lightBlue; radius: 6 }
                            contentItem: Text {
                                text: parent.text
                                color: "#0d1117"
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                font.bold: true
                            }
                            onClicked: {
                                if (roomDormCombo.currentText !== "") {
                                    backend.addRoom(roomDormCombo.currentText,
                                                     parseInt(roomNumber.text || "0"),
                                                     parseInt(roomCapacity.text || "0"))
                                    roomNumber.text = ""; roomCapacity.text = "";
                                    roomListView.model = backend.getRoomList(roomDormCombo.currentText)
                                }
                            }
                        }
                        Button {
                            text: "View Rooms"
                            Layout.fillWidth: true
                            background: Rectangle { color: fieldDark; radius: 6; border.color: borderGray; border.width: 1 }
                            contentItem: Text {
                                text: parent.text
                                color: textGray
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                            }
                            onClicked: {
                                roomDormCombo.model = backend.getDormitoryNames()
                                roomListView.model = backend.getRoomList(roomDormCombo.currentText)
                            }
                        }
                    }
                }

                Label {
                    text: "Rooms in Selected Dormitory"
                    font.pixelSize: 16
                    font.bold: true
                    color: textGray
                }

                ListView {
                    id: roomListView
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    clip: true
                    model: []
                    delegate: Rectangle {
                        width: roomListView.width
                        height: 36
                        color: index % 2 === 0 ? panelDark : fieldDark
                        Label {
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.left: parent.left
                            anchors.leftMargin: 10
                            text: modelData
                            color: textLight
                            font.pixelSize: 13
                        }
                    }
                }
            }

            ColumnLayout {
                anchors.fill: parent
                anchors.margins: 24
                spacing: 16
                visible: currentPage === 3

                Label {
                    text: "Restaurant Menu Management"
                    font.pixelSize: 22
                    font.bold: true
                    color: textLight
                }

                ColumnLayout {
                    spacing: 8
                    Layout.fillWidth: true

                    Label { text: "Dormitory:"; color: textGray }
                    ComboBox {
                        id: menuDormCombo
                        Layout.fillWidth: true
                        model: backend.getDormitoryNames()
                        background: Rectangle { color: fieldDark; radius: 6; border.color: borderGray; border.width: 1 }
                        contentItem: Text {
                            text: menuDormCombo.displayText
                            color: textLight
                            verticalAlignment: Text.AlignVCenter
                            leftPadding: 8
                        }
                        onCurrentTextChanged: {
                            if (currentText !== "") {
                                menuDisplay.text = backend.getMenu(currentText)
                            }
                        }
                    }
                    Button {
                        text: "Refresh Dorm List"
                        Layout.fillWidth: true
                        background: Rectangle { color: fieldDark; radius: 6; border.color: borderGray; border.width: 1 }
                        contentItem: Text {
                            text: parent.text
                            color: textGray
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                        }
                        onClicked: menuDormCombo.model = backend.getDormitoryNames()
                    }
                }

                Rectangle {
                    Layout.fillWidth: true
                    Layout.preferredHeight: 220
                    color: panelDark
                    radius: 8
                    border.color: borderGray
                    border.width: 1

                    ColumnLayout {
                        anchors.fill: parent
                        anchors.margins: 16
                        spacing: 8

                        TextField {
                            id: breakfastField
                            placeholderText: "Breakfast Menu"
                            Layout.fillWidth: true
                            color: textLight
                            placeholderTextColor: textGray
                            background: Rectangle { color: fieldDark; radius: 6; border.color: borderGray; border.width: 1 }
                        }
                        TextField {
                            id: lunchField
                            placeholderText: "Lunch Menu"
                            Layout.fillWidth: true
                            color: textLight
                            placeholderTextColor: textGray
                            background: Rectangle { color: fieldDark; radius: 6; border.color: borderGray; border.width: 1 }
                        }
                        TextField {
                            id: dinnerField
                            placeholderText: "Dinner Menu"
                            Layout.fillWidth: true
                            color: textLight
                            placeholderTextColor: textGray
                            background: Rectangle { color: fieldDark; radius: 6; border.color: borderGray; border.width: 1 }
                        }

                        Button {
                            text: "Save Menu"
                            Layout.fillWidth: true
                            background: Rectangle { color: lightBlue; radius: 6 }
                            contentItem: Text {
                                text: parent.text
                                color: "#0d1117"
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                font.bold: true
                            }
                            onClicked: {
                                if (menuDormCombo.currentText !== "") {
                                    backend.setMenu(menuDormCombo.currentText, breakfastField.text,
                                                      lunchField.text, dinnerField.text)
                                    menuDisplay.text = backend.getMenu(menuDormCombo.currentText)
                                }
                            }
                        }
                    }
                }

                Label {
                    text: "Current Menu"
                    font.pixelSize: 16
                    font.bold: true
                    color: textGray
                }

                Rectangle {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    color: panelDark
                    radius: 8
                    border.color: borderGray
                    border.width: 1

                    Label {
                        id: menuDisplay
                        anchors.fill: parent
                        anchors.margins: 16
                        text: ""
                        color: textLight
                        font.pixelSize: 14
                        wrapMode: Text.WordWrap
                        verticalAlignment: Text.AlignTop
                    }
                }
            }
        }
    }
}