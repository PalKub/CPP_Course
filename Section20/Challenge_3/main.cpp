#include <iostream>
#include <set>
#include <map>
#include <fstream>
#include <iomanip>

void display_words(const std::map<std::string, int> &words) {
    std::cout << std::setw(12) << std::left << "\nWord"
              << std::setw(7) << std::right << "Count" << std::endl;
    std::cout << "======================================================" << std::endl;
    for (auto pair : words)
        std::cout << std::setw(12) << std::left << pair.first
                  << std::setw(7) << std::right << pair.second << std::endl;
}

void display_words(const std::map<std::string, std::set<int>> &words) {
    std::cout << std::setw(12) << std::left << "\nWord"
              << "Occurences" << std::endl;
    std::cout << "======================================================" << std::endl;
    for(auto pair : words) {
        std::cout << std::setw(12) << std::left << pair.first
                  << std::left << "[ ";
        for(auto i : pair.second)
            std::cout << i << " ";
        std::cout << "]" << std::endl;
    }
}

std::string clean_string(const std::string &s) {
    std::string result;
    for(char c : s) {
        if(c == '.' || c == ',' || c == ';' || c == ':')
            continue;
        else
            result += c;
    }
    return result;
}

void part1() {
    std::map<std::string, int> words;
    std::string line;
    std::string word;
    std::ifstream in_file{"../Challenge_3/words.txt"};
    if(in_file) {
        while(std::getline(in_file, line)) {
            std::istringstream ss{line};
            while(ss >> word)
                words[clean_string(word)]++;
        }
        in_file.close();
        display_words(words);
    } else {
        std::cerr << "Error opening input file" << std::endl;
    }
}

void part2() {
    std::map<std::string, std::set<int>> words;
    std::string line;
    std::string word;
    std::ifstream in_file{"../Challenge_3/words.txt"};
    if(in_file) {
        int line_count {0};
        while(std::getline(in_file, line)) {
            line_count++;
            std::istringstream ss{line};
            while(ss >> word)
                words[clean_string(word)].insert(line_count);
        }
        in_file.close();
        display_words(words);
    } else {
        std::cerr << "Error opening input file" << std::endl;
    }
}

int main() {
    part1();
    part2();
    return 0;
}