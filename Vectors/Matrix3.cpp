#include "Matrix3.h"
#include <iostream>


Matrix3::Matrix3()
{
	xCol, yCol, zCol, xRow, yRow, zRow = Vector3(0, 0, 0);

	for (int i =0; i<9; i++)
	{
		data[i] = 0;
	}
}

Matrix3::Matrix3(float x1, float x2, float x3, float y1, float y2, float y3, float z1, float z2, float z3)
{
	xCol = Vector3(x1, x2, x3);
	yCol = Vector3(y1, y2, y3);
	zCol = Vector3(z1, z2, z3);

	xRow = Vector3(x1, y1, z1);
	yRow = Vector3(x2, y2, z2);
	zRow = Vector3(x3, y3, z3);

	data = { x1, x2, x3, y1, y2, y3, z1, z2, z3 };
}


Matrix3::~Matrix3()
{
}

Matrix3 Matrix3::operator*(Matrix3 & rhs)
{
	float x1, x2, x3, y1, y2, y3, z1, z2, z3;

	x1 = xRow.Dot(rhs.xCol);
	x2 = yRow.Dot(rhs.xCol);
	x3 = zRow.Dot(rhs.xCol);

	y1 = xRow.Dot(rhs.yCol);
	y2 = yRow.Dot(rhs.yCol);
	y3 = zRow.Dot(rhs.yCol);

	z1 = xRow.Dot(rhs.zCol);
	z2 = yRow.Dot(rhs.zCol);
	z3 = zRow.Dot(rhs.zCol);

	return Matrix3(x1, x2, x3, y1, y2, y3, z1, z2, z3);
}

Vector3 Matrix3::operator[](int index)
{
	if (index == 0)
		return xCol;
	else if (index == 1)
		return yCol;
	else if (index == 2)
		return zCol;
	else
		std::cout << "Invalid Index" <<std::endl;
	return Vector3();

}

Vector3 Matrix3::operator*(Vector3 & rhs)
{
	return Vector3(xCol.Dot(rhs), yCol.Dot(rhs), zCol.Dot(rhs));
}

Matrix3 Matrix3::setRotateZ(float angle)
{
	Matrix3 rotate = { cos(angle), sin(angle), 0, -sin(angle), cos(angle), 0, 0, 0, 1 };
	return Matrix3(*this * rotate);
}


void Matrix3::Print()
{
	for (int i = 0; i < 9; i++)
	{
		std::cout << data[i] << " ";
	}
}
