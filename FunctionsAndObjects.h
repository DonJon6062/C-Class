#pragma once

using namespace std;


class Birds //class name
{
public:
	string name;
	string size;

	Birds(string name, string size) //constructor
	{
		name = name;
		size = size;
	}
	//all birds peck and walk
	void peck() 
	{
		cout << "Peck Peck!\n";
	}

	void walk() 
	{
		cout << "Walking by!\n";
	}
};

class Insects //class name
{
public:
	string name;
	string size;

	Insects(string name, string size) //constructor
	{
		name = name;
		size = size;
	}
	//all insects munch and crawl
	void munch()
	{
		cout << "Munching!\n";
	}

	void skitter()
	{
		cout << "Skitter Skitter!\n";
	}
};
void watchOstrich();

void watchOstrich()
{
    Birds ostrich("ostrich", "large");
    ostrich.peck();
    ostrich.walk();
    cout << "You're watching the ostrich.\n";
}

void watchPenguin();

void watchPenguin()
{
    Birds penguin("penguin", "medium");
    penguin.peck();
    penguin.walk();
    cout << "You're watching the penguin.\n";
}

void watchCrane();

void watchCrane()
{
    Birds crane("crane", "large");
    crane.peck();
    crane.walk();
    cout << "You're watching the crane.\n";
}

void watchChicken();

void watchChicken()
{
    Birds chicken("chicken", "small");
    chicken.peck();
    chicken.walk();
    cout << "You're watching the chicken.\n";
}

void watchKiwi();

void watchKiwi()
{
    Birds kiwi("kiwi", "small");
    kiwi.peck();
    kiwi.walk();
    cout << "You're watching a kiwi.\n";
}
void watchMantis();

void watchMantis()
{
    Insects mantis("mantis", "small");
    mantis.munch();
    mantis.skitter();
    cout << "You're watching a mantis.\n";
}

void watchSnail();

void watchSnail()
{
    Insects snail("snail", "medium");
    snail.munch();
    snail.skitter();
    cout << "You're watching a snail.\n";
}

void watchWeevil();

void watchWeevil()
{
    Insects weevil("weevil", "small");
    weevil.munch();
    weevil.skitter();
    cout << "You're watching the weevil.\n";
}

void watchMillipede();

void watchMillipede()
{
    Insects millipede("millipede", "large");
    millipede.munch();
    millipede.skitter();
    cout << "You're watching a millipede.\n";
}

void watchWasp();

void watchWasp()
{
    Insects wasp("wasp", "small");
    wasp.munch();
    wasp.skitter();
    cout << "You're watching a wasp.\n";
}

