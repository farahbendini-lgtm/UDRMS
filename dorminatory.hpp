#ifndef DORMINATORY_HPP
#define DORMINATORY_HPP
#include<iostream>
#include "Restaurant.hpp"
#include "Room.hpp"
using namespace std ;
class Dormitory {
public:
    Dormitory();
    Dormitory(string n, int c);

    void setName(string n);
    void setCapacity(int c);

    string getName() const;
    int getCapacity() const;

    void addroom(const Room&) ; ;
    bool removeroom(int);
    void displayAvailableRooms() const;
    void displayOccupiedRooms() const ;
    void displayDormitory() const ;

    int getRoomsCount() const;
    Room getRoomAt(int index) const;
    Room& getRoomRef(int index);
    Restaurant& getRestaurant();

private:
    string name;
    int capacity;
    Room rooms[100] ;
    int roomscount ;
    Restaurant restaurant ;

};
#endif