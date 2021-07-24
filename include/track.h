#pragma once
#include <string>
#include <ctime>
#include <ostream>

class Player;

class Track{
    static int id;
    std::string titleSong;
    std::tm creationDate{}; 
    std::size_t duration;
    std::time_t endPlay;
    friend Player;
    friend std::ostream& operator<< (std::ostream& out, const Track &track);
public:
    void initSong();
    static void initRand();
};