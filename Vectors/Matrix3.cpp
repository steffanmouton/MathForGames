#include "Matrix3.h"



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

	x1 = xCol.Dot(xRow);
	x2 = xCol.Dot(yRow);
	x3 = xCol.Dot(zRow);

	y1 = yCol.Dot(xRow);
	y2 = yCol.Dot(yRow);
	y3 = yCol.Dot(zRow);

	z1 = zCol.Dot(xRow);
	z2 = zCol.Dot(yRow);
	z3 = zCol.Dot(zRow);

	return Matrix3(x1, x2, x3, y1, y2, y3, z1, z2, z3);
}
