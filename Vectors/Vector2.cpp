#include "Vector2.h"
#include <cmath>
#include <iostream>


Vector2::Vector2()
{
	xPos = 0;
	yPos = 0;
}


Vector2::~Vector2()
{
}

Vector2::Vector2(float x, float y)
{
	xPos = x;
	yPos = y;
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
	return Vector2(xPos + rhs.GetX(), yPos + rhs.GetY());
}

Vector2 Vector2::operator-(Vector2 & rhs) const
{
	return Vector2(xPos - rhs.GetX(), yPos - rhs.GetY());
}


Vector2 Vector2::operator*(float & rhs) const
{
	return Vector2(xPos * rhs, yPos * rhs);
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

Vector2 Vector2::normalise()
{
	float mag = magnitude();

	return Vector2(xPos / mag, yPos / mag);
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
