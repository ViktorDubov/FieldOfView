#include "Soldier.h"

namespace FieldOfView
{
	int Soldier::_generalID = 0;
	int Soldier::getGeneralID()
	{
		return _generalID;
	}
	Soldier::Soldier()
	{
		_ID = _generalID;
		_generalID++;

		_position = Vector2();
		_viewDirection = Vector2(0.0f, 1.0f);
		_viewDistance = 1.0f;
		_angle = PI;
		_cosAngleDev2 = 0;

		_viewedSoldiersID = std::vector<int>();
	}
	Soldier::Soldier(Vector2 position, Vector2 viewDirection, float viewDistance, float angleInRadian)
	{
		_ID = _generalID;
		_generalID++;

		_position = position;
		_viewDirection = viewDirection;//??? .normalize();
		_viewDistance = viewDistance;
		_angle = angleInRadian;
		_cosAngleDev2 = cos_opt(angleInRadian / 2, 0.001f);

		_viewedSoldiersID = std::vector<int>();
	}
	Soldier::Soldier(Vector2 position, Vector2 viewDirection, float viewDistance, float angleInRadian, std::vector<int> viewedSoldiersID)
	{
		_ID = _generalID;
		_generalID++;

		_position = position;
		_viewDirection = viewDirection;//??? .normalize();
		_viewDistance = viewDistance;
		_angle = angleInRadian;
		_cosAngleDev2 = cos_opt(angleInRadian / 2, 0.001f);
		_viewedSoldiersID = viewedSoldiersID;
	}
	int Soldier::getID()
	{
		return _ID;
	}
	Vector2 Soldier::getPosition() const
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
	std::vector<int> Soldier::getViewedSoldiersID()
	{
		return _viewedSoldiersID;
	}
	void Soldier::setViewedSoldiersID(std::vector<int> viewedSoldiersID)
	{
		_viewedSoldiersID = viewedSoldiersID;
	}
	void Soldier::addViewedSoldierID(int ID)
	{
		_viewedSoldiersID.push_back(ID);
	}
	void Soldier::clearViewedSoldiersID()
	{
		_viewedSoldiersID.clear();
	}
	std::ostream& operator<<(std::ostream& out, const Soldier& soldier)
	{
		out << soldier._ID << " " << soldier._position << " " << soldier._viewDirection << " " << soldier._viewDistance << " " << soldier._angle;
		for (size_t i = 0; i < soldier._viewedSoldiersID.size(); i++)
		{
			out << " " << soldier._viewedSoldiersID[i];
		}
		return out;
	}
	std::istream& operator>>(std::istream& in, Soldier& soldier)
	{
		in >> soldier._ID >> soldier._position >> soldier._viewDirection >> soldier._viewDistance >> soldier._angle;
		soldier._cosAngleDev2 = cos_opt(soldier._angle / 2, 0.001f);
		soldier._viewedSoldiersID.clear();
		int i;
		while (in.peek()!='\n')
		{
			in >> i;
			soldier._viewedSoldiersID.push_back(i);
		}
		return in;
	}
}