// CreateDestroy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <typeinfo>
#include <utility>
#include <Windows.h>
#include <string>
using namespace std;

class Animal
{
public:
	//constructor
	Animal(int* age, int* size, string* species, string* habitat)
	{

	}
	//method
	void Describe(int* age, int* size, string* species, string* habitat)
	{
		cout << "This is a "<<species<<", it is "<<age<< " years old and lives in the " <<habitat<<"! It is also "<<size<< "inches tall!" << endl;
	}
	//deconstructor
	~Animal()
	{
	};
};

int main()
{
	int animalAge;
	int animalSize;
	string animalSpecies;
	string animalHabitat;

	int randomAge = rand() % 20 + 1;
	int randomSize = rand() % 66 + 12;

	int* age = new int(randomAge);
	int* size = new int(randomSize);
	string* species = new string("pitbull");
	string* habitat = new string("shelter");

	Animal Betty(age, size, species, habitat);
	Animal Sally(age, size, species, habitat);
	Animal Ron(age, size, species, habitat);
	Animal Tim(age, size, species, habitat);
	Animal Alf(age, size, species, habitat);

	cout << "Welcome to the Pitbull Rescue! Would you like to meet our dogs?" << endl;
	while (true)
	{
		int choice;
		//explain options
		cout << "What would you like to do? \n1. Meet Betty. \n2. Meet Ron. \n3. Meet Sally.\n4. Meet Tim.\n5. Meet Alf.\n6. Leave." << endl;
		cin >> choice;
		if (choice == 1)
		{
			Betty.Describe(age, size, species, habitat);
		}
		if (choice == 2)
		{
			Ron.Describe(age, size, species, habitat);
		}
		if (choice == 3)
		{
			Sally.Describe(age, size, species, habitat);
		}
		if (choice == 4)
		{
			Tim.Describe(age, size, species, habitat);
		}
		if (choice == 5)
		{
			Alf.Describe(age, size, species, habitat);
		}
		if (choice == 6)
		{
			cout << "Thanks for coming to see our dogs!" << endl;
			break;
		}
	}

	delete size;
	delete age; 
	delete species;
	delete habitat;
}