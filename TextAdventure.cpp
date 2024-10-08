// TextAdventure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include <fstream>
#include "Header.h"
using namespace std;

int main()
{
	//variable used to see if the game will be played again
	char again;

	while (true) //due to a 'while' loop being used, the 'play again' question has to be within main()
	{
		while (outOfTime > 0) //makes sure the player has more than one charge
		{
			beginning(); //start the game with the intro
		}
		//restart code
		cout << "Play again? Y or N" << endl;
		cin >> again;
		if (again == 'N')
		{
			//stop loop
			break;
		}
		if (again == 'n')
		{
			//stop loop
			break;
		}
		else if (again == 'Y')
		{
			//reset the booleans for all days; set charges to 3
			outOfTime = 3;
			day1 = false;
			day2 = false;
			day3 = false;
			day4 = false;
			day5 = false;
			day6 = false;
			day7 = false;
		}
		else if (again == 'y')
		{
			//reset the booleans for all days; set charges to 3
			outOfTime = 3;
			day1 = false;
			day2 = false;
			day3 = false;
			day4 = false;
			day5 = false;
			day6 = false;
			day7 = false;
		}
		else
		{
			//tells user what to do
			cout << "Please use Y or N!" << endl;
		}
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
// .... .- .--. .--. -.-- / -.. . -.-. --- -.. .. -. --.
// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
