#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>
#include <algorithm>
#include <iterator>

class Song {
    friend std::ostream &operator<<(std::ostream &os, const Song &s);
    std::string name;
    std::string artist;
    int rating;
public:
    Song() = default;
    Song(std::string name, std::string artist, int rating)
        : name{name}, artist{artist}, rating{rating} {}
    std::string get_name() const {
        return name;
    }
    std::string get_artist() const {
        return artist;
    }
    int get_rating() const {
        return rating;
    }
    
    bool operator<(const Song &rhs) const {
        return this->name < rhs.name;
    }
    
    bool operator==(const Song &rhs) const {
        return this->name == rhs.name;
    }
};

std::ostream &operator<<(std::ostream &os, const Song &s) {
    os << std::setw(20) << std::left << s.name
       << std::setw(30) << std::left << s.artist
       << std::setw(2) << std::left << s.rating;
       return os;
}

void display_menu() {
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "N = Play Next song" << std::endl;
    std::cout << "P - Play Previous song" << std::endl;
    std::cout << "A - Add and play a new Song at current location" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
    std::cout << "============================================================" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song &song) {
    std::cout << "Playing:\n" << song << std::endl;
}

void play_next_song(std::list<Song> &playlist, std::list<Song>::iterator &it) {
    std::cout << "Playing next song" << std::endl;
    it++;
    if(it == playlist.end()) {
        std::cout << "Wrapping to start of playlist" << std::endl;
        it = playlist.begin();
    }
    play_current_song(*it);
}

void play_previous_song(std::list<Song> &playlist, std::list<Song>::iterator &it) {
    std::cout << "Playing previous song" << std::endl;
    if(it == playlist.begin()) {
        std::cout << "Wrapping to end of playlist" << std::endl;
        it = playlist.end();
    }
    it--;        
    play_current_song(*it);
}

void play_first_song(std::list<Song> &playlist, std::list<Song>::iterator &it) {
    it = playlist.begin();
    std::cout << "Playing current song" << std::endl;
    play_current_song(*it);
}

void add_new_song(std::list<Song> &playlist, std::list<Song>::iterator &it) {
    std::cout << "Adding and playing new song" << std::endl;
    
    std::string name{};
    std::string artist{};
    int rating{};
    
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter song name: ";
    getline(std::cin, name);
    std::cout << "Enter song artist: ";
    getline(std::cin, artist);
    std::cout << "Enter your rating (1-5): ";
    std::cin >> rating;
    
    playlist.emplace(it, name, artist, rating);
    it--;
    std::cout << std::endl;
    play_current_song(*it);
}

void display_playlist(const std::list<Song> &playlist, const Song &current_song) {
    for(const auto &song : playlist)
        std::cout << song << std::endl;
    std::cout << "Current song:\n" << current_song << std::endl;
}

int main() {
    
    std::list<Song> playlist{
        {"God's Plan", "Drake", 5},
        {"Never Be The Same", "Camila Cabello", 5},
        {"Pray For Me", "The Weekend and K. Lamar", 4},
        {"The Middle", "Zedd, Maren Morris & Grey", 5},
        {"Wait", "Maroon 5", 4},
        {"Whatever It Takes", "Imagine Dragons", 3}
    };
    
    std::list<Song>::iterator current_song = playlist.begin();
    
    display_playlist(playlist, *playlist.begin());
    
    char input{};
    
    do {
        display_menu();
        std::cin >> input;
        input = toupper(input);
        std::cout << std::endl;
        
        if(input == 'F')
            play_first_song(playlist, current_song);
        else if(input == 'N')
            play_next_song(playlist, current_song);
        else if(input == 'P')
            play_previous_song(playlist, current_song);
        else if(input == 'A')
            add_new_song(playlist, current_song);
        else if(input == 'L')
            display_playlist(playlist, *current_song);
        else if(input == 'Q')
            std::cout << "Quitting" << std::endl;
        else
            std::cout << "Illegal choice, try again...";
    } while(input != 'Q');
        
    std::cout << "Thanks for listening!" << std::endl;
    return 0;
}