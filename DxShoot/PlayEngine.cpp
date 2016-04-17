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
}


void PlayEngine::draw()
{
	player->draw();
	//DxLib::DrawGraph(100, 100, getImages().load("chara_test.png"), TRUE);
}

ImageLoader & PlayEngine::getImages()
{
	return *imageLoader;
}

void PlayEngine::init()
{
	imageLoader = std::make_unique<ImageLoader>();
	player = std::make_unique<PlayerCharacter>();
}

}
