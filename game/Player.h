#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Player
{
private:
	Sprite ship;
	int lives = 3;
	bool isAlive = true;
public:
	Sprite getSprite();
	Vector2f getPosition();
	int getLives();
	bool intersect(Sprite&);
	bool alive();
	void setTexture(Texture&);
	void setPosition(float, float);
	void move();
	void modlives(int);
	void setlives(int);
};