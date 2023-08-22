#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include "Object.h"

class Ball : public Object
{
private:
	float _x;
	float _y;
	float _speed;
	float _corner;
public:
	Ball();
	Ball(const std::string& img, float speed, float corner);
	void set_x(float x);
	void set_y(float y);
	void set_speed(float speed);
	void set_corner(float corner);
	float get_x();
	float get_y();
	float get_speed();
	float get_corner();
	void Move();
	//~Ball();

};

