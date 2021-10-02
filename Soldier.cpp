#include "Soldier.h"

namespace FieldOfView
{
	int Soldier::_generalID = 0;
	Soldier::Soldier()
	{
		_ID = _generalID;
		_position = Vector2();
		_viewDirection = Vector2(0.0f, 1.0f);
		_viewDistance = 1.0f;
		_angle = PI;
		_cosAngleDev2 = 0;

		_generalID++;

		//_viewedSoldiers = std::vector<Soldier>();
	}
	Soldier::Soldier(Vector2 position, Vector2 viewDirection, float viewDistance, float angleInRadian)
	{
		_ID = _generalID;
		_position = position;
		_viewDirection = viewDirection;//??? .normalize();
		_viewDistance = viewDistance;
		_angle = angleInRadian;
		_cosAngleDev2 = cos_opt(angleInRadian / 2, 0.001f);
		//_viewedSoldiers = std::vector<Soldier>();

		_generalID++;
	}
	Soldier::Soldier(Vector2 position, Vector2 viewDirection, float viewDistance, float angleInRadian, std::vector<int> viewedSoldiersID)
	{
		_ID = _generalID;
		_position = position;
		_viewDirection = viewDirection;//??? .normalize();
		_viewDistance = viewDistance;
		_angle = angleInRadian;
		_cosAngleDev2 = cos_opt(angleInRadian / 2, 0.001f);
		_viewedSoldiersID = viewedSoldiersID;

		_generalID++;
	}
	Soldier::~Soldier()
	{
		//_generalID--;
	}
	int Soldier::getID()
	{
		return _ID;
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
	//std::vector<int> Soldier::getViewedSoldiersID()
	//{
	//	return _viewedSoldiersID;
	//}
	//void Soldier::setViewedSoldiers(std::vector<Soldier> viewedSoldiers)
	//{
	//	_viewedSoldiers = viewedSoldiers;
	//}
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