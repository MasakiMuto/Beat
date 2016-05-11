#pragma once
#include "Vector2.h"

namespace dxshoot {

class Character
{
public:
	~Character();
	virtual void update() = 0;
	virtual void draw();
	virtual bool canDelete();
	bool isCollision(const Character& other);
protected:
	Vector2 position;
	Vector2 offset;
	Vector2 collisionRect;
	unsigned int color;

	Character();
};

}