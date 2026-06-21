#include "person.hpp"
#include <iostream>

using namespace std;
Person::Person()
{
    name = "";
}
Person::Person( string N)
{
    name = N;
}
void Person::setName(string N)
{
    name = N;
}
string Person::getName() const
{
    return name;
}
void Person::display() const
{
    cout << "Name: " << name << endl;
}