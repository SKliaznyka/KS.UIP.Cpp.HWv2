// KS.UIP.Cpp.HWv2.StructuresTask06.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Homework 08 v2. Task 06. Structures.
//Create Shooter Structure.
//Structure contain data: 
// - shot coordinate X, Y;
// - shooter names.
//Show all shooters and their shot results
//Shot rule: X and Y - Random init method: -10...10.
//Sort all Shooters in Alphabet direction (from A to Z).
//Show sorted results.

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
void sortShooterListAlphabetAZ(Shooter parr[], int size);   //Used: BubbleSort


//MAIN:
int main()
{
	const int SIZE = 10;

	Shooter shooters[SIZE];

	initShooterResults(shooters, SIZE);
	showShooterList(shooters, SIZE);
	
	sortShooterListAlphabetAZ(shooters, SIZE);
	std::cout << "Shooters arranged in Alphabet order [A - to - Z]:" << std::endl;
	showShooterList(shooters, SIZE);

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

void sortShooterListAlphabetAZ(Shooter parr[], int size)
{
	Shooter tempShooter[1];
	for (int i = 1; i < size; ++i)
	{
		tempShooter[0] = parr[i];
		for (int j = 0; j < i; ++j)
		{
			if (strcmp(parr[j].m_ShooterName, parr[i].m_ShooterName) > 0)
			{
				parr[i] = parr[j];
				parr[j] = tempShooter[0];
				tempShooter[0] = parr[i];
			}
		}
	}

}