#include "dorminatory.hpp"
#include <iostream>
using namespace std ;

Dormitory :: Dormitory(){
    name =" ";
    capacity =0 ;
    roomscount=0;
}
Dormitory :: Dormitory(string N, int C){
    setName(N);
    setCapacity(C);
    roomscount=0 ;
}
void Dormitory :: setName(string n){
    name = n;
}
void Dormitory :: setCapacity(int c){
    capacity =c ;
}
string Dormitory :: getName() const {
    return name;
}
int Dormitory :: getCapacity() const {
    return capacity;
}
void Dormitory :: addroom(const Room &r){
    rooms[roomscount] =r;
    roomscount++ ;
}
bool Dormitory :: removeroom(int roomNumber){
    for(int i = 0; i < roomscount; i++)
    {
        if(rooms[i].getRoomNumber() == roomNumber)
        {
            for(int j = i; j < roomscount - 1; j++)
            {
                rooms[j] = rooms[j + 1];
            }
            roomscount--;
            return true;
        }
    }
    return false;
}
void Dormitory::displayAvailableRooms() const
{
    cout << "\nAvailable Rooms:\n";

    for(int i = 0; i < roomscount; i++)
    {
        if(!rooms[i].isFull())
        {
            cout << "Room "
                 << rooms[i].getRoomNumber()
                 << endl;
        }
    }
}
void Dormitory::displayOccupiedRooms() const
{
    cout << "\nOccupied Rooms:\n";

    for(int i = 0; i < roomscount; i++)
    {
        if(rooms[i].getCurrentOccupancy() > 0)
        {
            cout << "Room "
                 << rooms[i].getRoomNumber()
                 << endl;
        }
    }
}
void Dormitory::displayDormitory() const
{
    cout << "\nDormitory Information\n";
    cout << "Name: " << name << endl;
    cout << "Capacity: " << capacity << endl;
    cout << "Number of Rooms: " << roomscount << endl;

    for(int i = 0; i < roomscount; i++)
    {
        cout << "\nRoom Number: "
             << rooms[i].getRoomNumber()
             << endl;

        cout << "Capacity: "
             << rooms[i].getCapacity()
             << endl;

        cout << "Occupancy: "
             << rooms[i].getCurrentOccupancy()
             << endl;
    }
}
int Dormitory::getRoomsCount() const
{
    return roomscount;
}

Room Dormitory::getRoomAt(int index) const
{
    return rooms[index];
}

Room& Dormitory::getRoomRef(int index)
{
    return rooms[index];
}

Restaurant& Dormitory::getRestaurant()
{
    return restaurant;
}