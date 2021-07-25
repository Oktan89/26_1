#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "track.h"

int Track::id{1};

void Track::initSong(){
    
    titleSong = "song#" + std::to_string(id++)+".mp3";
    std::time_t now = time(nullptr);
    creationDate =  *std::localtime(&now);
    duration = 120 + std::rand()%240;
    endPlay = 0;
}

void Track::initRand(){

    std::srand(time(nullptr));

}


std::ostream& operator<< (std::ostream& out, const Track &track){

    std::cout<<track.titleSong<<" duration seconds:["<<track.duration<<"] "<<std::put_time(&track.creationDate, "%c");

    return out;
}