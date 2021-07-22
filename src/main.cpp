#include <iostream>
#include <thread>
#include <chrono>
#include "track.h"

int main(){
    Track::initRand();

    Track* test = new Track;
    test->show();
    delete test;
    return 0;
}