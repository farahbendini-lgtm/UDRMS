#ifndef PERSON_HPP
#define PERSON_HPP
#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    Person();
    Person( string N);
    void setName(string N);
    string getName() const;

    virtual void display() const;

protected:
    string name;
};

#endif