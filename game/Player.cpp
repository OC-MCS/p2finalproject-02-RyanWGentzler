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
}