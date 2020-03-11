// KS.UIP.Cpp.HWv2.PtrStringHeapTask 00-3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Homework 06 v2. Task 00-3: Repeat Classes.
//Heap. Dynamic Arrays.
//Create Array. 20 elements. [-20, 20].
//Create Function(s):
//- all Negatives put into new Dynamically Allocating Array.
//- return Array Address [address of 1st element of new array].
//- return Number of Negatives in Array.

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <time.h>

//FUNC Init:
void initOneDimArr(int *pArray, int size);
void showOneDimArr(int *pArray, int size);

int countNegativesInArr(int *pArray, int size);

int *getArrWithNegatives(int *pArray, int size);


//MAIN:
int main()
{
	std::cout << "Homework 06 v2. Task 00-3: Dynamically Allocating Arrays:" << std::endl;

	int iSize(0);
	std::cout << "Enter the Array Length:\t";
	std::cin >> iSize;
	int *pArr = new int[iSize];

	initOneDimArr(pArr, iSize);
	showOneDimArr(pArr, iSize);
	
	int iNegatives = countNegativesInArr(pArr, iSize);
	std::cout << "Number of Negatives = \t" << iNegatives << std::endl << std::endl;

	int *pNewArrWithNeg = getArrWithNegatives(pArr, iSize);
	if (pNewArrWithNeg != nullptr)
	{
		showOneDimArr(pNewArrWithNeg, iNegatives);
	}
	else
	{
		std::cout << "There are No Negatives in init Array" << std::endl << std::endl;
	}
	std::cout << "New Array Address:\t" << pNewArrWithNeg << std::endl << std::endl;

	if (pNewArrWithNeg != nullptr)
	{
		delete[]pNewArrWithNeg;
	}
	delete[]pArr;
	return 0; 
}

//FUNC Body:
void initOneDimArr(int *pArray, int size)
{
	srand(time(0));
	for (int i = 0; i < size; i++)
	{
		pArray[i] = rand() % 41 - 20;
	}
}

void showOneDimArr(int *pArray, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << pArray[i] << "\t";
	}
	std::cout << std::endl << std::endl;
}

int countNegativesInArr(int *pArray, int size)
{
	int iCountNegative(0);
	for (int i = 0; i < size; i++)
	{
		(pArray[i] < 0) ? (++iCountNegative) : (iCountNegative);
	}
	return iCountNegative;
}

int *getArrWithNegatives(int *pArray, int size)
{
	int *pNewArr(nullptr);
	int NewArrSize = countNegativesInArr(pArray, size);
	int NewCount(0);
	if (NewArrSize > 0)
	{
		pNewArr = new int[NewArrSize];
		for (int i = 0; i < size; i++)
		{
			if (pArray[i] < 0)
			{
				pNewArr[NewCount] = pArray[i];
				++NewCount;
			}
		}
	}

	return pNewArr;
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
