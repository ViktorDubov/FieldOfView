#include "Mathf.h"

#include <cmath>

namespace MathOFVector
{
	float sqrt_opt(float x, float eps)
	{
		//����� ����������� ��������������, ���� ����������� �������
		return sqrt(x);
	}
	float abs_opt(float x)
	{
		if (x < 0) return -x;
		else return x;
	}
	float acos_opt(float x, float eps)
	{
		//����� ����������� ��������������, ���� ����������� �������
		return acos(x);
	}
	float cos_opt(float x, float eps)
	{
		//����� ����������� ��������������, ���� ����������� �������
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

