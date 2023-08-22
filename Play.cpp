#include "Play.h"
#include <SFML/Graphics.hpp>
using namespace sf;

Play::Play(){}

bool Play::isOpen() {
	return window.isOpen();
}

void Play::clear() {
	window.clear();
}

void Play::display() {
	window.display();
}

void Play::drawSprite(Object& object) {
	object.draw(window);
}