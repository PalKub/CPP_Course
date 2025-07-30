#include <iostream>
#include <string>

using namespace std;

int main() {
    string input {};
    cout << "Enter a string: ";
    cin >> input;
    
    for (size_t i {0}; i < input.length(); ++i) {
        string line {};
        string spaces (input.length() - i - 1, ' ');
        line += spaces;
        for (size_t j {0}; j <= i; ++j) {
            line += input.at(j);
        }
        for (size_t j {i}; j > 0; --j) {
            line += input.at(j - 1);
        }
        line += spaces;
        cout << line << endl;
    }
    
    cout << endl;
    return 0;
}