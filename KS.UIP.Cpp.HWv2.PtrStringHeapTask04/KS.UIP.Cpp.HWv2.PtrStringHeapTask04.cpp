// KS.UIP.Cpp.HWv2.PtrStringHeapTask04.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Homework 06. Task 04. Char.
//Input Word by User.
//Check how many Vovels.
//Show result.

#include "pch.h"
#include <iostream>

//FUNC Init:
void inputWord(char word[]);
int countVovels(char word[]);
void showVovelNumber(char word[]);

//MAIN:
int main()
{
	std::cout << "Homework 06 v2. Task 04: Counting Vovels in word:" << std::endl;

	char cWord[50];

	inputWord(cWord);
	showVovelNumber(cWord);

	return 0;
}


//FUNC Body:
void inputWord(char word[])
{
	std::cout << "input Word:\t";
	std::cin >> word;
	std::cout << std::endl << std::endl;
}

int countVovels(char word[])
{
	int lengthWord = strlen(word);
	int counter(0);
	for (int i = 0; i < lengthWord; i++)
	{
		if (word[i] >= 97)
		{
			if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' ||
				word[i] == 'j' || word[i] == 'o' || word[i] == 'u' || word[i] == 'y')
			{
				++counter;
			}
		}
		else
		{
			if (word[i] == 'A' || word[i] == 'E' || word[i] == 'I' ||
				word[i] == 'J' || word[i] == 'O' || word[i] == 'U' || word[i] == 'Y')
			{
				++counter;
			}
		}
	}
	
	return counter;
}

void showVovelNumber(char word[])
{
	int vovelsNumber = countVovels(word);
	std::cout << "Number of vovels =\t" << vovelsNumber << std::endl << std::endl;
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
