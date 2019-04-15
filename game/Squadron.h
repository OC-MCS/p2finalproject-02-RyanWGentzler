#pragma once
#include "Alien.h"
#include <list>

class Squadron
{
private:
	list<Sprite>squad;
	list<Sprite> ::iterator itr;
	Texture txt;
	int speed;
public:
	void setTexture(Texture&);
	void addAlien(int, int);
	void draw(RenderWindow&);
	void move(int);
	void remAlien(Sprite&);
};