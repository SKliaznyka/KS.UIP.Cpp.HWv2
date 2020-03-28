// KS.UIP.Cpp.HWv2.StructuresTask04.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Homework 08 v2. Task 04. Structures.


#include "pch.h"
#include <iostream>
#include <time.h>

//STRUCT Init:
struct Point
{
	double m_x;
	double m_y;
};

struct Circle
{
	unsigned int m_radius;
	Point m_center;
};

//FUNC Init:
void initArray(Point parr[], int size);
void showArray(Point parr[], int size);
void showShootArray(Point parr[], int size, int radius);
void showInTargetShots(Point parr[], int size, int radius);

//MAIN:
int main()
{
	const int SIZE = 10;
	const int RADIUS = 5;
	Point points[SIZE];


	initArray(points, SIZE);
	showArray(points, SIZE);
	showShootArray(points, SIZE, RADIUS);
	showInTargetShots(points, SIZE, RADIUS);

	return 0; 
}

//FUNC Body:
void initArray(Point parr[], int size)
{
	srand(time(0));
	for (int i = 0; i < size; ++i)
	{
		parr[i].m_x = rand() % 21 - 10;
		parr[i].m_y = rand() % 21 - 10;
	}
}

void showArray(Point parr[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << "x = " << parr[i].m_x << "  y = " << parr[i].m_y << std::endl;
	}
	std::cout << std::endl;
}

void showShootArray(Point parr[], int size, int radius)
{
	std::cout << "Successful shots:" << std::endl;
	for (int i = 0; i < size; ++i)
	{
		if ((radius*radius) > (parr[i].m_x*parr[i].m_x + parr[i].m_y*parr[i].m_y))
		{
			std::cout << "x = " << parr[i].m_x << "\t" << "y = " << parr[i].m_y << std::endl;
		}
	}
	std::cout << std::endl;
}

void showInTargetShots(Point parr[], int size, int radius)
{
	int count(0);
	for (int i = 0; i < size; ++i)
	{
		if ((radius*radius) > (parr[i].m_x*parr[i].m_x + parr[i].m_y*parr[i].m_y))
		{
			++count;
		}
	}
	std::cout << "Number of successful shot(s):\t" << count << std::endl << std::endl;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
