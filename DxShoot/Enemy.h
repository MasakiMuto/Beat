#pragma once
#include "Character.h"

namespace dxshoot {



class Enemy :
	public Character
{
public:
	Enemy(const char* imageName);
	~Enemy();

	virtual void update() override;
	virtual bool canDelete() override;
protected:
	int count;
};

}