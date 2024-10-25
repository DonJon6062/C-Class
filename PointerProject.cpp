// PointerProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
using namespace std;

//assign value
int number;
int* intPointer = &number;

//declare and initialize a pointer
//int* intPointer = nullptr;

//declare functions
void Begin();
void Choice();
void showNumber();
void revealTrueValue();
void revealGeneratedValue();

int main()
{
    //start program
    Begin();
    //begin core loop
    Choice();
}

//intro and setup
static void Begin()
{
    cout << "Give me a number" << endl;
    cin >> number;
}

//state options
static void Choice() 
{
    int choice;
    //explain options
    cout << "What would you like to do? \n1. See the values of the number as you see it. \n2. See the values of the number as the computer sees it. \n3. Generate another number and see all of its info.\n4. End program." << endl;
    cin >> choice;
    if (choice == 1) 
    {
        showNumber();
    }
    if (choice == 2)
    {
        revealTrueValue();
    }
    if (choice == 3)
    {
        revealGeneratedValue();
    }
    if (choice == 4)
    {
        cout << "Thanks for trying this little program out!" << endl;
    }
    //catch misinputs
    else if (choice != 1&&choice != 2&&choice !=3&&choice!=4)
    {
        cout << "Please enter a valid choice.." << endl;
        Choice();
    }
}

//show regular value
static void showNumber()
{
    cout << " The number itself is  " << number << endl;
    cout << " The address is  " << *intPointer << endl;
    Choice();
}

//show the value ij the 'puter
static void revealTrueValue()
{
    cout << " The number itself is also  " << &number << endl;
    cout << " The number itself, as the pointer sees it, is  " << intPointer << endl;
    Choice();
}

//make a new value 
static void revealGeneratedValue()
{
    int holdValue = rand() % 200 + 1;
    number = holdValue;
    cout << " Let's see about this... \n The number is now " << number << endl;
    cout << " The number itself is also  " << &number << endl;
    cout << " The number itself, as the pointer sees it, is  " << intPointer << endl;
    cout << " The address is  " << *intPointer << endl;
    Choice();
}