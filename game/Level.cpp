#include "Level.h"

int Level::getLevel()
{
	return level;
}

void Level::setLevel(int lev)
{
	level = lev;
}

void Level::setTexture1(Texture& txt)
{
	alienTex1 = txt;
}

void Level::setTexture2(Texture& txt)
{
	alienTex2 = txt;
}

Texture& Level::getAlienTexture()
{
	Texture* temp = &alienTex1;

	if (level == 1)
		temp = &alienTex1;
	else if (level == 2)
		temp = &alienTex2;

	return *temp;
}