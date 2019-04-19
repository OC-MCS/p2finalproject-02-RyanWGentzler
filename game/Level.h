#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Level
{
private:
	int level = 0;
	Texture alienTex1;
	Texture alienTex2;
public:
	int getLevel();
	void setLevel(int);
	void setTexture1(Texture&);
	void setTexture2(Texture&);
	Texture& getAlienTexture();
};