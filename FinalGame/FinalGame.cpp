// FinalGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include <algorithm>
#include <vector>
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

	//accuracy reduction code
	double pocketSand(double accuracy)
	{
		double reduction = accuracy / 6;
		accuracy -= reduction;
		cout << accuracy << " accuracy remains!" << endl;
		return reduction;
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

	void Intro(string Name, float health, int maxHealth)
	{
		cout << Name << endl;
		cout << health << " / " << maxHealth << " HP" << endl;
		//add atk, def, etc
	}
	
	double rollDamage()
	{
		//roll damage and state it
		double lower_bound = .85;
		double upper_bound = 1;

		uniform_real_distribution<double> unif(lower_bound, upper_bound);

		default_random_engine rand;

		double damageRoll = unif(rand);
		cout << damageRoll << " is the attack damage percent!\n" << endl;

		return damageRoll;
	}

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
		cout << accuracy << " accuracy remains!\n" << endl;
		return reduction;
	}

	//generate random number as a check for whether or not a move hits
	int rollHitChance()
	{
		//never less than one, never more than move hit chance
		int hitChance = rand() % (100 + 1) + 1;
		return hitChance;
	}
#pragma endregion
#pragma region Moves
	//if accuracy makes the move hit, determine damage done
	//test move power and accuracy
	int blindingStew(int damage, int opponentDefense)
	{
		//10 dmg, 50 % chance to reduce accuracy of enemy by one stage
		int power = 10;

		//50/50, no more than 2, no less than 1
		int reductionChance = rand() % (2) + 1;
		cout << reductionChance << " rolled! Should it blind?\n" << endl;

		if (reductionChance == 1)
		{
			//roll damage percent and state it
			double damageRoll = rollDamage();
			int damageDone = damage * damageRoll;
			damage = damageDone;
			cout << damage << " rolled! I sure hope it's random!\n" << endl;

			//division time
			int trueAttack = damage / opponentDefense;
			cout << trueAttack << " is the true attack!\n" << endl;

			//calculate damage to be done
			int blindingStewDamage = power * trueAttack;
			cout << blindingStewDamage << " damage calculated!" << endl;
			return blindingStewDamage;
			
			//implement secondary effect later
		}
		else
		{
			//roll damage percent and state it
			double damageRoll = rollDamage();
			int damageDone = damage * damageRoll;
			damage = damageDone;
			cout << damage << " rolled! I sure hope it's random!\n" << endl;

			//division time
			int trueAttack = damage / opponentDefense;
			cout << trueAttack << " is the true attack!\n" << endl;

			//calculate damage to be done
			int blindingStewDamage = power * trueAttack;
			cout << blindingStewDamage << " damage calculated!" << endl;
			return blindingStewDamage;
		}
	}

	int headbutt(float damage, float opponentDefense)
	{
		//just try to calculate damage with formula and have it pass
		int power = 30;

		//adjust damage value for randomness
		double damageRoll = rollDamage();
		int damageDone = damage * damageRoll;
		damage = damageDone;
		cout << damage << " rolled! I sure hope it's random!\n" << endl;

		//calculate true damage
		int trueAttack = damage / opponentDefense;
		cout << trueAttack << " is the true attack!\n" << endl;

		//make final value
		int headbuttDamage = power * trueAttack;
		cout << headbuttDamage << " is the headbutt damage!\n" << endl;
		return headbuttDamage;
	}
#pragma endregion
};

#pragma region Variables
int test;

//player stats
float fighterHealth = 100;
float fighterDamage = 10;
int fighterDefense = 5;

//better enemy stats
int haterMaxHealth = 100;
float haterHealth = 100;
float haterDamage = 10;
float haterAccuracy = 100;
float haterDefense = 5;

//better enemy stats, test player now
int nemesisMaxHealth = 500;
float nemesisHealth = 500;
float nemesisDamage = 25;
float nemesisAccuracy = 100;
float nemesisDefense = 5;

//better enemy stats
int foeMaxHealth = 200;
float foeHealth = 200;
float foeDamage = 5;
float foeAccuracy = 50;
float foeDefense = 5;

//set enemy stats
int enemyHP = 50;
int enemyDamage = 5;
#pragma endregion

