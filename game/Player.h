#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Player
{
private:
	Sprite ship;
	int lives;
public:
	Sprite getSprite();
	Vector2f getPosition();
	void setTexture(Texture&);
	void setPosition(float, float);
	void move();
};