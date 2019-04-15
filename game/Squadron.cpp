#include "Squadron.h"

void Squadron::setTexture(Texture& txt)
{
	this->txt = txt;
}

void Squadron::addAlien(int x, int y)
{
	Sprite temp;
	temp.setTexture(txt);
	temp.setPosition(x, y);
	squad.push_back(temp);
}

void Squadron::draw(RenderWindow& win)
{
	for (itr = squad.begin(); itr != squad.end(); itr++)
	{
		win.draw(*itr);
	}
}

void Squadron::move(int y)
{
	for (itr = squad.begin(); itr != squad.end(); itr++)
	{
		if (itr->getPosition().y < 500)
			itr->move(0, y);
	}
}