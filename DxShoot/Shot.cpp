#include "Shot.h"

namespace dxshoot {


Shot::Shot()
	: Character("bullet_test.png")
{
	position = Vector2(100.0f, 100.0f);
	velocity = Vector2(2.0f, 0.0f);
}


Shot::~Shot()
{
}

void dxshoot::Shot::update()
{
	position = position + velocity;
}

}