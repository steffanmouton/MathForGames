#include "Vector3.h"
#include <cmath>
#include <iostream>


Vector3::Vector3()
{
	xPos = 0;
	yPos = 0;
	zPos = 0;

	mData = new float[3] {xPos, yPos, zPos};
}


Vector3::~Vector3()
{
	
}

Vector3::Vector3(float x, float y, float z)
{
	xPos = x;
	yPos = y;
	zPos = z;

	mData = new float[3]{ xPos, yPos, zPos };
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

void Vector3::SetX(float x)
{
	xPos = x;
}

void Vector3::SetY(float y)
{
	yPos = y;
}

void Vector3::SetZ(float z)
{
	zPos = z;
}

Vector3 Vector3::operator+(Vector3 & rhs)
{
	return Vector3(xPos + rhs.GetX(), yPos + rhs.GetY(), zPos + rhs.GetZ());
}

Vector3 Vector3::operator-(Vector3 & rhs)
{
	return Vector3(xPos - rhs.GetX(), yPos - rhs.GetY(), zPos - rhs.GetZ());
}

Vector3 Vector3::operator*(float rhs)
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

float Vector3::operator[](int index)
{
	if (index == 0)
		return xPos;
	if (index == 1)
		return yPos;
	if (index == 2)
		return zPos;
	else
		std::cout << "Invalid Index" << std::endl;
		return 0.0f;
}

float Vector3::magnitude()
{
	return sqrt(pow(xPos, 2) + pow(yPos, 2) + pow(zPos, 2));
}

void Vector3::normalise()
{
	float mag = magnitude();

	Vector3 result(xPos / mag, yPos / mag, zPos / mag);
	*this = result;
}

float Vector3::dot(Vector3 other)
{
	return (GetX()*other.GetX() + GetY()*other.GetY() + GetZ()*other.GetZ()); 
}

Vector3 Vector3::cross(Vector3 other)
{
	float x = GetY()*other.GetZ() - GetZ()*other.GetY();
	float y = GetZ()*other.GetX() - GetX()*other.GetZ();
	float z = GetX()*other.GetY() - GetY()*other.GetX();
	return Vector3(x, y, z);
}

float Vector3::distance(Vector3 other)
{
	Vector3 temp = Vector3(xPos - other.GetX(), yPos - other.GetY(), zPos - other.GetZ());
	return temp.magnitude();
}

Vector3 operator*(float scalar, Vector3 & v)
{
	return v * scalar;;
}
