#include "Double_play.h"
#include <conio.h>
#include <chrono>
#include <iostream>
#include <ctime>
#include "Windows.h"

//A-1 trai
//B-2 phai

Double_play::Double_play(){}

void Double_play::A_Polish(){
	srand(time(NULL));
	float ball_x = _ball.get_x() - 7.5;
	float ball_y = _ball.get_y() - 7.5;
	float paddle1_x = _paddle1.get_x();
	float paddle1_y = _paddle1.get_y();

	if(ball_x > paddle1_x-15 && ball_x < paddle1_x+10 && ball_y > paddle1_y - 35 && ball_y < paddle1_y + 20){
		if(ball_y <= 336 && ball_y > 279){
			float x = -6 + rand() % 18;
			_ball.set_corner(x);
		}
		if(ball_y <= 393 && ball_y > 336){
			float x = -12 + rand() % 18;
			_ball.set_corner(x);
		}
		if(ball_y <= 279 && ball_y > 222){
			float x = 0 + rand() % 18;
			_ball.set_corner(x);
		}
		if(ball_y <= 450 && ball_y > 393){
			float x = -17.5 + rand() % 18;
			_ball.set_corner(x);
		}
		if(ball_y <= 222){
			float x = 15 + rand() % 8;
			_ball.set_corner(x);
		}
		if(ball_y > 450){
			float x = -22 + rand() % 10;
			_ball.set_corner(x);
		}
	}
}

void Double_play::B_Polish(){
	srand(time(NULL));
	float ball_x = _ball.get_x() - 7.5;
	float ball_y = _ball.get_y() - 7.5;
	float paddle2_x = _paddle2.get_x();
	float paddle2_y = _paddle2.get_y();

	if(ball_x > paddle2_x-15 && ball_x < paddle2_x+25 && ball_y > paddle2_y - 35 && ball_y < paddle2_y + 20){
		if(ball_y <= 336 && ball_y > 279){
			float x = -191.5 + rand() % 18;
			_ball.set_corner(x);
		}
		if(ball_y <= 393 && ball_y > 336){
			float x = -158.5 + rand() % 18;
			_ball.set_corner(x);
		}
		if(ball_y <= 279 && ball_y > 222){
			float x = 163.5 + rand() % 18;
			_ball.set_corner(x);
		}
		if(ball_y <= 450 && ball_y > 393){
			float x = -180 + rand() % 18;
			_ball.set_corner(x);
		}
		if(ball_y <= 222){
			float x = 158.5 + rand() % 17;
			_ball.set_corner(x);
		}
		if(ball_y > 450){
			float x = -167 + rand() % 10;
			_ball.set_corner(x);
		}
	}
}

void Double_play::createWindow(int width, int height, const std::string& title) {
	window.create(sf::VideoMode(width, height), title);
}

int Double_play::Check_result(){
	if(_ball.get_x() > 860 || _ball.get_x() < 40 || _ball.get_y() > 590 || _ball.get_y() < 110){
		if(_ball.get_y() > 590 || _ball.get_y() < 110){
			if(_ball.get_x() > 860) return 1;
			if(_ball.get_x() < 40) return 2;
		}
		else{
			if(_ball.get_x() <= 444 && _ball.get_y() <= 320){
				if(_ball.get_corner() < 0 && _ball.get_corner() >= 90) return 2;
				else{
					int x = (444 - _ball.get_x())*tan((90-_ball.get_corner()) *3.14159265f/180.0f ) + _ball.get_y();
					if(x >= 222) return 2;
					else return 1;
				}
			}

			if(_ball.get_x() <= 444 && _ball.get_y() > 320){
				if(_ball.get_corner() > 0 && _ball.get_corner() <= 90) return 2;
				else{
					int x = _ball.get_y() - (444 - _ball.get_x())*tan(-_ball.get_corner() *3.14159265f/180.0f );
					if(x <= 450) return 2;
					else return 1;
				}
			}

			if(_ball.get_x() > 444 && _ball.get_y() <= 320){
				if(_ball.get_corner() <= -90 && _ball.get_corner() >= -180) return 1;
				else{
					int x = _ball.get_y() + (44 - _ball.get_x())*tan(-_ball.get_corner() *3.14159265f/180.0f );
					if(x >= 222) return 1;
					else return 2;
				}
			}

			if(_ball.get_x() > 444 && _ball.get_y() > 320){
				if(_ball.get_corner() >= 90 && _ball.get_corner() <= 180) return 1;
				else{
					int x = _ball.get_y() - (_ball.get_x() - 444)*tan((180+_ball.get_corner()) *3.14159265f/180.0f );
					if(x <= 450) return 1;
					else return 2;
				}
			}
		}
	}
	return 0;
}

