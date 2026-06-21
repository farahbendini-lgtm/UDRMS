#include "Backend.h"

Backend::Backend(QObject *parent) : QObject(parent)
{
}

// ---------- STUDENTS ----------

QString Backend::addStudent(int id, const QString &name, int year,
                            const QString &dormitory, int room)
{
    // Check if ID already exists
    if (uni.searchStudent(id) != nullptr) {
        return QString("❌ Error: Student with ID %1 already exists.").arg(id);
    }

    // Check if dormitory exists
    Dormitory* d = uni.findDormitoryByName(dormitory.toStdString());
    if (d == nullptr) {
        return QString("❌ Error: Dormitory '%1' not found.").arg(dormitory);
    }

    // Check if room exists in dormitory and is not full
    int roomIndex = -1;
    for (int i = 0; i < d->getRoomsCount(); i++) {
        if (d->getRoomAt(i).getRoomNumber() == room) {
            roomIndex = i;
            break;
        }
    }
    if (roomIndex == -1) {
        return QString("❌ Error: Room %1 not found in dormitory '%2'.").arg(room).arg(dormitory);
    }

    Room& actualRoom = d->getRoomRef(roomIndex);
    if (actualRoom.isFull()) {
        return QString("❌ Error: Room %1 is full (capacity: %2/%3).")
            .arg(room).arg(actualRoom.getCurrentOccupancy()).arg(actualRoom.getCapacity());
    }

    Student s(id, name.toStdString(), year, dormitory.toStdString(), room);
    actualRoom.addstudent(s);
    uni.addStudent(s);

    return QString("✅ Student '%1' (ID: %2) successfully assigned to Room %3 in %4.")
        .arg(name).arg(id).arg(room).arg(dormitory);
}

QString Backend::removeStudent(int id)
{
    if (uni.searchStudent(id) == nullptr) {
        return QString("❌ Error: Student with ID %1 not found.").arg(id);
    }
    uni.removeStudent(id);
    return QString("✅ Student with ID %1 removed successfully.").arg(id);
}

QStringList Backend::getStudentList()
{
    QStringList list;
    int count = uni.getStudentCount();

    for (int i = 0; i < count; i++) {
        Student* s = uni.searchStudentByIndex(i);
        if (s != nullptr) {
            QString line = QString("ID: %1 | Name: %2 | Year: %3 | Dorm: %4 | Room: %5")
            .arg(s->getId())
                .arg(QString::fromStdString(s->getName()))
                .arg(s->getYear())
                .arg(QString::fromStdString(s->getDormitory()))
                .arg(s->getRoom());
            list.append(line);
        }
    }

    return list;
}

QString Backend::searchStudent(int id)
{
    Student* s = uni.searchStudent(id);

    if (s == nullptr) {
        return "Student not found.";
    }

    return QString("ID: %1 | Name: %2 | Year: %3 | Dorm: %4 | Room: %5")
        .arg(s->getId())
        .arg(QString::fromStdString(s->getName()))
        .arg(s->getYear())
        .arg(QString::fromStdString(s->getDormitory()))
        .arg(s->getRoom());
}

// ---------- DORMITORIES ----------

void Backend::addDormitory(const QString &name, int capacity)
{
    Dormitory d(name.toStdString(), capacity);
    uni.addDormitory(d);
}

QString Backend::removeDormitory(const QString &name)
{
    bool removed = uni.removeDormitory(name.toStdString());
    if (!removed) {
        return QString("❌ Error: Dormitory '%1' not found.").arg(name);
    }
    return QString("✅ Dormitory '%1' removed successfully.").arg(name);
}

QStringList Backend::getDormitoryList()
{
    QStringList list;
    int count = uni.getDormitoryCount();

    for (int i = 0; i < count; i++) {
        Dormitory &d = uni.getDormitoryAt(i);
        QString line = QString("%1 | Capacity: %2 | Rooms: %3")
                           .arg(QString::fromStdString(d.getName()))
                           .arg(d.getCapacity())
                           .arg(d.getRoomsCount());
        list.append(line);
    }

    return list;
}

