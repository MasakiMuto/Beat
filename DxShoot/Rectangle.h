#pragma once

#include "Vector2.h"
#include <utility>

namespace dxshoot {


class Rectangle
{
public:
	Rectangle(const Vector2 _position, const Vector2 _size);
	~Rectangle();
	bool isCollision(const Rectangle&& other);
private:
	const Vector2 position, size;
	const inline Vector2 getMin() const { return position - size; }
	const inline Vector2 getMax() const { return position + size; }
	const std::pair<bool, bool> isCollisionInner(const Rectangle&& other) const;
};

}