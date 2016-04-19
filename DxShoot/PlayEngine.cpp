#include "main.h"
#include "PlayEngine.h"

namespace dxshoot {
std::unique_ptr<PlayEngine> PlayEngine::instance;

PlayEngine & PlayEngine::getInstance()
{
	if (!instance)
	{
		instance = std::make_unique<PlayEngine>();
	}
	return *instance;
}

PlayEngine::PlayEngine()
{
}


PlayEngine::~PlayEngine()
{
}


void PlayEngine::update()
{
	player->update();
	for (auto& s : *shots) {
		s->update();
	}
}


void PlayEngine::draw()
{
	player->draw();
	for (auto& s : *shots) {
		s->draw();
	}
}

ImageLoader & PlayEngine::getImages()
{
	return *imageLoader;
}

void PlayEngine::init()
{
	imageLoader = std::make_unique<ImageLoader>();
	player = std::make_unique<PlayerCharacter>();
	shots = std::make_unique<ShotList>();
	shots->insert(shots->begin(), std::make_unique<Shot>(Vector2(100, 100), 3.0f, 0.0f));
	shots->insert(shots->begin(), std::make_unique<Shot>(Vector2(200.0f, 200.0f), 1.0f, -0.5f));
}

}
