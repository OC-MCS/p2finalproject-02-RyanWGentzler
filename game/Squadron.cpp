#include "Squadron.h"

//returns whether there are aliens in the list or not
bool Squadron::aliens()
{
	return areAliens;
}

//sets the texture of the aliens
void Squadron::setTexture(Texture& txt)
{
	this->txt = txt;
}

//adds an alien to the end of the list
void Squadron::addAlien(int x, int y)
{
	Sprite temp;
	temp.setTexture(txt);
	temp.setPosition(x, y);
	squad.push_back(temp);
	areAliens = true;
}

//draws the list of aliens onto the window 'win'
void Squadron::draw(RenderWindow& win)
{
	for (itr = squad.begin(); itr != squad.end(); itr++)
	{
		win.draw(*itr);
	}
}

//moves the whole squad 'y' pixels upwards
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

//checks to see if any alien intersects with the sprite 'other' and removes the alien if it does
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

//gets a random position from the list of aliens still alive
Vector2f Squadron::getRandPos()
{
	itr = squad.begin();
	for(int i = 0; i < (rand() % squad.size()); i++)
	{
		itr++;
	}

	return itr->getPosition();
}

//removes an alien from the list
void Squadron::remAlien()
{
	itr = squad.erase(itr);
	if (squad.begin() == squad.end())
		areAliens = false;
}