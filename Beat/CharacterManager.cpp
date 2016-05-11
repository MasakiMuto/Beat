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
	items.insert(items.begin(), std::move(c));
}

void CharacterManager::update()
{
	for (auto& c: items) {
		c->update();
	}
	items.remove_if([](auto& c) -> bool {return c->canDelete(); });
}

void CharacterManager::draw()
{
	for (auto& c : items) {
		c->draw();
	}
}

}