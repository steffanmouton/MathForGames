#pragma once
class Vector3
{
private:

	float xPos;
	float yPos;
	float zPos;

public:
	Vector3();
	~Vector3();
	Vector3(float x, float y, float z);

	float GetX();
	float GetY();
	float GetZ();

	Vector3 operator+(Vector3 &rhs);
	Vector3 operator-(Vector3 &rhs);
	Vector3 operator*(float &rhs);
	bool operator==(Vector3 &rhs);
	bool operator!=(Vector3 &rhs);

	float Magnitude();
	Vector3 Normalize();
};

