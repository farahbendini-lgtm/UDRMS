#ifndef UNIVERSITY_HPP
#define UNIVERSITY_HPP

#include <iostream>
#include <string>
#include "student.hpp"
#include <fstream>
#include "dorminatory.hpp"
using namespace std;

class University
{
public:
    University();
    University(string n);

    void setName(string n);
    string getName() const;

    void addStudent(const Student &s);
    void removeStudent(int id);

    void addDormitory(const Dormitory &d);
    bool removeDormitory(const string &name);

    Student* searchStudent(int id);
    Student* searchStudentByIndex(int index);
    int getStudentCount() const;

    int getDormitoryCount() const;
    Dormitory& getDormitoryAt(int index);
    Dormitory* findDormitoryByName(const string &n);

    void displayStudents() const;
    void displayDormitories() const;

    void saveStudents() const;
    void loadStudents();

    void saveDormitories() const;
    void loadDormitories();

private:
    string name;

    Student students[1000];
    int studentCount;

    Dormitory dormitories[20];
    int dormitoryCount;
};

#endif