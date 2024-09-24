// C++HealthAndClasses.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Unit 
{
private:
	int currentHealth;
public:
	//lets player state name
	string Name;
	//makes health as stated
	Unit(string name, int health, int damage) : Name(name)
	{
		setHealth(health);
	}
	//setter for hp
	void setHealth(int health) 
	{
		if (health <= 0) 
		{
			cout << "RIP! " << endl;
		}
		else 
		{
			currentHealth = health;
		}
	}
	//getter for hp
	int getHealth() 
	{
		return currentHealth;
	}
	//pass damage to health and say what has occured
	void damageDone(int health, int damage)
	{
		currentHealth -= damage;
		cout << "A nearby dummy took " << damage << " points of damage!" << endl;
		cout << currentHealth << " points of health remain! " << endl;
		health == currentHealth;
	}
	//say name and a blurb
	void Talk(string name) 
	{
		cout << name << " opens their eyes." << endl;
		cout << "Hello!" << endl;
	}
};


class Zombie : public Unit 
{
private:
	//private health variable
	int currentHealth;
public:
	//constructor
	Zombie(string name, int health, int damage) : Unit(name, health, damage) 
	{
		setHealth(health);
	}

	//alters attack method to be attacker specific; damage done is for damage done to YOU
	void damageDone(int health, int damage)
	{
		cout << "The werewolf claws!" << endl;
		currentHealth -= damage;
		cout << "Took " << damage << " points of damage!" << endl;
		cout << currentHealth << " points of health remain! " << endl;
		health == currentHealth;
	}
	//say name and a blurb
	void Talk(string name)
	{
		cout << name << " crawls from the crypt!" << endl;
		cout << "Eurghh.. (Zombie for 'eurghh'.)" << endl;
	}
	//setter for hp
	void setHealth(int health)
	{
		if (health <= 0)
		{
			cout << "RIP! " << endl;
		}
		else
		{
			currentHealth = health;
		}
	}
	//getter for hp
	int getHealth()
	{
		return currentHealth;
	}
};

class Werewolf : public Unit
{
private:
	//private health variable
	int currentHealth;
public:
	//constructor
	Werewolf(string name, int health, int damage) : Unit(name, health, damage)
	{
		setHealth(health);
	}

	//alters attack method to be attacker specific; damage done is for damage done to YOU
	void damageDone(int health, int damage)
	{
		cout << "The zombie bites!" << endl;
		currentHealth -= damage;
		cout << "Took " << damage << " points of damage!" << endl;
		cout << currentHealth << " points of health remain! " << endl;
		health == currentHealth;
	}
	//say name and a blurb
	void Talk(string name)
	{
		cout << name << " looks to the full moon!" << endl;
		cout << "Arooo! " << endl;
	}
	//setter for hp
	void setHealth(int health)
	{
		if (health <= 0)
		{
			cout << "RIP! " << endl;
		}
		else
		{
			currentHealth = health;
		}
	}
	//getter for hp
	int getHealth()
	{
		return currentHealth;
	}
};


int main()
{
	string charName;
	int choice;
	int hitsDone = 0;
	int attack;

	cout << "Welsome to the Tornadocube, the battle arena for ghouls of all types! " << endl;
	cout << "Thanks for respondong to the ad. " << endl;
	cout << "So we know what to shout for your introduction, what's your name? " << endl;
	cin >> charName;
	cout << "And what are you, exactly? So I can make a cool introduction for you. (1. Zombie, 2. Werewolf.) " << endl;
	cin >> choice;
	if (choice == 1) 
	{
		cout << " " << endl;
		Zombie zombie(charName, 100, 25);
		zombie.Talk(charName);
		cout << " " << endl;
		cout << "You're up against the werewolf! We'll leave the introduction to them." << endl;
		cout << " " << endl;
		Werewolf enemy("Ronnie", 100, 25);
		enemy.Talk("Ronnie");
	}
	else if (choice == 2)
	{
		cout << " " << endl;
		Werewolf werewolf(charName, 100, 25);
		werewolf.Talk(charName);
		cout << " " << endl;
		cout << "You're up against the zombie! We'll leave the introduction to them." << endl;
		cout << " " << endl;
		Zombie enemy("Ronnie", 100, 25);
		enemy.Talk("Ronnie");
	}
	else 
	{
		cout << "Please pick 1 or 2." << endl;
		cin >> choice;
		if (choice == 1)
		{
			cout << " " << endl;
			Zombie zombie(charName, 100, 25);
			zombie.Talk(charName);
			cout << " " << endl;
			cout << "You're up against the werewolf! We'll leave the introduction to them." << endl;
			cout << " " << endl;
			Werewolf enemy("Ronnie", 100, 25);
			enemy.Talk("Ronnie");
		}
		else if (choice == 2)
		{
			cout << " " << endl;
			Werewolf werewolf(charName, 100, 25);
			werewolf.Talk(charName);
			cout << " " << endl;
			cout << "You're up against the zombie! We'll leave the introduction to them." << endl;
			cout << " " << endl;
			Zombie enemy("Ronnie", 100, 25);
			enemy.Talk("Ronnie");
		}
	}
	cout << " " << endl;
	cout << "Now that introductions are out of the way, let's practice throwing a punch! " << endl;
	cout << "Land a good hit, like so. " << endl;
	cout << " " << endl;
	Unit character("Peach", 100, 10);
	character.damageDone(100, 10);
	cout << " " << endl;
	cout << "(Press '1' to attack!) " << endl;
	cin >> attack;
		if (attack == 1) 
		{
			if (choice == 1) 
			{
				cout << " " << endl;
				Zombie zombie(charName, 100, 25);
				Werewolf enemy("Ronnie", 100, 25);

				zombie.damageDone(100, 25);
				enemy.damageDone(100, 25);
				hitsDone += 1;
			}
			else if (choice == 2)
			{
				cout << " " << endl;
				Werewolf werewolf(charName, 100, 25);
				Zombie enemy("Ronnie", 100, 25);
				
				werewolf.damageDone(100, 25);
				enemy.damageDone(100, 25);
				hitsDone += 1;
			}
		}
		else if (attack != 1)
		{
			cout << "Don't just stand there!" << endl;
			cin >> attack;
		}
	cout << " " << endl;
	cout << "Solid hits on both sides!" << endl;
}
