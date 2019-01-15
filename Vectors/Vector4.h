#pragma once
class Vector4
{
private:
	float xPos;
	float yPos;
	float zPos;
	float wPos;

public:

	Vector4();
	~Vector4();
	Vector4(float x, float y, float z, float w);

	float GetX();
	float GetY();
	float GetZ();
	float GetW();

	void SetX(float x);
	void SetY(float y);
	void SetZ(float z);
	void SetW(float w);

	Vector4 operator+(Vector4 &rhs);
	Vector4 operator-(Vector4 &rhs);
	Vector4 operator*(float &rhs);
	bool operator==(Vector4 &rhs);
	bool operator!=(Vector4 &rhs);
	friend Vector4 operator* (float scalar, Vector4& v);
	float operator[](int index);

	float magnitude();
	Vector4 normalise();

	float dot(Vector4 other);

	float distance(Vector4 other);
};

