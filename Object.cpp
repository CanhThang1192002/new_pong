#include"Object.h"

Object::Object(){}

Object::Object(const std::string& img){
	if (!_texture.loadFromFile(img)) {
        // Xử lý lỗi tải ảnh
    }
    _sprite.setTexture(_texture);
}

void Object::setSprite(const std::string& img){
	if (!_texture.loadFromFile(img)) {
        // Xử lý lỗi tải ảnh
    }
    _sprite.setTexture(_texture);
}

void Object::setPosition(float x, float y){
	_sprite.setPosition(x, y);
}

void Object::draw(RenderWindow& window){
	window.draw(_sprite);
}

float Object::get_w(){
	return _sprite.getGlobalBounds().width;
}

float Object::get_h(){
	return _sprite.getGlobalBounds().height;
}

float Object::get_x(){
	return _sprite.getPosition().x;
}

float Object::get_y(){
	return _sprite.getPosition().y;
}

void Object::move(float speed, float corner){
	int dx = speed * std::cos(corner * 3.14159265f / 180.0f) + _sprite.getPosition().x;  
    int dy = speed * std::sin(corner * 3.14159265f / 180.0f) + _sprite.getPosition().y;
	setPosition(dx,dy);
}