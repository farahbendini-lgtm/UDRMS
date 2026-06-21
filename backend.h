#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QString>
#include <QStringList>
#include "university.hpp"
#include "dorminatory.hpp"
#include "Room.hpp"
#include "student.hpp"

class Backend : public QObject
{
    Q_OBJECT

public:
    explicit Backend(QObject *parent = nullptr);

    // ---------- STUDENTS ---------
    Q_INVOKABLE QString addStudent(int id, const QString &name, int year,
                                   const QString &dormitory, int room);
    Q_INVOKABLE QString removeStudent(int id);
    Q_INVOKABLE QStringList getStudentList();
    Q_INVOKABLE QString searchStudent(int id);

    // ---------- DORMITORIES ----------
    Q_INVOKABLE void addDormitory(const QString &name, int capacity);
    Q_INVOKABLE QString removeDormitory(const QString &name);
    Q_INVOKABLE QStringList getDormitoryList();
    Q_INVOKABLE QStringList getDormitoryNames();

    // ---------- ROOMS ----------
    Q_INVOKABLE QString addRoom(const QString &dormitoryName, int roomNumber, int capacity);
    Q_INVOKABLE QString removeRoom(const QString &dormitoryName, int roomNumber);
    Q_INVOKABLE QStringList getRoomList(const QString &dormitoryName);

    // ---------- RESTAURANT / MENUS ----------
    Q_INVOKABLE void setMenu(const QString &dormitoryName, const QString &breakfast,
                             const QString &lunch, const QString &dinner);
    Q_INVOKABLE QString getMenu(const QString &dormitoryName);

private:
    University uni;
};

#endif