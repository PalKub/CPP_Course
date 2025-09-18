#include <cstring>
#include <iostream>
#include "Mystring.h"

//No-args constructor
Mystring::Mystring() 
    : str{nullptr} {
        str = new char[1];
        *str = '\0';
}

//Overloaded constructor
Mystring::Mystring(const char *s) 
    : str{nullptr} {
        if (s == nullptr) {
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[std::strlen(s) + 1];
            std::strcpy(str, s);
        }
}

//Copy constructor
Mystring::Mystring(const Mystring &source) 
    : str{nullptr} {
        str = new char[std::strlen(source.str) + 1];
        std::strcpy(str, source.str);
        //std::cout << "Copy constructor used" << std::endl;
}

//Move constructor
Mystring::Mystring(Mystring &&source) 
    : str(source.str) {
        source.str = nullptr;
        //std::cout << "Move constructor used" << std::endl;
}

//Destructor
Mystring::~Mystring() {
    if (str == nullptr) {
        //std::cout << "Calling destructor for Mystring : nullptr" << std::endl;
    } else {
        //std::cout << "Calling destructor for Mystring : " << str << std::endl;
    }
    delete [] str;
}

//Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs) {
    //std::cout << "Using copy assignment" << std::endl;
    if(this == &rhs)
        return *this;
    delete [] str;
    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(str, rhs.str);
    return *this;
}

//Move assignment
Mystring &Mystring::operator=(Mystring &&rhs) {
    //std::cout << "Using move assignment" << std::endl;
    if (this == &rhs)
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}


//Display methos
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

//length getter
int Mystring::get_length() const { return std::strlen(str); }

//string getter
const char *Mystring::get_str() const { return str; }

//overloaded insertion operator
std::ostream &operator<<(std::ostream &os, const Mystring &rhs) {
    os << rhs.str;
    return os;
}

//overloaded extraction operator
std::istream &operator>>(std::istream &in, Mystring &rhs) {
    char *buff = new char[1000];
    in >> buff;
    rhs = Mystring{buff};
    delete [] buff;
    return in;
}

//Equality
bool operator==(const Mystring &lhs, const Mystring &rhs) {
    return (std::strcmp(lhs.str, rhs.str) == 0);
}

bool operator!=(const Mystring &lhs, const Mystring &rhs) {
    return !(rhs == lhs);
}

bool operator<(const Mystring &lhs, const Mystring &rhs) {
    return lhs.str < rhs.str;
}

bool operator>(const Mystring &lhs, const Mystring &rhs) {
    return lhs.str > rhs.str;
}

//Make lowercase
Mystring operator-(const Mystring &lhs) {
    char *buff = new char[std::strlen(lhs.str) + 1];
    std::strcpy(buff, lhs.str);
    for (size_t i = 0; i < std::strlen(buff); i++)
        buff[i] = std::tolower(buff[i]);
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

//Concatenate
Mystring operator+(const Mystring &lhs, const Mystring &rhs) {
    char *buff = new char[std::strlen(lhs.str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, lhs.str);
    std::strcat(buff, rhs.str);
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

Mystring operator*(const Mystring &lhs, int multiplier) {
    Mystring temp;
    for (int i = 1; i <= multiplier; i++)
        temp = temp + lhs;
    return temp;
}

Mystring &operator+=(Mystring &lhs, const Mystring &rhs) {
    lhs = lhs + rhs;
    return lhs;
}

Mystring &operator*=(Mystring &lhs, int multiplier) {
    lhs = lhs * multiplier;
    return lhs;
}

Mystring &operator++(Mystring &obj) {
    for (size_t i = 0; i < std::strlen(obj.str); i++)
        obj.str[i] = std::toupper(obj.str[i]);
    return obj;
}

Mystring operator++(Mystring &obj, int) {
    Mystring temp {obj};
    ++obj;
    return temp;
}