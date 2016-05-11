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
	DxLib::DrawGraphF(position.x - offset.x, position.y - offset.y, image, TRUE);
}

bool Character::canDelete()
{

	return false;
}

bool Character::isCollision(const Character & other)
{
	return Rectangle(position, collisionRect).isCollision(Rectangle(other.position, other.collisionRect));
}

Character::Character(const char * imageName)
{
	image = PlayEngine::getInstance().getImages().load(imageName);
	int x, y;
	DxLib::GetGraphSize(image, &x, &y);
	offset = Vector2(x * 0.5f, y * 0.5f);
}

}