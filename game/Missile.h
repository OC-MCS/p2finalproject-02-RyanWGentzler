#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Missile
{
private:
	Sprite missile;
	bool flight;
public:
	Missile(Texture&, Vector2f);
	void setInFlight(bool);
	Sprite getSprite();
	bool isInFlight();
};