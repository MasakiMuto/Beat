#include "Character.h"
#include "PlayEngine.h"
#include "main.h"
#include "Rectangle.h"

namespace dxshoot {

Character::~Character()
{
}

void Character::draw()
{
	auto rect = dxshoot::Rectangle(position, collisionRect);
	DxLib::DrawBox(static_cast<int>(rect.getMin().x), static_cast<int>(rect.getMin().y),
		static_cast<int>(rect.getMax().x), static_cast<int>(rect.getMax().y), color, TRUE);
}

bool Character::canDelete()
{

	return false;
}

bool Character::isCollision(const Character & other)
{
	return Rectangle(position, collisionRect).isCollision(Rectangle(other.position, other.collisionRect));
}

Character::Character()
{
}

}