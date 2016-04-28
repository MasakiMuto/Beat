#include "Shot.h"
#include <cmath>
#include "PlayEngine.h"

namespace dxshoot {


Shot::Shot(Vector2 pos, float s, float a)
	: Character("bullet_test.png")
{
	position = pos;
	velocity = Vector2::polar(s, a);
	collisionRect = Vector2(16.0f, 16.0f);
}


Shot::~Shot()
{
	Character::~Character();
}

void Shot::update()
{
	position += velocity;
}

bool Shot::canDelete()
{
	return !PlayEngine::getInstance().getPlayArea().isCollision(Rectangle(position, collisionRect));
}

}