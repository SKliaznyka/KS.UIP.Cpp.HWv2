// KS.UIP.Cpp.HWv2.PtrStringHeapTask00-2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Homework 06 v2. Task 00-2: Repeat Classes
//Init Array with 20 elements
//Range [-20, 20]
//Create Function, which output Address of the Last Negative number from Array

#include "pch.h"
#include <iostream>
#include <time.h>
#include <iomanip>

//FUNC Init:
void initOneDimmArray(int *pArray, int size);
void showOneDimmArray(int *pArray, int size);

int *getAddressLastNegativeFromArray(int *pArray, int size);

//MAIN:
int main()
{
	std::cout << "Homework 06 v2. Task 00-2: Repeat classes" << std::endl << std::endl;
	
	const int SIZE(20);
	int iArr[SIZE] = { 0 };
	
	initOneDimmArray(iArr, SIZE);
	showOneDimmArray(iArr, SIZE);

	int *pLastNegativeNumber = getAddressLastNegativeFromArray(iArr, SIZE);
	if (pLastNegativeNumber == nullptr)
	{
		std::cout << "Array does not contain Negatives";
	}
	else
	{
		std::cout << "Last Negative Address:\t" << pLastNegativeNumber << std::endl;
		std::cout << "Last Negative Number:\t" << *pLastNegativeNumber << std::endl;
		std::cout << std::endl;
	}
	
	return 0;
}


//FUNC Body:
void initOneDimmArray(int *pArray, int size)
{
	srand(time(0));
	for (int i = 0; i < size; i++)
	{
		pArray[i] = rand() % 41 - 20;
	}
	//pArray[0] = -10;
}

void showOneDimmArray(int *pArray, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << pArray[i] << "\t";
	}
	std::cout << std::endl << std::endl;
}

int *getAddressLastNegativeFromArray(int *pArray, int size)
{
	int *pLastNegative(nullptr);
	for (int i = size - 1; i >= 0; i--)
	{
		if (pArray[i] < 0)
		{
			pLastNegative = pArray + i;
			break;
		}
	}
	return pLastNegative;
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
