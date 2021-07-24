#include <iostream>
#include "player.h"
#include "track.h"


int main(){
   Player player;
   Track::initRand();

   player.loadPlaylists();
   std::string answer;
   while(answer!= "exit"){
       std::cin>>answer;
       if(answer == "p"){
           player.play(1);///???????
       }else if(answer == "s"){
           player.stop();
       }else if(answer == "n"){
           player.next();
       }
       
   }
   
    return 0;
}