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

bool Squadron::move(int y)
{
	bool limit = false;
	for (itr = squad.begin(); itr != squad.end(); itr++)
	{
		if (itr->getPosition().y < 480 && y > 0)
			itr->move(0, y);
		else if (y < 0)
		{
			itr->move(0, y);
			limit = false;
		}
		else
			limit = true;
	}
	return limit;
}

bool Squadron::intersect(Sprite& other)
{
	bool inter = false;
	for (itr = squad.begin(); itr != squad.end() && !inter; itr++)
	{
		if (itr->getGlobalBounds().intersects(other.getGlobalBounds()))
		{
			inter = true;
		}
	}
	return inter;
}

void Squadron::remAlien(Sprite& alien)
{
	for (itr = squad.begin(); itr != squad.end(); itr++)
	{
		itr = squad.erase(itr);
	}
}