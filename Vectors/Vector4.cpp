#include "Vector4.h"
#include <cmath>
#include <iostream>


Vector4::Vector4()
{
	xPos = 0;
	yPos = 0;
	zPos = 0;
	wPos = 0;

	mData = new float[4] {xPos, yPos, zPos, wPos};
}


Vector4::~Vector4()
{

}

Vector4::Vector4(float x, float y, float z, float w)
{
	xPos = x;
	yPos = y;
	zPos = z;
	wPos = w;

	mData = new float[4]{ xPos, yPos, zPos, wPos };
}

float Vector4::GetX()
{
	return xPos;
}

float Vector4::GetY()
{
	return yPos;
}

float Vector4::GetZ()
{
	return zPos;
}

float Vector4::GetW()
{
	return wPos;
}

void Vector4::SetX(float x)
{
	xPos = x;
}

void Vector4::SetY(float y)
{
	yPos = y;
}

void Vector4::SetZ(float z)
{
	zPos = z;
}

void Vector4::SetW(float w)
{
	wPos = w;
}

Vector4 Vector4::operator+(Vector4& rhs)
{
	return Vector4(xPos + rhs.GetX(), yPos + rhs.GetY(), zPos + rhs.GetZ(), 
		wPos + rhs.GetW());
}

Vector4 Vector4::operator-(Vector4& rhs)
{
	return Vector4(xPos - rhs.GetX(), yPos - rhs.GetY(), zPos - rhs.GetZ(), 
		wPos - rhs.GetW());
}

Vector4 Vector4::operator*(float rhs)
{
	return Vector4(xPos * rhs, yPos * rhs, zPos * rhs, wPos * rhs);
}

bool Vector4::operator==(Vector4& rhs)
{
	return xPos == rhs.GetX() && yPos == rhs.GetY() && zPos == rhs.GetZ() 
	&& wPos == rhs.GetW();
}

bool Vector4::operator!=(Vector4& rhs)
{
	return xPos != rhs.GetX() || yPos != rhs.GetY() || zPos != rhs.GetZ() 
	|| wPos != rhs.GetW();
}

float Vector4::operator[](int index)
{
	if (index == 0)
		return xPos;
	if (index == 1)
		return yPos;
	if (index == 2)
		return zPos;
	if (index == 3)
		return wPos;
	else
		std::cout << "Invalid Index" << std::endl;
		return 0.0f;
}

float Vector4::magnitude()
{
	return sqrt(pow(xPos, 2) + pow(yPos, 2) + pow(zPos, 2) + pow(wPos, 2));
}

void Vector4::normalise()
{
	float mag = magnitude();

	Vector4 result(xPos / mag, yPos / mag, zPos / mag, wPos / mag);
	*this = result;
}

float Vector4::dot(Vector4 other)
{
	return (GetX()*other.GetX() + GetY()*other.GetY() + GetZ()*other.GetZ() 
		+ GetW()*other.GetW());
}

Vector4 Vector4::cross(Vector4 other)
{
	float x = GetY()*other.GetZ() - GetZ()*other.GetY();
	float y = GetZ()*other.GetX() - GetX()*other.GetZ();
	float z = GetX()*other.GetY() - GetY()*other.GetX();
	return Vector4(x, y, z, 0);
}

float Vector4::distance(Vector4 other)
{
	Vector4 temp = Vector4(xPos - other.GetX(), yPos - other.GetY(), 
		zPos - other.GetZ(), wPos - other.GetW());
	return temp.magnitude();
}

Vector4 operator*(float scalar, Vector4 & v)
{
	return v * scalar;
}
