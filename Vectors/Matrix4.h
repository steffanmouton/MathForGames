#pragma once
#include "Vector4.h"
#include <vector>


class Matrix4
{
private:
	

public:

	Vector4 xCol;
	Vector4 yCol;
	Vector4 zCol;
	Vector4 wCol;

	Vector4 xRow;
	Vector4 yRow;
	Vector4 zRow;
	Vector4 wRow;

	std::vector<float> data;

	float *mData;

	Matrix4();
	Matrix4(float x1, float x2, float x3, float x4,
		float y1, float y2,float y3, float y4,
		float z1, float z2, float z3, float z4, 
		float w1, float w2, float w3, float w4);
	~Matrix4();

	Matrix4 operator*(Matrix4& rhs);
	Vector4 operator[](int index);
	Vector4 operator*(Vector4& rhs);

	void setRotateX(float angle);
	void setRotateY(float angle);
	void setRotateZ(float angle);

	void Print();

	operator float*()
	{
		return mData;
	}
};

