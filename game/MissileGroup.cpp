#include "MissileGroup.h"

//returns the size of the list
int MissileGroup::getSize()
{
	return missiles.size();
}

//returns a specific sprite in position 'i' in the list
Sprite& MissileGroup::getSprite(int i)
{
	itr = missiles.begin();
	for (int t = 0; t < i; t++)
	{
		itr++;
	}
	return *itr;
}

//draws the list of missiles on the window 'win'
void MissileGroup::draw(RenderWindow& win)
{
	for (itr = missiles.begin(); itr != missiles.end(); itr++)
	{
		win.draw(*itr);
	}
}

//sets the texture of the missiles
void MissileGroup::setTexture(Texture& txt)
{
	this->txt = txt;
}

//adds a missile to the list
void MissileGroup::addMiss(Vector2f pos)
{
	Sprite temp;
	temp.setTexture(txt);
	temp.setPosition(pos);
	temp.move(7, 5);
	missiles.push_back(temp);
}

//moves the list of missiles MISDIS up
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

//removes the missile that itr points to
void MissileGroup::remMiss()
{
	itr = missiles.erase(itr);
}