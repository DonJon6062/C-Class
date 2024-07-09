// BetterFiles.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int choice;
    ofstream createdFile; //output

    while (true) //lifetime
    {
        cout << "What would you like to do?" << endl;
        cout << "1. Edit the file." << endl;
        cout << "2. Read the file." << endl;
        cout << "3. Start over." << endl;
        cout << "4. Stop the program." << endl;
        cin >> choice;
        if (choice == 1)
        {
            cout << "Alrighty!" << endl;

            ofstream createdFile("newCreation.txt", ios::app);
            if (!createdFile.is_open())
            {
                cout << "Sorry! There's some issue opening the file!" << endl;
                break;
            }
            char arr[100];
            cin >> arr;
            cin.getline(arr, 100);
            createdFile << arr;
            createdFile.close();
        }
        else if (choice == 2)
        {
            cout << "Here's what it says!" << endl;
            ifstream createdFile("newCreation.txt");

            string s;
            while (!createdFile.eof()) 
            {
                createdFile >> s;
                cout << s << endl;
            }
            createdFile.close();
        }
        else if (choice == 3)
        {
            ifstream obj("newCreation.txt");
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            cout << "Please use one of the outlined number choices." << endl;
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
