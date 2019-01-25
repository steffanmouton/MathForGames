#pragma once
class Vector2
{
private:

	float xPos;
	float yPos;

	float *mData;

public:
	Vector2();
	~Vector2();
	Vector2(float x, float y);

	float GetX();
	float GetY();

	void SetX(float x);
	void SetY(float y);

	Vector2 operator+(Vector2 &rhs) const;
	Vector2 operator-(Vector2 &rhs) const;
	Vector2 operator*(float rhs) const;
	bool operator==(Vector2 &rhs) const;
	bool operator!=(Vector2 &rhs) const;
	friend Vector2 operator* (float scalar, Vector2& v);

	float magnitude();
	void normalise();

	float dot(Vector2 other);

	float distance(Vector2 other);

	float operator[](int index);

	operator float*()
	{
		return mData;
	}
};

