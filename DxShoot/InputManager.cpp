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
	buttons = std::vector<ButtonState>{ ButtonState(), ButtonState() };
}


InputManager::~InputManager()
{
}


void InputManager::update()
{
	int s = DxLib::GetJoypadInputState(DX_INPUT_KEY_PAD1);

	int y = 0;
	int x = 0;
	y += (s & PAD_INPUT_DOWN) ? 1 : 0;
	y -= (s & PAD_INPUT_UP) ? 1 : 0;
	x += (s & PAD_INPUT_RIGHT) ? 1 : 0;
	x -= (s & PAD_INPUT_LEFT) ? 1 : 0;
	direction = Vector2(static_cast<float>(x), static_cast<float>(y)).normalized();

	buttons.at(0).update((s & PAD_INPUT_1) != 0);
	buttons.at(1).update((s & PAD_INPUT_2) != 0);
}


Vector2 InputManager::getDirection() const
{
	return direction;
}

InputManager::ButtonState& InputManager::getButton(Button bt)
{
	return buttons.at((int)bt);
}

int InputManager::ButtonState::repeat() const
{
	return count;
}

bool InputManager::ButtonState::push() const
{
	return count == 1;
}

bool InputManager::ButtonState::release() const
{
	return count == -1;
}

void InputManager::ButtonState::step()
{
	if (push()) {
		count++;
	}
}

void InputManager::ButtonState::update(bool state)
{
	if (state) {
		count++;
	}
	else {
		if (count > 0) {
			count = -1;
		   }
		else {
			count = 0;
		}
	}
}

}