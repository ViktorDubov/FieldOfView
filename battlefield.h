#pragma once

#include <map>

#include "Vector2.h"
#include "Soldier.h"

using namespace MathOFVector;

namespace FieldOfView
{
	typedef std::multimap<float, Soldier> YMap;
	typedef std::multimap<float, YMap> XMap;

	class Battlefield
	{
	private:
		XMap _mapOFUnits;
		int _sizeX;
		int _sizeY;

		XMap GeneratedSoldier(int sizeX, int sizeY, int countOfGeneratedSoldier);
	public:
		Battlefield();
		Battlefield(int sizeX, int sizeY, int countOfGeneratedSoldier);
		Battlefield(int sizeX, int sizeY, std::map<float, std::multimap<float, Soldier>> mapOFUnits);

		static std::map<float, std::multimap<float, Soldier>> getMapOFUnits(const std::vector<Soldier>& vectorOfSoldiers);
		template <typename Soldier, const size_t n1>
		static std::map<float, std::multimap<float, Soldier>> getMapOFUnits(const Soldier(&arrayOfSoldiers)[n1]);


	};
}


