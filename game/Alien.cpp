#include "Alien.h"

Sprite Alien::getSprite()
{
	return ship;
}

void Alien::setTexture(Texture& text)
{
	ship.setTexture(text);
}

void Alien::setPosition(int x, int y)
{
	ship.setPosition(x, y);
}

void Alien::move(int y)
{
	if(ship.getPosition().y < 500)
		ship.move(0, y);
}

void Alien::draw(RenderWindow& win)
{
	win.draw(ship);
}