#pragma region Classes
//test player char
Basic punchy(fighterHealth, fighterDamage);

Enemy puncha(enemyHP, enemyDamage);

//test acc char
unique_ptr<Nemesis> hater(new Nemesis(haterHealth, haterDamage, haterAccuracy));

unique_ptr<Nemesis> nemesis(new Nemesis(nemesisHealth, nemesisDamage, nemesisAccuracy));

unique_ptr<Nemesis> foe(new Nemesis(foeHealth, foeDamage, foeAccuracy));
#pragma endregion

#pragma region Stages
void testBattle();
#pragma endregion

#pragma region TestBattle
void testBattle()
{
	int Choices;
	int enemyChoice;
	int attackChoice;

	//vector to manage active units
	vector<unique_ptr<Nemesis>> vectorForUnits;
	//vectorForUnits.push_back(foe);
	//vectorForUnits.push_back(hater);

	//vector<float> vec = { foeHealth, nemesisHealth, haterHealth };
	//(sizeof(vec) != 1)
	cout << "\nEncountered two enemies!" << endl;

	//while foes and hero are alive
	//while enemyhp < 0


	while (foeHealth > 0 && haterHealth > 0)
	{
		if(nemesisHealth > 0)
		{

			cout << "What would you like to do?" << endl;
			//display foes
			foe->Intro("Jeff", foeHealth, foeMaxHealth);
			hater->Intro("Stephen", haterHealth, haterMaxHealth);

			//give options, player's turn
			cout << "1. Attack" << endl;
			cout << "2. Item" << endl;
			//input/output
			cin >> Choices;
			if (Choices == 1)
			{
				cout << "Which enemy?" << endl;
				//give options
				cout << "1. Jeff" << endl;
				cout << "2. Stephen" << endl;
				//input/output
				cin >> enemyChoice;
				if (enemyChoice == 1)
				{
					cout << "Which attack?" << endl;
					//give options
					cout << "1. Pocket Sand!" << endl;
					cout << "2. Punch!" << endl;
					//input/output
					cin >> attackChoice;
					if (attackChoice == 1)
					{
						foeAccuracy -= nemesis->pocketSand(foeAccuracy);
					}
					else if (attackChoice == 2)
					{
						int headbuttDamage = nemesis->headbutt(nemesisDamage, foeDefense);
						cout << headbuttDamage << " damage done to Jeff!\n" << endl;
						foeHealth -= headbuttDamage;
					}
				}
				else if (enemyChoice == 2)
				{
					cout << "Which attack?" << endl;
					//give options
					cout << "1. Pocket Sand!" << endl;
					cout << "2. Punch!" << endl;
					//input/output
					//attacking this dipshit isn't wyrkyng
					cin >> attackChoice;
					if (attackChoice == 1)
					{
						haterAccuracy -= nemesis->pocketSand(haterAccuracy);
					}
					else if (attackChoice == 2)
					{
						int headbuttDamage = nemesis->headbutt(nemesisDamage, haterDefense);
						cout << headbuttDamage << " done to Stephen!\n" << endl;
						haterHealth -= headbuttDamage;
					}
				}
			}
			//invalid input catch
			else
			{
				//oopsie! you didn't follow the rules!
			}

			//enemy 1 turn
			int enemyOneAttack = rand() % (2) + 1;
			if (enemyOneAttack == 1)
			{
				nemesisAccuracy -= foe->pocketSand(nemesisAccuracy);
				cout << "Pocketsanded by Jeff!" << endl;
			}
			if (enemyOneAttack == 2)
			{
				int headbuttDamage = hater->headbutt(haterDamage, nemesisDefense);
				cout << headbuttDamage << " damage done by Jeff.\n" << endl;
				nemesisHealth -= headbuttDamage;
			}
			//enemy 2
			int enemyTwoAttack = rand() % (2) + 1;
			if (enemyOneAttack == 1)
			{
				nemesisAccuracy -= hater->pocketSand(nemesisAccuracy);
				cout << "Pocketsanded by Stephen!" << endl;
			}
			if (enemyOneAttack == 2)
			{
				int headbuttDamage = hater->headbutt(haterDamage, nemesisDefense);
				cout << headbuttDamage << " damage done by Stephen.\n" << endl;
				nemesisHealth -= headbuttDamage;
			}

			//show stats after
			nemesis->Intro("Player", nemesisHealth, nemesisMaxHealth);
			foe->Intro("Jeff", foeHealth, foeMaxHealth);
			hater->Intro("Stephen", haterHealth, haterMaxHealth);
		}
		else
		{
			cout << "You lost!" << endl;
		}
		//if (foeHealth > 0)
		//{
		//	//locate value
		//	int nullValue = foeHealth;
		//	//remove and readjust vector size
		//	auto removeFromIndex = remove(vec.begin(), vec.end(), nullValue);

		//	// Print the vector after deletion
		//	cout << "Vector After Deletion:";
		//	for (int element : vec) 
		//	{
		//		cout << element << " " << endl;
		//	}
		//}
		//else if (haterHealth > 0)
		//{
		//	int nullValue = haterHealth;
		//	//remove and readjust vector size
		//	auto removeFromIndex = remove(vec.begin(), vec.end(), nullValue);

		//	// Print the vector after deletion
		//	cout << "Vector After Deletion:";
		//	for (int element : vec)
		//	{
		//		cout << element << " " << endl;
		//	}
		//}
		//else if (nemesisHealth > 0)
		//{
		//	int nullValue = nemesisHealth;
		//	//remove and readjust vector size
		//	auto removeFromIndex = remove(vec.begin(), vec.end(), nullValue);

		//	// Print the vector after deletion
		//	cout << "Vector After Deletion:";
		//	for (int element : vec)
		//	{
		//		cout << element << " " << endl;
		//	}
		//}
	}
}
#pragma endregion
#pragma region TestTwo
void TestTwo();


