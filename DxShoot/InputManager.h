#pragma once

#include "Vector2.h"
#include <memory>
#include <vector>

namespace dxshoot
{

enum class Button {
	A, B
};

class InputManager
{
	class ButtonState {
		friend InputManager;
	public:
		int repeat();
		bool push();
		bool release();
		void step();
	private:
		int count;
		void update(bool state);
	};
public:
	static InputManager& getInstance();

	InputManager();
	~InputManager();
	void update();
	Vector2 getDirection();
	ButtonState& getButton(Button bt);
private:
	static std::unique_ptr<InputManager> instance;

	Vector2 direction;
	std::vector<ButtonState> buttons;
};

}