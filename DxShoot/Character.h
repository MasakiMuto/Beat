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
	inline int getImage() const { return image; }
	bool isCollision(const Character& other);
protected:
	Vector2 position;
	int image;
	Vector2 offset;
	Vector2 collisionRect;

	Character(const char* imageName);
};

}