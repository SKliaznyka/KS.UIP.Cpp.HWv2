// KS.UIP.Cpp.HWv2.PtrStringHeapTask02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Homework 06 v2. Task02.
//Create "Init Array". Size / way of creation - whatever you want!
//Create Function which:
// - returns address of Element = 0 from Init Array;


#include "pch.h"
#include <iostream>
#include <time.h>
#include <iomanip>

//FUNC Init:
int getArrSizeFromUser();
int *initOneDimArrDynamic(int *pArray, int size);
void showOneDimArr(int *pArray, int size);
int *getAddrFirstZeroFromArr(int *pArray, int size);

//MAIN:
int main()
{
	std::cout << "Homework 06 v2. Task 01: Dynamic Array by Rule(s):" << std::endl;
	int *pArr(nullptr);
	int iInitArrSize = getArrSizeFromUser();
	
	pArr = initOneDimArrDynamic(pArr, iInitArrSize);
	showOneDimArr(pArr, iInitArrSize);
	
	int *pFirstZeroAddress = getAddrFirstZeroFromArr(pArr, iInitArrSize);
	if (pFirstZeroAddress != nullptr)
	{
		std::cout << "First Array Zero-Element Address is:\t" << pFirstZeroAddress << std::endl;
	}
	else
	{
		std::cout << "Array does not contain Any Zero-Number" << std::endl << std::endl;
	}

	if (pArr != nullptr)
	{
		delete[]pArr;
	}
	std::cout << "Memory Leak = \t" << _CrtDumpMemoryLeaks() << std::endl;
	return 0; 
}

//FUNC Body:
int getArrSizeFromUser()
{
	int arrSize(0);
	std::cout << "Input SIZE of Initial Array:\t";
	std::cin >> arrSize;
	std::cout << std::endl;

	return arrSize;
}

int *initOneDimArrDynamic(int *pArray, int size)
{
	srand(time(0));
	int *pInitArray = new int[size];
	
	for (int i = 0; i < size; i++)
	{
		pInitArray[i] = rand() % 21 - 20;
	}

	return pInitArray;
}

void showOneDimArr(int *pArray, int size)
{
	std::cout << "Array:" << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cout << std::setw(3) << pArray[i] << " ";
	}
	std::cout << std::endl << std::endl;
}

int *getAddrFirstZeroFromArr(int *pArray, int size)
{
	int *pFirstZeroAddr(nullptr);
	for (int i = 0; i < size; i++)
	{
		if (pArray[i] == 0)
		{
			pFirstZeroAddr = pArray + i;
			break;
		}
	}
	return pFirstZeroAddr;
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
