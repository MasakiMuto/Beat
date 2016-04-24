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
protected:
	Vector2 position;
	int image;
	Vector2 offset;

	Character(const char* imageName);
};

}