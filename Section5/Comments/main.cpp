/******************************************
 * author Kuba
 * 
 * 
******************************************/

#include <iostream>

// This is a comment

/* This is a multiple
    line
    comment
*/

// Using a modified version of Djikstra's alghoritm to improve space efficiency

int main() {
    int favourite_number; // this is where my favourite number is stored
    
    std::cout << "Enter your favourite number between 1 and 100: ";
    
    std::cin >> favourite_number; /* comment */
    
    std::cout << "Amazing!! That's my favourite number too!" << std::endl;
    std::cout << "No really!! " << favourite_number << " is my favourite number." << std::endl;
    
    return 0; // return 0
}