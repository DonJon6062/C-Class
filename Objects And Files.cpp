// Objects And Files.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//
#include <iostream>
#include <windows.h>
#include <fstream>
#include "FunctionsAndObjects.h"

using namespace std;

int main()
{
    cout << "Let's watch some animals today.\n";
    while (true)
    {
        cout << "Pick a random animal to watch by choosing a number between 1 and 10!\n";
        cout << "Enter 13 to exit!\n";

        int selectAnimal;
        cin >> selectAnimal;
        if (selectAnimal == 1)
        {
            watchOstrich();
        }
        if (selectAnimal == 2)
        {
            watchCrane();
        }
        if (selectAnimal == 3)
        {
            watchPenguin();
        }
        if (selectAnimal == 4)
        {
            watchChicken();
        }
        if (selectAnimal == 5)
        {
            watchKiwi();
        }
        if (selectAnimal == 6)
        {
            watchMantis();
        }
        if (selectAnimal == 7)
        {
            watchSnail();
        }
        if (selectAnimal == 8)
        {
            watchWeevil();
        }
        if (selectAnimal == 9)
        {
            watchMillipede();
        }
        if (selectAnimal == 10)
        {
            watchWasp();
        }
        if (selectAnimal == 13)
        {
            break;
        }
        else
        {
            while (selectAnimal >= 0 || selectAnimal <= 11)
            {
                cout << "Please pick a number between 1 and 10\n";
                int selectAnimal;
                cin >> selectAnimal;
                if (selectAnimal == 1)
                {
                    watchOstrich();
                }
                if (selectAnimal == 2)
                {
                    watchCrane();
                }
                if (selectAnimal == 3)
                {
                    watchPenguin();
                }
                if (selectAnimal == 4)
                {
                    watchChicken();
                }
                if (selectAnimal == 5)
                {
                    watchKiwi();
                }
                if (selectAnimal == 6)
                {
                    watchMantis();
                }
                if (selectAnimal == 7)
                {
                    watchSnail();
                }
                if (selectAnimal == 8)
                {
                    watchWeevil();
                }
                if (selectAnimal == 9)
                {
                    watchMillipede();
                }
                if (selectAnimal == 10)
                {
                    watchWasp();
                }
                if (selectAnimal == 13)
                {
                    break;
                }
            }
        }
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
