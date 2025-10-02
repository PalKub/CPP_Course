#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream in_file {"../Copy_File2/poem.txt", std::ios::app};
    std::ofstream out_file {"../Copy_File2/poem_out.txt", std::ios::app};
    if (!in_file) {
        std::cerr << "Error opening input file" << std::endl;
        return 1;
    }
    if (!out_file) {
        std::cerr << "Error opening output file" << std::endl;
        return 1;
    }
    
    char c;
    while (in_file.get(c))
        out_file.put(c);
    
    std::cout << "File copied" << std::endl;
    in_file.close();
    out_file.close();
    return 0;
}