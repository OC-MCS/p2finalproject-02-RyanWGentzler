#include "Alien.h"

//returns the sprite information so that other functions can manipulate it
Sprite Alien::getSprite()
{
	return ship;
}

//can set the texture of the individual aliens
void Alien::setTexture(Texture& text)
{
	ship.setTexture(text);
}

//moves the position of the individual alien
void Alien::setPosition(int x, int y)
{
	ship.setPosition(x, y);
}

//changes the Y axis location of the alien for reset purposes
void Alien::move(int y)
{
	if(ship.getPosition().y < 500)
		ship.move(0, y);
}

//Draws the alien on the window passed to it
void Alien::draw(RenderWindow& win)
{
	win.draw(ship);
}