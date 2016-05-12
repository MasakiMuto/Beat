#include "Enemy.h"
#include "PlayEngine.h"
#include <DxLib.h>
#include "main.h"

namespace dxshoot {


dxshoot::Enemy::Enemy(float pos, bool direction)
	: Character()
{
	if (direction) {
		position = Vector2(pos, 0.0f);
		collisionRect = Vector2(Width, static_cast<float>(Size));
	}
	else {
		position = Vector2(0.0f, pos);
		collisionRect = Vector2(static_cast<float>(Size), Width);
	}

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
	const double Base = 0.3;
	color = DxLib::GetColor(static_cast<int>(255 * (r * (1 - Base) + Base)), 0, 0);
	if (count <= 1) {
		canCollision = true;
	}
}

bool Enemy::canDelete()
{
	return count <= 0;
}

}