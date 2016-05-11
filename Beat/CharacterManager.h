#pragma once

#include "Character.h"
#include <memory>

namespace dxshoot {


class CharacterManager
{
public:
	CharacterManager();
	~CharacterManager();
	void add(std::unique_ptr<Character> c);
	void update();
	void draw();
private:
	struct Impl;
	std::unique_ptr<Impl> impl;

};

}