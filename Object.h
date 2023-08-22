#pragma once
#include <SFML\Graphics.hpp>
#include <string>
using namespace sf;

class Object
{
protected:
	Sprite _sprite;
	Texture _texture;

public:
	Object();
	Object(const std::string& img);
	void setSprite(const std::string& img);
	void setPosition(float x, float y);
    void draw(RenderWindow& window);
	void move(float speed, float corner);
	float get_w();
	float get_h();
	float get_x();
	float get_y();
	//~Object();

};
