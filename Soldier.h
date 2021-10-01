#pragma once

#include <vector>

#include "Vector2.h"


using namespace MathOFVector;

namespace FieldOfView
{
	class Soldier
	{
	private:
		Vector2 _position;
		Vector2 _viewDirection;
		float _viewDistance;
		float _angle;
		float _cosAngleDev2;//косинус от угла зрения делённого на 2

		std::vector<Soldier> _viewedSoldiers;
	public:
		Soldier();
		Soldier(Vector2 position, Vector2 viewDirection, float viewDistance, float angleInRadian);

		Vector2 getPosition();
		Vector2 getViewDirection();
		float getViewDistance();
		float getAngle();
		float getCosAngleDev2();

	};
}


