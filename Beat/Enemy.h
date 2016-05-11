#pragma once
#include "Character.h"


namespace dxshoot {



class Enemy :
	public Character
{
public:
	Enemy(Vector2 pos);
	~Enemy();

	virtual void update() override;
	virtual bool canDelete() override;
	bool canCollision;
protected:
	const int MaxCount = 30;
	int count;
};

}