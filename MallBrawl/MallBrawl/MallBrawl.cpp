// MallBrawl.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
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
	{}
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
		int newAccuracy = accuracy -= reduction;
		cout << newAccuracy << " is the Blitz's current accuracy!" << endl;
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
		cout << finalDMG << " is the headbutt damage done by Blitz!\n" << endl;
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
		cout << finalDMG << " ramming damage done by Blitz!\n" << endl;
		return finalDMG;
	}
#pragma endregion
};

//vampiric enemy
class Crumb : public Unit
{
public:
	Crumb(string name, int health, int maxHealth, int attack, int defense, int accuracy) : Unit(name, health, maxHealth, attack, defense, accuracy)
	{}
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
		double newAccuracy = accuracy -= reduction;
		cout << newAccuracy << " is the Crumb's current accuracy!"<< endl;
		return reduction;
	}

	//recoil; the damage these powerful attacks do to this unit
	int heal(int moveDamage)
	{
		int healAmount = moveDamage / 5;
		cout << healAmount << " health recovered by its attack!\n" << endl;
		return healAmount;
	}
#pragma endregion
#pragma region Attacks
	//heal self after
	int leech(int attack, int opponentDefense)
	{
		//just try to calculate damage with formula and have it pass
		int power = 15;

		//adjust damage value for randomness
		double damageRoll = rollDamage();

		//calculate true damage
		int trueAttack = attack / opponentDefense;

		//make final value
		int leechDamage = power * trueAttack;
		int finalDMG = damageRoll * leechDamage;
		cout << finalDMG << " health leeched by Crumb!\n" << endl;
		return finalDMG;
	}

	//divvy up hp between self and ally
	int mutualism(string name, int health, string allyName, int allyHealth)
	{
		cout <<name<< " splits health between self and "<< allyName << "."<<endl;
		int healthPool = health + allyHealth;
		int midpointHealth = healthPool / 2 + 1;
		cout <<"New health total for both is " <<midpointHealth<<".\n" << endl;
		return midpointHealth;
	}

	//kill an ally, gain their health (-= devour on ally, += devour on self)
	int devour(string name, string allyName, int allyHealth)
	{
		cout << name << " ate " << allyName << "!\n"<<endl;
		return allyHealth;
	}
#pragma endregion
};

//do little damage, on death buff the one who deals the final blow
class Test : public Unit
{
	Test(string name, int health, int maxHealth, int attack, int defense, int accuracy, int currentMana, int maxMana) : Unit(name, health, maxHealth, attack, defense, accuracy)
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
		double newAccuracy = accuracy -= reduction;
		cout << newAccuracy << " is the Crumb's current accuracy!" << endl;
		return reduction;
	}

	//remove mana
	int subtractMana(int manaCost, int currentMana)
	{
		currentMana = currentMana -= manaCost;
		return currentMana;
	}

	//add mana
	int addMana(int maxMana)
	{
		int addedMana = maxMana * 0.75;
		if (addedMana < maxMana)
		{
			addedMana == maxMana;
		}
		return addedMana;
	}
#pragma endregion
#pragma region Attacks
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
		int newAccuracy = accuracy -= reduction;
		cout << newAccuracy << " is the your current accuracy!" << endl;
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
		cout << "\n" << finalDMG << " is the damage your Mighty Punch does!\n" << endl;
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
		cout << "\n" << finalDMG << " is the damage your Pocket Sand does!\n" << endl;
		return finalDMG;
	}
#pragma endregion
};

#pragma endregion

#pragma region Items

class item
{
public:
	item(string type){}

	void itemDetails(string type)
	{
		cout << type << endl;
	}
};

//healing, damage boost, ect. single use. 3 inventory slots. on use, remove item from vector.
class healthPotion : public item
{
public:
	healthPotion(string itemType) : item(itemType){}

	void itemDetails(string itemType)
	{
		cout << itemType << " : Restores 33% of the user's health!" << endl;
	}
};

class bomb : public item
{
public:	
	bomb(string itemType) : item(itemType) {}

	void itemDetails(string itemType)
	{
		cout << itemType << " : Does half of an enemy's (and your own!) current health." << endl;
	}
};

class dmgBoost : public item
{
public:
	dmgBoost(string itemtype) : item(itemtype){}

