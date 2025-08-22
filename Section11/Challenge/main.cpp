#include <iostream>
#include <vector>

using namespace std;

void display_menu(vector<int>& list);
void print_numbers(vector<int>& list);
void add_number(vector<int>& list);
void display_mean(vector<int>& list);
void display_smallest(vector<int>& list);
void display_largest(vector<int>& list);
void find_on_list(vector<int>& list);
void clear_list(vector<int>& list);
void quit();

void display_menu(vector<int>& list) {
    char input {};
    
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
            case 'p':
                print_numbers(list);
                break;
                
            case 'A':
            case 'a':
                add_number(list);
                break;
            
            case 'M':
            case 'm':
                display_mean(list);
                break;
            
            case 'S':
            case 's':
                display_smallest(list);
                break;
            
            case 'L':
            case 'l':
                display_largest(list);
                break;
            
            case 'F':
            case 'f':
                find_on_list(list);
                break;
            
            case 'C':
            case 'c':
                clear_list(list);
                break;
            
            case 'Q':
            case 'q':
                quit();
                break;
            
            default :
                cout << "Unknown selection, please try again" << endl;
        }
        
        
    } while (input != 'Q' && input != 'q');
}

void print_numbers(vector<int>& list) {
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
}

void add_number(vector<int>& list) {
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
}

void display_mean(vector<int>& list) {
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
}

void display_smallest(vector<int>& list) {
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
}

void display_largest(vector<int>& list) {
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
}

void find_on_list(vector<int>& list) {
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
}

void clear_list(vector<int>& list) {
    list.clear();
    cout << "List cleared" << endl;
}

void quit() {
    cout << "Goodbye";
}

int main() {
    
    vector<int> list {};
    
    display_menu(list);
    
    cout << endl;
    return 0;
}