#include <iostream>
//#include <stream>
#include "Mathf.h"
#include "Vector2.h"
#include "Soldier.h"

using namespace MathOFVector;
using namespace FieldOfView;

int main()
{
    //std::cout << "Hello World!\n";
    //std::cout << Math::sqrt(4, 0.001);
    //std::cout << Math::abs(4) << std::endl;
    //std::cout << Math::abs(-4) << std::endl;
    //std::cout << MathOFVector::Vector2(0, 1).cosAngle(MathOFVector::Vector2(0, 1)) << std::endl;
    //Vector2 v;
    //std::cin >> v;
    //std::cout << v;

    Soldier soldier = Soldier(Vector2(0, 0), Vector2(0, 1), 1, 1, std::vector<int> {1,2,3});
    //std::cout << soldier._generalID;
    //std::cin >> soldier;
    std::cout << soldier << std::endl;

    std::cin >> soldier;
    std::cout << soldier;
}

