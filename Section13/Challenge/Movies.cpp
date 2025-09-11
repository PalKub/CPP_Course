#include "Movies.h"

Movies::Movies() 
    : movie_list{} {
}

Movies::~Movies()
{
}

bool Movies::add_movie(std::string name_val, std::string rating_val, int watched_val) {
    for (const Movie &movie: movie_list) {
        if (movie.get_name() == name_val)
            return false;
    }
    movie_list.push_back(Movie(name_val, rating_val, watched_val));
    return true;
}

bool Movies::increment_watched(std::string name_val) {
    for (Movie &movie: movie_list) {
        if (movie.get_name() == name_val) {
            movie.increment_watched();
            return true;
        }
    }
    return false;
}

void Movies::display() const {
    if (movie_list.size() == 0) {
        std::cout << "The movie list is empty" << std::endl;
    } else {
        std::cout << "\n------------------- Movie List -------------------" << std::endl;
        for (const Movie &movie: movie_list) {
            movie.display();
        }
        std::cout << "--------------------------------------------------\n" << std::endl;
    }
}