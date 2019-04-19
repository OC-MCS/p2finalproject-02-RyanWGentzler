#include "Player.h"
#include <SFML/Graphics.hpp>

Sprite Player::getSprite()
{
	return ship;
}

Vector2f Player::getPosition()
{
	return ship.getPosition();
}

int Player::getLives()
{
	return lives;
}

bool Player::intersect(Sprite& other)
{
	bool inter = false;
	if (ship.getGlobalBounds().intersects(other.getGlobalBounds()))
	{
		inter =  true;
		lives--;
	}
	return inter;
}

bool Player::alive()
{
	return isAlive;
}

void Player::setTexture(Texture& shipTex)
{
	ship.setTexture(shipTex);
}

void Player::setPosition(float x, float y)
{
	ship.setPosition(x, y);
}

void Player::move()
{
	const float DISTANCE = 5.0;

	if (Keyboard::isKeyPressed(Keyboard::Left) && !(ship.getPosition().x < 0))
	{
		// left arrow is pressed: move our ship left 5 pixels
		// 2nd parm is y direction. We don't want to move up/down, so it's zero.
		ship.move(-DISTANCE, 0);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right) && !(ship.getPosition().x > 790))
	{
		// right arrow is pressed: move our ship right 5 pixels
		ship.move(DISTANCE, 0);
	}
}

void Player::modlives(int dir)
{
	lives += dir;
	if (lives <= 0)
		isAlive = false;
}

void Player::setlives(int set)
{
	lives = set;
	isAlive = true;
}