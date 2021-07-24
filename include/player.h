#pragma once
#include <vector>


class Track;

class Player{
    enum Status{
        PLAY,
        STOP,
        PAUSE
    };
    Status status{Status::STOP};
    std::vector<Track*> playlists;
    int indexSong{0};
    void print();

public:

    void loadPlaylists(int size = 3);
    void setIndexSong(int numSong);
    void play();
    void stop(bool print = true);
    void pause();
    void next();
    ~Player();
};