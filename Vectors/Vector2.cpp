#include "Vector2.h"
#include <cmath>
#include <iostream>


Vector2::Vector2()
{
	xPos = 0;
	yPos = 0;

	mData = new float[2] {xPos, yPos};
}


Vector2::~Vector2()
{
	
}

Vector2::Vector2(float x, float y)
{
	xPos = x;
	yPos = y;

	mData = new float[2] {xPos, yPos};
}

float Vector2::GetX()
{
	return xPos;
}

float Vector2::GetY()
{
	return yPos;
}

void Vector2::SetX(float x)
{
	xPos = x;
}

void Vector2::SetY(float y)
{
	yPos = y;
}


Vector2 Vector2::operator+(Vector2 & rhs) const
{
	Vector2 result(xPos + rhs.GetX(), yPos + rhs.GetY());
	return result;
}

Vector2 Vector2::operator-(Vector2 & rhs) const
{
	Vector2 result(xPos - rhs.GetX(), yPos - rhs.GetY());
	return result;
}



bool Vector2::operator==(Vector2 & rhs) const
{
	return xPos == rhs.GetX() && yPos == rhs.GetY();
}

bool Vector2::operator!=(Vector2 & rhs) const
{
	return xPos != rhs.GetX() || yPos != rhs.GetY();
}

float Vector2::magnitude()
{
	return sqrt(pow(xPos, 2) + pow(yPos, 2));
}

void Vector2::normalise()
{
	float mag = magnitude();

	Vector2 result(xPos / mag, yPos / mag);
	*this = result;
}

float Vector2::dot(Vector2 other)
{
	return (GetX()*other.GetX() + GetY()*other.GetY());
}

float Vector2::distance(Vector2 other)
{
	Vector2 temp = Vector2(xPos - other.GetX(), yPos - other.GetY());
	return temp.magnitude();
}

float Vector2::operator[](int index)
{
	if (index == 0)
		return xPos;
	else if (index == 1)
		return yPos;
	else
		std::cout << "Invalid Index" << std::endl;
	return -1;
}


Vector2 operator*(float scalar, Vector2& v)
{
	return v * scalar;
}
Vector2 Vector2::operator*(float  rhs) const
{
	return Vector2(xPos * rhs, yPos * rhs);
}
