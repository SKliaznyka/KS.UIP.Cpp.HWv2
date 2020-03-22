// KS.UIP.Cpp.HWv2.PtrStringHeapTask05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Homework 06 v2. Task 05. Array.
//Init 2-Dimm Square Array. Method: Random.
//Array size: by CONST (= 10).
//Sort array. 
//Output New Array, which built by spiral with increasing elements from Init Array.
//Show results.


#include "pch.h"
#include <iostream>
#include <time.h>
#include <iomanip>

const int SIZE(4);

//FUNC Init:
void initArr(int iArr[][SIZE], int size);
void showArr(int iArr[][SIZE], int size);
void insertionSortUpward(int iArr[][SIZE], int size);



//MAIN:
int main()
{
	std::cout << "Homework 06 v2. Task 05: Array by Spiral:" << std::endl << std::endl;
	
	int iArray[SIZE][SIZE] = { 0 };
	initArr(iArray, SIZE);
	std::cout << "init array:" << std::endl;
	showArr(iArray, SIZE);

	insertionSortUpward(iArray, SIZE);
	std::cout << "sorted upward array:" << std::endl;
	showArr(iArray, SIZE);
	
	

	return 0; 
}

//FUNC Body:
void initArr(int iArr[][SIZE], int size)
{
	srand(time(0));
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			iArr[i][j] = rand() % 31 - 5;
		}
	}
}

void showArr(int iArr[][SIZE], int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			std::cout << std::setw(3) << iArr[i][j] << ' ';
		}
		std::cout << std::endl;
	}
	std::cout << "------------------------------------" << std::endl << std::endl;
}

void insertionSortUpward(int iArr[][SIZE], int size)
{
	int iNext(0), iCurrent(0);
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			iNext = iArr[i][j];
			for (int iRaw = i; iRaw >= 0; --iRaw)
			{
				for (int iCol = j - 1; iCol >= 0; --iCol)
				{
					iCurrent = iArr[iRaw][iCol];
					if (iCurrent > iNext)
					{
						iArr[iRaw][iCol] = iNext;
						if (iCol != size - 1)
						{
							iArr[iRaw][iCol + 1] = iCurrent;
							iNext = iArr[iRaw][iCol];
						}
						else
						{
							iArr[iRaw + 1][0] = iCurrent;
							iNext = iArr[iRaw][iCol];
						}
					}
				}
			}
		}
	}

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
