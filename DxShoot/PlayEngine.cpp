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
	enemys->update();
}


void PlayEngine::draw()
{
	enemys->draw();
	player->draw();
	cshots->draw();
}

ImageLoader & PlayEngine::getImages()
{
	return *imageLoader;
}

Rectangle PlayEngine::getPlayArea()
{
	return Rectangle::fromPoint(0.0f, 0.0f, 640.0f, 480.0f);
}

void PlayEngine::init()
{
	imageLoader = std::make_unique<ImageLoader>();
	player = std::make_unique<PlayerCharacter>();
	cshots = std::make_unique<CharacterManager>();
	enemys = std::make_unique<CharacterManager>();

	addEnemy(std::make_unique<Enemy>("chara_test.png", Vector2(400.0f, 300.0f)));
}

void PlayEngine::addShot(std::unique_ptr<Shot> s) {
	cshots->add(std::move(s));
}

void PlayEngine::addEnemy(std::unique_ptr<Enemy> e)
{
	enemys->add(std::move(e));
}


}
