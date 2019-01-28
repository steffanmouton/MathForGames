#include "Matrix3.h"
#include <iostream>


Matrix3::Matrix3()
{
	xCol, yCol, zCol, xRow, yRow, zRow = Vector3(0, 0, 0);

	data = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	mData = new float[9] {0, 0, 0, 0, 0, 0, 0, 0, 0};
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
	mData = new float[9] { x1, x2, x3, y1, y2, y3, z1, z2, z3 };
}


Matrix3::~Matrix3()
{
	
}

Matrix3 Matrix3::operator*(Matrix3 & rhs)
{
	refreshMat();
	float x1, x2, x3, y1, y2, y3, z1, z2, z3;

	x1 = xRow.dot(rhs.xCol);
	x2 = yRow.dot(rhs.xCol);
	x3 = zRow.dot(rhs.xCol);

	y1 = xRow.dot(rhs.yCol);
	y2 = yRow.dot(rhs.yCol);
	y3 = zRow.dot(rhs.yCol);

	z1 = xRow.dot(rhs.zCol);
	z2 = yRow.dot(rhs.zCol);
	z3 = zRow.dot(rhs.zCol);

	return Matrix3(x1, x2, x3, y1, y2, y3, z1, z2, z3);
}

Vector3& Matrix3::operator[](int index)
{
	if (index == 0)
		return xCol;
	else if (index == 1)
		return yCol;
	else if (index == 2)
		return zCol;
	else
		std::cout << "Invalid Index" <<std::endl;	
}

Vector3 Matrix3::operator*(Vector3 & rhs)
{
	refreshMat();

	return Vector3(xRow.dot(rhs), yRow.dot(rhs), zRow.dot(rhs));
}


void Matrix3::setRotateX(float angle)
{
	refreshMat();
	Matrix3 rotate = { 1, 0, 0, 0, cos(angle), sin(angle), 0, -sin(angle), cos(angle) };
	*this = rotate;
}

void Matrix3::setRotateY(float angle)
{
	refreshMat();
	Matrix3 rotate = { cos(angle), 0, -sin(angle), 0, 1, 0, sin(angle), 0, cos(angle) };
	*this = rotate;
}

void Matrix3::setRotateZ(float angle)
{
	refreshMat();
	Matrix3 rotate = { cos(angle), sin(angle), 0, -sin(angle), cos(angle), 0, 0, 0, 1 };
	*this = rotate;	
}

void Matrix3::refreshMat()
{
	delete mData;
	mData = new float[9] { xCol.GetX(), xCol.GetY(), xCol.GetZ(), yCol.GetX(), yCol.GetY(), yCol.GetZ(),
	zCol.GetX(), zCol.GetY(), zCol.GetZ() };

	xRow = Vector3(xCol.GetX(), yCol.GetX(), zCol.GetX());
	yRow = Vector3(xCol.GetY(), yCol.GetY(), zCol.GetY());
	zRow = Vector3(xCol.GetZ(), yCol.GetZ(), zCol.GetZ());
}


void Matrix3::Print()
{
	for (int i = 0; i < 9; i++)
	{
		std::cout << data[i] << " ";
	}
}
