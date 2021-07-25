#include <iostream>
#include <iomanip>
#include <ctime>
#include "player.h"
#include "track.h"


int Player::loadPlaylists(int size){

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
    return playlists.size();
}

Player::~Player(){

    for(int i = 0; i < playlists.size(); ++i){

        std::cout<<"delete "<<playlists[i]->titleSong<<"...";
        delete playlists[i];
        std::cout<<"ok"<<std::endl;

    }
}
void Player::print(){

#if defined(__unix__) || defined(__APPLE__)
    system("clear");
#elif defined(_WIN32) || defined(_WIN64)
    system("cls");
#endif 
    std::string _status;
    
    for(int i = 0; i < playlists.size(); ++i){
        if(status == PAUSE){
            _status = (playlists[i]->endPlay)? "Pause " : "Stop ";

        }else{
            _status = (playlists[i]->endPlay)? "Play " : "Stop ";
        }
       std::cout<<_status<<*playlists[i]
            <<((playlists[i]->endPlay)? " remaining playing time:["+ std::to_string(playlists[i]->endPlay - std::time(nullptr)) + "]" : " ")
            <<std::endl;
    }
    //std::cout<<"Press command: [play] [stop] [pause] [next] [exit]"<<std::endl;
}

void Player::setIndexSong(int numSong){
    --numSong;
    if(numSong >= 0 && numSong < playlists.size())
    {
        indexSong = numSong;
    }else{

        std::cout<<"song#"<<++numSong<<" not found"<<std::endl;

    }
}

void Player::play(){
    
        switch(status){
            case Status::PLAY:
                if(playlists[indexSong]->endPlay <= std::time(nullptr)){
                    status = STOP;
                    playlists[indexSong]->endPlay = 0;
                }
            break;
            case Status::STOP:
                playlists[indexSong]->endPlay = playlists[indexSong]->duration + std::time(nullptr);
                status = PLAY;
               
            break;
            case Status::PAUSE:
     
            status = PLAY;
                
            break;
        };
        print();
}

void Player::stop(bool show){
    if(status == PLAY || status == PAUSE){
        playlists[indexSong]->endPlay = 0;
        status = STOP;
        
    }
    if(show) print();
}

void Player::next(){
    stop(false);
    rand();
    indexSong = rand()%playlists.size();
    play();
}

void Player::pause(){
    if(status == PLAY){
        duration_paus = playlists[indexSong]->endPlay - std::time(nullptr);
        playlists[indexSong]->endPlay = duration_paus + std::time(nullptr);
        
        status = PAUSE;
    }else if(status == PAUSE){
        
        playlists[indexSong]->endPlay = duration_paus + std::time(nullptr);

    }
    
   print();
}