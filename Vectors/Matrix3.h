#pragma once
#include "Vector3.h"
#include <vector>

class Matrix3
{
private:
	Vector3 xCol;
	Vector3 yCol;
	Vector3 zCol;

	Vector3 xRow;
	Vector3 yRow;
	Vector3 zRow;

	std::vector<float> data;

public:

	Matrix3();
	Matrix3(float x1, float x2, float x3, float y1, float y2, 
		float y3, float z1, float z2, float z3);
	
	~Matrix3();

	Matrix3 operator*(Matrix3& rhs);

	Vector3 operator[](int index);

	Vector3 operator*(Vector3& rhs);

	Matrix3 setRotateZ(float angle);

	void Print();
};

