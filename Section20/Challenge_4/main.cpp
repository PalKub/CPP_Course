#include <cctype>
#include <iostream>
#include <string>
#include <iomanip>
#include <stack>
#include <queue>

bool is_palindrome(const std::string& s) {
    std::queue<char> word_queue;
    std::stack<char> word_stack;
    
    for(const char &c : s)
        if(isalpha(c)) {
            word_queue.push(toupper(c));
            word_stack.push(toupper(c));
        }
        
    while(!word_stack.empty()) {
        if(word_queue.front() == word_stack.top()) {
            word_stack.pop();
            word_queue.pop();
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