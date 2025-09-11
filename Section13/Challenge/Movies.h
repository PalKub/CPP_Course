#ifndef _MOVIES_H_
#define _MOVIES_H_
#include <iostream>
#include <string>
#include <vector>
#include "Movie.h"


class Movies
{
private:
    std::vector<Movie> movie_list;
public:
    Movies();
    ~Movies();
    bool add_movie(std::string name_val, std::string rating_val, int watched_val);
    bool increment_watched(std::string name_val);
    void display() const;
};

#endif // _MOVIES_H_