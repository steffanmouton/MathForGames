#pragma once
class Vector2
{
private:

	float xPos;
	float yPos;

public:
	Vector2();
	~Vector2();
	Vector2(float x, float y);

	float GetX();
	float GetY();

	void SetX(float x);
	void SetY(float y);

	Vector2 operator+(Vector2 &rhs);
	Vector2 operator-(Vector2 &rhs);
	Vector2 operator*(float &rhs);
	bool operator==(Vector2 &rhs);
	bool operator!=(Vector2 &rhs);

	float Magnitude();
	Vector2 Normalize();

	float Dot(Vector2 other);

	float Distance(Vector2 other);
};

