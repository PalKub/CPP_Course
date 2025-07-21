#include <iostream>

using namespace std;

int main() {
    
    int balance {}, cents {}, dollars {}, quarters {}, dimes {}, nickels {}, pennies {};
    
    const int dollar_value {100};
    const int quarter_value {25};
    const int dime_value {10};
    const int nickel_value {5};
    
    cout << "Enter an amount in cents: ";
    cin >> cents;
    
    dollars = cents / dollar_value;
    balance = cents % dollar_value;
    
    quarters = balance / quarter_value;
    balance %= quarter_value;
    
    dimes = balance / dime_value;
    balance %= dime_value;
    
    nickels = balance / nickel_value;
    balance %= nickel_value;
    
    pennies = balance;
    
    cout << "dollars  : " << dollars << endl;
    cout << "quarters : " << quarters << endl;
    cout << "dimes    : " << dimes << endl;
    cout << "nickels  : " << nickels << endl;
    cout << "pennies  : " << pennies << endl;
    
    cout << endl;
    return 0;
}