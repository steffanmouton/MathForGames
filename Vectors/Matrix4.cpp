#include "Matrix4.h"
#include <iostream>


Matrix4::Matrix4()
{
	xCol, yCol, zCol, wCol, xRow, yRow, zRow, wRow = Vector4(0, 0, 0, 0);

	for (int i = 0; i<9; i++)
	{
		data[i] = 0;
	}
}

Matrix4::Matrix4(float x1, float x2, float x3, float x4, float y1, float y2, float y3, float y4, float z1, float z2, float z3, float z4, float w1, float w2, float w3, float w4)
{
	xCol = Vector4(x1, x2, x3, x4);
	yCol = Vector4(y1, y2, y3, y4);
	zCol = Vector4(z1, z2, z3, z4);
	wCol = Vector4(w1, w2, w3, w4);

	xRow = Vector4(x1, y1, z1, w1);
	yRow = Vector4(x2, y2, z2, w2);
	zRow = Vector4(x3, y3, z3, w3);
	wRow = Vector4(x4, y4, z4, w4);

	data = { x1, x2, x3, x4, y1, y2, y3, y4, z1, z2, z3, z4, w1, w2, w3, w4 };
}


Matrix4::~Matrix4()
{
}

Matrix4 Matrix4::operator*(Matrix4 & rhs)
{
	float x1, x2, x3, x4, y1, y2, y3, y4, z1, z2, z3, z4, w1, w2, w3, w4;

	x1 = xRow.dot(rhs.xCol);
	x2 = yRow.dot(rhs.xCol);
	x3 = zRow.dot(rhs.xCol);
	x4 = wRow.dot(rhs.xCol);

	y1 = xRow.dot(rhs.yCol);
	y2 = yRow.dot(rhs.yCol);
	y3 = zRow.dot(rhs.yCol);
	y4 = wRow.dot(rhs.yCol);

	z1 = xRow.dot(rhs.zCol);
	z2 = yRow.dot(rhs.zCol);
	z3 = zRow.dot(rhs.zCol);
	z4 = wRow.dot(rhs.zCol);

	w1 = xRow.dot(rhs.wCol);
	w2 = yRow.dot(rhs.wCol);
	w3 = zRow.dot(rhs.wCol);
	w4 = wRow.dot(rhs.wCol);

	return Matrix4(x1, x2, x3, x4, y1, y2, y3, y4, z1, z2, z3, z4, w1, w2, w3, w4);
}

Vector4 Matrix4::operator[](int index)
{
	if (index == 0)
		return xCol;
	else if (index == 1)
		return yCol;
	else if (index == 2)
		return zCol;
	else if (index == 3)
		return wCol;
	else
		std::cout << "Invalid Index" << std::endl;
	return Vector4();
}

Vector4 Matrix4::operator*(Vector4 & rhs)
{
	return Vector4(xCol.dot(rhs), yCol.dot(rhs), zCol.dot(rhs), wCol.dot(rhs));
}

Matrix4 Matrix4::setRotateX(float angle)
{
	Matrix4 rotate = { 1, 0, 0, 0, 0, cos(angle), sin(angle), 0, 0, -sin(angle),
		cos(angle), 0, 0, 0, 0, 1 };
	return Matrix4(*this * rotate);
}

Matrix4 Matrix4::setRotateY(float angle)
{
	Matrix4 rotate = { cos(angle), 0, -sin(angle), 0, 0, 1, 0, 0, sin(angle), 0,
		cos(angle), 0, 0, 0, 0, 1 };
	return Matrix4(*this * rotate);
}

Matrix4 Matrix4::setRotateZ(float angle)
{
	Matrix4 rotate = { cos(angle), sin(angle), 0, 0, -sin(angle), cos(angle), 0, 0, 0, 0,
		1, 0, 0, 0, 0, 1 };
	return Matrix4(*this * rotate);
}

void Matrix4::Print()
{
	for (int i = 0; i < 16; i++)
	{
		std::cout << data[i] << " ";
	}
}
