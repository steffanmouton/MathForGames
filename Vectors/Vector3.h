#pragma once
class Vector3
{
private:

	float xPos;
	float yPos;
	float zPos;

	float *mData;

public:
	Vector3();
	~Vector3();
	Vector3(float x, float y, float z);

	float GetX();
	float GetY();
	float GetZ();

	

	void SetX(float x);
	void SetY(float y);
	void SetZ(float z);

	Vector3 operator+(Vector3 &rhs);
	Vector3 operator-(Vector3 &rhs);
	Vector3 operator*(float rhs);
	bool operator==(Vector3 &rhs);
	bool operator!=(Vector3 &rhs);
	friend Vector3 operator* (float scalar, Vector3& v);
	float operator[](int index);

	Vector3 operator=(Vector3 rhs);

	float magnitude();
	void normalise();

	float dot(Vector3 other);
	Vector3 cross(Vector3 other);

	float distance(Vector3 other);

	operator float*()
	{
		return mData;
	}
};

