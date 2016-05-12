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
	beatCount++;
	if (beatCount >= getBeat()) {
		beatCount -= getBeat();
		int n = getNum();
		direction = !direction;
		for (int i = 0; i < n; i++) {
			PlayEngine::getInstance().addEnemy(std::make_unique<Enemy>((*dist)(*mt), direction));
		}
	}
}

int Level::getNum()
{
	return 3 + count / 300 + (count % 600 / 60);
}

int Level::getBeat()
{
	return 60;
}

}