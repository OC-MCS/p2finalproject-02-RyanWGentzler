#include "Alien.h"

void Alien::setTexture(Texture& text)
{
	ship.setTexture(text);
}

void Alien::setPosition(int x, int y)
{
	ship.setPosition(x, y);
}

void Alien::draw(RenderWindow& win)
{
	win.draw(ship);
}