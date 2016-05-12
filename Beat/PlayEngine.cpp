#include "main.h"
#include "PlayEngine.h"
#include "InputManager.h"

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

void PlayEngine::destroyInstance()
{
	if (instance) {
		instance.reset();
	}
}

void PlayEngine::reset()
{
	destroyInstance();
	getInstance().init();
}

PlayEngine::PlayEngine()
{
}


PlayEngine::~PlayEngine()
{
}


void PlayEngine::update()
{
	switch (state)
	{
	case dxshoot::PlayEngine::State::Title:
		updateTitle();
		break;
	case dxshoot::PlayEngine::State::Play:
		updatePlay();
		break;
	case dxshoot::PlayEngine::State::Gameover:
		updateGameover();
		break;
	default:
		break;
	}
}


void PlayEngine::draw()
{
	DxLib::DrawFormatString(0, 0, DxLib::GetColor(64, 64, 64), "%d", count);
	enemys->draw();
	player->draw();
}

ImageLoader & PlayEngine::getImages()
{
	return *imageLoader;
}

Rectangle PlayEngine::getPlayArea()
{
	return Rectangle::fromPoint(0.0f, 0.0f, 640.0f, 480.0f);
}

void PlayEngine::updateTitle()
{
	player->update();
}

void PlayEngine::updatePlay()
{
	player->update();
	level->update();
	enemys->update();
	for (auto& en : enemys->getItems()) {
		if (static_cast<Enemy&>(*en).canCollision && player->isCollision(*en)) {
			state = State::Gameover;
		}
	}
	count++;
}

void PlayEngine::updateGameover()
{
}

void PlayEngine::init()
{
	imageLoader = std::make_unique<ImageLoader>();
	player = std::make_unique<PlayerCharacter>();
	enemys = std::make_unique<CharacterManager>();
	level = std::make_unique<Level>();
	state = State::Play;
}


void PlayEngine::addEnemy(std::unique_ptr<Enemy> e)
{
	enemys->add(std::move(e));
}


}
