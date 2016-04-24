#pragma once
#include <memory>
#include <list>
#include "ImageLoader.h"
#include "PlayerCharacter.h"
#include "Shot.h"
#include "CharacterManager.h"

namespace dxshoot
{

class PlayEngine
{
public:
	static PlayEngine& getInstance();

	PlayEngine();
	~PlayEngine();
	void update();
	void draw();
	ImageLoader& getImages();
private:
	using ShotList = std::list<std::unique_ptr<Shot>>;
	static std::unique_ptr<PlayEngine> instance;

	std::unique_ptr<ImageLoader> imageLoader;
	std::unique_ptr<PlayerCharacter> player;
	std::unique_ptr<ShotList> shots;

	std::unique_ptr<CharacterManager> cshots;

public:
	void init();
	void addShot(std::unique_ptr<Shot> s);
};


}