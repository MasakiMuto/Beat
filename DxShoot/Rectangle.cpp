#include "Rectangle.h"


namespace dxshoot {

Rectangle::Rectangle(const Vector2 _position, const Vector2 _size)
	: position(_position), size(_size)
{
}

Rectangle::~Rectangle()
{
}

bool Rectangle::isCollision(const Rectangle && other)
{
	auto p1 = isCollisionInner(std::move(other));
	auto p2 = other.isCollisionInner(std::move(*this));

	return (p1.first || p2.first) && (p1.second || p2.second);
}

const std::pair<bool, bool> Rectangle::isCollisionInner(const Rectangle && other) const
{
	auto min = getMin();
	auto max = getMax();
	auto omin = other.getMin();
	auto omax = other.getMax();
	bool r[2];
	for (int i = 0; i < 2; i++) {
		r[i] = (min[i] < omin[i] && omin[i] < max[i]) || (min[i] < omax[i] && omax[i] < max[i]);
	}
	return std::make_pair(r[0], r[1]);
}

}

