#pragma once
#include <memory>
#include <list>
#include "ImageLoader.h"
#include "PlayerCharacter.h"
#include "CharacterManager.h"
#include "Enemy.h"
#include "Rectangle.h"
#include "Level.h"

namespace dxshoot
{

class PlayEngine
{
public:
	static PlayEngine& getInstance();
	static void destroyInstance();
	static void reset();

	PlayEngine();
	~PlayEngine();
	void update();
	void draw();
	ImageLoader& getImages();
	inline PlayerCharacter& getPlayer() { return *player; }
	Rectangle getPlayArea();
private:
	enum class State {
		Title,
		Play,
		Gameover
	};
	State state;
	
	static std::unique_ptr<PlayEngine> instance;

	std::unique_ptr<ImageLoader> imageLoader;
	std::unique_ptr<PlayerCharacter> player;

	std::unique_ptr<CharacterManager> enemys;
	std::unique_ptr<Level> level;


	void updateTitle();
	void updatePlay();
	void updateGameover();
public:
	void init();
	void addEnemy(std::unique_ptr<Enemy> e);
};


}