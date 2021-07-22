#pragma once
#include <string>
#include <ctime>

class Track{
    static int id;
    std::string titleSong;
    std::tm creationDate{}; 
    std::size_t duration;
    std::time_t endPlay;
   
public:
    Track();
    static void initRand();
    friend void play(Track& track);
    void show();
};