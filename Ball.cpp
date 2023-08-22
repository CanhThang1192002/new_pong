
#include "Ball.h"

Ball::Ball(){}

Ball::Ball(const std::string& img, float speed, float corner) : Object(img), _speed(speed), _corner(corner) {}

void Ball::set_x(float x){
	_x = x;
}

void Ball::set_y(float y){
	_y = y;
}

void Ball::set_speed(float speed){
	_speed = speed;
}

void Ball::set_corner(float corner){
	_corner = corner;
}

float Ball::get_x(){
	return _x;
}

float Ball::get_y(){
	return _y;
}

float Ball::get_speed(){
	return _speed;
}

float Ball::get_corner(){
	return _corner;
}

void Ball::Move(){
	_x += _speed * std::cos(_corner * 3.14159265f / 180.0f);  
    _y += _speed * std::sin(_corner * 3.14159265f / 180.0f);
	//_h = _h + (_v * std::sin(ampha)*t - (10*t*t)/2)/20;
	//_v = sqrt(pow(_v*sin(ampha) - 10*t, 2) + pow(_v*cos(ampha),2));
}
