#include "InputManager.h"
#include "main.h"
#include <iostream>

namespace dxshoot
{

std::unique_ptr<InputManager> InputManager::instance;

InputManager & InputManager::getInstance()
{
	if (!instance) {
		instance = std::make_unique<InputManager>();
	}
	return *instance;
}

InputManager::InputManager()
{
}


InputManager::~InputManager()
{
}


void InputManager::update()
{
	
}


Vector2 InputManager::getDirection()
{
	int y = 0;
	int x = 0;
	int s = DxLib::GetJoypadInputState(DX_INPUT_KEY_PAD1);
	y += (s & PAD_INPUT_DOWN) ? 1 : 0;
	y -= (s & PAD_INPUT_UP) ? 1 : 0;
	x += (s & PAD_INPUT_RIGHT) ? 1 : 0;
	x -= (s & PAD_INPUT_LEFT) ? 1 : 0;
	return Vector2(static_cast<float>(x), static_cast<float>(y)).normalized();
}

}