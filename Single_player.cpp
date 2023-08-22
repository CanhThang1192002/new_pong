#include "Single_player.h"
#include <conio.h>
#include <chrono>
#include <iostream>
#include <ctime>
#include "Windows.h"

//A-1 la nguoi
//B-2 la bot

Single_player::Single_player(){}

void Single_player::A_Polish() {
	srand(time(NULL));
	float ball_x = _ball.get_x() - 7.5;
	float ball_y = _ball.get_y() - 7.5;
	float paddle_x = _paddle1.get_x();
	float paddle_y = _paddle1.get_y();
	if(ball_x > paddle_x-20 && ball_x < paddle_x+20 && ball_y > paddle_y - 30 && ball_y < paddle_y + 30){
		if(ball_x <= 282 && ball_x >= 190){
			float corner = -92.5 + rand() % 22;
			_ball.set_corner(corner);
		}
		if(ball_x <= 374 && ball_x > 282){
			float corner = -108.5 + rand() % 22;
			_ball.set_corner(corner);
		}
		if(ball_x < 190 && ball_x >= 99){
			float corner = -76 + rand() % 19;
			_ball.set_corner(corner);
		}
		if(ball_x <= 466 && ball_x > 374){
			float corner = -122 + rand() % 19;
			_ball.set_corner(corner);
		}
		if(ball_x < 99){
			float corner = -61.5 + rand() % 15;
			_ball.set_corner(corner);
		}
		if(ball_x > 466){
			float corner = -132.5 + rand() % 15;
			_ball.set_corner(corner);
		}
	}
}

void Single_player::B_Polish(){
	srand(time(NULL));
	float ball_x = _ball.get_x() - 7.5;
	float ball_y = _ball.get_y() - 7.5;
	float paddle_x = _paddle2.get_x();
	float paddle_y = _paddle2.get_y();
	//std::cout <<"     --->  x bong: " << ball_x << "  y bong: " << ball_y << "  x bot: " << paddle_x << "  y bot:  " << paddle_y << std::endl;
	if(ball_x > paddle_x-20 && ball_x < paddle_x+20 && ball_y > paddle_y - 30 && ball_y < paddle_y){
		if(ball_x <= 282 && ball_x >= 230){
			float corner = 60 + rand() % 47;
			_ball.set_corner(corner);
		}
		if(ball_x <= 334 && ball_x > 282){
			float corner = 74 + rand() % 47;
			_ball.set_corner(corner);
		}
		if(ball_x < 230 && ball_x >= 178){
			float corner = 50.5 + rand() % 54;
			_ball.set_corner(corner);
		}
		if(ball_x <= 386 && ball_x > 334){
			float corner = 76 + rand() % 54;
			_ball.set_corner(corner);
		}
		if(ball_x < 178){
			float corner = 47.5 + rand() % 27;
			_ball.set_corner(corner);
		}
		if(ball_x > 386){
			float corner = 106.5 + rand() % 27;
			_ball.set_corner(corner);
		}
	}
}

void Single_player::createWindow(int width, int height, const std::string& title) {
	window.create(sf::VideoMode(width, height), title);
}

int Single_player::Check_result(){ //1 bot win - 2 nguoi win
	if(_ball.get_x() > 500 || _ball.get_x() < 20 || _ball.get_y() > 630 || _ball.get_y() < 10){
		if(_ball.get_x() > 20 || _ball.get_x() < 500){
			if(_ball.get_y() > 630) return 1;
			if(_ball.get_y() < 10) return 2;
		}
		else{
			if(_ball.get_x() <= 380 && _ball.get_y() >= 225){
				if(_ball.get_corner() < 0) return 1;
				else{
					int x = (_ball.get_y() - 225)/tan((180-_ball.get_corner()) *3.14159265f/180.0f ) + _ball.get_x();
					if(x >= 146) return 1;
					else return 2;
				}
			}

			if(_ball.get_x() > 380 && _ball.get_y() >= 225){
				if(_ball.get_corner() < 0) return 1;
				else{
					int x = _ball.get_x() - (_ball.get_y() - 225)/tan(_ball.get_corner() *3.14159265f/180.0f );
					if(x <= 419) return 1;
					else return 2;
				}
			}

			if(_ball.get_x() >= 380 && _ball.get_y() < 225){
				if(_ball.get_corner() > 0) return 2;
				else{
					int x = _ball.get_x() - (_ball.get_y() - 225)/tan(-_ball.get_corner() *3.14159265f/180.0f );
					if(x <= 419) return 1;
					else return 2;
				}
			}

			if(_ball.get_x() < 380 && _ball.get_y() < 225){
				if(_ball.get_corner() > 0) return 2;
				else{
					int x = (_ball.get_y() - 225)/tan((180+_ball.get_corner()) *3.14159265f/180.0f ) + _ball.get_x();
					if(x >= 146) return 1;
					else return 2;
				}
			}
		}
	}
	return 0;
}

