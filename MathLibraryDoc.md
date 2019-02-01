# MathLibrary Documentation

Steffan Mouton

s188045

Math for Games Assessment

## Requirements Documentation

- Description of Problem
  - Name: Create a Math Library
  - Problem Statement: Create a math library that utlizes vectors and matrices
  - Problem Specification: Must contain classes as dictated by AIE assessment criteria:
```
The Math Library
Your math library must include the following classes. The maths operations should be in column-major order, using a right-handed coordinate system, with the following names of classes and functions to ensure that your code works correctly with the Unit Test Application:

·         Vector2 (2-dimensional vector using 2 float)

·         Vector3 (3-dimensional vector using 3 floats)

·         Vector4 (3-dimensional homogeneous vector using 4 floats)

·         Matrix3 (3-dimensional 3x3 rotation matrix using 9 float)

·         Matrix4 (3-dimensional 4x4 transform matrix using 16 float)

·         Colour (RGBA values stored as a 4 byte integer)

Your classes must overload the following mathematical operators and include the additionally mentioned member functions, where V represents a Vector, M represents a Matrix, n represents an index and f represents a float:

·         V = V + V (point translated by a vector)

·         V = V – V (point translated by a vector)

·         V = V x f (vector scale)

·         V = f x V (vector scale)

·         V = M x V (vector transformation)

·         M = M x M (matrix concatenation)

·         f = V.dot( V )

·         V = V.cross( V ) (not needed for Vector2)

·         f = V.magnitude()

·         V.normalise()

·         f = V[n] (sub-script operator)

·         V = M[n] (sub-script operator)

·         V[n] = f (sub-script operator returning reference)

·         M[n] = V (sub-script operator returning reference)

·         float* fp = (float*)V (cast operator)

·         float* fp = (float*)M (cast operator)

·         M.setRotateX( f ) and M.setRotateY( f ) and M.setRotateZ( f ) (for Matrix3 and Matrix4)

Your classes will all have default constructors, and constructors that allow each float element to be set individually, for example:

·         Vector2 v2; // default

·         Vector4 v4( 0, 0, 0, 1 );

·         Matrix3 m3 = Matrix3( 1, 0, 0, 0, 1, 0, 0, 0, 1 );
```

- Input Information
  - N/A
- Output Information
  - Performs mathematical operations and creates and stores data for vectors and matrices

- User Interface Information
  - Description: There is no user interface

## Design Documentation

- System Architecture Description
  - C++. Static Library. All independent class files.
