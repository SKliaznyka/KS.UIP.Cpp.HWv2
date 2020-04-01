// KS.UIP.Cpp.HWv2.HW09.RecursionTask01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Homework 09 v2. Task 01.
//Recursion.
//Create Recursion Function:
//Summ of Array elements.
//Array Init: Random.



#include "pch.h"
#include <iostream>
#include <time.h>
#include <iomanip>

//FUNC Init:
void initArray(int *pArr, int size);
void showArray(int *pArr, int size);
int summArrayElements(int *pArr, int begin, int end);

//MAIN:
int main()
{
	const int SIZE(5);
	int pArray[SIZE] = { 0 };
	
	initArray(pArray, SIZE);
	showArray(pArray, SIZE);
	std::cout << "Summ of all Array elements:\t";
	std::cout << summArrayElements(pArray, 0, SIZE - 1) << std::endl;
	return 0; 
}

//FUNC Body:
void initArray(int *pArr, int size)
{
	srand(time(0));
	for (int i = 0; i < size; ++i)
	{
		pArr[i] = rand() % 21;
	}
}

void showArray(int *pArr, int size)
{
	std::cout << "Array:" << std::endl;
	for (int i = 0; i < size; ++i)
	{
		std::cout << std::setw(3) << pArr[i] << ' ';
	}
	std::cout << std::endl << std::endl;
}

int summArrayElements(int *pArr, int begin, int end)
{
	if (begin == end)
	{
		return pArr[begin];
	}
	return pArr[begin] + summArrayElements(pArr, begin + 1, end);
}