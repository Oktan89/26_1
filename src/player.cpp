#include <iostream>
#include <iomanip>
#include <ctime>
#include "player.h"
#include "track.h"


void Player::loadPlaylists(int size){

    for(int i = 0; i < size; ++i){
        std::cout<<"Load playlists...";
        Track* song = new (std::nothrow) Track;

        if(song == nullptr){

            std::cout<<"error"<<std::endl;

        }else{

            song->initSong();
            playlists.push_back(song);
            std::cout<<*song<<" ок"<<std::endl;

        }
    }
}

Player::~Player(){

    for(int i = 0; i < playlists.size(); ++i){

        std::cout<<"delete "<<playlists[i]->titleSong<<"...";
        delete playlists[i];
        std::cout<<"ok"<<std::endl;

    }
}
void Player::print(){
    
    for(int i = 0; i < playlists.size(); ++i){
       std::cout<<((playlists[i]->endPlay)? "Play " : "Stop ")
            <<*playlists[i]
            <<((playlists[i]->endPlay)? " remaining playing time:["+ std::to_string(playlists[i]->endPlay - std::time(nullptr)) + "]" : " ")
            <<std::endl;
    }
}

void Player::play(int numSong){
    --numSong;
    if(numSong >= 0 && numSong < playlists.size())
    {
        switch(status){
            case Status::PLAY:
                if(playlists[numSong]->endPlay <= std::time(nullptr)){
                    status = STOP;
                    playlists[numSong]->endPlay = 0;
                    print();
                }else{
                    
                    print();
                }
                
            break;
            case Status::STOP:
                playlists[numSong]->endPlay = playlists[numSong]->duration + std::time(nullptr);
                status = PLAY;
                print();
            break;
            case Status::PAUSE:
            break;
        };
        

    }else{

        std::cout<<"song#"<<++numSong<<" not found"<<std::endl;

    }
    
}