QStringList Backend::getDormitoryNames()
{
    QStringList list;
    int count = uni.getDormitoryCount();

    for (int i = 0; i < count; i++) {
        Dormitory &d = uni.getDormitoryAt(i);
        list.append(QString::fromStdString(d.getName()));
    }

    return list;
}

// ---------- ROOMS ----------

QString Backend::addRoom(const QString &dormitoryName, int roomNumber, int capacity)
{
    Dormitory* d = uni.findDormitoryByName(dormitoryName.toStdString());

    if (d == nullptr) {
        return QString("❌ Error: Dormitory '%1' not found.").arg(dormitoryName);
    }

    // Check if total rooms would exceed dormitory capacity
    if (d->getRoomsCount() >= d->getCapacity()) {
        return QString("❌ Error: Dormitory '%1' is full (max %2 rooms).")
            .arg(dormitoryName).arg(d->getCapacity());
    }

    // Check if room number already exists
    for (int i = 0; i < d->getRoomsCount(); i++) {
        if (d->getRoomAt(i).getRoomNumber() == roomNumber) {
            return QString("❌ Error: Room %1 already exists in '%2'.")
                .arg(roomNumber).arg(dormitoryName);
        }
    }

    Room r(roomNumber, capacity);
    d->addroom(r);
    return QString("✅ Room %1 (capacity: %2) added to '%3' successfully.")
        .arg(roomNumber).arg(capacity).arg(dormitoryName);
}

QString Backend::removeRoom(const QString &dormitoryName, int roomNumber)
{
    Dormitory* d = uni.findDormitoryByName(dormitoryName.toStdString());
    if (d == nullptr) {
        return QString("❌ Error: Dormitory '%1' not found.").arg(dormitoryName);
    }
    bool removed = d->removeroom(roomNumber);
    if (!removed) {
        return QString("❌ Error: Room %1 not found in '%2'.").arg(roomNumber).arg(dormitoryName);
    }
    return QString("✅ Room %1 removed from '%2' successfully.").arg(roomNumber).arg(dormitoryName);
}

QStringList Backend::getRoomList(const QString &dormitoryName)
{
    QStringList list;

    Dormitory* d = uni.findDormitoryByName(dormitoryName.toStdString());

    if (d == nullptr) {
        return list;
    }

    int count = d->getRoomsCount();

    for (int i = 0; i < count; i++) {
        Room r = d->getRoomAt(i);
        QString status = r.isFull() ? "Full" : "Available";

        QString line = QString("Room %1 | Capacity: %2 | Occupied: %3 | %4")
                           .arg(r.getRoomNumber())
                           .arg(r.getCapacity())
                           .arg(r.getCurrentOccupancy())
                           .arg(status);
        list.append(line);
    }

    return list;
}

// ---------- RESTAURANT / MENUS ----------

void Backend::setMenu(const QString &dormitoryName, const QString &breakfast,
                      const QString &lunch, const QString &dinner)
{
    Dormitory* d = uni.findDormitoryByName(dormitoryName.toStdString());

    if (d == nullptr) {
        return;
    }

    Restaurant &r = d->getRestaurant();
    r.setBreakfastMenu(breakfast.toStdString());
    r.setLunchMenu(lunch.toStdString());
    r.setDinnerMenu(dinner.toStdString());
}

QString Backend::getMenu(const QString &dormitoryName)
{
    Dormitory* d = uni.findDormitoryByName(dormitoryName.toStdString());

    if (d == nullptr) {
        return "Dormitory not found.";
    }

    Restaurant &r = d->getRestaurant();

    return QString("Breakfast: %1\nLunch: %2\nDinner: %3")
        .arg(QString::fromStdString(r.getBreakfastMenu()))
        .arg(QString::fromStdString(r.getLunchMenu()))
        .arg(QString::fromStdString(r.getDinnerMenu()));
}