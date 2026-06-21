#ifndef ROOM_HPP
#define ROOM_HPP
#include <iostream>
#include "student.hpp"
using namespace std;
class Room
{
public:
    Room();
    Room(int , int );

    void setRoomNumber(int n);
    void setCapacity(int c);

    int getRoomNumber() const;
    int getCapacity() const;
    void addstudent(const Student&) ;;
    bool isFull() const;
    void removeStudent(int id);
    int getCurrentOccupancy() const;
private:
    int RoomNumber;
    int capacity;
    int studentcount ;
    Student students[10]; 
    
};
#endif 