#include <iostream>
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix3.h"
#include "Matrix4.h"



int main()
{
	Matrix3 ID = { 1, 0, 0, 0, 1, 0, 5, 5, 1 };
	Matrix3 RandT = { 0, 1, 0, -1, 0, 0, 0 , 0, 1 };

	Matrix3 New = ID * RandT;

	ID.Print();

	std::cout << std::endl;

	RandT.Print();

	std::cout << std::endl;

	New.Print();

	std::cout << std::endl;

	Vector3 test = New[0];

	system("pause");

}