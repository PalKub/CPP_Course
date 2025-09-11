#ifndef _MOVIE_H_
#define _MOVIE_H_
#include <string>
#include <iostream>

class Movie
{
    std::string name;
    std::string rating;
    int watched;
    
public:
    Movie(std::string name_val, std::string rating_val, int watched_val);
    Movie(const Movie &source);
    ~Movie();
    void increment_watched();
    int get_watched() const { return watched; }
    std::string get_name() const { return name; }
    std::string get_rating() const {return rating; }
    void display() const;
};

#endif // _MOVIE_H_