- Information about the objects
  - *Class Information*
    - Name: Vector2
      - Description: Holds two points of data. Performs operations unique to vector math
      - Base Class: N/A
      - Class Attributes
        - Name: xPos
          - Description: First data point
          - Type: float
          - Range of Acceptable Values: any float
        - Name: yPos
          - Description: Second data point
          - Type: float
          - Range of Acceptable Values: any float
        - Name: mData
          - Description: pointer to array of all data in vector
          - Type: float pointer
          - Range of Acceptable Values: address of floats
      - Class Operations
        - Prototype: Vector2();
          - Description: default constructor for Vector2
          - Pre-Conditions: Instance of a Vector2 is created
          - Post-Conditions: a Vector2 instance is initialized with default values of 0
          - Visibility: Public
        - Prototype: Vector2(float, float);
          - Description: Constructor taking in two floats
          - Pre-Conditions: Instance of a Vector2 is created with two floats
          - Post-Conditions: Instance of Vector2 is created with two floats, in order
        - Prototype: ~Vector2()
          - Description: destructor for Vector2
          - Pre-Conditions: Vector2 is destroyed
          - Post-Conditions: memory used by vector is freed up
          - Visibility: Public
        - Prototype: float GetX();
          - Description: returns the xPos member
          - Pre-Conditions: Instance of Vector2 exists
          - Post-Conditions: returned xPos member
          - Visibility: Public
        - Prototype: float GetY();
          - Description: returns the yPos member
          - Pre-Conditions: Instance of Vector2 exists
          - Post-Conditions: returned yPos member
          - Visibility: Public
        - Prototype: void SetX(float)
          - Description: sets xPos to passed in float value
          - Pre-Conditions: An instance of Vector2 exists
          - Post-Conditions: xPos is set to new value
          - Visibility: Public
        - Prototype: void SetY(float)
          - Description: sets yPos to passed in float value
          - Pre-Conditions: An instance of Vector2 exists
          - Post-Conditions: yPos is set to new value
          - Visibility: Public
        - Prototype: operator+(Vector2);
          - Description: adds two Vector2s together
          - Pre-Conditions: two Vectors2s exist
          - Post-Conditions: Returns a vector that is the sum of the two vectors in the operation
          - Visibility: Public
        - Prototype: operator-(Vector2);
          - Description: subtracts two Vector2s
          - Pre-Conditions: two Vectors2s exist
          - Post-Conditions: Returns a vector that is the difference of the two vectors in the operation
          - Visibility: Public
        - Prototype: operator*(float);
          - Description: Multiplies Vector2 by a scalar value
          - Pre-Conditions: Vector2 exists 
          - Post-Conditions: Returns a vector that is the result of scalar operation by the passed in float value
          - Visibility: Public
        - Prototype: operator==(Vector2);
          - Description: Bool to see if two Vector2s are the same
          - Pre-Conditions: two Vectors2s exist
          - Post-Conditions: Returns a bool on comparison
          - Visibility: Public
        - Prototype: operator!=(Vector2);
          - Description: Bool to see if two Vector2s are different
          - Pre-Conditions: two Vectors2s exist
          - Post-Conditions: Returns a bool on comparison
          - Visibility: Public
        - Prototype: friend operator*(float, Vector2);
          - Description: Multiplies Vector2 by a scalar value
          - Pre-Conditions: Vector2 exists 
          - Post-Conditions: Returns a vector that is the result of scalar operation by the passed in float value
          - Visibility: Public
        - Prototype: operator float*();
          - Description: returns float pointer to the start of the vector info array
          - Pre-Conditions: Vector2 exists
          - Post-Conditions: Returned pointer to start of mData array
          - Visibility: Public
        - Prototype: operator[](int);
          - Description: Returns the item at the index inside the subscript
          - Pre-Conditions: Vector2 exists
          - Post-Conditions: Returns the item at called index
          - Visibility: Public
        - Prototype: float magnitude();
          - Description: returns the magnitude of a vector as a float value
          - Pre-Conditions: a Vector2 exists
          - Post-Conditions: Returns a float value for this vector's magnitude
          - Visibility: Public
        - Prototype: float distance(Vector2);
          - Description: returns the distance as float between two vectors
          - Pre-Conditions: two Vectors2s exist
          - Post-Conditions: Returns a float value for distance
          - Visibility: Public
    - Name: Vector3
      - Description: Holds three points of data. Performs operations unique to vector math
      - Base Class: N/A
      - Class Attributes
        - Name: xPos
          - Description: First data point
          - Type: float
          - Range of Acceptable Values: any float
        - Name: yPos
          - Description: Second data point
          - Type: float
          - Range of Acceptable Values: any float
        - Name: zPos
          - Description: Third data point
          - Type: float
          - Range of Acceptable Values: any float
        - Name: mData
          - Description: pointer to array of all data in vector
          - Type: float pointer
          - Range of Acceptable Values: address of floats
      - Class Operations
        - Prototype: Vector3();
          - Description: default constructor for Vector3
          - Pre-Conditions: Instance of a Vector3 is created
          - Post-Conditions: a Vector3 instance is initialized with default values of 0
          - Visibility: Public
        - Prototype: Vector3(float, float, float);
          - Description: Constructor taking in three floats
          - Pre-Conditions: Instance of a Vector3 is created with two floats
          - Post-Conditions: Instance of Vector3 is created with two floats, in order
        - Prototype: ~Vector3()
          - Description: destructor for Vector3
          - Pre-Conditions: Vector3 is destroyed
          - Post-Conditions: memory used by vector is freed up
          - Visibility: Public
        - Prototype: float GetX();
          - Description: returns the xPos member
          - Pre-Conditions: Instance of Vector3 exists
          - Post-Conditions: returned xPos member
          - Visibility: Public
        - Prototype: float GetY();
          - Description: returns the yPos member
          - Pre-Conditions: Instance of Vector3 exists
          - Post-Conditions: returned yPos member
          - Visibility: Public
        - Prototype: float GetZ();
          - Description: returns the zPos member
          - Pre-Conditions: Instance of Vector3 exists
          - Post-Conditions: returned zPos member
          - Visibility: Public
        - Prototype: void SetX(float)
          - Description: sets xPos to passed in float value
          - Pre-Conditions: An instance of Vector3 exists
          - Post-Conditions: xPos is set to new value
          - Visibility: Public
        - Prototype: void SetY(float)
          - Description: sets yPos to passed in float value
          - Pre-Conditions: An instance of Vector3 exists
          - Post-Conditions: yPos is set to new value
          - Visibility: Public
        - Prototype: void SetZ(float)
          - Description: sets zPos to passed in float value
          - Pre-Conditions: An instance of Vector3 exists
          - Post-Conditions: zPos is set to new value
          - Visibility: Public
        - Prototype: operator+(Vector3);
          - Description: adds two Vector3s together
          - Pre-Conditions: two Vectors3s exist
          - Post-Conditions: Returns a vector that is the sum of the two vectors in the operation
          - Visibility: Public
        - Prototype: operator-(Vector3);
          - Description: subtracts two Vector3s
          - Pre-Conditions: two Vectors3s exist
          - Post-Conditions: Returns a vector that is the difference of the two vectors in the operation
          - Visibility: Public
        - Prototype: operator*(float);
          - Description: Multiplies Vector3 by a scalar value
          - Pre-Conditions: Vector3 exists 
          - Post-Conditions: Returns a vector that is the result of scalar operation by the passed in float value
          - Visibility: Public
        - Prototype: operator==(Vector3);
          - Description: Bool to see if two Vector3s are the same
          - Pre-Conditions: two Vectors3s exist
          - Post-Conditions: Returns a bool on comparison
          - Visibility: Public
        - Prototype: operator!=(Vector3);
          - Description: Bool to see if two Vector3s are different
          - Pre-Conditions: two Vectors3s exist
          - Post-Conditions: Returns a bool on comparison
          - Visibility: Public
        - Prototype: friend operator*(float, Vector3);
          - Description: Multiplies Vector3 by a scalar value
          - Pre-Conditions: Vector3 exists 
          - Post-Conditions: Returns a vector that is the result of scalar operation by the passed in float value
          - Visibility: Public
        - Prototype: operator float*();
          - Description: returns float pointer to the start of the vector info array
          - Pre-Conditions: Vector3 exists
          - Post-Conditions: Returned pointer to start of mData array
          - Visibility: Public
        - Prototype: operator[](int);
          - Description: Returns the item at the index inside the subscript
          - Pre-Conditions: Vector3 exists
          - Post-Conditions: Returns the item at called index
          - Visibility: Public
        - Prototype: float magnitude();
          - Description: returns the magnitude of a vector as a float value
          - Pre-Conditions: a Vector3 exists
          - Post-Conditions: Returns a float value for this vector's magnitude
          - Visibility: Public
        - Prototype: float distance(Vector3);
          - Description: returns the distance as float between two vectors
          - Pre-Conditions: two Vectors3s exist
          - Post-Conditions: Returns a float value for distance
          - Visibility: Public
        - Prototype: float dot(Vector3);
          - Description: takes the dot product of two vectors
          - Pre-Conditions: Two Vector3s exist
          - Post-Conditions: Returns a float value for the dot product of two vectors
          - Visibility: Public
        - Prototype: Vector3 cross(Vector3);
          - Description: returns a Vector3 that is the cross product of two vector3s
          - Pre-Conditions: two Vector3 exists
          - Post-Conditions: Returns a Vector3 that is perpedicular to the two in the cross product operation
          - Visibility: Public
    - Name: Vector4
      - Description: Holds four points of data. Performs operations unique to vector math
      - Base Class: N/A
      - Class Attributes
        - Name: xPos
          - Description: First data point
          - Type: float
          - Range of Acceptable Values: any float
        - Name: yPos
          - Description: Second data point
          - Type: float
          - Range of Acceptable Values: any float
        - Name: zPos
          - Description: Third data point
          - Type: float
          - Range of Acceptable Values: any float
        - Name: wPos
          - Description: Fourth data point
          - Type: float
          - Range of Acceptable Values: any float
        - Name: mData
          - Description: pointer to array of all data in vector
          - Type: float pointer
          - Range of Acceptable Values: address of floats
      - Class Operations
        - Prototype: Vector4();
          - Description: default constructor for Vector4
          - Pre-Conditions: Instance of a Vector4 is created
          - Post-Conditions: a Vector4 instance is initialized with default values of 0
          - Visibility: Public
        - Prototype: Vector4(float, float, float, float);
          - Description: Constructor taking in four floats
          - Pre-Conditions: Instance of a Vector4 is created with two floats
          - Post-Conditions: Instance of Vector4 is created with two floats, in order
        - Prototype: ~Vector4()
          - Description: destructor for Vector4
          - Pre-Conditions: Vector4 is destroyed
          - Post-Conditions: memory used by vector is freed up
          - Visibility: Public
        - Prototype: float GetX();
          - Description: returns the xPos member
          - Pre-Conditions: Instance of Vector4 exists
          - Post-Conditions: returned xPos member
          - Visibility: Public
        - Prototype: float GetY();
          - Description: returns the yPos member
          - Pre-Conditions: Instance of Vector4 exists
          - Post-Conditions: returned yPos member
          - Visibility: Public
        - Prototype: float GetZ();
          - Description: returns the zPos member
          - Pre-Conditions: Instance of Vector4 exists
          - Post-Conditions: returned zPos member
          - Visibility: Public
        - Prototype: float GetW();
          - Description: returns the wPos member
          - Pre-Conditions: Instance of Vector4 exists
          - Post-Conditions: returned wPos member
          - Visibility: Public
        - Prototype: void SetX(float)
          - Description: sets xPos to passed in float value
          - Pre-Conditions: An instance of Vector4 exists
          - Post-Conditions: xPos is set to new value
          - Visibility: Public
        - Prototype: void SetY(float)
          - Description: sets yPos to passed in float value
          - Pre-Conditions: An instance of Vector4 exists
          - Post-Conditions: yPos is set to new value
          - Visibility: Public
        - Prototype: void SetZ(float)
          - Description: sets zPos to passed in float value
          - Pre-Conditions: An instance of Vector4 exists
          - Post-Conditions: zPos is set to new value
          - Visibility: Public
        - Prototype: void SetW(float)
          - Description: sets wPos to passed in float value
          - Pre-Conditions: An instance of Vector4 exists
          - Post-Conditions: wPos is set to new value
          - Visibility: Public
        - Prototype: operator+(Vector4);
          - Description: adds two Vector4s together
          - Pre-Conditions: two Vectors4s exist
          - Post-Conditions: Returns a vector that is the sum of the two vectors in the operation
          - Visibility: Public
        - Prototype: operator-(Vector4);
          - Description: subtracts two Vector3s
          - Pre-Conditions: two Vectors4s exist
          - Post-Conditions: Returns a vector that is the difference of the two vectors in the operation
          - Visibility: Public
        - Prototype: operator*(float);
          - Description: Multiplies Vector4 by a scalar value
          - Pre-Conditions: Vector4 exists
          - Post-Conditions: Returns a vector that is the result of scalar operation by the passed in float value
          - Visibility: Public
        - Prototype: operator==(Vector4);
          - Description: Bool to see if two Vector3s are the same
          - Pre-Conditions: two Vectors4s exist
          - Post-Conditions: Returns a bool on comparison
          - Visibility: Public
        - Prototype: operator!=(Vector4);
          - Description: Bool to see if two Vector4s are different
          - Pre-Conditions: two Vectors4s exist
          - Post-Conditions: Returns a bool on comparison
          - Visibility: Public
        - Prototype: friend operator*(float, Vector4);
          - Description: Multiplies Vector4 by a scalar value
          - Pre-Conditions: Vector4 exists
          - Post-Conditions: Returns a vector that is the result of scalar operation by the passed in float value
          - Visibility: Public
        - Prototype: operator float*();
          - Description: returns float pointer to the start of the vector info array
          - Pre-Conditions: Vector4 exists
          - Post-Conditions: Returned pointer to start of mData array
          - Visibility: Public
        - Prototype: operator[](int);
          - Description: Returns the item at the index inside the subscript
          - Pre-Conditions: Vector4 exists
          - Post-Conditions: Returns the item at called index
          - Visibility: Public
        - Prototype: float magnitude();
          - Description: returns the magnitude of a vector as a float value
          - Pre-Conditions: a Vector4 exists
          - Post-Conditions: Returns a float value for this vector's magnitude
          - Visibility: Public
        - Prototype: float distance(Vector4);
          - Description: returns the distance as float between two vectors
          - Pre-Conditions: two Vectors4s exist
          - Post-Conditions: Returns a float value for distance
          - Visibility: Public
        - Prototype: float dot(Vector4);
          - Description: takes the dot product of two vectors
          - Pre-Conditions: Two Vector4s exist
          - Post-Conditions: Returns a float value for the dot product of two vectors
          - Visibility: Public
        - Prototype: Vector4 cross(Vector4);
          - Description: returns a Vector3 that is the cross product of two vector4s
          - Pre-Conditions: two Vector4 exists
          - Post-Conditions: Returns a Vector3 that is perpedicular to the two in the cross product operation
          - Visibility: Public
    - Name: Matrix3
      - Description: Contains the data and methods associated with Matrix3 and math invloving matrices
      - Base Class: N/A
      - Class Attributes
        - Name: xCol
          - Description: First vector. Contains first column
          - Type: Vector3
          - Range of Acceptable Values: a Vector3 of floats
        - Name: yCol
          - Description: Second vector. Contains second column
          - Type: Vector3
          - Range of Acceptable Values: a Vector3 of floats
        - Name: zCol
          - Description: Third vector. Contains third column
          - Type: Vector3
          - Range of Acceptable Values: a Vector3 of floats
        - Name: xRow
          - Description: Fourth vector. Contains first row
          - Type: Vector3
          - Range of Acceptable Values: a Vector3 of floats
        - Name: yRow
          - Description: Fifth vector. Contains second row
          - Type: Vector3
          - Range of Acceptable Values: a Vector3 of floats
        - Name: zRow
          - Description: Sixth vector. Contains third row
          - Type: Vector3
          - Range of Acceptable Values: a Vector3 of floats
        - Name: mData
          - Description: pointer to array of all data in vector
          - Type: float pointer
          - Range of Acceptable Values: address of floats
        - Name: data
          - Description: std::vector to contain all the data of the matrix. Column major.
          - Type: std::vector
          - Range of Acceptable Values: all floats
      - Class Operations
        - Prototype: Matrix3();
          - Description: default constructor for the Matrix
          - Pre-Conditions: Instance of a matrix is created
          - Post-Conditions: a matrix instance is initialized with default values of 0
          - Visibility: Public
        - Prototype: Matrix3(float, float, float, float, float, float, float, float, float);
          - Description: Constructor taking in nine floats
          - Pre-Conditions: Instance of a matrix is created
          - Post-Conditions: Instance of matrix is created with nine floats, in order
        - Prototype: ~Matrix3()
          - Description: destructor for matrix
          - Pre-Conditions: matrix is destroyed
          - Post-Conditions: memory used by matrix is freed up
          - Visibility: Public
        - Prototype: operator*(Matrix3);
          - Description: Multiplication overload for multiplying two matrices
          - Pre-Conditions: two matrices exist
          - Post-Conditions: returns a Matrix that is the product of the two involved
          - Visibility: Public
        - Prototype: operator[](int);
          - Description: overload to obtain the vector at a given index in the array
          - Pre-Conditions: matrix exists
          - Post-Conditions: returns a Vector3 in the array of the column at the index
          - Visibility: Public
        - Prototype: operator*(Vector3);
          - Description: multiply a matrix by a vector
          - Pre-Conditions: Matrix and vector exist
          - Post-Conditions: returns the product vector
          - Visibility: Public
        - Prototype: void setRotateX(float);
          - Description: set the rotation of the around X axis to the angle passed in
          - Pre-Conditions: Matrix exists
          - Post-Conditions: Matrix values are rotated
          - Visibility: Public
        - Prototype: operator*(Vector3);
          - Description: multiply a matrix by a vector
          - Pre-Conditions: Matrix and vector exist
          - Post-Conditions: returns the product vector
          - Visibility: Public
        - Prototype: refreshMat();
          - Description: Updates row vectors to match columns
          - Pre-Conditions: Math is done on matrix. This is called first in math functions to ensure row correctness
          - Post-Conditions: rows in matrix are up to date
          - Visibility: Public
        - Prototype: Print();
          - Description: prints the data in the matrix to the console
          - Pre-Conditions: Matrix exists
          - Post-Conditions: matrix data printed to console
          - Visibility: Public
        - Prototype: operator float*();
          - Description: returns pointer to beginning of mData array
          - Pre-Conditions: Matrix exists
          - Post-Conditions: float pointer returned
          - Visibility: Public
    - Name: Matrix4
      - Description: Contains the data and methods associated with Matrix4 and math invloving matrices
      - Base Class: N/A
      - Class Attributes
        - Name: xCol
          - Description: First vector. Contains first column
          - Type: Vector4
          - Range of Acceptable Values: a Vector4 of floats
        - Name: yCol
          - Description: Second vector. Contains second column
          - Type: Vector4
          - Range of Acceptable Values: a Vector4 of floats
        - Name: zCol
          - Description: Third vector. Contains third column
          - Type: Vector4
          - Range of Acceptable Values: a Vector4 of floats
        - Name: wCol
          - Description: Fourth vector. Contains fourth column
          - Type: Vector4
          - Range of Acceptable Values: a Vector4 of floats
        - Name: xRow
          - Description: Fifth vector. Contains first row
          - Type: Vector4
          - Range of Acceptable Values: a Vector4 of floats
        - Name: yRow
          - Description: Seventh vector. Contains second row
          - Type: Vector4
          - Range of Acceptable Values: a Vector4 of floats
        - Name: zRow
          - Description: Eighth vector. Contains third row
          - Type: Vector4
          - Range of Acceptable Values: a Vector4 of floats
        - Name: wRow
          - Description: Ninth vector. Contains fourth column
          - Type: Vector4
          - Range of Acceptable Values: a Vector4 of floats
        - Name: mData
          - Description: pointer to array of all data in vector
          - Type: float pointer
          - Range of Acceptable Values: address of floats
        - Name: data
          - Description: std::vector to contain all the data of the matrix. Column major.
          - Type: std::vector
          - Range of Acceptable Values: all floats
      - Class Operations
        - Prototype: Matrix4();
          - Description: default constructor for the Matrix
          - Pre-Conditions: Instance of a matrix is created
          - Post-Conditions: a matrix instance is initialized with default values of 0
          - Visibility: Public
        - Prototype: Matrix4(float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float);
          - Description: Constructor taking in sixteen floats
          - Pre-Conditions: Instance of a matrix is created
          - Post-Conditions: Instance of matrix is created with sixteen floats, in order
        - Prototype: ~Matrix4()
          - Description: destructor for matrix
          - Pre-Conditions: matrix is destroyed
          - Post-Conditions: memory used by matrix is freed up
          - Visibility: Public
        - Prototype: operator*(Matrix4);
          - Description: Multiplication overload for multiplying two matrices
          - Pre-Conditions: two matrices exist
          - Post-Conditions: returns a Matrix that is the product of the two involved
          - Visibility: Public
        - Prototype: operator[](int);
          - Description: overload to obtain the vector at a given index in the array
          - Pre-Conditions: matrix exists
          - Post-Conditions: returns a Vector4 in the array of the column at the index
          - Visibility: Public
        - Prototype: operator*(Vector4);
          - Description: multiply a matrix by a vector
          - Pre-Conditions: Matrix and vector exist
          - Post-Conditions: returns the product vector
          - Visibility: Public
        - Prototype: void setRotateX(float);
          - Description: set the rotation of the around X axis to the angle passed in
          - Pre-Conditions: Matrix exists
          - Post-Conditions: Matrix values are rotated
          - Visibility: Public
        - Prototype: operator*(Vector3);
          - Description: multiply a matrix by a vector
          - Pre-Conditions: Matrix and vector exist
          - Post-Conditions: returns the product vector
          - Visibility: Public
        - Prototype: refreshMat();
          - Description: Updates row vectors to match columns
          - Pre-Conditions: Math is done on matrix. This is called first in math functions to ensure row correctness
          - Post-Conditions: rows in matrix are up to date
          - Visibility: Public
        - Prototype: Print();
          - Description: prints the data in the matrix to the console
          - Pre-Conditions: Matrix exists
          - Post-Conditions: matrix data printed to console
          - Visibility: Public
        - Prototype: operator float*();
          - Description: returns pointer to beginning of mData array
          - Pre-Conditions: Matrix exists
          - Post-Conditions: float pointer returned
          - Visibility: Public

