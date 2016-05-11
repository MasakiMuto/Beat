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
	static inline Rectangle fromPoint(float minX, float minY, float maxX, float maxY) {
		Vector2 mn(minX, minY);
		Vector2 mx(maxX, maxY);
		return Rectangle((mn + mx) * 0.5f, (mx - mn) * 0.5f);
	}
private:
	const Vector2 position, size;
	const inline Vector2 getMin() const { return position - size; }
	const inline Vector2 getMax() const { return position + size; }
	const std::pair<bool, bool> isCollisionInner(const Rectangle&& other) const;
};

}