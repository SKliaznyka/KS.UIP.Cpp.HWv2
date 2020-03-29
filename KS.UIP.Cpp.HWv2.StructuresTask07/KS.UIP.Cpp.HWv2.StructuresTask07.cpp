// KS.UIP.Cpp.HWv2.StructuresTask07.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Homework 08 v2. Task 07. Structures.
//Create Shooter Structure.
//Structure contain data: 
// - shot coordinate X, Y;
// - shooter names.
//Show all shooters and their shot results
//Shot rule: X and Y - Random init method: -10...10.
//Sort all Shooters in direction of "from Best shot Result towards Worst" 
//(first - Shooter whose shot was closer to Target center).
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
	double m_absresult;
};


//FUNC Init:
void initShooterResults(Shooter parr[], int size);
void showShooterList(Shooter parr[], int size);
void calcShotAbsResult(Shooter parr[], int size);
void sortShooterListByBestShot(Shooter parr[], int size);   //Used: BubbleSort


//MAIN:
int main()
{
	const int SIZE = 10;

	Shooter shooters[SIZE];

	initShooterResults(shooters, SIZE);
	showShooterList(shooters, SIZE);

	calcShotAbsResult(shooters, SIZE);
	sortShooterListByBestShot(shooters, SIZE);

	std::cout << "Shooters arranged in 'Best Shot Order':" << std::endl;
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

void calcShotAbsResult(Shooter parr[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		parr[i].m_absresult = parr[i].m_x * parr[i].m_x + parr[i].m_y * parr[i].m_y;
	}
}

void sortShooterListByBestShot(Shooter parr[], int size)
{
	Shooter tempShooter[1];
	for (int i = 1; i < size; ++i)
	{
		tempShooter[0] = parr[i];
		for (int j = 0; j < i; ++j)
		{
			if (parr[j].m_absresult > parr[i].m_absresult)
			{
				parr[i] = parr[j];
				parr[j] = tempShooter[0];
				tempShooter[0] = parr[i];
			}
		}
	}

}