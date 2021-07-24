#include <iostream>
#include "player.h"
#include "track.h"


int main(){
   Player player;
   Track::initRand();

   player.loadPlaylists(3);
   std::string answer;
   while(answer!= "exit"){
       std::cin>>answer;
       player.play(1);
   }
   
    return 0;
}