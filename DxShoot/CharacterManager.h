#pragma once

#include "Character.h"
#include <memory>
#include <list>
#include <map>

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
	using ItemList = std::list<std::unique_ptr<Character>>;
	using ItemSet = std::map<int, std::unique_ptr<ItemList>>;
	ItemSet items;

	ItemList& getList(const Character& c);
};

}