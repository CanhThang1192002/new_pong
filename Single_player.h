#include "Menu.h"
#include <SFML/Graphics.hpp>
#include "Play.h"
using namespace sf;

//A-1 la nguoi
//B-2 la bot
class Single_player : public Play
{
private:
	
public:
	Single_player();
	void A_Polish() override;
	void B_Polish() override;
	void createWindow(int width, int height, const std::string& title) override;
	int Check_result() override;
	int Play_game() override;

	//~Single_player();

};
