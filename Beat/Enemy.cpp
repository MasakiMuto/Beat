#include "Enemy.h"
#include "PlayEngine.h"
#include <DxLib.h>
#include "main.h"

namespace dxshoot {


dxshoot::Enemy::Enemy(Vector2 pos)
	: Character()
{
	position = pos;
	collisionRect = Vector2(8.0f, static_cast<float>(Size));
	color = DxLib::GetColor(0, 0, 0);
	count = MaxCount;
	canCollision = false;
}

Enemy::~Enemy()
{
	Character::~Character();
}

void Enemy::update()
{
	count--;
	double r = std::sqrt(static_cast<double>(MaxCount - count) / MaxCount);
	color = DxLib::GetColor(static_cast<int>(255 * r), 0, 0);
	if (count <= 1) {
		canCollision = true;
	}
}

bool Enemy::canDelete()
{
	return count <= 0;
}

}