#include "Enemy.h"

namespace dxshoot {


dxshoot::Enemy::Enemy(const char * imageName)
	: Character(imageName)
{
}

Enemy::~Enemy()
{
	Character::~Character();
}

void Enemy::update()
{
	count++;
}

bool Enemy::canDelete()
{
	return false;
}

}