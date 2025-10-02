#include <iostream>
#include <fstream>
#include <string>

std::string current_word;
std::string search_word;
int word_counter{0};
int found_words_counter{0};

int main() {
    std::ifstream in_file;
    in_file.open("../Challenge_3/romeoandjuliet.txt");
    if(!in_file) {
        std::cerr << "Problem opening file" << std::endl;
        return 1;
    }
    std::cout << "Enter the substring to search for: ";
    std::cin >> search_word;
    
    while(in_file >> current_word) {
        word_counter++;
        if (current_word.find(search_word) != std::string::npos)
            found_words_counter++;
    }
    std::cout << word_counter << " words were searched..." << std::endl;
    std::cout << "The substring " << search_word << " was found " << found_words_counter << " times" << std::endl;
    
    in_file.close();
    std::cout << std::endl;
}