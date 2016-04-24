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
	cshots->update();
}


void PlayEngine::draw()
{
	player->draw();
	cshots->draw();
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
	cshots = std::make_unique<CharacterManager>();
}

void PlayEngine::addShot(std::unique_ptr<Shot> s) {
	cshots->add(std::move(s));
}

}
