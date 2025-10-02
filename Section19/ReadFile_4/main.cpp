#include <iostream>
#include <fstream>

int main() {
    std::ifstream in_file;
    in_file.open("../ReadFile_4/poem.txt");
    if(!in_file) {
        std::cerr << "Problem opening file" << std::endl;
        return 1;
    }
    
    char c{};
    while(in_file.get(c)) {
        std::cout << c;
    }
    std::cout << std::endl;
    in_file.close();
    return 0;
}