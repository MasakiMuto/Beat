#pragma once
#include "Character.h"

namespace dxshoot {

class Shot :
	public Character
{
public:
	Shot();
	~Shot();
	virtual void update() override;
protected:
	Vector2 velocity;
};

}