#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Alien
{
private:
	Sprite ship;
public:
	void setTexture(Texture&);
	void setPosition(int x, int y);
	void move();
	void draw(RenderWindow&);
};