#include "Vector2.h"
#include <cmath>


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

Vector2 Vector2::operator+(Vector2 & rhs)
{
	return Vector2(xPos + rhs.GetX(), yPos + rhs.GetY());
}

Vector2 Vector2::operator-(Vector2 & rhs)
{
	return Vector2(xPos - rhs.GetX(), yPos - rhs.GetY());
}


Vector2 Vector2::operator*(float & rhs)
{
	return Vector2(xPos * rhs, yPos * rhs); 
}

bool Vector2::operator==(Vector2 & rhs)
{
	return xPos == rhs.GetX() && yPos == rhs.GetY();
}

bool Vector2::operator!=(Vector2 & rhs)
{
	return xPos != rhs.GetX() || yPos != rhs.GetY();
}

float Vector2::Magnitude()
{
	return sqrt(pow(xPos, 2) + pow(yPos, 2));
}

Vector2 Vector2::Normalize()
{
	float mag = Magnitude();

	return Vector2(xPos / mag, yPos / mag);
}

float Vector2::Distance(Vector2 other)
{
	Vector2 temp = Vector2(xPos - other.GetX(), yPos - other.GetY());
	return temp.Magnitude();
}
