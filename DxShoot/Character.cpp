#include "Character.h"
#include "PlayEngine.h"
#include "main.h"

namespace dxshoot {

Character::~Character()
{
}

void Character::draw()
{
	DxLib::DrawGraphF(position.x - offset.x, position.y - offset.y, image, TRUE);
}

Character::Character(const char * imageName)
{
	image = PlayEngine::getInstance().getImages().load(imageName);
	int x, y;
	DxLib::GetGraphSize(image, &x, &y);
	offset = Vector2(x * 0.5f, y * 0.5f);
}

}