	void itemDetails(string itemType)
	{
		cout << itemType << " : Boosts your damage by 5 permanently." << endl;
	}
}; 

class hpBoost : public item
{
public:
	hpBoost(string itemtype) : item(itemtype) {}

	void itemDetails(string itemType)
	{
		cout << itemType << " : Boosts your health by 25 permanently." << endl;
	}
};

class shield : public item
{
public:
	shield(string itemtype) : item(itemtype) {}

	void itemDetails(string itemType)
	{
		cout << itemType << " : Absorbs one hit." << endl;
	}
};
#pragma endregion

//generate random number as a check for whether or not a move hits
static int rollHitChance()
{
	srand(time(0));
	//never less than one, never more than move hit chance
	int hitChance = rand() % (100 + 1) + 1;
	return hitChance;
}

#pragma region Variables
//roll hit chance
int hitNum = rollHitChance();

//files for saving
ofstream file("saveFile.txt");
string progress;

//all vars required
string name;
int health;
int maxHealth;
int attack;
int defense;
int accuracy; 

//player vars
string playerName = "Player";
int playerHealth = 1000;
int playerMaxHealth = 1000;
int playerAttack = 10;
int playerDefense = 15;
int playerAccuracy = 100;

unique_ptr<Player> player(new Player(playerName, playerHealth, playerMaxHealth, playerAttack, playerDefense, playerAccuracy));

//holds possible options for additional objects
vector<item*> options;
//objects the player can use
vector<item*> inventory;
#pragma endregion

#pragma region arenaTitles
void start();
void intro();
void firstBattle();
void secondBattle();
#pragma endregion

void load()
{
	//read progress from file; send to proper setting.
	cout << "Loading!" << endl;
	// Creation of ifstream class object to read the file
	ifstream read;
	read.open("saveFile.txt");
	// Close the file
	read.close();
	file.close();
}

void start()
{
	file.clear();
	progress = "Starting!";
	file << progress;
	cout << progress << endl;
}

