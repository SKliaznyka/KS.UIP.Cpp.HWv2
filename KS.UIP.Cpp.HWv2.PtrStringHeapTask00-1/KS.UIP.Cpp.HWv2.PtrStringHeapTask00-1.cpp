//HomeWork 06v2. Task 00-1.
//Classwork: repetition of studied


#include "pch.h"
#include <iostream>

int main()
{
	std::cout << "Block 1 ______________________" << std::endl;
	int nNumber(17);
	std::cout << "&nNumber = \t" << &nNumber << std::endl;
	std::cout << "nNumber = \t" << nNumber << std::endl << std::endl;

	std::cout << "Block 2 ______________________" << std::endl;
	int &rRef = nNumber;
	rRef += 10;
	std::cout << "rRef = \t" << rRef << std::endl;
	std::cout << "&rRef = \t" << &rRef << std::endl;
	std::cout << "nNumber = \t" << nNumber << std::endl << std::endl;

	std::cout << "Block 3 ______________________" << std::endl;
	int *pNum;
	pNum = nullptr;
	if (pNum == nullptr)
	{
		pNum = &nNumber;
	}
	std::cout << "*pNum = \t" << *pNum << std::endl;
	if (pNum != nullptr)
	{
		*pNum = 100;
	}
	std::cout << "*pNum = \t" << *pNum << std::endl;
	std::cout << "pNum = \t" << pNum << std::endl << std::endl;

	std::cout << "Block 4 ______________________" << std::endl;
	pNum = &rRef;
	std::cout << "*pNum = \t" << *pNum << std::endl;
	std::cout << "pNum = \t" << pNum << std::endl << std::endl;

	std::cout << "Block 5 ______________________" << std::endl;
	int *pPointer = &rRef;
	*pPointer = 100;
	std::cout << "*pPointer = \t" << *pPointer << std::endl;
	std::cout << "pPointer = \t" << pPointer << std::endl;
	std::cout << "rRef = \t" << rRef << std::endl << std::endl;

	return 0;
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
