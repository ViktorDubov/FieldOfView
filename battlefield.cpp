#include "Battlefield.h"

FieldOfView::map2d FieldOfView::Battlefield::GeneratedSoldiers(int sizeX, int sizeY, int countOfGeneratedSoldier)
{
	map2d mapOFUnits = map2d();
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(0.0, 1.0);
	for (size_t i = 0; i < countOfGeneratedSoldier; i++)
	{
		float x = dis(gen) * sizeX;
		float y = dis(gen) * sizeY;
		mapOFUnits.emplace(std::make_pair(x, y), Soldier(Vector2(x, y), Vector2(dis(gen), dis(gen)), (dis(gen) * (sizeX / 2 + sizeY / 2)), dis(gen) * PI));
	}

	return mapOFUnits;
}

FieldOfView::Battlefield::Battlefield()
{
	_mapOFUnits = map2d();
	_sizeX = 1;
	_sizeY = 1;
}

FieldOfView::Battlefield::Battlefield(int sizeX, int sizeY, int countOfGeneratedSoldier)
{
	_sizeX = sizeX;
	_sizeY = sizeY;
	_mapOFUnits = GeneratedSoldiers(sizeX, sizeY, countOfGeneratedSoldier);
}

FieldOfView::Battlefield::Battlefield(int sizeX, int sizeY, std::map<std::pair<float, float>, Soldier > mapOFUnits)
{
	_sizeX = sizeX;
	_sizeY = sizeY;
	_mapOFUnits = mapOFUnits;
}

FieldOfView::map2d FieldOfView::Battlefield::transformToMapOFSoldiers(const std::vector<Soldier>& vectorOfSoldiers)
{
	map2d battlefield = map2d();
	for (std::vector<Soldier>::const_iterator iter= vectorOfSoldiers.begin(); iter != vectorOfSoldiers.end(); ++iter)
	{
		battlefield.emplace(std::make_pair(iter->getPosition().getX(), iter->getPosition().getY()), *iter);
	}
	return battlefield;
}

void FieldOfView::Battlefield::calculateFieldsOfViewForAllSoldier()
{
	for (map2d::iterator iter = _mapOFUnits.begin(); iter != _mapOFUnits.end(); ++iter)
	{
		Soldier& thisSoldier = iter->second;
		thisSoldier.clearViewedSoldiersID();
		map2d::iterator iter2 = iter;
		iter2++;
		float sqrDistance = thisSoldier.getViewDistance() * thisSoldier.getViewDistance();
		for (iter2; iter2 != _mapOFUnits.end(); ++iter2)
		{
			Soldier& tempSoldier = iter2->second;
			if (thisSoldier.getPosition().sqrDistance(tempSoldier.getPosition()) <= sqrDistance)
			{
				if (thisSoldier.getViewDirection().cosAngle(tempSoldier.getPosition() - thisSoldier.getPosition()) >= thisSoldier.getCosAngleDev2())
				{
					thisSoldier.addViewedSoldierID(tempSoldier.getID());
				}
			}
			else
			{
				break;
			}
		}
		iter2 = iter;
		if (iter2!= _mapOFUnits.begin())
		{
			iter2--;
		}
		for (iter2; iter2 != _mapOFUnits.begin(); --iter2)
		{
			Soldier& tempSoldier = iter2->second;
			if (thisSoldier.getPosition().sqrDistance(tempSoldier.getPosition()) <= sqrDistance)
			{
				if (thisSoldier.getViewDirection().cosAngle(tempSoldier.getPosition() - thisSoldier.getPosition()) >= thisSoldier.getCosAngleDev2())
				{
					thisSoldier.addViewedSoldierID(tempSoldier.getID());
				}
			}
			else
			{
				break;
			}
		}
	}

}


std::ostream& FieldOfView::operator<<(std::ostream& out, Battlefield& battlefield)
{
	for (map2d::iterator iter = battlefield._mapOFUnits.begin(); iter != battlefield._mapOFUnits.end(); ++iter)
	{
		out << iter->second << '\n';
	}
	return out;
}

//std::istream& FieldOfView::operator>>(std::istream& in, Battlefield& battlefield)
//{
//	battlefield._mapOFUnits.clear();
//	while (in.eof())
//	{
//		Soldier soldier;
//		in >> soldier;
//		std::cout << soldier << std::endl;
//		//if (in.eof())
//		//{
//		//	break;
//		//}
//		battlefield._mapOFUnits.emplace(std::make_pair(soldier.getPosition().getX(), soldier.getPosition().getY()), soldier);
//	}
//	return in;
//}

