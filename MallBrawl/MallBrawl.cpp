// MallBrawl.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include <algorithm>
#include <vector>
#include <random>
#include <ctime>
#include "Units.h"
using namespace std;

#pragma region Classes
class Unit
{
public:
	//constructor with all of the important features units will need
	Unit(string name, int health, int maxHealth, int attack, int defense, int accuracy) {}

	void Intro(string name, int health, int maxHealth)
	{
		//give player all necescarry info
		cout << name << endl;
		cout << health << " / " << maxHealth << " HP" << endl;
	}
};

//high atk, low accuracy enemy. glass cannon 
class Blitz :public Unit
{
public:
	Blitz(string name, int health, int maxHealth, int attack, int defense, int accuracy) :Unit(name, health, maxHealth, attack, defense, accuracy)
	{
	}
#pragma region UtilityFunctions
	double rollDamage()
	{
		//roll damage and state it
		double lower_bound = .85;
		double upper_bound = 1;

		uniform_real_distribution<double> unif(lower_bound, upper_bound);

		default_random_engine rand;

		double damageRoll = unif(rand);

		return damageRoll;
	}

	//generate random number as a check for whether or not a move hits
	int rollHitChance()
	{
		//never less than one, never more than move hit chance
		int hitChance = rand() % (100 + 1) + 1;
		return hitChance;
	}

	//accuracy reduction code
	double accuracyRedution(double accuracy)
	{
		double reduction = accuracy / 6;
		accuracy -= reduction;
		return reduction;
	}

	//recoil; the damage these powerful attacks do to this unit
	int recoil(int moveDamage)
	{
		int recoilDamage = moveDamage / 3;
		cout << recoilDamage << " is the recoil damage sustained from such a reckless attack!\n" << endl;
		return recoilDamage;
	}
#pragma endregion
#pragma region Attacks
	int headbutt(int attack, int opponentDefense)
	{
		//just try to calculate damage with formula and have it pass
		int power = 20;

		//adjust damage value for randomness
		double damageRoll = rollDamage();

		//calculate true damage
		int trueAttack = attack / opponentDefense;

		//make final value
		int headbuttDamage = power * trueAttack;
		int finalDMG = damageRoll * headbuttDamage;
		//cout << headbuttDamage << " is the headbutt damage!\n" << endl;
		return finalDMG;
	}

	int recklessRam(int attack, int opponentDefense)
	{
		//just try to calculate damage with formula and have it pass
		int power = 30;

		//adjust damage value for randomness
		double damageRoll = rollDamage();

		//calculate true damage
		int trueAttack = attack / opponentDefense;
		//cout << trueAttack << " is the true attack!\n" << endl;

		//make final value
		int ramDamage = power * trueAttack;
		int finalDMG = damageRoll * ramDamage;
		//cout << ramDamage << " is the Reckless Ram damage!\n" << endl;
		return finalDMG;
	}
#pragma endregion
};

//basic player unit
class Player : public Unit
{
public:
	Player(string name, int health, int maxHealth, int attack, int defense, int accuracy) : Unit(name, health, maxHealth, attack, defense, accuracy)
	{
	}
#pragma region UtilityFunctions
	double rollDamage()
	{
		//roll damage and state it
		double lower_bound = .85;
		double upper_bound = 1;

		uniform_real_distribution<double> unif(lower_bound, upper_bound);

		default_random_engine rand;

		double damageRoll = unif(rand);

		return damageRoll;
	}

	//accuracy reduction code
	double accuracyRedution(double accuracy)
	{
		double reduction = accuracy / 6;
		accuracy -= reduction;
		return reduction;
	}
#pragma endregion
#pragma region Attacks
	int punch(int attack, int opponentDefense)
	{
		//just try to calculate damage with formula and have it pass
		int power = 15;

		//adjust damage value for randomness
		double damageRoll = rollDamage();

		//calculate true damage
		int trueAttack = attack / opponentDefense;

		//make final value
		int punchDamage = power * trueAttack;
		int finalDMG = damageRoll * punchDamage;
		//cout << headbuttDamage << " is the headbutt damage!\n" << endl;
		return finalDMG;
	}

	int pocketSand(int attack, int opponentDefense)
	{
		//just try to calculate damage with formula and have it pass
		int power = 10;

		//adjust damage value for randomness
		double damageRoll = rollDamage();

		//calculate true damage
		int trueAttack = attack / opponentDefense;

		//make final value
		int pocketSandDamage = power * trueAttack;
		int finalDMG = damageRoll * pocketSandDamage;
		//cout << headbuttDamage << " is the headbutt damage!\n" << endl;
		return finalDMG;
	}
#pragma endregion
};

#pragma endregion


