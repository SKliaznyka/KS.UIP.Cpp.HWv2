// KS.UIP.Cpp.HWv2.HW09.RecursionTask02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Homework 09 v2. Task 01.
//Recursion.
//Create Recursion Function:
//Exponentiation of the Number.
//Number Init: User input.
//Exponent Init: User input.


#include "pch.h"
#include <iostream>

int exponentNumber(int number, int expstart, int expfinish);

int main()
{
	std::cout << "Homework 09 v2. Task 02. Exponent the number." << std::endl << std::endl;
	
	int nNum(0);
	int nExp(0);
	std::cout << "Input a Number:\t";
	std::cin >> nNum;
	std::cout << std::endl;
	std::cout << "Input an Exponent:\t";
	std::cin >> nExp;
	std::cout << std::endl;

	std::cout << nNum << " ^ " << nExp << " = " << exponentNumber(nNum, 0, nExp - 1);
	
	return 0; 
}


int exponentNumber(int number, int expstart, int expfinish)
{
	for (int i = 0; i < expfinish; ++i)
	{
		if (expstart == expfinish)
		{
			return number;
		}
		return number * exponentNumber(number, )
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
