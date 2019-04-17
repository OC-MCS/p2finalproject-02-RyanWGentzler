#include "MissileGroup.h"

int MissileGroup::getSize()
{
	return missiles.size();
}

Sprite MissileGroup::getSprite(int i)
{
	itr = missiles.begin();
	for (int t = 0; t < i; t++)
	{
		itr++;
	}
	return *itr;
}

void MissileGroup::draw(RenderWindow& win)
{
	for (itr = missiles.begin(); itr != missiles.end(); itr++)
	{
		win.draw(*itr);
	}
}

void MissileGroup::setTexture(Texture& txt)
{
	this->txt = txt;
}

void MissileGroup::addMiss(Vector2f pos)
{
	Sprite temp;
	temp.setTexture(txt);
	temp.setPosition(pos);
	temp.move(7, 5);
	missiles.push_back(temp);
}

void MissileGroup::moveMissiles()
{
	const int MISDIS = -10;
	Sprite* temp = nullptr;
	itr = missiles.begin();
	while (itr != missiles.end())
	{
		itr->move(0, MISDIS);
		if (itr->getPosition().y < -10)
		{
			remMiss();
		}
		else
		{
			itr++;
		}
	}
}

void MissileGroup::remMiss()
{
	itr = missiles.erase(itr);
}