#include "Mathf.h"

#include <cmath>

namespace MathOFVector
{
	float sqrt_opt(float x, float eps)
	{
		//можно попробовать оптимизировать, пока стандартная функция
		//x -= 1;
		//float q = 1, sum = 1, previousSum = 0;
		//int n = 1;
		//while (Math::abs(sum - previousSum) > eps)
		//{
		//	q *= (-1.0f) * ((int)2 * n - (int)1) * 2 * n * x / (n * n * (int)4);
		//	std::cout << q << std::endl;
		//	previousSum = sum;
		//	sum += q / (1.0f - (int)2 * n);
		//	//std::cout << sum  << std::endl;
		//	n++;
		//}
		//sqrt
		return sqrt(x);
	}
	float abs_opt(float x)
	{
		if (x < 0) return -x;
		else return x;
	}
	float acos_opt(float x, float eps)
	{
		//можно попробовать оптимизировать, пока стандартная функция
		return acos(x);
	}
	float cos_opt(float x, float eps)
	{
		//можно попробовать оптимизировать, пока стандартная функция
		return cos(x);
	}
	float degreeToRadian(float degree)
	{
		return degree * (PI / 180);
	}
	float radianToDegree(float radian)
	{
		return radian * (180 / PI);
	}
}

