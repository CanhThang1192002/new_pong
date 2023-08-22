#include "Menu.h"
#include <SFML/Graphics.hpp>
#include "Play.h"
using namespace sf;

//A-1 trai
//B-2 phai
class Double_play : public Play
{
private:
	
public:
	Double_play();
	void A_Polish() override;
	void B_Polish() override;
	void createWindow(int width, int height, const std::string& title) override;
	int Check_result() override;
	int Play_game() override;

	//~Double_play();

};
