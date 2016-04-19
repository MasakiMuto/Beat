#pragma once
#include "Character.h"

namespace dxshoot {

class Shot :
	public Character
{
public:
	Shot(Vector2 pos, float s, float a);
	Shot(Shot& s) = delete;
	~Shot();
	virtual void update() override;
	bool canDelete();
protected:
	Vector2 velocity;
};

}