#pragma once
#include <string>
#include <ctime>
#include "player.h"


class Track{
    static int id;
    std::string titleSong;
    std::tm creationDate{}; 
    std::size_t duration;
    std::time_t endPlay;
    friend void Player::play(Track &track);
    
public:
    Track();
    static void initRand();
    void show();
};