#include "Shot.h"
#include <cmath>

namespace dxshoot {


Shot::Shot(Vector2 pos, float s, float a)
	: Character("bullet_test.png")
{
	position = pos;
	velocity = Vector2::polar(s, a);
}


Shot::~Shot()
{
}

void Shot::update()
{
	position += velocity;
}

}