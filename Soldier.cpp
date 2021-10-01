#include "Soldier.h"

namespace FieldOfView
{
	Soldier::Soldier()
	{
		_position = Vector2();
		_viewDirection = Vector2(0.0f, 1.0f);
		_viewDistance = 1.0f;
		_angle = PI;
		_cosAngleDev2 = 0;
	}
	Soldier::Soldier(Vector2 position, Vector2 viewDirection, float viewDistance, float angleInRadian)
	{
		_position = position;
		_viewDirection = viewDirection;//??? .normalize();
		_viewDistance = viewDistance;
		_angle = angleInRadian;
		_cosAngleDev2 = cos_opt(angleInRadian / 2, 0.001);
	}
	Vector2 Soldier::getPosition()
	{
		return _position;
	}
	Vector2 Soldier::getViewDirection()
	{
		return _viewDirection;
	}
	float Soldier::getViewDistance()
	{
		return _viewDistance;
	}
	float Soldier::getAngle()
	{
		return _angle;
	}
	float Soldier::getCosAngleDev2()
	{
		return _cosAngleDev2;
	}
}