//generate random number as a check for whether or not a move hits
int rollHitChance()
{
	srand(time(0));
	//never less than one, never more than move hit chance
	int hitChance = rand() % (100 + 1) + 1;
	return hitChance;
}

#pragma region Variables
//roll hit chance
int hitNum = rollHitChance();

//all vars required
string name;
int health;
int maxHealth;
int attack;
int defense;
int accuracy; 
int speed;

//player vars
string playerName = "Player";
int playerHealth = 1000;
int playerMaxHealth = 1000;
int playerAttack = 10;
int playerDefense = 15;
int playerAccuracy = 100;

unique_ptr<Player> player(new Player(playerName, playerHealth, playerMaxHealth, playerAttack, playerDefense, playerAccuracy));
#pragma endregion



#pragma region Arenas
void firstBattle();

void firstBattle()
{
	//variables for later options
	int playerChoice;
	int attackChoice;

	srand(time(0));

	//enemy blitz vars
	int blitzHealth = 70;
	int blitzMaxHealth = 70;
	int blitzAttack = 30;
	int blitzDefense = 5;
	int blitzAccuracy = 50;//move accuracy instead of overall accuracy

	//vars used for this function; only exist here
	unique_ptr<Blitz> zip(new Blitz("Zip", blitzHealth, blitzMaxHealth, blitzAttack, blitzDefense, blitzAccuracy));

	cout << "Encountered an enemy!" << endl;
	while (true)
	{
		if(playerHealth > 0)
		{
			int enemyChoice = 0;
			player->Intro(playerName, playerHealth, playerMaxHealth);
			cout << "What would you like to do?\n" << endl;
			//display active foes
			if (blitzHealth > 0)
			{
				zip->Intro("Zip", blitzHealth, blitzMaxHealth);
			}
			cout << "1. Attack\n2. Item" << endl;
			cin >> playerChoice;
			if (playerChoice == 1)
			{
				//implement turn system (player first)
				cout << "Which attack?\n1. Punch\n2. Pocket Sand" << endl;
				cin >> attackChoice;
				//punch
				if (attackChoice == 1)
				{
					//hit or miss
					bool moveHits = getMax(hitNum, playerAccuracy);
					if (true)
					{
						//get amount done and relay to player
						int damageDone = player->punch(playerAttack, blitzDefense);
						blitzHealth -= damageDone;
						cout << damageDone << " damage from your punch!\n" << endl;
					}
					else
					{
						cout << "You missed!\n" << endl;
					}
				}
				else if (attackChoice == 2)
				{
					//hit or miss
					bool moveHits = getMax(hitNum, playerAccuracy);
					if (moveHits == true)
					{
						//get amount done and relay to player
						int damageDone = player->pocketSand(playerAttack, blitzDefense);
						blitzHealth -= damageDone;
						int accuracyReduced = zip->accuracyRedution(blitzAccuracy);
						blitzAccuracy -= accuracyReduced;
						cout << damageDone << " damage taken from your pocket sand!" << endl;
						cout << blitzAccuracy << " is Zip's current accuarcy!\n" << endl;
					}
					else
					{
						cout << "You missed!\n" << endl;
					}
				}
				else
				{
					cerr << "That's an invalid input..." << endl;
					firstBattle();
				}
				bool moveHits = getMax(hitNum, blitzAccuracy);
				if(moveHits == true)
				{
					int moveSelected = rand() % (2) + 1;
					if (moveSelected == 1)
					{
						int damageOverall = zip->recklessRam(blitzAttack, playerDefense);
						cout << damageOverall << " damage done by Zip's Reckless Ram!\n" << endl;
						playerHealth -= damageOverall;
						blitzHealth -= zip->recoil(damageOverall);
					}
					else
					{
						int damageOverall = zip->headbutt(blitzAttack, playerDefense);
						cout << damageOverall << " damage done by Zip's Headbutt!!\n" << endl;
						playerHealth -= damageOverall;
						blitzHealth -= zip->recoil(damageOverall);
					}
				}
				else
				{
					cout << "The Zip missed!\n" << endl;
				}
			}
			else if (playerChoice == 2)
			{
				cout << "Sorry, no items!" << endl;
				firstBattle();
			}
			else
			{
				cerr << "That's an invalid input..." << endl;
				firstBattle();
			}
			//wincondition
			if (blitzHealth < 0)
			{
				player->Intro(playerName, playerHealth, playerMaxHealth);
				zip->Intro("Zip", blitzHealth, blitzMaxHealth);
				cout << "You win!\n" << endl;
				break;
			}
		}
		//lose condition
		else
		{
			cout << "You lost!\n" << endl;
			break;
		}
	}
}
#pragma endregion


int main()
{
	firstBattle();
}
