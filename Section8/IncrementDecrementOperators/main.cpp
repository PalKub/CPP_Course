#include <iostream>

using namespace std;

int main() {
    
    int counter {10};
    int result {0};
    
//    cout << "Counter: " << counter << endl;
//    
//    counter = counter + 1;
//    cout << "Counter: " << counter << endl;
//    
//    counter++;
//    cout << "Counter: " << counter << endl;
//    
//    ++counter;
//    cout << "Counter: " << counter << endl;
    
    
//    counter = 10;
//    result = 0;
//    
//    cout << "Counter: " << counter << endl;
//    
//    result = ++counter; //Note the pre increment
//    cout << "Counter: " << counter << endl;
//    cout << "Result: " << result << endl;
    
    
//    counter = 10;
//    result = 0;
//    
//    cout << "Counter: " << counter << endl;
//    
//    result = counter++; //Note the post increment
//    cout << "Counter: " << counter << endl;
//    cout << "Result: " << result << endl;
    
    
//    counter = 10;
//    result = 0;
//    
//    cout << "Counter: " << counter << endl;
//    
//    result = ++counter + 10; //Note the pre increment
//    
//    cout << "Counter: " << counter << endl;
//    cout << "Result: " << result << endl;

    
    counter = 10;
    result = 0;
    
    cout << "Counter: " << counter << endl;
    
    result = counter++ + 10; //Note the post increment
    
    cout << "Counter: " << counter << endl;
    cout << "Result: " << result << endl;

    cout << endl;
    return 0;
}