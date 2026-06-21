#ifndef STUDENT_HPP
#define STUDENT_HPP
#include "person.hpp"
#include<iostream>
using namespace std;
class Student : public Person {
public:
Student();
Student(int I, string N, int Y, string D, int R);

void setname(string N);
void setID(int I);
void setyear(int Y);
void setDorminatory(string D);
void setRoom(int R);

int getId() const ;
int getYear() const ;
string getDormitory() const ;
int getRoom() const ;
void display() const ;

private:
int ID;
int year ;
string Dorminatory;
int Room;

};
#endif 