int Single_player::Play_game()
{
	float x = 0, y = 0; // toa do con tro chuot
	_paddle1.set_x(282);
	_paddle1.set_y(413);
	_paddle2.set_x(282);
	_paddle2.set_y(60);
	_ball.set_x(280);
	_ball.set_y(90);
	_ball.set_speed(0.5f);
	_ball.set_corner(90.0f);
	createWindow(850,641,"Single player");
	Object bg("./img/bg1.png");
	_table.setSprite("./img/table1.png");
	_ball.setSprite("./img/ball.png");
	_paddle1.setSprite("./img/paddle.png");
	_paddle2.setSprite("./img/paddle.png");
	_score1 = 0;
	_score2 = 0;
	Text textScore1, textScore2;
	Font font;
	if (!font.loadFromFile("Roboto-Black.ttf")) {
		// Xử lý lỗi nếu không thể tải font
		return 0;
	}
	Object imgScore1("./img/botScore.png");
	Object imgScore2("./img/yourScore.png");
	textScore1.setFont(font);
	textScore1.setCharacterSize(100);
	textScore1.setFillColor(Color::Red);

	textScore2.setFont(font);
	textScore2.setCharacterSize(100);
	textScore2.setFillColor(Color::Red);
	while (isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
			if (event.type ==  Event::MouseMoved) {
				x = event.mouseMove.x;
				y = event.mouseMove.y;
			}
		}

		window.clear( Color::White);
		drawSprite(bg);

		imgScore1.setPosition(600,20);
		drawSprite(imgScore1);
		textScore1.setString(std::to_string(_score1));
		textScore1.setPosition(670,150);
		window.draw(textScore1);

		imgScore2.setPosition(600,350);
		drawSprite(imgScore2);
		textScore2.setString(std::to_string(_score2));
		textScore2.setPosition(670,500);
		window.draw(textScore2);

		drawSprite(_table);

		_ball.Move();
		_ball.setPosition(_ball.get_x()-7.5,_ball.get_y()-7.5);
		drawSprite(_ball);
		A_Polish();

		float newx = x, newy = y;
		if(y < 215) newy = 215;
		if(y > 600) newy = 600;
		if(x < 40) newx = 40;
		if(x > 520) newx = 520;
		_paddle1.set_x(newx);
		_paddle1.set_y(newy);
		_paddle1.setPosition(_paddle1.get_x()-20,_paddle1.get_y()-30);
		drawSprite(_paddle1);

		B_Polish();
		_paddle2.set_x(_ball.get_x());
		_paddle2.setPosition(_paddle2.get_x()-20,_paddle2.get_y()-30);
		drawSprite(_paddle2)
			;
		_ball.set_speed(_ball.get_speed() + 0.00001);

		int result = 0;
		result = Check_result();
		if(result > 0) {
			if(result == 1) {
				_score1++;
			} else {
				_score2++;
			}
			x = 0;
			y = 0;
			_paddle2.set_x(282);
			_paddle2.set_y(60);
			_ball.set_x(280);
			_ball.set_y(90);
			_ball.set_speed(0.5f);
			_ball.set_corner(90.0f);
			Sleep(1000);
		}
		if(_score1 == 11) { 
			Sleep(3000);
			return 1;
		}
		if(_score2 == 11) {
			Sleep(3000);
			return 2;
		}

		window.display();
	}
	return 0;
}