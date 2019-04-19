#include "Bombardment.h"

int Bombardment::getSize()
{
	return missiles.size();
}

Sprite& Bombardment::getSprite(int i)
{
	itr = missiles.begin();
	for (int t = 0; t < i; t++)
	{
		itr++;
	}
	return *itr;
}

void Bombardment::draw(RenderWindow& win)
{
	for (itr = missiles.begin(); itr != missiles.end(); itr++)
	{
		win.draw(*itr);
	}
}

void Bombardment::setTexture(Texture& txt)
{
	this->txt = txt;
}

void Bombardment::addMiss(Vector2f pos)
{
	Sprite temp;
	temp.setTexture(txt);
	temp.setPosition(pos);
	missiles.push_back(temp);
}

void Bombardment::moveMissiles()
{
	const int MISDIS = 10;
	itr = missiles.begin();
	while (itr != missiles.end())
	{
		itr->move(0, MISDIS);
		if (itr->getPosition().y > 600)
		{
			remMiss();
		}
		else
		{
			itr++;
		}
	}
}

void Bombardment::remMiss()
{
	itr = missiles.erase(itr);
}