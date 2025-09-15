#include <iostream>
#include <vector>
#include "Mystring.h"

using namespace std;

int main() {
    cout << boolalpha << endl;
    
    Mystring larry{"Larry"};
    larry.display();                                //Larry
    
    larry = -larry;
    larry.display();                                //larry
    
    Mystring moe{"Moe"};
    Mystring stooge = larry;
    
    cout << (larry == moe) << endl;                 //false
    cout << (larry == stooge) << endl;              //true
    
    
    //Mystring stooges = larry + "Moe";             
    Mystring stooges = "Larry" + moe;              //Now ok with non-member function
    stooges.display();                             //LarryMoe
    
    Mystring two_stooges = moe + " " + "Larry";
    two_stooges.display();                          //Moe Larry
    Mystring three_stooges = moe + " " + larry + " " + "Curly";
    three_stooges.display();                         //Moe Larry Curly
    
    return 0;
}