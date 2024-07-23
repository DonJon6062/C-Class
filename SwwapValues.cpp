// SwwapValues.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

//the cash in both accounts
int bankOfTerror = 10000;
int joesCoffee = 13;


void checkBalances();
void mockTransfer();

void swap(int a, int b);

void swap(int a, int b) 
{
    int temp = a;
    a = b;
    b = temp;

    cout << "Now the coffee shop has $" << a << endl;
    cout << "And the Bank of Terror has a mere $" << b << endl;
}

void checkBalances() 
{
    cout << "The terrorists are planning to transfer $" << bankOfTerror << endl;
    cout << "That great coffee shop has a mere $" << joesCoffee << endl;
}

void mockTransfer() 
{
    int* bankAmount = &bankOfTerror;
    int* coffeeShopAmount = &joesCoffee;

    cout << "If the transfer goes successfully, then.. "<< endl;
    cout << "The bank would recieve it all, $" << *bankAmount << endl;
    cout << "That great coffee shop has a mere $" << *coffeeShopAmount << endl;
}


int main()
{
    int choice;
    int secondChoice;
    char playAgain;

    int a = 13;
    int b = 10000;
    
    while (true) 
    {
        cout << "Time to do something important! First let's see the bank accounts..." << endl;
        cout << "Press 1 to do so." << endl;
        cin >> choice;
        if (choice == 1) 
        {
            checkBalances();
        }
        else 
        {
            while (choice != 1) 
            {
                cout << "Please cooperate. Press number 1, as displayed on your keyboard." << endl;
                cin >> choice;
                if (choice == 1)
                {
                    checkBalances();
                }
            }
        }
        cout << "And if things go as planned, " << endl;
        mockTransfer();
        cout << "Luckily, we're hackers." << endl;
        cout << "Press 1 to intercept." << endl;
        cin >> secondChoice;
        if (secondChoice == 1)
        {
            swap(a,b);
        }
        else
        {
            while (secondChoice != 1)
            {
                cout << "Please cooperate. Press number 1, as displayed on your keyboard." << endl;
                cin >> secondChoice;
                if (secondChoice == 1)
                {
                    swap(a,b);
                }
            }
        }

        cout << "Relive the hack? Y or N." << endl;
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
