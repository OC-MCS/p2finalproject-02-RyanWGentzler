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
	bool areAliens = false;
public:
	bool aliens();
	void setTexture(Texture&);
	void addAlien(int, int);
	void draw(RenderWindow&);
	bool move(int);
	bool intersect(Sprite&);
	Vector2f getRandPos();
	void remAlien();
};