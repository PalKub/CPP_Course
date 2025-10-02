#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int line_counter{1};

int main() {
    std::ifstream in_file;
    std::ofstream out_file;
    in_file.open("../Challenge_4/romeoandjuliet.txt");
    out_file.open("../Challenge_4/romeoandjuliet_out.txt");
    
    if (!in_file) {
        std::cerr << "Error opening input file" << std::endl;
        return 1;
    }
    if (!out_file) {
        std::cerr << "Error opening output file" << std::endl;
        return 1;
    }
    
    std::string line;
    while (std::getline(in_file, line)) {
        if(line != "") {
            out_file << std::setw(7) << std::left << line_counter << line << std::endl;
            line_counter++;
        }
        else
            out_file << std::endl;
    }
    std::cout << "File copied" << std::endl;
    in_file.close();
    out_file.close();
    std::cout << std::endl;
}