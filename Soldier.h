#pragma once

#include <vector>
#include <iostream>

#include "Vector2.h"

using namespace MathOFVector;

namespace FieldOfView
{
	class Soldier 
	{
	private:
		int _ID;
		Vector2 _position;
		Vector2 _viewDirection;
		float _viewDistance;
		float _angle;
		float _cosAngleDev2;//косинус от угла зрения делённого на 2

		std::vector<int> _viewedSoldiersID;

		static int _generalID;
	public:
		int getGeneralID();

		Soldier();
		Soldier(Vector2 position, Vector2 viewDirection, float viewDistance, float angleInRadian);
		Soldier(Vector2 position, Vector2 viewDirection, float viewDistance, float angleInRadian, std::vector<int> viewedSoldiersID);

		//~Soldier();

		int getID();
		Vector2 getPosition() const;
		Vector2 getViewDirection();
		float getViewDistance();
		float getAngle();
		float getCosAngleDev2();

		friend std::ostream& operator<<(std::ostream& out, const Soldier& soldier);
		friend std::istream& operator>>(std::istream& in, Soldier& soldier);

		std::vector<int> getViewedSoldiersID();
		void setViewedSoldiersID(std::vector<int> viewedSoldiersID);
		void addViewedSoldierID(int ID);
		void clearViewedSoldiersID();
	};
	
}