### Vector2.h
```
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
```

## Vector2.cpp
```
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
```

## Vector3.h
```
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
```

## Vector3.cpp
```
#include "Vector3.h"
#include <cmath>
#include <iostream>


Vector3::Vector3()
{
	xPos = 0;
	yPos = 0;
	zPos = 0;

	mData = new float[3] {xPos, yPos, zPos};
}


Vector3::~Vector3()
{
	
}

Vector3::Vector3(float x, float y, float z)
{
	xPos = x;
	yPos = y;
	zPos = z;

	mData = new float[3]{ xPos, yPos, zPos };
}

float Vector3::GetX()
{
	return xPos;
}

float Vector3::GetY()
{
	return yPos;
}

float Vector3::GetZ()
{
	return zPos;
}

void Vector3::SetX(float x)
{
	xPos = x;
	mData[0] = x;
}

void Vector3::SetY(float y)
{
	yPos = y;
	mData[1] = y;
}

void Vector3::SetZ(float z)
{
	zPos = z;
	mData[2] = z;
}

Vector3 Vector3::operator+(Vector3 & rhs)
{
	return Vector3(xPos + rhs.GetX(), yPos + rhs.GetY(), zPos + rhs.GetZ());
}

Vector3 Vector3::operator-(Vector3 & rhs)
{
	return Vector3(xPos - rhs.GetX(), yPos - rhs.GetY(), zPos - rhs.GetZ());
}

Vector3 Vector3::operator*(float rhs)
{
	return Vector3(xPos * rhs, yPos * rhs, zPos * rhs);
}

bool Vector3::operator==(Vector3 & rhs)
{
	return xPos == rhs.GetX() && yPos == rhs.GetY() && zPos == rhs.GetZ();
}

bool Vector3::operator!=(Vector3 & rhs)
{
	return xPos != rhs.GetX() || yPos != rhs.GetY() || zPos != rhs.GetZ();
}

float Vector3::operator[](int index)
{
	if (index == 0)
		return xPos;
	if (index == 1)
		return yPos;
	if (index == 2)
		return zPos;
	else
		std::cout << "Invalid Index" << std::endl;
		return 0.0f;
}

Vector3 Vector3::operator=(Vector3  rhs)
{
	this->SetX(rhs.GetX());
	this->SetY(rhs.GetY());
	this->SetZ(rhs.GetZ());

	return *this;
}

float Vector3::magnitude()
{
	return sqrt(pow(xPos, 2) + pow(yPos, 2) + pow(zPos, 2));
}

void Vector3::normalise()
{
	float mag = magnitude();

	Vector3 result(xPos / mag, yPos / mag, zPos / mag);
	*this = result;
}

float Vector3::dot(Vector3 other)
{
	return (GetX()*other.GetX() + GetY()*other.GetY() + GetZ()*other.GetZ()); 
}

Vector3 Vector3::cross(Vector3 other)
{
	float x = GetY()*other.GetZ() - GetZ()*other.GetY();
	float y = GetZ()*other.GetX() - GetX()*other.GetZ();
	float z = GetX()*other.GetY() - GetY()*other.GetX();
	return Vector3(x, y, z);
}

float Vector3::distance(Vector3 other)
{
	Vector3 temp = Vector3(xPos - other.GetX(), yPos - other.GetY(), zPos - other.GetZ());
	return temp.magnitude();
}

Vector3 operator*(float scalar, Vector3 & v)
{
	return v * scalar;;
}
```

