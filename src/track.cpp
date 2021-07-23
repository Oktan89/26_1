#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "track.h"

int Track::id = 1;

Track::Track(){
    
    titleSong = "soung_" + std::to_string(id++)+".mp3";
    std::time_t now = time(nullptr);
    creationDate =  *std::localtime(&now);
    duration = 120 + std::rand()%240;
    endPlay = 0;
}

void Track::initRand(){
    std::srand(time(nullptr));
}

void Track::show(){
    std::cout<<titleSong<<" "<<duration<<" "<<std::put_time(&creationDate, "%c");
}