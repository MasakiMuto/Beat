#pragma once
#include "Character.h"


namespace dxshoot {



class Enemy :
	public Character
{
public:
	Enemy(float pos, bool direction);
	~Enemy();

	virtual void update() override;
	virtual bool canDelete() override;
	bool canCollision;
protected:
	const int MaxCount = 30;
	int count;
	const float Width = 4.0f;
};

}