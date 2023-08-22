
#include "Paddle.h"

Paddle::Paddle(){}

Paddle::Paddle(const std::string& img, float speed, float corner) : Object(img), _speed(speed), _corner(corner) {}

void Paddle::set_x(float x){
	_x = x;
}

void Paddle::set_y(float y){
	_y = y;
}

void Paddle::set_speed(float speed){
	_speed = speed;
}

void Paddle::set_corner(float corner){
	_corner = corner;
}

float Paddle::get_x(){
	return _x;
}

float Paddle::get_y(){
	return _y;
}

float Paddle::get_speed(){
	return _speed;
}

float Paddle::get_corner(){
	return _corner;
}

void Paddle::Move(){
	_x += _speed * std::cos(_corner * 3.14159265f / 180.0f);  
    _y += _speed * std::sin(_corner * 3.14159265f / 180.0f);
}