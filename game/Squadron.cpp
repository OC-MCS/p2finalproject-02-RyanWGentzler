#include "Squadron.h"

bool Squadron::aliens()
{
	return areAliens;
}

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
	areAliens = true;
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
 	for (itr = squad.begin(); itr != squad.end() && !inter;)
	{
		if (itr->getGlobalBounds().intersects(other.getGlobalBounds()))
		{
			inter = true;
			remAlien();
		}
		else
		{
			itr++;
		}
	}
	return inter;
}

Vector2f Squadron::getRandPos()
{
	itr = squad.begin();
	for(int i = 0; i < (rand() % squad.size()); i++)
	{
		itr++;
	}

	return itr->getPosition();
}

void Squadron::remAlien()
{
	itr = squad.erase(itr);
	if (squad.begin() == squad.end())
		areAliens = false;
}