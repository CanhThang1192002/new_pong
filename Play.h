#ifndef AAA_HEADER
#define AAA_HEADER

#include "Ball.h"
#include "Table.h"
#include "Paddle.h"

class Play
{
protected:
	RenderWindow window;
	Ball _ball;	
	Table _table;
	Paddle _paddle1;
	Paddle _paddle2;
	int _score1;
	int _score2;
public:
	Play();
	virtual void A_Polish() = 0;
	virtual void B_Polish() = 0;
	virtual int Check_result() = 0;
	virtual int Play_game() = 0;
	virtual void createWindow(int width, int height, const std::string& title) = 0;
	bool isOpen();
    void clear();
    void display();
    void drawSprite(Object& opject);
	//~Play();

};

#endif
