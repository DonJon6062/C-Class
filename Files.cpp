// Files.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include<string>
using namespace std;

int main()
{
	int choice;
	//ofstream createdFile; //output
	//writing to text files
	string line;
	ifstream infile; /*("example.txt");*/
	ofstream outfile; /*("output.txt");*/

	try 
	{
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

				ofstream outfile("newCreation.txt", ios::app);
				if (!outfile.is_open())
				{
					throw runtime_error("Error: Unable to access output file!");
					break;
				}
				else 
				{
					string writing;
					cin >> writing;
					outfile << writing;
					outfile.close();
				}
			}
			else if (choice == 2)
			{
				cout << "Here's what it says!" << endl;
				ifstream infile("newCreation.txt");

				string reading;
				while (!infile.eof())
				{
					infile >> reading;
					cout << reading << endl;
				}
				infile.close();
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
				throw runtime_error("Error: Please use one of the numbered choices!");
				break;
			}
		}
	}
	catch (const runtime_error& e)
	{
		cerr << e.what() << endl;
	}
	catch (const ifstream::failure)
	{
		cerr << "An file handling error has occured..." << endl;
	}
	catch (...) 
	{
		cerr << "An unexpected error has occured..." << endl;
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
