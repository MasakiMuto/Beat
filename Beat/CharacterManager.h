#pragma once

#include "Character.h"
#include <memory>
#include <list>

namespace dxshoot {


class CharacterManager
{
public:
	CharacterManager();
	~CharacterManager();
	void add(std::unique_ptr<Character> c);
	void update();
	void draw();
	using ItemList = std::list<std::unique_ptr<Character>>;
	inline ItemList& getItems() { return items; }
private:
	ItemList items;

};

}