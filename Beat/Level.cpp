#include "Level.h"
#include "PlayEngine.h"
#include "main.h"

namespace dxshoot {

Level::Level()
{
	mt = std::make_unique<std::mt19937>(std::random_device()());
	dist = std::make_unique<std::uniform_int_distribution<> >(0, dxshoot::Size);
}


Level::~Level()
{
}

void Level::update()
{
	count++;
	if (count % 60 == 0) {
		direction = !direction;
		for (int i = 0; i < 10; i++) {
			PlayEngine::getInstance().addEnemy(std::make_unique<Enemy>((*dist)(*mt), direction));
		}
	}
}

}