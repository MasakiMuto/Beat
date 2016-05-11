#include "CharacterManager.h"
#include <list>
#include <map>


namespace dxshoot {

struct CharacterManager::Impl {
	using ItemList = std::list<std::unique_ptr<Character>>;
	using ItemSet = std::map<int, std::unique_ptr<ItemList>>;
	ItemSet items;

	ItemList& getList(const Character& c);

};

CharacterManager::CharacterManager()
	: impl(new CharacterManager::Impl)
{
}


CharacterManager::~CharacterManager()
{
}

void CharacterManager::add(std::unique_ptr<Character> c)
{
	auto& list = impl->getList(*c);
	list.insert(list.begin(), std::move(c));
}

void CharacterManager::update()
{
	for (auto& list : impl->items) {
		for (auto& c : *(list.second)) {
			c->update();
		}
		list.second->remove_if([](auto& c) -> bool {return c->canDelete(); });
	}
}

void CharacterManager::draw()
{
	for (auto& list : impl->items) {
		for (auto& c : *(list.second)) {
			c->draw();
		}
	}
}


CharacterManager::Impl::ItemList & CharacterManager::Impl::getList(const Character & c)
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