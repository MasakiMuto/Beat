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
	
	shots->remove_if([](auto& s) -> bool { return s->canDelete(); });
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
}

void PlayEngine::addShot(std::unique_ptr<Shot> s) {
	shots->insert(shots->begin(), std::move(s));
}

}
