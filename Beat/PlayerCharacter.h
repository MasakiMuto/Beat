#pragma once
#include "Vector2.h"
#include "Character.h"

namespace dxshoot{

class PlayerCharacter : public Character
{
public:
	PlayerCharacter();
	~PlayerCharacter();
	virtual void update() override;
private:
	const float Speed = 8.0f;
};


}