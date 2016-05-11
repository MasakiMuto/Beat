#include "Level.h"
#include "PlayEngine.h"
#include "main.h"

namespace dxshoot {

Level::Level()
{
	mt = std::make_unique<std::mt19937>();
	dist = std::make_unique<std::uniform_int_distribution<> >(0, dxshoot::Size);
}


Level::~Level()
{
}

void Level::update()
{
	count++;
	if (count % 10 == 0) {
		PlayEngine::getInstance().addEnemy(std::make_unique<Enemy>(Vector2((*dist)(*mt), 0.0f)));
	}
}

}