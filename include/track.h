#pragma once
#include <string>
#include <ctime>

class Track{
    std::string titleSong;
    std::time_t creationDate; 
    std::size_t duration;
public:
    Track();
    Track(const std::string &titleSong, const std::size_t duration);
    ~Track();
};