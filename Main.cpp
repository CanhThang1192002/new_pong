#include "Menu.h"
#include "Single_player.h"
#include "Double_play.h"
#include "Play.h"
#include <SFML/Graphics.hpp>
using namespace sf;

int main(){
	Menu menu("./img/menu.png","./img/person1.png","./img/person2.png","./img/online.png","./img/logo.png","./img/name.png");
	int check = menu.Display();
	if(check == 1){
		Single_player SinglePlay;
		Play* play = &SinglePlay;
		play->Play_game();
	}
	if(check == 2){
		Double_play Double_play;
		Play* play = &Double_play;
		play ->Play_game();
	}
	return 0;
}


