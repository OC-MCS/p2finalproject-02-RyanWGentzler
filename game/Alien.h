#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Alien
{
private:
	Sprite ship;
public:
	Sprite getSprite();
	void setTexture(Texture&);
	void setPosition(int x, int y);
	void move(int);
	void draw(RenderWindow&);
};