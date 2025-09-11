#include "Movie.h"

Movie::Movie(std::string name_val, std::string rating_val, int watched_val)
    : name{name_val}, rating{rating_val}, watched{watched_val} {
}

Movie::Movie(const Movie &source)
    : Movie{source.name, source.rating, source.watched} {
}

Movie::~Movie() {
}

void Movie::increment_watched() {
    watched++;
}

void Movie::display() const {
    std::cout << "Title: "<< name << ", Rating: " << rating << ", Watched: " << watched << "time(s)." << std::endl;
}