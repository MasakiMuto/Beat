#pragma once
#include "Character.h"

namespace dxshoot {

class Shot :
	public Character
{
public:
	Shot(Vector2 pos, float s, float a);
	~Shot();
	virtual void update() override;
protected:
	Vector2 velocity;
};

}