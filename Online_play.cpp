#include "Online.h"
#include "Double_play.h"
#include <conio.h>
#include <chrono>
#include <iostream>
#include <ctime>
#include "Windows.h"
#include "Server.h"
#include "Client.h"

Online::Online(){}

int Online::Online_play(){
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
		}
		//server
		unsigned short port = 54000;
		Server server(port);
		server.startListening();

		//client

		/*const std::string serverip = "địa_chỉ_ip_của_máy_chủ";
		unsigned short port = 54000;

		Client Client(serverip, port);
		Client.connectToServer();*/


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

		drawSprite(_table);
		//server
		float newx = x, newy = y;
		if(y < 120) newy = 120;
		if(y > 560) newy = 560;
		if(x < 490) newx = 490;
		if(x > 850) newx = 850;
		_paddle2.set_x(newx);
		_paddle2.set_y(newy);

		//client

		/*float newx = x, newy = y;
		if(y < 120) newy = 120;
		if(y > 560) newy = 560;
		if(x < 50) newx = 50;
		if(x > 400) newx = 400;
		_paddle1.set_x(newx);
		_paddle1.set_y(newy)*/;


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