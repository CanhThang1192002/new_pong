#include "Play.h"
#include "Double_play.h"

class Online : Double_play
{
public:
	Online();
	int Online_play();
	//~Online();

private:
	float x_paddle1;
	float x_paddle2;
	float y_paddle1;
	float y_paddle2;
};
