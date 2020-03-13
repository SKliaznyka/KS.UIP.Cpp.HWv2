// KS.UIP.Cpp.HWv2.PtrStringHeapTask01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Homework 06 v2. Task01.
//Create "Init Array". Size / way of creation - whatever you want!
//Create Function which create dynamically-alocating Array by Rule(s):
// - put elements >5 from "Init Array";
// - put event elements >5 from "Init Array";
// - use both options.

#include "pch.h"
#include <iostream>
#include <time.h>
#include <iomanip>

//FUNC Init:
int *initOneDimArrDynamic(int *pArray, int &size);
void showOneDimArr(int *pArray, int size);
int getRuleNumberFromUser();
void showRule(int ruleNumber);
int getNumberEvenGreaterThanInput(int *pArray, int size, int ruleNumber);
int *createOneDimDynamicArrByRule(int *pArray, int &size, int ruleNumber);


//MAIN:
int main()
{
	std::cout << "Homework 06 v2. Task 01: Dynamic Array by Rule(s):" << std::endl;
	
	int *pArr(nullptr);
	int iSize(0);
	pArr = initOneDimArrDynamic(pArr, iSize);
	showOneDimArr(pArr, iSize);
	
	int iRuleNumber = getRuleNumberFromUser();
	showRule(iRuleNumber);
	int *pArrByRule(nullptr);
	pArrByRule = createOneDimDynamicArrByRule(pArr, iSize, iRuleNumber);
	
	if (iSize > 0)
	{
		showOneDimArr(pArrByRule, iSize);
	}
	else
	{
		std::cout << "There are No Elements matches the RULE" << std::endl << std::endl;
	}
	
	delete[] pArr;
	delete[] pArrByRule;
	std::cout << "Memory Leak = \t" << _CrtDumpMemoryLeaks() << std::endl;

	return 0;
}

//FUNC Body:
int *initOneDimArrDynamic(int *pArray, int &size)
{
	srand(time(0));
	
	int iInputSize(0);
	std::cout << "Input SIZE of Initial Array:\t";
	std::cin >> iInputSize;
	std::cout << std::endl;

	int *pInitArray = new int[iInputSize];
	for (int i = 0; i < iInputSize; i++)
	{
		pInitArray[i] = rand() % 21;
	}
	
	size = iInputSize;
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

int getRuleNumberFromUser()
{
	int inputUserNumber(0);
	std::cout << "Input Number for the RULE:\t";
	std::cin >> inputUserNumber;
	std::cout << std::endl;

	return inputUserNumber;
}

void showRule(int ruleNumber)
{
	std::cout << "RULE: New array Must contain EVEN elements which >\t" << ruleNumber;
	std::cout << std::endl << std::endl;
}

int getNumberEvenGreaterThanInput(int *pArray, int size, int ruleNumber)
{
	int iNewSize(0);

	for (int i = 0; i < size; i++)
	{
		if (pArray[i] > ruleNumber && (pArray[i] % 2) == 0)
		{
			++iNewSize;
		}
	}
	return iNewSize;
}

int *createOneDimDynamicArrByRule(int *pArray, int &size, int ruleNumber)
{
	int iSizeByRule = getNumberEvenGreaterThanInput(pArray, size, ruleNumber);
	int *pArrayByRule = new int[iSizeByRule];
	int ind(0);
	for (int i = 0; i < size; i++)
	{
		if (pArray[i] > ruleNumber && (pArray[i] % 2) == 0)
		{
			pArrayByRule[ind++] = pArray[i];
		}
	}

	size = iSizeByRule;
	return pArrayByRule;
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
