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
	void draw(RenderWindow&);
	void setTexture(Texture&);
	void addMiss(Vector2f);
	void moveMissiles();
	void remMiss(Sprite&);
};