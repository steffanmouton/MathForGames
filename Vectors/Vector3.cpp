#include "Vector3.h"
#include <cmath>


Vector3::Vector3()
{
	xPos = 0;
	yPos = 0;
	zPos = 0;
}


Vector3::~Vector3()
{
}

Vector3::Vector3(float x, float y, float z)
{
	xPos = x;
	yPos = y;
	zPos = z;
}

float Vector3::GetX()
{
	return xPos;
}

float Vector3::GetY()
{
	return yPos;
}

float Vector3::GetZ()
{
	return zPos;
}

Vector3 Vector3::operator+(Vector3 & rhs)
{
	return Vector3(xPos + rhs.GetX(), yPos + rhs.GetY(), zPos + rhs.GetZ());
}

Vector3 Vector3::operator-(Vector3 & rhs)
{
	return Vector3(xPos - rhs.GetX(), yPos - rhs.GetY(), zPos - rhs.GetZ());
}

Vector3 Vector3::operator*(float & rhs)
{
	return Vector3(xPos * rhs, yPos * rhs, zPos * rhs);
}

bool Vector3::operator==(Vector3 & rhs)
{
	return xPos == rhs.GetX() && yPos == rhs.GetY() && zPos == rhs.GetZ();
}

bool Vector3::operator!=(Vector3 & rhs)
{
	return xPos != rhs.GetX() || yPos != rhs.GetY() || zPos != rhs.GetZ();
}

float Vector3::Magnitude()
{
	return sqrt(pow(xPos, 2) + pow(yPos, 2) + pow(zPos, 2));
}

Vector3 Vector3::Normalize()
{
	float mag = Magnitude();

	return Vector3(xPos / mag, yPos / mag, zPos / mag);
}

float Vector3::Dot(Vector3 other)
{
	return (GetX()*other.GetX() + GetY()*other.GetY() + GetZ()*other.GetZ());
}

Vector3 Vector3::Cross(Vector3 other)
{
	float x = GetY()*other.GetZ() - GetZ()*other.GetY();
	float y = GetZ()*other.GetX() - GetX()*other.GetZ();
	float z = GetX()*other.GetY() - GetY()*other.GetX();
	return Vector3(x, y, z);
}

float Vector3::Distance(Vector3 other)
{
	Vector3 temp = Vector3(xPos - other.GetX(), yPos - other.GetY(), zPos - other.GetZ());
	return temp.Magnitude();
}
