#include <iostream>
#include "player.h"
#include "track.h"


int main(){
   Player player;
   Track::initRand();

   player.loadPlaylists();
   std::string answer;
   std::cout<<"Enter idex song: ";
   std::cin>>answer;
   player.setIndexSong(std::stoi(answer));
   while(answer!= "exit"){
       std::cin>>answer;
       if(answer == "play"){
           player.play();
       }else if(answer == "stop"){
           player.stop();
       }else if(answer == "next"){
           player.next();
       }else if(answer == "pause"){
           player.pause();
       }
       
   }
   
    return 0;
}