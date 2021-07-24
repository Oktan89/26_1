#pragma once
#include <vector>


class Track;

class Player{
    enum Status{
        PLAY,
        STOP,
        PAUSE
    };
    Status status = Status::STOP;
    std::vector<Track*> playlists;
    void print();

public:

    void loadPlaylists(int size = 3);
    void play(int numSong);
    ~Player();
};