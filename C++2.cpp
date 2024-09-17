// C++2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

bool GameOn = true;

class Character
{
private: //abstraction, shows only important info
	int health;
public:	
	void displayAttack(int health)
	{
		cout << "Placeholder." << endl;
	}
};

class Ninja : public Character 
{
private: 
	int health = 5;
public:
	void displayAttack(int health)
	{
		cout << "Throwing shurikens!" << endl;
		cout << "Your enemy took damage!" << endl;
		health -= 1;
		if (health == 0) 
		{
			GameOn = false;
		}
	}
};

class Pirate : public Character 
{
private: 
	int health = 5;
public:
	void displayAttack(int health)
	{
		cout << "Slashing cutlass!" << endl;
		cout << "Your enemy took damage!" << endl;
		health -= 1;
		if (health == 0)
		{
			GameOn = false;
		}
	}

};

int main()
{
	int choice;
	int attack;
	int health = 5;

	Pirate pirateCharacter;
	Ninja ninjaCharacter;

	if(GameOn = true)
	{
		cout << "Greetings. Please try this combat simulation." << endl;
		cout << "Would you like to be a pirate or a ninja?" << endl;
		cout << "1.Pirate, 2.Ninja" << endl;
		cin >> choice;
		if (choice == 1)
		{
			cout << "Yaargh! Yer now a pirate!" << endl;
		}
		else if (choice == 2)
		{
			cout << "Hai. You are now a ninja." << endl;
		}
		else
		{
			cout << "Please use a valid number choice." << endl;
			cout << "1.Pirate, 2.Ninja" << endl;
			cin >> choice;
		}
		while (health > 0) 
		{
			cout << "Use 1 to attack!" << endl;
			cin >> attack;
			if (attack == 1)
			{
				if (choice == 1)
				{
					pirateCharacter.displayAttack(health);
					health -= 1;
				}
				else if (choice == 2)
				{
					ninjaCharacter.displayAttack(health);
					health -= 1;
				}
			}
			while (attack != 1)
			{
				cout << "Please, this is a combat simulation. Try out your weapon." << endl;
				cin >> attack;
			}
		}
		cout << "You won!" << endl;
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
