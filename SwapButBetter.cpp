// SwapButBetter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;
//first data type, interger
void modifyValue(int* a, int*b);

void modifyValue(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
//second data type, string
void modifyWord(string* a, string* b);

void modifyWord(string* a, string* b)
{
    string temp = *a;
    *a = *b;
    *b = temp;
}



int main()
{
    //for selections
    int choice;
    int secondChoice;
    char playAgain;
    //var ints
    int numUn;
    int numDeux;
    //var strings
    string first; 
    string second;

    while (true)
    {
        //first prompt
        cout << "Enter a number." << endl;
        cin >> numUn;
        //second prompt
        cout << "Enter another number." << endl;
        cin >> numDeux;
        cout << "You entered " << numUn << " and " << numDeux <<  endl;
        cout << "Would you like to see something cool?" << endl;
        cout << "Press 1." << endl;
        cin >> choice;
        if (choice == 1)
        {
            //swap em
            modifyValue(&numUn, &numDeux);
            cout << "Now the first value is " << numUn << endl;
            cout << "And the second value is " << numDeux << endl;
        }
        else
        {
            while (choice != 1)
            {
                cout << "Please cooperate. Press number 1, as displayed on your keyboard." << endl;
                cin >> choice;
                if (choice == 1)
                {
                    modifyValue(&numUn, &numDeux);
                    cout << "Now the first value is " << numUn << endl;
                    cout << "And the second value is " << numDeux << endl;
                }
            }
        }
        //string prompt
        cout << "Enter a color." << endl;
        cin >> first;
        //second string prompt
        cout << "Enter a shape." << endl;
        cin >> second;
        cout << "You entered " << first << " and " << second << endl;
        cout << "One more time!" << endl;
        cout << "Press 1." << endl;
        cin >> secondChoice;
        if (secondChoice == 1)
        {
            //swap words
            modifyWord(&first, &second);
            cout << "Now the first value is " << first << endl;
            cout << "And the second value is " << second << endl;
        }
        else
        {
            while (secondChoice != 1)
            {
                cout << "Please cooperate. Press number 1, as displayed on your keyboard." << endl;
                cin >> secondChoice;
                if (secondChoice == 1)
                {
                    modifyWord(&first, &second);
                    cout << "Now the first value is " << first << endl;
                    cout << "And the second value is " << second << endl;
                }
            }
        }
        //replay check
        cout << "Do it again? Y or N." << endl;
        cin >> playAgain;
        if (playAgain == 'N')
        {
            break;
        }
        else if (playAgain == 'n')
        {
            break;
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
