#pragma once
#include <list>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class MissileGroup
{
private:
	list<Sprite>missiles;
	list<Sprite> :: iterator itr;
	Texture txt;
public:
	int getSize();
	Sprite getSprite(int);
	void draw(RenderWindow&);
	void setTexture(Texture&);
	void addMiss(Vector2f);
	void moveMissiles();
	void remMiss();
};