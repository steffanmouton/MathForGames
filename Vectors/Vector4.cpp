#include "Vector4.h"
#include <cmath>
#include <iostream>


Vector4::Vector4()
{
	xPos = 0;
	yPos = 0;
	zPos = 0;
	wPos = 0;
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

Vector4 Vector4::operator*(float& rhs)
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

float Vector4::Magnitude()
{
	return sqrt(pow(xPos, 2) + pow(yPos, 2) + pow(zPos, 2) + pow(wPos, 2));
}

Vector4 Vector4::Normalize()
{
	float mag = Magnitude();

	return Vector4(xPos / mag, yPos / mag, zPos / mag, wPos / mag);

}

float Vector4::Dot(Vector4 other)
{
	return (GetX()*other.GetX() + GetY()*other.GetY() + GetZ()*other.GetZ() 
		+ GetW()*other.GetW());
}

float Vector4::Distance(Vector4 other)
{
	Vector4 temp = Vector4(xPos - other.GetX(), yPos - other.GetY(), 
		zPos - other.GetZ(), wPos - other.GetW());
	return temp.Magnitude();
}

Vector4 operator*(float scalar, Vector4 & v)
{
	return v * scalar;
}