## Vector4.h
```
#pragma once
class Vector4
{
private:
	float xPos;
	float yPos;
	float zPos;
	float wPos;

	float *mData;

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
	Vector4 operator*(float rhs);
	bool operator==(Vector4 &rhs);
	bool operator!=(Vector4 &rhs);

	Vector4 operator=(Vector4 rhs);
	friend Vector4 operator* (float scalar, Vector4& v);
	float operator[](int index);

	float magnitude();
	void normalise();

	float dot(Vector4 other);
	Vector4 cross(Vector4 other);

	float distance(Vector4 other);

	operator float*()
	{
		return mData;
	}
};
```

## Vector4.cpp
```
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
	mData[0] = x;
}

void Vector4::SetY(float y)
{
	yPos = y;
	mData[1] = y;
}

void Vector4::SetZ(float z)
{
	zPos = z;
	mData[2] = z;
}

void Vector4::SetW(float w)
{
	wPos = w;
	mData[3] = w;
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

Vector4 Vector4::operator=(Vector4  rhs)
{
	this->SetX(rhs.GetX());
	this->SetY(rhs.GetY());
	this->SetZ(rhs.GetZ());
	this->SetW(rhs.GetW());

	return *this;
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
```

## Matrix3.h
```
#pragma once
#include "Vector3.h"
#include <vector>

class Matrix3
{
private:
	Vector3 xCol;
	Vector3 yCol;
	Vector3 zCol;

	Vector3 xRow;
	Vector3 yRow;
	Vector3 zRow;

	std::vector<float> data;

	float *mData;


public:

	Matrix3();
	Matrix3(float x1, float x2, float x3, float y1, float y2, 
		float y3, float z1, float z2, float z3);
	
	~Matrix3();

	Matrix3 operator*(Matrix3& rhs);

	Vector3& operator[](int index);

	Vector3 operator*(Vector3& rhs);

	void setRotateX(float angle);
	void setRotateY(float angle);
	void setRotateZ(float angle);

	void refreshMat();

	void Print();

	operator float*()
	{

		return mData;
	}
};
```

