#include "Restaurant.hpp"
#include <iostream>
using namespace std;

Restaurant :: Restaurant(){
breakfastMenu =" ";
lunchMenu =" ";
dinnerMenu =" ";
}
Restaurant :: Restaurant(string b, string l, string d){
setBreakfastMenu(b);
setLunchMenu(l);
setDinnerMenu(d);
}
void Restaurant :: setBreakfastMenu(string b){
  breakfastMenu=b;
}
void Restaurant :: setLunchMenu(string l){
    lunchMenu=l;
}
void Restaurant :: setDinnerMenu(string d){
    dinnerMenu =d ;
}
string Restaurant:: getBreakfastMenu ()const {
    return breakfastMenu;
}
string Restaurant :: getDinnerMenu() const {
    return dinnerMenu;
}
string Restaurant :: getLunchMenu() const {
    return lunchMenu ;
}