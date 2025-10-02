#include <iostream>
#include <fstream>
#include <iomanip>

const int name_width = 15;
const int score_width = 5;
std::string correct_answers{};
int num_students{};
int score_sum{};

void print_header() {
    std::cout << std::setw(name_width) << std::left << "Student" << std::setw(score_width) << std::right << "Score" << std::endl;
    std::cout << std::setfill('-') << std::setw(name_width + score_width) << "" << std:: endl;
    std::cout << std::setfill(' ');
}

void print_footnote() {
    std::cout << std::setfill('-') << std::setw(name_width + score_width) << "" << std:: endl;
    std::cout << std::setfill(' ') << std::setw(name_width) << std::left << "Average score";
    std::cout << std::setw(score_width) << std::right << static_cast<double>(score_sum) / num_students;
}

int process_answers(std::string &answers) {
    int score{};
    num_students++;
    for (size_t i = 0; i < answers.length(); i++)
        if(correct_answers[i] == answers[i])
            score++;
    score_sum += score;
    return score;
}

void print_student(std::string &name, std::string &answers) {
    std::cout << std::setw(name_width) << std::left << name
              << std::setw(score_width) << std::right << process_answers(answers) << std::endl;
}

int main() {
    std::ifstream in_file;
    in_file.open("../Challenge_2/responses.txt");
    if(!in_file) {
        std::cerr << "Problem opening file" << std::endl;
        return 1;
    }
    
    in_file >> correct_answers;
    print_header();
    
    std::string name{};
    std::string answers{};
    
    while(in_file >> name >> answers)
        print_student(name, answers);
    
    print_footnote();
    in_file.close();
    std::cout << std::endl;
    return 0;
}