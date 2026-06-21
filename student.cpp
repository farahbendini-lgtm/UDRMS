#include "student.hpp"
#include<iostream>
using namespace std;

Student::Student()
{
    ID = 0;
    year = 0;
    Room = 0;
    Dorminatory = "";
}
Student::Student(int I, string N, int Y, string D, int R)
    : Person(N)
{
    year = Y;
    Dorminatory = D;
    Room = R;
    ID =I;
}
void Student::setname(string N)
{
    name = N;  
}
void Student::setID(int I)
{
    ID = I;
}
void Student::setyear(int Y)
{
    year = Y;
}
void Student::setDorminatory(string D)
{
    Dorminatory = D;
}
void Student::setRoom(int R)
{
    Room = R;
}
int Student::getId() const
{
    return ID;
}
int Student::getYear() const
{
    return year;
}
string Student::getDormitory() const
{
    return Dorminatory;
}
int Student::getRoom() const
{
    return Room;
}

void Student::display() const
{
    cout << "ID: " << ID << endl;
    cout << "Name: " << name << endl;
    cout << "Year: " << year << endl;
    cout << "Dormitory: " << Dorminatory << endl;
    cout << "Room: " << Room << endl;
}