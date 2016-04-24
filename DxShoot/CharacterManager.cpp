#include "CharacterManager.h"

namespace dxshoot {


CharacterManager::CharacterManager()
{
}


CharacterManager::~CharacterManager()
{
}

void CharacterManager::add(std::unique_ptr<Character> c)
{
	auto& list = getList(*c);
	list.insert(list.begin(), std::move(c));
}

void CharacterManager::update()
{
	for (auto& list : items) {
		for (auto& c : *(list.second)) {
			c->update();
		}
		list.second->remove_if([](auto& c) -> bool {return c->canDelete(); });
	}
}

void CharacterManager::draw()
{
	for (auto& list : items) {
		for (auto& c : *(list.second)) {
			c->draw();
		}
	}
}

CharacterManager::ItemList & CharacterManager::getList(const Character & c)
{
	auto l = items.find(c.getImage());
	if (l == items.end()) {
		auto p = items.insert(std::make_pair(c.getImage(), std::make_unique<ItemList>()));
		return *(p.first->second);
	}
	else {
		return *(l->second);
	}
}

}