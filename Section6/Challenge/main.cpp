#include <iostream>

using namespace std;

int main() {
    cout << "Hello, welcome to Frank's Carpet Cleaning Service" << endl;
    cout << "\nHow many small rooms would you like cleaned? ";
    
    int number_of_small_rooms {0};
    cin >> number_of_small_rooms;
    
    cout << "How many big rooms would you like cleaned? ";
    
    int number_of_big_rooms {0};
    cin >> number_of_big_rooms;
    
    const double price_per_small_room {25.0};
    const double price_per_big_room {35.0};
    const double sales_tax {0.06};
    const int estimate_expiry {30}; // days
    
    cout << "\nEstimate for carpet cleaning service" << endl;
    cout << "Number of  small rooms: " << number_of_small_rooms << endl;
    cout << "Number of  big rooms: " << number_of_big_rooms << endl;
    cout << "Price per small room: $" << price_per_small_room << endl;
    cout << "Price per big room: $" << price_per_big_room << endl;
    cout << "Cost: $" << (price_per_small_room * number_of_small_rooms) + (price_per_big_room * number_of_big_rooms)<< endl;
    cout << "Tax: $" << ((price_per_small_room * number_of_small_rooms) + (price_per_big_room * number_of_big_rooms)) * sales_tax << endl;
    cout << "=============================================" << endl;
    cout << "Total estimate: $" << (price_per_small_room * number_of_small_rooms) + (price_per_big_room * number_of_big_rooms) + ((price_per_small_room * number_of_small_rooms) + (price_per_big_room * number_of_big_rooms)) * sales_tax << endl;
    cout << "This estimate is valid for " << estimate_expiry << " days" << endl;
    
    cout << endl;
    return 0;
}