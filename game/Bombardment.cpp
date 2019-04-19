#include "Bombardment.h"

//returns the size of the array that holds the bombs
int Bombardment::getSize()
{
	return missiles.size();
}

//gets the sprite from the bomb at position 'i'
Sprite& Bombardment::getSprite(int i)
{
	itr = missiles.begin();
	for (int t = 0; t < i; t++)
	{
		itr++;
	}
	return *itr;
}

//draws all the bombs in the list
void Bombardment::draw(RenderWindow& win)
{
	for (itr = missiles.begin(); itr != missiles.end(); itr++)
	{
		win.draw(*itr);
	}
}

//sets the texture of the list of bombs
void Bombardment::setTexture(Texture& txt)
{
	this->txt = txt;
}

//adds a bomb to the list
void Bombardment::addMiss(Vector2f pos)
{
	Sprite temp;
	temp.setTexture(txt);
	temp.setPosition(pos);
	missiles.push_back(temp);
}

//moves the list of bombs down depending on what level it is
void Bombardment::moveMissiles(int level)
{
	int MISDIS;
	if (level == 1)
		MISDIS = 10;
	else
		MISDIS = 15;
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

//removes a bomb from the list
void Bombardment::remMiss()
{
	itr = missiles.erase(itr);
}