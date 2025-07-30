#include <iostream>

using namespace std;

int main() {
    
    string alphabet {"[ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string key {" [XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};
    
    string message {};
    
    cout << "Type your message to encode: ";
    getline(cin, message);
    
    for (size_t i = {}; i < message.length(); ++i) {
        if (alphabet.find(message.at(i)) != string::npos)
            message.at(i) = key.at(alphabet.find(message.at(i)));
    }
    
    cout << "Here is your encoded message: " << message << endl;
    
    for (size_t i = {}; i < message.length(); ++i) {
        if (key.find(message.at(i)) != string::npos)
            message.at(i) = alphabet.at(key.find(message.at(i)));
    }
    
    cout << "Here is your decoded message: " << message << endl;
    
    cout << endl;
    return 0;
}