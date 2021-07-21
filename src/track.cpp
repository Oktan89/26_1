#include "track.h"

Track::Track(){

}

Track::Track(const std::string &titleSong, const std::size_t duration){
    this->titleSong = titleSong;
    this->duration = duration;
}