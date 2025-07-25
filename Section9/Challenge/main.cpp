#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    char input {};
    vector<int> list {};
    
    do {
        cout << "\nP - Print numbers" << endl;
        cout << "A - Add a number" << endl;
        cout << "M - Display mean of the numbers" << endl;
        cout << "S - Display the smallest number" << endl;
        cout << "L - Display the largest number" << endl;
        cout << "F - Find if a number is on the list" << endl;
        cout << "C - Clear the list" << endl;
        cout << "Q - Quit" << endl;
        cout << "\nEnter your choice: ";
        
        cin >> input;
        
        switch (input) {
            case 'P':
            case 'p': {
                if (list.empty()) {
                    cout << "[] - the list is empty" << endl;;
                }
                else {
                    cout << "[ ";
                    for (auto val : list) {
                        cout << val << " ";
                    }
                    cout << "]" << endl;
                }
                break;
            }
                
            case 'A':
            case 'a': {
                cout << "Enter an integer to add to the list: ";
                int input_int {};
                cin >> input_int;
                
                bool duplicate {false};
                for (auto val : list) {
                    if (val == input_int) {
                        duplicate = true;
                        break;
                    }
                }
                
                if (duplicate) {
                    cout << "Number already on the list" << endl;
                }
                else {
                    list.push_back(input_int);
                    cout << input_int << " added" << endl;
                }
                
                break;
            }
            
            case 'M':
            case 'm': {
                if (list.empty()) {
                    cout << "Unable to calculate the mean - no data" << endl;
                }
                else {
                    double sum {};
                    for (auto val : list) {
                        sum += val;
                    }
                    cout << "The mean of the elements is " << sum / list.size() << endl;
                }
                break;
            }
            
            case 'S':
            case 's': {
                if (list.empty()) {
                    cout << "Unable to determine the smallest number - list is empty" << endl;
                }
                else {
                    int smallest_number {list.at(0)};
                    for (auto val : list) {
                        if (val < smallest_number) 
                            smallest_number = val;
                    }
                    cout << "The smallest number is " << smallest_number << endl;
                }
                break;
            }
            
            case 'L':
            case 'l': {
                if (list.empty()) {
                    cout << "Unable to determine the largest number - list is empty" << endl;
                }
                else {
                    int largest_number {list.at(0)};
                    for (auto val : list) {
                        if (val > largest_number) 
                            largest_number = val;
                    }
                    cout << "The largest number is " << largest_number << endl;
                }
                break;
            }
            
            case 'F':
            case 'f': {
                int number {};
                int counter {};
                
                cout << "Enter a number you want to find: ";
                cin >> number;
        
                for (auto val : list) {
                    if (number == val) {
                        ++counter; 
                    }
                }
                
                cout << "Number " << number << " is present on the list " << counter << " time(s)" << endl;
                break;
            }
            
            case 'C':
            case 'c': {
                list.clear();
                cout << "List cleared" << endl;
                break;
            }
            
            case 'Q':
            case 'q': {
                cout << "Goodbye";
                break;
            }
            
            default : {
                cout << "Unknows selection, please try again" << endl;
            }
        }
        
        
    } while (input != 'Q' && input != 'q');
    
    cout << endl;
    return 0;
}