//sometimes the attack takes out more enemies tahn it should
void TestTwo()
{
	//variables for later options

	int playerChoice;
	int enemyChoice = 0;
	int attackChoice;
	
	cout << "\nEncountered two enemies!" << endl;
	//while loop with checks as to whether or not units are alive
	while(true)
	{
		//if the player is alive, otherwise the game sends them to the continue/quit screen
		if(nemesisHealth > 0)
		{
			//give player info of their standings
			nemesis->Intro("Player", nemesisHealth, nemesisMaxHealth);
			//use item or attack, all options for player
			{
				cout << "What would you like to do?" << endl;
				//display active foes
				if (foeHealth > 0)
				{
					foe->Intro("Foe", foeHealth, foeMaxHealth);
				}
				if (haterHealth > 0)
				{
					hater->Intro("Hater", haterHealth, haterMaxHealth);
				}
				//give options, player's turn
				cout << "1. Attack" << endl;
				cout << "2. Item" << endl;
				//input/output
				cin >> playerChoice;
				if(playerChoice == 1)
				{
					//attack before enemy choice
					cout << "Which attack?" << endl;
					//give options
					cout << "1. Pocket Sand!" << endl;
					cout << "2. Heatbutt!" << endl;
					//input/output
					cin >> attackChoice;
					if (attackChoice == 1)
					{
						//check if both units are alive first
						if (foeHealth > 0 && haterHealth > 0)
						{
							cout << "Which enemy?" << endl;
							//give options
							cout << "1. Foe" << endl;
							cout << "2. Hater" << endl;
							cin >> enemyChoice;
						}
						cout << enemyChoice << endl;
						//use pocket sand
						//default to last enemy, otherwise give the player a choice
						//pocket sand foe
						if(enemyChoice == 1)
						{
							//check to see if move hits then attack
							int hitnum = nemesis->rollHitChance();
							if (hitnum <= nemesisAccuracy)
							{
								foeAccuracy -= nemesis->pocketSand(foeAccuracy);
								cout << "Pocketsanded Foe!" << endl;
							}
							else
							{
								cout << "You Missed" << endl;
							}
						}
						if (haterHealth < 0)/*if it's the last enemy or if the player chooses it in the statement above*/
						{
							//check to see if move hits then attack
							int hitnum = nemesis->rollHitChance();
							if (hitnum <= nemesisAccuracy)
							{
								foeAccuracy -= nemesis->pocketSand(foeAccuracy);
								cout << "Pocketsanded Foe!" << endl;
							}
							else
							{
								cout << "You Missed" << endl;
							}
						}
						//pocket sand hater
						if(enemyChoice == 2)
						{
							//check to see if move hits then attack
							int hitnum = nemesis->rollHitChance();
							if (hitnum <= nemesisAccuracy)
							{
								haterAccuracy -= nemesis->pocketSand(haterAccuracy);
								cout << "Pocketsanded Hater!" << endl;
							}
							else
							{
								cout << "You Missed" << endl;
							}
						}
					
						if (foeHealth < 0)/*if it's the last enemy or if the player chooses it in the statement above*/
						{
							//check to see if move hits then attack
							int hitnum = nemesis->rollHitChance();
							if (hitnum <= nemesisAccuracy)
							{
								haterAccuracy -= nemesis->pocketSand(haterAccuracy);
								cout << "Pocketsanded Hater!" << endl;
							}
							else
							{
								cout << "You Missed" << endl;
							}
						}
					}
					else if (attackChoice == 2)
					{
						//check if both units are alive first
						if (foeHealth > 0 && haterHealth > 0)
						{
							cout << "Which enemy?" << endl;
							//give options
							cout << "1. Foe" << endl;
							cout << "2. Hater" << endl;
							cin >> enemyChoice;
						}
						cout << enemyChoice << endl;
						//hit foe
						if (enemyChoice == 1)
						{
							//check to see if move hits then attack
							int hitnum = nemesis->rollHitChance();
							if (hitnum <= nemesisAccuracy)
							{
								//use headbutt
								int headbuttDamage = nemesis->headbutt(nemesisDamage, foeDefense);
								cout << headbuttDamage << " damage done to Foe!\n" << endl;
								foeHealth -= headbuttDamage;
							}
							else
							{
								cout << "You Missed" << endl;
							}
						}
						if (haterHealth < 0)
						{
							//check to see if move hits then attack
							int hitnum = nemesis->rollHitChance();
							if (hitnum <= nemesisAccuracy)
							{
								//use headbutt
								int headbuttDamage = nemesis->headbutt(nemesisDamage, foeDefense);
								cout << headbuttDamage << " damage done to Foe!\n" << endl;
								foeHealth -= headbuttDamage;
							}
							else
							{
								cout << "You Missed" << endl;
							}
						}
						//hit hater
						if (enemyChoice == 2)
						{
							//check to see if move hits then attack
							int hitnum = nemesis->rollHitChance();
							if (hitnum <= nemesisAccuracy)
							{
								//use headbutt
								int headbuttDamage = nemesis->headbutt(nemesisDamage, haterDefense);
								cout << headbuttDamage << " damage done to Hater!\n" << endl;
								haterHealth -= headbuttDamage;
							}
							else
							{
								cout << "You Missed" << endl;
							}
						}
						if (foeHealth < 0)/*if one is dead, auto select the other*/
						{
							//check to see if move hits then attack
							int hitnum = nemesis->rollHitChance();
							if (hitnum <= nemesisAccuracy)
							{
								//use headbutt
								int headbuttDamage = nemesis->headbutt(nemesisDamage, haterDefense);
								cout << headbuttDamage << " damage done to Hater!\n" << endl;
								haterHealth -= headbuttDamage;
							}
							else
							{
								cout << "You Missed" << endl;
							}
						}
					}
					//enemy turns
					if (foeHealth > 0)/*if they're alive, spin the wheel*/
					{
						//check hit or miss
						int enemyOneHitNum = foe->rollHitChance();
						if (enemyOneHitNum <= foeAccuracy)
						{
							int enemyOneAttack = rand() % (2) + 1;
							if (enemyOneAttack == 1)
							{
								nemesisAccuracy -= foe->pocketSand(nemesisAccuracy);
								cout << "Pocketsanded by Foe!" << endl;
							}
							if (enemyOneAttack == 2)
							{
								int headbuttDamage = foe->headbutt(foeDamage, nemesisDefense);
								cout << headbuttDamage << " damage done by Foe.\n" << endl;
								nemesisHealth -= headbuttDamage;
							}
						}
						else
						{
							cout << "Foe missed!" << endl;
						}
					}
					if (haterHealth > 0)/*if they're alive, spin the wheel*/
					{
						//check hit or miss
						int enemyTwoHitNum = hater->rollHitChance();
						if (enemyTwoHitNum <= haterAccuracy)
						{
							int enemyTwoAttack = rand() % (2) + 1;
							if (enemyTwoAttack == 1)
							{
								nemesisAccuracy -= hater->pocketSand(nemesisAccuracy);
								cout << "Pocketsanded by Hater!" << endl;
							}
							if (enemyTwoAttack == 2)
							{
								int headbuttDamage = hater->headbutt(haterDamage, nemesisDefense);
								cout << headbuttDamage << " damage done by Hater.\n" << endl;
								nemesisHealth -= headbuttDamage;
							}
						}
						else
						{
							cout << "Hater missed!" << endl;
						}
					}
					//check if both units are dead first
					if (foeHealth < 0 && haterHealth < 0)
					{
						cout << "You win!" << endl;
						//send to item select function
						break;
					}
				}
			}
		}
		else
		{
			cout << "You're dead!" << endl;
			//send to retry function
			break;
		}
	}
}
#pragma endregion

