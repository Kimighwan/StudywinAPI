#pragma once


struct Vec2
{
	float x;
	float y;

	Vec2() : x(0), y(0) {}
	Vec2(float _x, float _y) : x(_x), y(_y) {}
	Vec2(int _x, int _y) : x((float)_x), y((float)_y) {}
	Vec2(const POINT& point) { x = (float)point.x; y = (float)point.y; }

	Vec2 operator*(float f) const
	{
		return Vec2(x * f, y * f);
	}

	Vec2& operator+=(const Vec2& v)
	{
		x += v.x;
		y += v.y;
		return *this;
	}

	Vec2& Normalize()
	{
		float length = Length();

		assert(length != 0.f);

		x /= length;
		y /= length;

		return *this;
	}

private:
	float Length()
	{
		return sqrt(x * x + y * y);
	}
};