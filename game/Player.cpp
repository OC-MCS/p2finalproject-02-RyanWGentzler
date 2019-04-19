#include "Player.h"
#include <SFML/Graphics.hpp>

//gets a Sprite Cranberry. Just kidding, it returns the sprite of the player
Sprite Player::getSprite()
{
	return ship;
}

//returns the position of the sprite for functions that need that specifically
Vector2f Player::getPosition()
{
	return ship.getPosition();
}

//returns the number of lives that the player currently has
int Player::getLives()
{
	return lives;
}

//checks to see if the ship intersects with the 'other' sprite (see what I did there?[I guess it wasn't funny, sorry])
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

//returns whether the player is alive or not
bool Player::alive()
{
	return isAlive;
}

//sets the texture of the ship
void Player::setTexture(Texture& shipTex)
{
	ship.setTexture(shipTex);
}

//sets the current position of the ship
void Player::setPosition(float x, float y)
{
	ship.setPosition(x, y);
}

//depending on what direction the player is holding, will move left or right. Stops at the end of the screen
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

//modifies the player's lives by 'dir' amount
void Player::modlives(int dir)
{
	lives += dir;
	if (lives <= 0)
		isAlive = false;
}

//just straight up sets the player's life total
void Player::setlives(int set)
{
	lives = set;
	isAlive = true;
}