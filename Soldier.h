#pragma once

#include <vector>
#include <iostream>

#include "Vector2.h"


using namespace MathOFVector;

namespace FieldOfView
{
	//class BasicUnit
	//{
	//public:
	//	virtual Vector2 getPosition() = 0;
	//	virtual Vector2 getViewDirection() = 0;
	//	virtual float getViewDistance() = 0;
	//	virtual float getAngle() = 0;
	//	virtual float getCosAngleDev2() = 0;

	//	virtual std::vector<BasicUnit> getViewedUnits() = 0;
	//	virtual void setViewedUnits(std::vector<BasicUnit> viewedSoldiers) = 0;
	//};
	
	class Soldier //: BasicUnit
	{
	private:
		int _ID;
		Vector2 _position;
		Vector2 _viewDirection;
		float _viewDistance;
		float _angle;
		float _cosAngleDev2;//косинус от угла зрения делённого на 2

		

		std::vector<int> _viewedSoldiersID;
	public:
		static int _generalID;

		Soldier();
		Soldier(Vector2 position, Vector2 viewDirection, float viewDistance, float angleInRadian);
		Soldier(Vector2 position, Vector2 viewDirection, float viewDistance, float angleInRadian, std::vector<int> viewedSoldiersID);

		~Soldier();

		int getID();
		Vector2 getPosition();
		Vector2 getViewDirection();
		float getViewDistance();
		float getAngle();
		float getCosAngleDev2();

		friend std::ostream& operator<<(std::ostream& out, const Soldier& soldier);
		friend std::istream& operator>>(std::istream& in, Soldier& soldier);

		//std::vector<int> getViewedSoldiersID();
		//void setViewedSoldiers(std::vector<Soldier> viewedSoldiers);
	};
	
}


