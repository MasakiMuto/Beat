#pragma once
#include <memory>
#include "ImageLoader.h"
#include "PlayerCharacter.h"

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
	static std::unique_ptr<PlayEngine> instance;

	std::unique_ptr<ImageLoader> imageLoader;
	std::unique_ptr<PlayerCharacter> player;
public:
	void init();
};


}