int main()
{
	srand(time(0));
	TestTwo();
	//show stats after
	nemesis->Intro("Player", nemesisHealth, nemesisMaxHealth);
	foe->Intro("Foe", foeHealth, foeMaxHealth);
	hater->Intro("Hater", haterHealth, haterMaxHealth);

#pragma region TestArea
		//while (true)
		//{
		//	cout << "To test, press 1" << endl;
		//	cin >> test;
		//	if (test == 1)
		//	{
		//		//check to see if move hits then attack
		//		int hitNum = hater->rollHitChance();
		//		cout << hitNum << " hit chance.\n" << endl;

		//		//if the hit chance is less than or equal to hater accuracy, the move hits
		//		if (hitNum <= haterAccuracy)
		//		{
		//			cout << "The move hit!\n" << endl;
		//			//calculations
		//			//make a shorter ver of all.. this..

		//			int headbuttDamage = hater->headbutt(haterDamage, foeDefense);
		//			cout << headbuttDamage << " damage calculated...\n" << endl;

		//			foeHealth -= headbuttDamage;
		//			cout << foeHealth << " remains!\n" << endl;

		//			//more calcs
		//			int blindingStewDamage = hater->blindingStew(haterDamage, foeDefense);
		//		}
		//		else if (hitNum > haterAccuracy)
		//		{
		//			cout << "The hater's move misses.\n" << endl;
		//		}
		//		else
		//		{
		//			cout << "Something isn't right..." << endl;
		//		}
		//	}
		//	else
		//	{
		//		break;
		//	}
		//}
	#pragma endregion

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
//Exception handling <throw error; cerr>

//Step two: get this to work (moderate, put your back into it)
//File input and output processing <save/load?>
//Vectors <with save file>

//Multi - Threading <_>
//Templates <_>
//Recursion <_>
//Iterators <_>


//Discarded code but who knows the future? I may need it...


//see if the move hits
	//bool hitChance(bool hitOrMiss, double accuracy)
	//{
	//	//set variable, get a random hit chance
	//	int hitChance = rollHitChance();
	//	cout << hitChance << " hit chance!" << endl;
	//	//cout << hitOrMiss << " boolean!" << endl;

//	//if accuracy is high enough to match hit chance, the move hits
	//	if (hitChance <= accuracy)
	//	{
	//		hitOrMiss = true;
	//		//cout << hitOrMiss << " boolean!" << endl;
	//		cout << accuracy << " accuracy remains!" << endl;
	//		return hitOrMiss;
	//	}
	//	//if accuracy doesn't pass the check, the move fails
	//	else if (hitChance > accuracy)
	//	{
	//		hitOrMiss = false;
	//		//cout << hitOrMiss << " boolean!" << endl;
	//		cout << accuracy << " accuracy remains!" << endl;
	//		cout << "Missed!" << endl;
	//		return hitOrMiss;
	//	}
	//	else
	//	{
	//		cerr << "I messed up. " << endl;
	//		return hitOrMiss;
	//	}
	//}