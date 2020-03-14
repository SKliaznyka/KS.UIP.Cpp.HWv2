// KS.UIP.Cpp.HWv2.PtrStringHeapTask03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Homework 06. Task 03. Char.
//Input Name by User.
//Check if Name started with nonCapital.
//Make the first Letter Capital.
//Show result.


#include "pch.h"
#include <iostream>

//FUNC Init:
void inputName(char name[]);
void changeFirstLetter(char name[]);
void showName(char name[]);

char *inName(char *pNam);

//MAIN:
int main()
{
	std::cout << "Homework 06 v2. Task 03: Check 1st Letter:" << std::endl;

	char cName[50];

	inputName(cName);
	changeFirstLetter(cName);
	showName(cName);
	

	char *pName(nullptr);
	pName = inName(pName);
	std::cout << "Name1:\t" << pName << std::endl;
	return 0; 
}

//FUNC Body:
void inputName(char name[])
{
	std::cout << "input name:\t";
	std::cin >> name;
	std::cout << std::endl << std::endl;
}

void changeFirstLetter(char name[])
{
	if (name[0] >= 97)
	{
		name[0] = name[0] - 32;
	}
}

void showName(char name[])
{
	std::cout << "Name:\t" << name << std::endl << std::endl;
}



char *inName(char *pNam)
{
	char name[50];
	std::cout << "input name:\t";
	std::cin >> name;

	char *pN = new char[strlen(name)];
	return pN;
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
