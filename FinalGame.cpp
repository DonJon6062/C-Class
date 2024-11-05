// FinalGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include <random>
using namespace std;

class Enemy
{
public:
	Enemy(int health,int damage)
	{
	
	}
	//pass damage via this code
	int attackPlayer(int damage) 
	{
		int damageDone = rand() % (damage + 1) + 1;
		damage = damageDone;
		cout << damage << " HP lost!" << endl;
		return damage;
	}
};

class Basic
{
public:
	Basic(float health, float damage)
	{}
};

class Fighter : public Basic 
{
public:
	//constructor
	Fighter(float health, float damage) : Basic(health, damage)
	{}
};

class Nemesis: public Basic
{
public:
	//you will test accuracy
	Nemesis(float health, float damage, double accuracy) : Basic(health, damage)
	{}

	//pass damage via this code
	int attackPlayer(int damage)
	{
		int damageDone = rand() % (damage + 1) + 1;
		damage = damageDone;
		cout << damage << " HP lost!" << endl;
		return damage;
	}

#pragma region accuracy
	//accuracy reduction code
	double pocketSand(double accuracy)
	{
		double reduction = accuracy / 6;
		accuracy -= reduction;
		cout << accuracy << " accuracy remains!" << endl;
		return reduction;
	}

	//generate random number as a check for whether or not a move hits
	int rollHitChance()
	{
		//never less than one, never more than move hit chance
		int hitChance = rand() % (100 + 1) + 1;
		return hitChance;
	}

	//see if the move hits
	double hitChance(bool hitOrMiss, double accuracy)
	{
		//set variable, get a random hit chance
		int hitChance = rollHitChance();

		cout << hitChance << " hit chance!" << endl;

		cout << hitOrMiss << " boolean!" << endl;

		//if accuracy is high enough to match hit chance, the move hits
		if (hitChance <= accuracy)
		{
			hitOrMiss = true;
			cout << hitOrMiss << " boolean!" << endl;
			cout << accuracy << " accuracy remains!" << endl;
			return accuracy;
		}
		//if accuracy doesn't pass the check, the move fails
		else if (hitChance > accuracy)
		{
			hitOrMiss = false;
			cout << hitOrMiss << " boolean!" << endl;
			cout << accuracy << " accuracy remains!" << endl;
			cout << "Missed!" << endl;
			return accuracy;
		}
	}
#pragma endregion
};

int main()
{
#pragma region Variables
	int test;

	//player stats
	float fighterHealth = 100;
	float fighterDamage = 10;

	//better enemy stats
	float haterHealth = 100;
	float haterDamage = 10;
	float haterAccuracy = 100;
	//bool for hits/misses
	bool hitOrMiss = false;

	//better enemy stats
	float nemesisHealth = 50;
	float nemesisDamage = 15;
	float nemesisAccuracy = 75;

	//better enemy stats
	float foeHealth = 200;
	float foeDamage = 5;
	float foeAccuracy = 50;

	//set enemy stats
	int enemyHP = 50;
	int enemyDamage = 5;
#pragma endregion
#pragma region Classes
	//test player char
	Basic punchy(fighterHealth, fighterDamage);
	//test acc char
	unique_ptr<Nemesis> hater(new Nemesis(haterHealth, haterDamage, haterAccuracy));

	Enemy puncha(enemyHP, enemyDamage);

	unique_ptr<Nemesis> nemesis(new Nemesis(nemesisHealth,nemesisDamage, nemesisAccuracy));

	unique_ptr<Nemesis> foe(new Nemesis(foeHealth, foeDamage, foeAccuracy));
#pragma endregion
	while (true)
	{
		cout << "To test, press 1" << endl;
		cin >> test;
		if (test == 1)
		{
			//fighterHealth -= nemesis->attackPlayer(haterDamage);
			//cout << fighterHealth << " HP remains!" << endl;

			nemesisAccuracy -= nemesis->pocketSand(nemesisAccuracy);
			cout << "nemesis accuracy ^" << endl;
			
			foeAccuracy -= foe->pocketSand(foeAccuracy);
			cout << "foe accuracy ^" << endl;

			//reduce accuracy
			haterAccuracy -= hater->pocketSand(haterAccuracy);

			//check to see if move hits then attack
			hater->hitChance(hitOrMiss, haterAccuracy);
			
			if (hitOrMiss = false)
			{
				cout << "The hater's move misses." << endl;
			}
			else if (hitOrMiss = true)
			{
				//re-enable when it stops giving false positive
				//fighterHealth -= hater.attackPlayer(haterDamage);
				//cout << fighterHealth << " HP remains!" << endl;
				
				cout << "The move hit!" << endl;
			}
			else
			{
				cout << "Something isn't right..." << endl;
			}
		}
		else 
		{
			break;
		}
	}

#pragma region FirstDraft
	//First Draft
	// 
	//int attack;
	////set player stats
	//int characterHP = 100;
	//int characterDamage = 10;

	////set enemy stats
	//int enemyHP = 50;
	//int enemyDamage = 5;


	////to have fluid hp, while true, check hps, if both are above 0 give results 
	//while (characterHP > 0 && enemyHP > 0)
	//{
	//	cout << "(Press '1' to attack!) " << endl;
	//	cin >> attack;
	//	if (attack == 1)
	//	{
	//		//make chars
	//		Unit character("Peach", characterHP, characterDamage);
	//		Enemy werewolf(enemyHP,enemyDamage);
	//		int maxEnemyHP = enemyHP;

	//		//trying out another damage formula
	//		

	//		//roll player damage
	//		int damageDealt = rand() % (characterDamage + 1) + 5;
	//		characterDamage = damageDealt;
	//		
	//		//roll enemy damage
	//		int damageDone = rand() % (enemyDamage + 1) + 1;
	//		enemyDamage = damageDone;
	//		
	//		//readjust HP(s)
	//		characterHP = characterHP -= damageDone;
	//		cout << characterHP << " points of health remain! " << endl;
	//		enemyHP = enemyHP -= damageDealt;
	//		cout << enemyHP << "/" << maxEnemyHP << " is left! " << endl;

	//		cout << " " << endl;
	//	}
	//	else if (attack != 1 && attack != 2)
	//	{
	//		cout << "Don't just stand there!" << endl;
	//		cin >> attack;
	//		cout << " " << endl;
	//	}
	//	else 
	//	{
	//		cerr << "This is an unexpected reaction. " << endl;
	//	}
	//}
	//if (enemyHP <= 0)
	//{
	//	cout << "You win!" << endl;
	//}
	//else if (characterHP <= 0)
	//{
	//	cout << "You lose!" << endl;
	//}
#pragma endregion
}

void printPtr();

void printPtr()
{
	cout << foe->pocketSand(foeAccuracy); << endl;
}

//Requirements

//Step one: get these to function (easy)
//Opening screen with a description of the application and instructions <intro and title>
//Menu for the user to choose options <main loop>
//At least 4 classes total <unit and three types>
//
//Inheritance(minimum 2 derived classes) <three unit types>
//Polymorphism(Overloading and overriding) <inherited units do this>
//Encapsulation <hp and damage are complex systems, but in the end, you know you've taken damage and have less health>
//Abstraction <_>
//
//Recursion <base loop; while hps are above zero keep the game going>
//Exception handling <throw error; cerr>

//Step two: get this to work (moderate, put your back into it)
//File input and output processing <save/load?>
//Vectors <with save file>

//Multi - Threading <_>
//Templates <_>

//Iterators <_>
