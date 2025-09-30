#include <iostream>
#include <string>

class DivideByZeroException {
};

class NegativeValueException {
};

double calculate_mpg(int miles, int gallons) {
    if (gallons == 0)
        throw DivideByZeroException();
    if (miles < 0 || gallons < 0)
        throw NegativeValueException();
    return static_cast<double>(miles) / gallons;
}

int main() {
    int miles{};
    int gallons{};
    double miles_per_galon{};
    
    std::cout << "Enter the miles: ";
    std::cin >> miles;
    std::cout << "Enter the gallons: ";
    std::cin >> gallons;
    
    try {
        miles_per_galon = calculate_mpg(miles, gallons);
        std::cout << "Result: " << miles_per_galon << std::endl;
    }
    catch (const DivideByZeroException &ex) {
        std::cerr << "Tried to divide by zero" << std::endl;
    }
    catch (const NegativeValueException &ex) {
        std::cerr << "Sorry, one of your parameters is negative" << std::endl;
    }
    std::cout << "Bye" << std::endl;
    return 0;
}