#pragma once
#include <string>
#include <ctime>
#include "player.h"

class Player;

class Track{
    static int id;
    std::string titleSong;
    std::tm creationDate{}; 
    std::size_t duration;
    std::time_t endPlay;
   
public:
    Track();
    static void initRand();
    friend void Player::play(Track &track);
    void show();
};