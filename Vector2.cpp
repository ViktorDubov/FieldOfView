#include "Vector2.h"

namespace MathOFVector
{
	Vector2::Vector2()
	{
		_x = 0;
		_y = 0;
	}
	Vector2::Vector2(float x, float y)
	{
		_x = x;
		_y = y;
	}
	void Vector2::setVector2(float x, float y)
	{
		_x = x;
		_y = y;
	}
	float Vector2::getX() const
	{
		return _x;
	}
	float Vector2::getY() const
	{
		return _y;
	}
	Vector2 Vector2::operator+(const Vector2& v2) const
	{
		Vector2 v;
		v._x = _x + v2._x;
		v._y = _y + v2._y;
		return v;
	}
	Vector2 Vector2::operator-(const Vector2& v2) const
	{
		Vector2 v;
		v._x = _x - v2._x;
		v._y = _y - v2._y;
		return v;
	}
	Vector2 Vector2::operator*(float val) const
	{
		Vector2 v;
		v._x = _x * val;
		v._y = _y * val;
		return v;
	}
	Vector2 Vector2::operator/(float val) const
	{
		Vector2 v;
		v._x = _x / val;
		v._y = _y / val;
		return v;
	}
	float Vector2::dot(const Vector2& v2) const 
	{
		return _x * v2._x + _y * v2._y;
	}
	float Vector2::sqrMagnitude() const
	{
		return _x * _x + _y * _y;
	}
	float Vector2::magnitude() const
	{
		return sqrt_opt(_x * _x + _y * _y, 0.001);
	}
	Vector2 Vector2::normalize() const
	{
		return *this / this->magnitude();
	}
	float Vector2::cosAngle(const Vector2& v2) const
	{
		return this->dot(v2) / (this->magnitude() * v2.magnitude());;
	}
	float Vector2::angle(const Vector2& v2) const
	{
		return acos_opt(this->cosAngle(v2), 0.001);
	}
	float Vector2::distance(const Vector2& v2) const
	{
		return sqrt_opt((v2._x-_x)* (v2._x - _x) + (v2._y - _y) * (v2._y - _y), 0.001);
	}
	float Vector2::sqrDistance(const Vector2& v2) const
	{
		return (v2._x - _x) * (v2._x - _x) + (v2._y - _y) * (v2._y - _y);
	}
	std::ostream& operator<<(std::ostream& out, const Vector2& v)
	{
		out << v._x << " " << v._y;
		return out;
	}
	std::istream& operator>>(std::istream& in, Vector2& v)
	{
		in >> v._x >> v._y;
		return in;
	}
}