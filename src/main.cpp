#include <iostream>
#include "player.h"
#include "track.h"


int main(){
   Player player;
   Track::initRand();

   int size = player.loadPlaylists();
   int index = 0;
      
   do{
        
        std::cout<<"Enter idex song#x: ";
        std::cin>>index;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(INT16_MAX, '\n');
            std::cout<<"Error index"<<std::endl;
        }
      
   }while(index <= 0 || index > size);


   player.setIndexSong(index);
   std::string answer;
   
   do{
       std::cout<<"Press command: [play] [stop] [pause] [next] [exit]"<<std::endl;
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
       
   }while(answer!= "exit");
   
    return 0;
}