## Matrix3.cpp
```
#include "Matrix4.h"
#include <iostream>


Matrix4::Matrix4()
{
	xCol, yCol, zCol, wCol, xRow, yRow, zRow, wRow = Vector4(0, 0, 0, 0);
	
	data = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	mData = new float[16] {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
}

Matrix4::Matrix4(float x1, float x2, float x3, float x4, 
	float y1, float y2, float y3, float y4, 
	float z1, float z2, float z3, float z4, 
	float w1, float w2, float w3, float w4)
{
	xCol = Vector4(x1, x2, x3, x4);
	yCol = Vector4(y1, y2, y3, y4);
	zCol = Vector4(z1, z2, z3, z4);
	wCol = Vector4(w1, w2, w3, w4);

	xRow = Vector4(x1, y1, z1, w1);
	yRow = Vector4(x2, y2, z2, w2);
	zRow = Vector4(x3, y3, z3, w3);
	wRow = Vector4(x4, y4, z4, w4);

	data = { x1, x2, x3, x4, y1, y2, y3, y4, z1, z2, z3, z4, w1, w2, w3, w4 };
	mData = new float[16] {x1, x2, x3, x4, y1, y2, y3, y4, z1, z2, z3, z4, w1, w2, w3, w4};
}


Matrix4::~Matrix4()
{
	
}

Matrix4 Matrix4::operator*(Matrix4 & rhs)
{
	refreshMat();
	float x1, x2, x3, x4, y1, y2, y3, y4, z1, z2, z3, z4, w1, w2, w3, w4;

	x1 = xRow.dot(rhs.xCol);
	x2 = yRow.dot(rhs.xCol);
	x3 = zRow.dot(rhs.xCol);
	x4 = wRow.dot(rhs.xCol);

	y1 = xRow.dot(rhs.yCol);
	y2 = yRow.dot(rhs.yCol);
	y3 = zRow.dot(rhs.yCol);
	y4 = wRow.dot(rhs.yCol);

	z1 = xRow.dot(rhs.zCol);
	z2 = yRow.dot(rhs.zCol);
	z3 = zRow.dot(rhs.zCol);
	z4 = wRow.dot(rhs.zCol);

	w1 = xRow.dot(rhs.wCol);
	w2 = yRow.dot(rhs.wCol);
	w3 = zRow.dot(rhs.wCol);
	w4 = wRow.dot(rhs.wCol);

	return Matrix4(x1, x2, x3, x4, y1, y2, y3, y4, z1, z2, z3, z4, w1, w2, w3, w4);
}

Vector4& Matrix4::operator[](int index)
{
	if (index == 0)
		return xCol;
	else if (index == 1)
		return yCol;
	else if (index == 2)
		return zCol;
	else if (index == 3)
		return wCol;
	else
		std::cout << "Invalid Index" << std::endl;
}

Vector4 Matrix4::operator*(Vector4 & rhs)
{
	refreshMat();

	return Vector4(xRow.dot(rhs), yRow.dot(rhs), zRow.dot(rhs), wRow.dot(rhs));
}

void Matrix4::setRotateX(float angle)
{
	refreshMat();
	Matrix4 rotate = { 1, 0, 0, 0, 0, cos(angle), sin(angle), 0, 0, -sin(angle),
		cos(angle), 0, data[12], data[13], data[14], 1 };

	*this = rotate;
}

void Matrix4::setRotateY(float angle)
{
	refreshMat();
	Matrix4 rotate = { cos(angle), 0, -sin(angle), 0, 0, 1, 0, 0, sin(angle), 0,
		cos(angle), 0, data[12], data[13], data[14], 1 };

	*this = rotate;
}

void Matrix4::setRotateZ(float angle)
{
	refreshMat();
	Matrix4 rotate = { cos(angle), sin(angle), 0, 0, -sin(angle), cos(angle), 0, 0, 0, 0,
		1, 0, data[12], data[13], data[14], 1 };

	*this = rotate;
}

void Matrix4::refreshMat()
{
	delete mData;
	mData = new float[19]{ xCol.GetX(), xCol.GetY(), xCol.GetZ(), xCol.GetW(),
		yCol.GetX(), yCol.GetY(), yCol.GetZ(), yCol.GetW(),
		zCol.GetX(), zCol.GetY(), zCol.GetZ(), zCol.GetW(),
		wCol.GetX(), wCol.GetY(), wCol.GetZ(), wCol.GetW()};

	xRow = Vector4(xCol.GetX(), yCol.GetX(), zCol.GetX(), wCol.GetX());
	yRow = Vector4(xCol.GetY(), yCol.GetY(), zCol.GetY(), wCol.GetY());
	zRow = Vector4(xCol.GetZ(), yCol.GetZ(), zCol.GetZ(), wCol.GetZ());
	wRow = Vector4(xCol.GetW(), yCol.GetW(), zCol.GetW(), wCol.GetW());
}

void Matrix4::Print()
{
	for (int i = 0; i < 16; i++)
	{
		std::cout << data[i] << " ";
	}
}
```