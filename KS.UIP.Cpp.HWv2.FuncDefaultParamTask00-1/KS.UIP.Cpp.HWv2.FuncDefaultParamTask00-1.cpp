// KS.UIP.Cpp.HWv2.FuncDefaultParamTask00-1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Homework 08 v02. Task 01.
//Create Function which output rectangle.
//Function should use parameters "by default".
//Function parameters: (length, width, XShift, YShift, '*', ' ')
//DEFAULTs:  length = 6; width = 4; XShift = 0; YShift = 0; * - contour, ' ' - fill.
//Prompt user input all of these parameters. In case of not input, use DEFAULTs.

#include "pch.h"
#include <iostream>
#include <time.h>
#include <iomanip>

//FUNC Init:
void drawDescription();
void initParameters(int &length, int &width, int &xShift, int &yShift, 
	char &contour, char &fill);
void myRectangle(int length = 6, int width = 4, int xShift = 0, int yShift = 0,
	char contour = '*', char fill = ' ');

//MAIN:
int main()
{
	std::cout << "Homework 08 v02. Task 01. Draw a Rectangle." << std::endl << std::endl;
	
	drawDescription();
	
	int iLen(0), iWid(0);
	int iXshift(0), iYshift(0);
	char cCont(' '), cFill(' ');
	
	//initParameters(iLen, iWid, iXshift, iYshift, cCont, cFill);
	
	//INIT
	std::cout << "input Rectangle Length (0 - by default):\t";
	std::cin >> iLen;
	std::cout << "input Rectangle Width (0 - by default):\t";
	std::cin >> iWid;
	std::cout << "input Rectangle X-shift Position (0 - by default):\t";
	std::cin >> iXshift;
	std::cout << "input Rectangle Y-shift Position (0 - by default):\t";
	std::cin >> iYshift;
	std::cout << "input Rectangle Contour-symbol (0 - by default):\t";
	std::cin >> cCont;
	std::cout << "input Rectangle Fill-symbol (0 - by default):\t";
	std::cin >> cFill;

	myRectangle(iLen, iWid, iXshift, iYshift, cCont, cFill);
	

	/*std::cout << "iLen:\t" <<iLen << std::endl;
	std::cout << "iWid:\t" << iWid << std::endl;
	std::cout << "iXshift:\t" << iXshift << std::endl;
	std::cout << "iYshift:\t" << iYshift << std::endl;
	std::cout << "cCont:\t" << cCont << std::endl;
	std::cout << "cFill:\t" << cFill << std::endl;*/

	return 0; 
}

//FUNC Body:
void drawDescription()
{
	std::cout << "DESCRIPTION:" << std::endl;
	std::cout << "Build a rectangle under DEFAULT pattern depicted below:" << std::endl;
	std::cout << "******" << std::endl;
	std::cout << "*    *" << std::endl;
	std::cout << "*    *" << std::endl;
	std::cout << "******" << std::endl;
	std::cout << "Parameters by Default:" << std::endl;
	std::cout << "length = 6; width = 4; XShift = 0; YShift = 0; * - contour, ' ' - fill" <<
		std::endl << std::endl;
	std::cout << "User would prompted to change any Default parameter." << std::endl;
	std::cout << "----------------------------------------------------" << std::endl << std::endl;
}

void initParameters(int &length, int &width, int &xShift, int &yShift,
	char &contour, char &fill)
{
	std::cout << "input Rectangle Length (0 - skip):\t";
	std::cin >> length;
	std::cout << "input Rectangle Width (0 - skip):\t";
	std::cin >> width;
	std::cout << "input Rectangle X-shift Position (0 - skip):\t";
	std::cin >> xShift;
	std::cout << "input Rectangle Y-shift Position (0 - skip):\t";
	std::cin >> yShift;
	std::cout << "input Rectangle Contour-symbol (0 - skip):\t";
	std::cin >> contour;
	std::cout << "input Rectangle Fill-symbol (0 - skip):\t";
	std::cin >> fill;
}

void myRectangle(int length, int width, int xShift, int yShift,
	char contour, char fill)
{
	
	int xMaxShift = xShift + length;
	for (int i = 0; i < yShift; ++i)
	{
		std::cout << std::endl;
	}
	
	for (int i = 0; i < width; ++i)
	{
		for (int j = xShift; j < xMaxShift; ++j)
		{
			if ((i == 0 || i == width - 1) || (j == xShift || j == xMaxShift - 1))
			{
				std::cout << contour << std::setw(3) << ' ';
			}
			else
			{
				std::cout << fill << std::setw(3) << ' ';
			}
		}
		std::cout << std::endl;
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
