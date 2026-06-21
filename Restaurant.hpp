#ifndef RESTAURANT_HPP
#define RESTAURANT_HPP
#include <iostream>
using namespace std ;
class Restaurant
{
public:
    Restaurant();
    Restaurant(string b, string l, string d);
 
    void setBreakfastMenu(string b);
    void setLunchMenu(string l);
    void setDinnerMenu(string d);

    string getBreakfastMenu() const;
    string getLunchMenu() const;
    string getDinnerMenu() const;

private:
    string breakfastMenu;
    string lunchMenu;
    string dinnerMenu;
};
#endif