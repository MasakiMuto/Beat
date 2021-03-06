#pragma once
#include <cmath>
#include <cassert>

namespace dxshoot {

class Vector2
{
public:
	float x, y;

	inline Vector2() : x(0.0f), y(0.0f) { }
	inline ~Vector2() {	}
	inline Vector2(float _x, float _y) : x(_x), y(_y) { }
	inline float length() { return std::sqrt(lengthSquared()); }
	inline const float lengthSquared() { return x * x + y * y; }
	inline const Vector2 operator +(const Vector2& other) const { return Vector2(x + other.x, y + other.y); }
	inline const Vector2 operator *(float a) const { return Vector2(x * a, y * a); }
	inline const Vector2 operator -(const Vector2& other) const { return Vector2(x - other.x, y - other.y); }
	inline Vector2 normalized()
	{
		float l = length();
		if (l == 0.0f) 
		{
			return Vector2();
		}
		return *this * (1.0f / l);
	}
	inline void operator +=(const Vector2& other) { x += other.x; y += other.y; }
	inline void operator -=(const Vector2& other) { x -= other.x; y -= other.y; }
	inline void operator *=(float a) { x *= a; y *= a; }
	inline float angle() { return std::atan2(y, x); }
	inline float operator[](int i) 
	{
		//NDEBUG
		assert(i == 0 || i == 1);
		return i == 0 ? x : y;
	}

	static inline Vector2 polar(float length, float angle) { return Vector2(std::cos(angle) * length, std::sin(angle) * length); }
};

}
