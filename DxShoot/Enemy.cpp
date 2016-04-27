#include "Enemy.h"
#include "PlayEngine.h"

namespace dxshoot {


dxshoot::Enemy::Enemy(const char * imageName, Vector2 pos)
	: Character(imageName)
{
	position = pos;
	life = 5;
	collisionRect = Vector2(16.0f, 32.0f);
}

Enemy::~Enemy()
{
	Character::~Character();
}

void Enemy::update()
{
	count++;
	if (isCollision(PlayEngine::getInstance().getPlayer())) {
		life--;
	}
}

bool Enemy::canDelete()
{
	return life <= 0;
}

}