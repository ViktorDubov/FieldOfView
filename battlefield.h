#pragma once

#include <map>
#include <random>

#include "Soldier.h"
#include "Vector2.h"

using namespace MathOFVector;

namespace FieldOfView
{
	typedef std::map<std::pair<float, float>, Soldier > map2d;

	class Battlefield
	{
	private:
		map2d _mapOFUnits;
		int _sizeX;
		int _sizeY;

		map2d GeneratedSoldiers(int sizeX, int sizeY, int countOfGeneratedSoldier);
	public:
		Battlefield();
		Battlefield(int sizeX, int sizeY, int countOfGeneratedSoldier);
		Battlefield(int sizeX, int sizeY, std::map<std::pair<float, float>, Soldier > mapOFSoldiers);

		map2d transformToMapOFSoldiers(const std::vector<Soldier>& vectorOfSoldiers);
		//template <typename Soldier, const size_t n>
		//static std::multimap<float, std::multimap<float, FieldOfView::Soldier>> transformToMapOFSoldiers(const Soldier(&arrayOfSoldiers)[n]);

		void calculateFieldsOfViewForAllSoldier();
		
		friend std::ostream& operator<<(std::ostream& out, Battlefield& battlefield);
		//friend std::istream& operator>>(std::istream& in, Battlefield& battlefield);
	};
}