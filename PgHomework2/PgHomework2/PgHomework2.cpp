/******************************************************************************************
**                                SAKARYA UNIVERSITY
**                    FACULTY OF COMPUTER AND INFORMATION SCIENCES
**                               COMPUTER ENGINEERING
**                           INTRODUCTION TO PROGRAMMING
**
**                          HOMEWORK NUMBER : 2
**                          STUDENT'S NAMES : ÝSMAÝL METE UCAR
**                          STUDENT'S NUMBERS : G201210051
**                          LESSON GROUP : 2C
*******************************************************************************************/
//Added required libraries.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <conio.h>
using namespace std;

HANDLE rainbow = GetStdHandle(STD_OUTPUT_HANDLE); //Added required function for colours to appear on the screen

enum COLOURS //Added required colour codes.
{
	LIGHTBLUE = 9,
	LIGHTGREEN = 10,
	LIGHTCYAN = 11,
	LIGHTRED = 12,
	LIGHTMAGENTA = 13,
	YELLOW = 14,
};

class Cell //Created variables for characters in cell class.
{
public:
	Cell()
	{}
	char letter;
	int colour;
	int number;
};

class Array //Created functions for processes in array class.
{
public:
	Array()
	{
		cellNumber = 0;
	}

	void characterAdd()
	{
		int furthest = 90, least = 65;
		int furthestColour = 14, leastColour = 9;

		COLOURS colour = COLOURS(rand() % (furthestColour - leastColour + 1) + leastColour); // Created function for find random color.
		cells[cellNumber] = Cell();
		cells[cellNumber].colour = colour;
		cells[cellNumber].letter = (char)(rand() % (furthest - least + 1)) + least; //Created function for find random letter.
		cells[cellNumber].number = (rand() % 9 )+1; //Created function for find random number.

			cout << "\nPrevious status" << endl;
			cellNumber;

			outPut();

			cout << "Next status" << endl;
			cellNumber++;
	}	

	void characterSubtract() // Added function for take out character.
	{
			cout << "\nPrevious status" << endl;
			cells[cellNumber];

			outPut();

			cout << "Next status" << endl;
			cells[--cellNumber];
	}

	void outPut() //Loop for create cells.
	{
		if (cellNumber == 50)
		{
			SetConsoleTextAttribute(rainbow, 12);
			cout << "Cannot add \a" << endl;
			cellNumber = 49;
			int main(); 
		}
		else if(cellNumber < 0)
		{
			SetConsoleTextAttribute(rainbow, 12);
			cout << " Cannot subtract \a " << endl;
			cellNumber = 0;
		}
		else
		{
			cout << "Cell number : " << cellNumber  << endl;
			cout << toplefthandcorner;

			for (int i = 0; i < cellNumber; i++)
			{
				cout << straight << straight << straight;

				if (cellNumber - 1 != i)
				{
					cout << chevrondown;
				}
				else
					cout << toprighthandcorner;
			}

			cout << endl;

			for (int i = 0; i < cellNumber; i++)
			{
				cout << vertical;
				SetConsoleTextAttribute(rainbow, cells[i].colour);
				cout << " " << cells[i].letter << " ";
				SetConsoleTextAttribute(rainbow, 15);
			}

			cout << vertical;
			cout << endl;

			for (int i = 0; i < cellNumber; i++)
			{
				cout << vertical;
				SetConsoleTextAttribute(rainbow, cells[i].colour);
				cout << " " << cells[i].number << " ";
				SetConsoleTextAttribute(rainbow, 15);
			}
			cout << vertical;
			cout << endl;
			cout << lowerlefthandcorner;
			for (int i = 0; i < cellNumber; i++)
			{
				cout << straight << straight << straight;
				if (cellNumber - 1 != i)
				{
					cout << chevronup;
				}
				else
					cout << bottomrighthandcorner;
			}
			cout << endl;
		}
	}

private:
	Cell cells[50]; //Created an array of cells with 50 elements.
	int cellNumber;
	char straight = 205;
	char toplefthandcorner = 201;
	char toprighthandcorner = 187;
	char vertical = 186;
	char chevrondown = 203;
	char lowerlefthandcorner = 200;
	char bottomrighthandcorner = 188;
	char chevronup = 202;
};

int main()
{
	int select;
	srand(time(0));
	Array* arrays = new Array(); //Created array object that holding address from array class.
	do
	{
		SetConsoleTextAttribute(rainbow, 15);
		cout << "Please select 	instruction" << endl; 
		cout << "1- Character add" << endl;
		cout << "2- Character subtract" << endl;
		cout << "3- Exit" << endl << "Select : ";
		cin >> select;
		switch (select)
		{
		case 1:
			arrays->characterAdd(); //Summoned character insertion function.
			arrays->outPut(); //Summoned print function.
			break;
		case 2:
			arrays->characterSubtract();
			arrays->outPut();
			break;
		case 3:
			delete arrays;
			system("pause");
			return 0;
		default:
			cout << "Plese choose one of options \a" << endl;
			break;
		}
	} while (select != 3);
		SetConsoleTextAttribute(rainbow, 15);
		return 0;
}