int Double_play::Play_game(){
	float x = 0, y = 0;
	_paddle1.set_x(140);
	_paddle1.set_y(320);
	_paddle2.set_x(745);
	_paddle2.set_y(320);
	_ball.set_x(444);
	_ball.set_y(320);
	_ball.set_corner(0.0f);
	_ball.set_speed(0.3f);
	_paddle1.set_speed(20.0f);
	_paddle2.set_speed(20.0f);
	_paddle1.set_corner(77.0f);
	_paddle2.set_corner(103.0f);

	createWindow(900,600,"Double Play");
	Object bg("./img/bg2.png");
	_table.setSprite("./img/table2.png");
	_ball.setSprite("./img/ball.png");
	_paddle1.setSprite("./img/paddle1.png");
	_paddle2.setSprite("./img/paddle2.png");
	_score1 = 0;
	_score2 = 0;
	Text textScore1, textScore2;
	Font font;
	if (!font.loadFromFile("Roboto-Black.ttf")) {
		// Xử lý lỗi nếu không thể tải font
		return 0;
	}
	Object imgScore1("./img/aScore.png");
	Object imgScore2("./img/bScore.png");

	textScore1.setFont(font);
	textScore1.setCharacterSize(70);
	textScore1.setFillColor(Color::Red);

	textScore2.setFont(font);
	textScore2.setCharacterSize(70);
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
			//di chuyen bat 1:
			if(Keyboard::isKeyPressed(Keyboard::A)){
				if(_paddle1.get_x() > 50){
					_paddle1.set_corner(180.0f);
					_paddle1.Move();
				}
			}
			if(Keyboard::isKeyPressed(Keyboard::D)){
				if(_paddle1.get_x() < 400){
					_paddle1.set_corner(0.0f);
					_paddle1.Move();
				}
			}
			if(Keyboard::isKeyPressed(Keyboard::W)){
				if(_paddle1.get_y() > 120){
					_paddle1.set_corner(-75.96375653f);
					_paddle1.Move();
				}
			}
			if(Keyboard::isKeyPressed(Keyboard::S)){
				if(_paddle1.get_y() < 560){
					_paddle1.set_corner(104.03624347f);
					_paddle1.Move();
				}
			}
			// di chuyen bat 2
			if(Keyboard::isKeyPressed(Keyboard::Left)){
				if(_paddle2.get_x() > 490){
					_paddle2.set_corner(180.0f);
					_paddle2.Move();
				}
			}
			if(Keyboard::isKeyPressed(Keyboard::Right)){
				if(_paddle2.get_x() < 850){
					_paddle2.set_corner(0.0f);
					_paddle2.Move();
				}
			}
			if(Keyboard::isKeyPressed(Keyboard::Up)){
				if(_paddle2.get_y() > 120){
					_paddle2.set_corner(-104.03624347f);
					_paddle2.Move();
				}
			}
			if(Keyboard::isKeyPressed(Keyboard::Down)){
				if(_paddle2.get_y() < 560){
					_paddle2.set_corner(75.96375653f);
					_paddle2.Move();
				}
			}
		}

		window.clear( Color::White);

		drawSprite(bg);

		imgScore1.setPosition(50,20);
		drawSprite(imgScore1);
		textScore1.setString(std::to_string(_score1));
		textScore1.setPosition(350,0);
		window.draw(textScore1);

		textScore2.setString(std::to_string(_score2));
		textScore2.setPosition(500,0);
		window.draw(textScore2);
		imgScore2.setPosition(650,20);
		drawSprite(imgScore2);
		
		_table.setPosition(0,85);
		drawSprite(_table);

		_paddle1.setPosition(_paddle1.get_x()-12,_paddle1.get_y()-33);
		drawSprite(_paddle1);
		A_Polish();

		_paddle2.setPosition(_paddle2.get_x()-12,_paddle2.get_y()-33);
		drawSprite(_paddle2);
		B_Polish();

		_ball.setPosition(_ball.get_x()-7.5,_ball.get_y()-7.5);
		drawSprite(_ball);
		_ball.Move();


		_ball.set_speed(_ball.get_speed() + 0.00001f);
		window.display();
		int result = 0;
		result = Check_result();
		if( result > 0){
			if(result == 1){
				_score1++;
				std::cout << "Player 1 win";
			} else{
				_score2++;
				std::cout << "Player 2 win";
			}
			x = 0;
			y = 0;
			_paddle1.set_x(140);
			_paddle1.set_y(320);
			_paddle2.set_x(745);
			_paddle2.set_y(320);
			_ball.set_x(444);
			_ball.set_y(320);
			_ball.set_corner(0.0f);
			_ball.set_speed(0.3f);
			_paddle1.set_speed(10.0f);
			_paddle2.set_speed(10.0f);
			_paddle1.set_corner(77.0f);
			_paddle2.set_corner(103.0f);
			Sleep(1000);
		}
		if(_score1 == 11 ){
			Sleep(3000);
			return 1;
		}
		if(_score2 == 11 ){
			Sleep(3000);
			return 2;
		}
	}
	return 0;
}