// KS.UIP.Cpp.HWv2.StructuresTask05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Homework 08 v2. Task 05. Structures.
//Create Shooter Structure.
//Structure of 10 shooters.
//Structure contain data: 
// - shot coordinate X, Y;
// - shooter names.
//Show all shooters and their shot results.
//Shot rule: X and Y - Random init method: -10...10.
//Ask user input letter. Show shooters which names starts on input letter.

#include "pch.h"
#include <iostream>
#include <time.h>

//STRUCT Init:
struct Shooter
{
	char m_ShooterName[25];
	double m_x;
	double m_y;
};


//FUNC Init:
void initShooterResults(Shooter parr[], int size);
void showShooterList(Shooter parr[], int size);
void showShooterListByInputLetter(Shooter parr[], int size);

//MAIN:
int main()
{
	const int SIZE = 10;

	Shooter shooters[SIZE];
	initShooterResults(shooters, SIZE);
	showShooterList(shooters, SIZE);
	showShooterListByInputLetter(shooters, SIZE);
	
	return 0;
}

//FUNC Body:
void initShooterResults(Shooter parr[], int size)
{
	const int NAMES = 10;
	const char *arr[NAMES] = { "Ivanov", "Petrov", "Eliseev", "Egorov",
		"Sergeev", "Sidorov", "Anisim", "Pavlov", "Kovalev", "Andreev" };
	int ind(0);

	for (int i = 0; i < size; ++i)
	{
		strcpy_s(parr[i].m_ShooterName, 30, arr[i]);
		parr[i].m_x = rand() % 21 - 10;
		parr[i].m_y = rand() % 21 - 10;
	}

}

void showShooterList(Shooter parr[], int size)
{
	std::cout << "Shooters List and their shot results:" << std::endl;
	std::cout << "-------------------------------------" << std::endl;
	for (int i = 0; i < size; ++i)
	{
		std::cout << parr[i].m_ShooterName << "\t\t" <<
			"x = " << parr[i].m_x << "  y = " << parr[i].m_y << std::endl;
	}
	std::cout << "-------------------------------------" << std::endl << std::endl;
}

void showShooterListByInputLetter(Shooter parr[], int size)
{
	char letter(' ');
	std::cout << "Input 1st Letter from shooter name:\t";
	std::cin >> letter;
	std::cout << std::endl;
	int FirstLetter(0);
	int InputCode = letter;
	int CountLetterMatches(0);

	std::cout << "Search results for Names starts on '" << letter << "' - letter:" << std::endl;
	for (int i = 0; i < size; ++i)
	{
		FirstLetter = parr[i].m_ShooterName[0];
		if (InputCode >= 65 && InputCode <= 90 && FirstLetter == InputCode)
		{
			std::cout << parr[i].m_ShooterName << "\t" <<
				"x = " << parr[i].m_x << "  y = " << parr[i].m_y << std::endl;
			++CountLetterMatches;
		}
		else if (InputCode >= 97 && InputCode <= 122 && FirstLetter == InputCode - 32)
		{
			std::cout << parr[i].m_ShooterName << "\t" <<
				"x = " << parr[i].m_x << "  y = " << parr[i].m_y << std::endl;
			++CountLetterMatches;
		}
	}
	if (CountLetterMatches == 0)
	{
		std::cout << "No such name started on input letter: " << letter << std::endl << std::endl;
	}
}