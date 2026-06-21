#include "Room.hpp"
#include <iostream>
#include <stdexcept>
using namespace std ;
Room::Room()
{
    RoomNumber = 0;
    capacity = 0;
    studentcount = 0;
}
Room :: Room(int N,int C){
setRoomNumber( N);
setCapacity( C);
studentcount=0;
}
void Room::setRoomNumber(int n)
{
    RoomNumber = n;
}
void Room::setCapacity(int c)
{
    capacity = c;
}
int Room::getRoomNumber() const
{
    return RoomNumber;
}
int Room::getCapacity() const
{
    return capacity;
}
int Room::getCurrentOccupancy() const
{
    return studentcount;
}
void Room :: addstudent(const Student &s){
  if (isFull()){
        throw runtime_error("Room is full");
  } 
  else {
    students[studentcount]=s;
   studentcount++ ;
}
}
bool Room::isFull() const
{
    return studentcount >= capacity;
}
void Room::removeStudent(int id)
{
    int position = -1;

    for(int i = 0; i < studentcount; i++)
    {
        if(students[i].getId() == id)
        {
            position = i;
            break;
        }
    }

    if(position == -1)
    {
        cout << "Student not found!" << endl;
        return;
    }

    for(int i = position; i < studentcount - 1; i++)
    {
        students[i] = students[i + 1];
    }

    studentcount--;

    cout << "Student removed successfully." << endl;
}