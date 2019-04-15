#include "Missile.h"

Missile::Missile(Texture& text, Vector2f pos)
{
	missile.setTexture(text);
	missile.setPosition(pos);
}

