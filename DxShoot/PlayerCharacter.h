#pragma once
#include "Vector2.h"

namespace dxshoot{

class PlayerCharacter
{
public:
	PlayerCharacter();
	~PlayerCharacter();
	void update();
	void draw();

private:
	Vector2 pos;
	int image;
};


}