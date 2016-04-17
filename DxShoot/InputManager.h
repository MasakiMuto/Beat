#pragma once

#include "Vector2.h"
#include <memory>

namespace dxshoot
{

class InputManager
{
public:
	static InputManager& getInstance();

	InputManager();
	~InputManager();
	void update();
	Vector2 getDirection();

private:
	static std::unique_ptr<InputManager> instance;

	Vector2 direction;

};

}