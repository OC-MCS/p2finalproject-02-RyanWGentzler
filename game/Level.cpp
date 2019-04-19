#include "Level.h"

//returns the level that the player is currently on
int Level::getLevel()
{
	return level;
}

//will set the level to whatever is passed to it
void Level::setLevel(int lev)
{
	level = lev;
}

//sets the texture of the level one alien
void Level::setTexture1(Texture& txt)
{
	alienTex1 = txt;
}

//sets the texture of the level two alien
void Level::setTexture2(Texture& txt)
{
	alienTex2 = txt;
}

//returns the texture of the alien that the player is currently on
Texture& Level::getAlienTexture()
{
	Texture* temp = &alienTex1;

	if (level == 0)
		temp = &alienTex1;
	else if (level == 1)
		temp = &alienTex2;

	return *temp;
}