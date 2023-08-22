#pragma once
#include <SFML\Graphics.hpp>
#include <string>
using namespace sf;
 
class Menu
{
private:
        RenderWindow window;
        Sprite _menu;
		Texture textureMenu;
        Sprite _person1;
		Texture texturePerson1;
        Sprite _person2;
		Texture texturePerson2;
        Sprite _online;
		Texture textureOnline;
        Sprite _logo;
		Texture textureLogo;
        Sprite _name;
		Texture textureName;
public:
        //Menu();
        Menu(const std::string&,const std::string&,const std::string&,const std::string&,const std::string&,const std::string&);
        //~Menu();
        int Display();
};