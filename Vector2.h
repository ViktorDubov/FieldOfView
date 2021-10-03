#pragma once

#include "Mathf.h"

namespace MathOFVector
{
	class Vector2
	{
	private:
		float _x;
		float _y;
	public:
		Vector2();
		Vector2(float x, float y);

		void setVector2(float x, float y);
		float getX() const;
		float getY() const;

		Vector2 operator+(const Vector2& v) const;
		Vector2 operator-(const Vector2& v) const;
		Vector2 operator*(float val) const;
		Vector2 operator/(float val) const;

		float dot(const Vector2& v2) const;
		//Vector2 cross(const Vector2& v2) const;//пока не нужна

		friend std::ostream& operator<<(std::ostream& out, const Vector2& v);
		friend std::istream& operator>>(std::istream& in, Vector2& v);

		float sqrMagnitude() const;
		float magnitude() const;
		Vector2 normalize() const;
		float cosAngle(const Vector2& v2) const;
		float angle(const Vector2& v2) const;
		float distance(const Vector2& v2) const;
		float sqrDistance(const Vector2& v2) const;
	};
}