#pragma region Arenas
void intro()
{
	start();
	cout << "The mall troll, yes all malls have them, wants you to answer some stupid riddles to get into a store that he doesn’t even work at.\nIt’s stupid, so you don’t, but the very shop he’s elected to block is the only one in an aimable distance from your house with the item you want to buy.\nArtificial scarcity-consumerism-fomo, blah blah blah, you want that item.\nThe alternative entrance, however, is through The Alley That Has Hordes Of Biotic Lifeforms(Saying Monsters Is Mildly Inaccurate And Kind Of Offensive Because There Are Humans, Also) Who Want To Fight And Will Only Let You Through By Battling.\nWhile the senseless hyper - violence is concerning, especially seeing as the unbelievably long title is a proper noun, meaning that many people are aware of and cool with battle alley, its informal name.\nBut you’ll take a brawl to stupid riddles any day." << endl;
	file.open("saveFile.txt");
	file << "introDone";
	file.close();
}
void firstBattle()
{
	//variables for later options
	int playerChoice;
	int attackChoice;

	srand(time(0));

	//enemy blitz vars
	string blitzName = "Blitz";
	int blitzHealth = 70;
	int blitzMaxHealth = 70;
	int blitzAttack = 25;
	int blitzDefense = 5;
	int blitzAccuracy = 50;

	//vars used for this function; only exist here
	unique_ptr<Blitz> blitz(new Blitz(blitzName, blitzHealth, blitzMaxHealth, blitzAttack, blitzDefense, blitzAccuracy));

	file.open("saveFile.txt");
	file << "firstBattleStart";
	file.close();

	cout << "Encountered an enemy!" << endl;
	while (true)
	{
		if(playerHealth > 0)
		{
			player->Intro(playerName, playerHealth, playerMaxHealth);
			cout << "What would you like to do?\n" << endl;
			//display active foes
			if (blitzHealth > 0)
			{
				blitz->Intro(blitzName, blitzHealth, blitzMaxHealth);
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
						//damage blitz
						blitzHealth -= player->punch(playerAttack, blitzDefense);
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
						//damage blitz and reduce accuracy
						blitzHealth -= player->pocketSand(playerAttack, blitzDefense);
						blitzAccuracy -= blitz->accuracyRedution(blitzAccuracy);
					}
					else
					{
						cout << "You missed!\n" << endl;
					}
				}
				else
				{
					cerr << "That's an invalid input..." << endl;
					continue;
				}
				bool moveHits = getMax(hitNum, blitzAccuracy);
				if(moveHits == true)
				{
					int moveSelected = rand() % (2) + 1;
					if (moveSelected == 1)
					{
						int damageOverall = blitz->recklessRam(blitzAttack, playerDefense);
						playerHealth -= damageOverall;
						blitzHealth -= blitz->recoil(damageOverall);
					}
					else
					{
						int damageOverall = blitz->headbutt(blitzAttack, playerDefense);
						playerHealth -= damageOverall;
						blitzHealth -= blitz->recoil(damageOverall);
					}
				}
				else
				{
					cout << "Blitz missed!\n" << endl;
				}
			}
			else if (playerChoice == 2)
			{
				cout << "Sorry, no items!" << endl;
				continue;
			}
			else
			{
				cerr << "That's an invalid input..." << endl;
				continue;
			}
			//wincondition
			if (blitzHealth < 0)
			{
				player->Intro(playerName, playerHealth, playerMaxHealth);
				blitz->Intro(blitzName, blitzHealth, blitzMaxHealth);
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
void secondBattle()
{
	//two enemies
	//variables for choices
	int playerChoice;
	int attackChoice;

	srand(time(0));

	//enemy blitz vars
	string blitzName = "Blitz";
	int blitzHealth = 70;
	int blitzMaxHealth = 70;
	int blitzAttack = 25;
	int blitzDefense = 5;
	int blitzAccuracy = 50;

	//enemy crumb vars
	string crumbName = "Crumb";
	int crumbHealth = 35;
	int crumbMaxHealth = 35;
	int crumbAttack = 15;
	int crumbDefense = 10;
	int crumbAccuracy = 100;

	//vars used for this function; only exist here
	unique_ptr<Blitz> blitz(new Blitz(blitzName, blitzHealth, blitzMaxHealth, blitzAttack, blitzDefense, blitzAccuracy));
	unique_ptr<Crumb> crumb(new Crumb(crumbName, crumbHealth, crumbMaxHealth, crumbAttack, crumbDefense, crumbAccuracy));

	file.open("saveFile.txt");
	file << "secondBattleStart";
	file.close();

	cout << "Encountered two enemies!\n" << endl;

	while (true)
	{
		if (playerHealth > 0)
		{
			int enemyChoice = 0;
			player->Intro(playerName, playerHealth, playerMaxHealth);
			cout << "What would you like to do?\n" << endl;
			//display active foes
			if (blitzHealth > 0)
			{
				blitz->Intro(blitzName, blitzHealth, blitzMaxHealth);
			}
			if (crumbHealth > 0)
			{
				crumb->Intro(crumbName, crumbHealth, crumbMaxHealth);
			}
			cout << "1. Attack\n2. Item" << endl;
			cin >> playerChoice;
			if (playerChoice == 1)
			{
				//attack before enemy choice; default to last alive enemy or provide options if more than one is alive
				cout << "Which attack?\n1. Punch!\n2. Pocket Sand!\n" << endl;
				cin >> attackChoice;
				if (attackChoice == 1)
				{
					//check if both units are alive first
					if (crumbHealth > 0 && blitzHealth > 0)
					{
						//prompt input
						cout << "Which enemy?\n1. Crumb\n2. Blitz\n" << endl;
						cin >> enemyChoice;
					}
					//(if crumb is chosen)
					if (enemyChoice == 1)
					{
						//punch
						//hit or miss
						bool moveHits = getMax(hitNum, playerAccuracy);
						if (true)
						{
							//adjust health accordingly
							crumbHealth -= player->punch(playerAttack, crumbDefense);
						}
						else
						{
							cout << "You missed!\n" << endl;
						}
					}
					//(if blitz is chosen)
					if (enemyChoice == 2)
					{
						//punch
						//hit or miss
						bool moveHits = getMax(hitNum, playerAccuracy);
						if (true)
						{
							//adjust health
							blitzHealth -= player->punch(playerAttack, blitzDefense);
						}
						else
						{
							cout << "You missed!\n" << endl;
						}
					}
					//default to living enemy (if blitz is dead)
					if (blitzHealth <= 0)
					{
						//punch
						//hit or miss
						bool moveHits = getMax(hitNum, playerAccuracy);
						if (true)
						{
							//adjust health accordingly
							crumbHealth -= player->punch(playerAttack, crumbDefense);
						}
						else
						{
							cout << "You missed!\n" << endl;
						}
					}
					//default to living enemy (if crumb is dead)
					if (crumbHealth <= 0)
					{
						//punch
						//hit or miss
						bool moveHits = getMax(hitNum, playerAccuracy);
						if (true)
						{
							//adjust health
							blitzHealth -= player->punch(playerAttack, blitzDefense);
						}
						else
						{
							cout << "You missed!\n" << endl;
						}
					}
				}
				else if (attackChoice == 2)
				{
					//check if both units are alive first
					if (crumbHealth > 0 && blitzHealth > 0)
					{
						//prompt input
						cout << "Which enemy?\n1. Crumb\n2. Blitz\n" << endl;
						cin >> enemyChoice;
					}
					//(if crumb is chosen)
					if (enemyChoice == 1)
					{
						//pocket sand
						bool moveHits = getMax(hitNum, playerAccuracy);
						if (true)
						{
							//adjust health accordingly
							crumbHealth -= player->pocketSand(playerAttack, crumbDefense);
							crumbAccuracy -= crumb->accuracyRedution(crumbAccuracy);
						}
						else
						{
							cout << "You missed!\n" << endl;
						}
					}
					//(if blitz is chosen)
					if (enemyChoice == 2)
					{
						//pocket sand
						//hit or miss
						bool moveHits = getMax(hitNum, playerAccuracy);
						if (true)
						{
							//adjust health
							blitzHealth -= player->pocketSand(playerAttack, blitzDefense);
							blitzAccuracy -= blitz->accuracyRedution(blitzAccuracy);
						}
						else
						{
							cout << "You missed!\n" << endl;
						}
					}
					//default to living enemy (if blitz is dead)
					if (blitzHealth < 0)
					{
						//pocket sand
						bool moveHits = getMax(hitNum, playerAccuracy);
						if (true)
						{
							//adjust health accordingly
							crumbHealth -= player->pocketSand(playerAttack, crumbDefense);
							crumbAccuracy -= crumb->accuracyRedution(crumbAccuracy);
						}
						else
						{
							cout << "You missed!\n" << endl;
						}
					}
					//default to living enemy (if crumb is dead)
					if (crumbHealth <= 0)
					{
						//pocket sand
						//hit or miss
						bool moveHits = getMax(hitNum, playerAccuracy);
						if (true)
						{
							//adjust health
							blitzHealth -= player->pocketSand(playerAttack, blitzDefense);
							blitzAccuracy -= blitz->accuracyRedution(blitzAccuracy);
						}
						else
						{
							cout << "You missed!\n" << endl;
						}
					}
				}
				//no valid attackChoice
				else
				{
					cerr << "That's an invalid input...\n" << endl;
					continue;
				}
				//blitz turn, prevent ghost boxing
				if (blitzHealth > 0)
				{
					bool moveHits = getMax(hitNum, blitzAccuracy);
					if (moveHits == true)
					{
						int moveSelected = rand() % (2) + 1;
						if (moveSelected == 1)
						{
							int damageOverall = blitz->recklessRam(blitzAttack, playerDefense);
							playerHealth -= damageOverall;
							blitzHealth -= blitz->recoil(damageOverall);
						}
						else
						{
							int damageOverall = blitz->headbutt(blitzAttack, playerDefense);
							playerHealth -= damageOverall;
							blitzHealth -= blitz->recoil(damageOverall);
						}
					}
					//hit check not passed
					else
					{
						cout << "Blitz missed!\n" << endl;
					}
				}
				//crumb turn, prevent a death being caused by a ghost
				if (crumbHealth > 0)
				{
					bool moveHits = getMax(hitNum, crumbAccuracy);
					if (moveHits == true)
					{
						//if any ally is alive use expanded move list, otherwise leech player
						if (blitzHealth > 0)
						{
							int moveSelected = rand() % (3) + 1;
							if (moveSelected == 1)
							{
								//repeating a function makes the text within repeat
								int allyHealth = crumb->devour(crumbName, blitzName, blitzHealth);
								crumbHealth += allyHealth;
								blitzHealth -= allyHealth;

							}
							else if (moveSelected == 2)
							{
								int adjustedHealth = crumb->mutualism(crumbName, crumbHealth, blitzName, blitzHealth);
								blitzHealth = adjustedHealth;
								crumbHealth = adjustedHealth;
							}
							else
							{
								int damageOverall = crumb->leech(crumbAttack, playerDefense);
								playerHealth -= damageOverall;
								crumbHealth += crumb->heal(damageOverall);
							}
						}
						//no allies to do the freak tactics with
						else if (blitzHealth <= 0)
						{
							int damageOverall = crumb->leech(crumbAttack, playerDefense);
							playerHealth -= damageOverall;
							crumbHealth += crumb->heal(damageOverall);
						}
					}
					//hit check not passed
					else
					{
						cout << "Crumb missed!\n" << endl;
					}
				}	
			}			
			//items to be implemented later, if at all
			else if (playerChoice == 2)
			{
				cerr << "Sorry, no items!\n" << endl;
				continue;
			}
			//no valid input at playerChoice
			else
			{
				cerr << "That's an invalid input...\n" << endl;
				continue;
			}
		}
		//if enemies are dead
		if (crumbHealth <= 0 && blitzHealth <= 0)
		{
			cout << "You win!\n" << endl;
			crumb->Intro(crumbName, crumbHealth, crumbMaxHealth);
			blitz->Intro(blitzName, blitzHealth, blitzMaxHealth);
			break;
		}
		//if player is dead
		if(playerHealth <= 0)
		{
			cout << "You lost!\n" << endl;
			break;
		}
	}
}
#pragma endregion

#pragma region GetItem
void giveItems()
{
	srand(time(0));

	int listInt = 1;

	for (int i = 0; i < 3; i++)
	{
		int selection = rand() % (5) + 1;

		if (selection == 1)
		{
			options.push_back(new healthPotion("Health Potion"));
			healthPotion item("Health Potion");
			cout << listInt << ". ";
			item.itemDetails("Health Potion");
			listInt += 1;
		}
		else if (selection == 2)
		{
			options.push_back(new dmgBoost("Damage Boost"));
			dmgBoost item("Damage Boost");
			cout << listInt << ". ";
			item.itemDetails("Damage Boost");
			listInt += 1;
		}
		else if (selection == 3)
		{
			options.push_back(new hpBoost("Health Boost"));
			hpBoost item("Health Boost");
			cout << listInt << ". ";
			item.itemDetails("Health Boost");
			listInt += 1;
		}
		else if (selection == 4)
		{
			options.push_back(new shield("Shield"));
			shield item("Shield");
			cout << listInt << ". ";
			item.itemDetails("Shield");
			listInt += 1;
		}
		else
		{
			options.push_back(new bomb("Bomb"));
			bomb item("Bomb");
			cout << listInt << ". ";
			item.itemDetails("Bomb");
			listInt += 1;
		}
	}
}
void itemReward()
{
	file.open("saveFile.txt");
	file<< "itemRewardStart";
	file.close();

	giveItems();
	int userChoice;
	//randomly select three items to use (later)
	cout << "Select your reward! Please enter a number." << endl;
	//print options; push_back to add; check if size is over three, if true select one to discard. use ints
	cin >> userChoice;
	if (userChoice == 1)
	{
		int itemToAdd = userChoice - 1;
		inventory.push_back(options[itemToAdd]);
		for (int i = 0; i < options.size(); i++)
		{
			options.pop_back();
		}
	}
	else if (userChoice == 2)
	{
		int itemToAdd = userChoice - 1;
		inventory.push_back(options[itemToAdd]);
		for (int i = 0; i < options.size(); i++)
		{
			options.pop_back();
		}
	}
	else if (userChoice == 3)
	{
		int itemToAdd = userChoice - 1;
		inventory.push_back(options[itemToAdd]);
		for (int i = 0; i < options.size(); i++) 
		{
			options.pop_back();
		}
	}
	else
	{
		cout << "Invalid selection! Please enter a whole number selection." << endl;
	}
	file.open("saveFile.txt");
	file << "itemRewardEnd";
	file.close();
}
#pragma endregion

int main()
{
	intro();
	firstBattle();
	itemReward();
	secondBattle();
	itemReward();
}
