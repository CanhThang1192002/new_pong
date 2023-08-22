#include "Menu.h"
#include <SFML\Graphics.hpp>
#include <string>
#include<iostream>
using namespace sf;

Menu::Menu(const std::string& menu, const std::string& person1, const std::string& person2, const std::string& online, const std::string& logo, const std::string& name) : window(sf::VideoMode(500, 700), "Start Game"){
	if (!textureMenu.loadFromFile(menu)) {
		// Xử lý lỗi tải ảnh
	}
	_menu.setTexture(textureMenu);
	if (!texturePerson1.loadFromFile(person1)) {
		// Xử lý lỗi tải ảnh
	}
	_person1.setTexture(texturePerson1);
	if (!texturePerson2.loadFromFile(person2)) {
		// Xử lý lỗi tải ảnh
	}
	_person2.setTexture(texturePerson2);
	if (!textureOnline.loadFromFile(online)) {
		// Xử lý lỗi tải ảnh
	}
	_online.setTexture(textureOnline);
	if (!textureLogo.loadFromFile(logo)) {
		// Xử lý lỗi tải ảnh
	}
	_logo.setTexture(textureLogo);
	if (!textureName.loadFromFile(name)) {
		// Xử lý lỗi tải ảnh
	}
	_name.setTexture(textureName);
}

int Menu::Display(){
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
			if (event.type == Event::MouseButtonPressed) {
				if (event.mouseButton.button == Mouse::Left) {
					std::cout << "Mouse Clicked at: " << event.mouseButton.x << ", " << event.mouseButton.y << std::endl;
					if(event.mouseButton.x > 155 && event.mouseButton.x < 345 && event.mouseButton.y > 405 && event.mouseButton.y < 477){
						window.close();
						return 1;
					}
					if(event.mouseButton.x > 155 && event.mouseButton.x < 345 && event.mouseButton.y > 505 && event.mouseButton.y < 577){
						window.close();
						return 2;
					}
				}
			}
		}

		window.clear();
		window.draw(_menu);

		_name.setPosition(50,10);
		window.draw(_name);

		_logo.setPosition(50,130);
		window.draw(_logo);

		_person1.setPosition(150,400);
		window.draw(_person1);

		_person2.setPosition(150,500);
		window.draw(_person2);

		_online.setPosition(150,600);
		window.draw(_online);

		window.display();
	}
	return 0;
}
