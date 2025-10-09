#include <cctype>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

bool is_palindrome(const std::string& s) {
    std::deque<char> word;
    
    for(const char &c : s)
        if(isalpha(c))
            word.push_back(toupper(c));
        
    while(word.size() > 1) {
        if(word.front() == word.back()) {
            word.pop_back();
            word.pop_front();
        } else
            return false;
    }
    return true;
}

int main() {
    std::vector<std::string> test_strings{"a", "aa", "abba", "abbccbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome"};
        
    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    for(const auto &s : test_strings) {
        std::cout << std::setw(8) << std::left << is_palindrome(s) << s << std::endl;
    }
    std::cout<<std::endl;
    return 0;
}