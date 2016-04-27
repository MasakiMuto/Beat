#pragma once
#include <memory>
#include <list>
#include "ImageLoader.h"
#include "PlayerCharacter.h"
#include "Shot.h"
#include "CharacterManager.h"
#include "Enemy.h"

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
	inline CharacterManager& getShots() { return *cshots; }
	inline PlayerCharacter& getPlayer() { return *player; }
private:
	static std::unique_ptr<PlayEngine> instance;

	std::unique_ptr<ImageLoader> imageLoader;
	std::unique_ptr<PlayerCharacter> player;

	std::unique_ptr<CharacterManager> cshots;
	std::unique_ptr<CharacterManager> enemys;

public:
	void init();
	void addShot(std::unique_ptr<Shot> s);
	void addEnemy(std::unique_ptr<Enemy> e);
};


}