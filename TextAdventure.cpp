// TextAdventure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include <fstream>
//using std::endl;
using namespace std;

//the signifier of your limited tries
int outOfTime = 3; //global value int 
bool day1 = false; 
bool day2 = false;
bool day3 = false;
bool day4 = false;
bool day5 = false;
bool day6 = false;
bool day7 = false;


//an extensive list of the acts structure
void beginning();
void dayOne();
void dayTwo();
void dayThree();
void dayFour();
void dayFive();
void daySix();
void daySeven();
void Finale();

void check(); //small function that shows global int
void choice(); //the meat and potatoes of choices

void check() 
{
	cout << outOfTime << endl; //accesses global variable
	choice(); //goes back to the main function
}

void choice() 
{
	char select; //local vars
	int daySelect; //for choices made only here

	if (outOfTime == 0)
	{
		Finale(); //checks whether or not the final function should be run first
	}
	else 
	{
		cout << "Use 'C' to check those charges, and 'T' to traverse the days. Uppercase, please!" << endl; //instructions
		cin >> select; //gets a letter variable
		if (select == 'C')
		{
			check(); //runs the smallest function
		}
		else if (select == 'T')
		{
			cout << "How many days back? 1-7; Pick 1 for yesterday, and 7 for the beginning of the week." << endl; //instructions
			cin >> daySelect; //aptly named functions and variable
			if (daySelect == 1)
			{
				dayOne();
			}
			if (daySelect == 2)
			{
				dayTwo();
			}
			if (daySelect == 3)
			{
				dayThree();
			}
			if (daySelect == 4)
			{
				dayFour();
			}
			if (daySelect == 5)
			{
				dayFive();
			}
			if (daySelect == 6)
			{
				daySix();
			}
			if (daySelect == 7)
			{
				daySeven();
			}
		}
		else //in the case of a misclick for the char
		{
			cout << "Invalid! You are using uppercases, yeah?" << endl;
		}
	}
}
void beginning() //textdump that runs first
{
	if (outOfTime < 0)
	{
		cout << "Your wrist time machine buzzes with what is definitely a 'no' buzz." << endl;
	}
	else
	{
		cout << "As the sun shines through your window, you can't help but think so. Good morning!" << endl;
		cout << "Your sweet dreams were interrupted rather unfortunately, with quite the ring from your nearby phone." << endl;
		cout << "Your alarm successfully woke you up, but fails to inform you /why/ you need to wake up early." << endl;
		cout << "Curses, past you, as present you is living with the consequenses of those actions!" << endl;
		cout << "Luckily, however, you still have that spur-of-the-moment-purchase time machine. Or more accurately, leased time machine." << endl;
		cout << "It wasn't cheap, and due to being slightly delinquent on those payments, you're stuck with a limited number of jumps: 3." << endl;
		cout << "To make matters worse, the time you're able to travel is only one week. What a scam for the price! at least its wristband-like shape makes it easy to carry." << endl;
		cout << "The restriction is useful for avoiding creating too many paradoxes, you've only met another you once before, but if you set an alarm it's important." << endl;
		cout << "May as well see for yourself, from yourself what it is you've forgotten. No use wasting any more time!" << endl;
		choice();
	}
}

void dayOne() //if one is seleted; subtracts from the global variable once it has run, bday card
{
	if (outOfTime < 0)
	{
		cout << "Your wrist time machine buzzes with what is definitely a 'no' buzz." << endl;
		Finale();
	}
	else
	{
		cout << "Yesterday, the only time you've seen yourself. Probably should've asked then, yeah?" << endl;
		cout << "Time traveller you was rummaging through present you's own belongings until present you walked in, then time traveller you let out a shrill cry before dissappearing." << endl;
		cout << "You were kind of scared after that. Who wouldn't be? Seeing another you scream and become nothing." << endl;
		cout << "Now, the time traveler rather than the time travel..-ee? That was funny, to scare yourself. You do it again when past you walks in." << endl;
		cout << "Unfortunately, nothing of note other than /a/ card, giving the name of your friend, Francis. Not enough info yet.." << endl;
		if (outOfTime > -1)
		{
			outOfTime -= 1;
			day1 = true; 
		}
		choice();
	}
}

void dayTwo()  //points user to day four, a failsafe in the beginning to ensure the finale plays at 0 for the global int
{
	if (outOfTime < 0)
	{
		cout << "Your wrist time machine buzzes with what is definitely a 'no' buzz." << endl;
		Finale();
	}
	else
	{
		cout << "The day of The Incident, aka the Baby Duck Rescue of two days ago. " << endl;
		cout << "You weren't in the house then, and as such, you can turn the place inside out. " << endl;
		cout << "You did wonder if yu had misplaced your things when you got back, but now you see, it's future shenanigans. " << endl;
		cout << "You disvover the remnants of what was, once, a rather important looking piece of cardstock, now eaten by one of your friends' dogs. " << endl;
		cout << "If your memory serves you, the dog came over and tore it to shreds two days ago. " << endl;
		if (outOfTime > -1)
		{
			outOfTime -= 1;
			day2 = true;
		}
		choice();
	}
}

void dayThree() //gift wrapping
{
	if (outOfTime < 0)
	{
		cout << "Your wrist time machine buzzes with what is definitely a 'no' buzz." << endl;
		Finale();
	}
	else
	{
		cout << "The day where after the Dog Mischief Event, you and your friends went to a doggy park. " << endl;
		cout << "Cute furball, needed a chew toy. Very bite-y. " << endl;
		cout << "You may as well head out, too.  " << endl;
		cout << "In your travels you find gift wrap fairly cheap, which you remember buying. So you were making some gift look pretty. " << endl;
		if (outOfTime > -1)
		{
			outOfTime -= 1;
			day3 = true;
		}
		choice();
	}
}

void dayFour() //pastry recipie
{
	if (outOfTime < 0)
	{
		cout << "Your wrist time machine buzzes with what is definitely a 'no' buzz." << endl;
		Finale();
	}
	else
	{
		cout << "The day your friend showed off their new pooch, which eagerly decimated a few of your items. " << endl;
		cout << "Past you is asleep, however. you could warn yourself, but.. the dog was cute, and nothing major was damaged. " << endl;
		cout << "A few bits of paper is nothing! Speaking of, in an inner monologue, you see a list of ingredients.  " << endl;
		cout << "Flour, eggs, baking soda, cocoa powder.. definitely some sort of pastry recipe. " << endl;
		if (outOfTime > -1)
		{
			outOfTime -= 1;
			day4 = true;
		}
		choice();
	}
}

void dayFive() //gift
{
	if (outOfTime < 0)
	{
		cout << "Your wrist time machine buzzes with what is definitely a 'no' buzz." << endl;
		Finale();
	}
	else
	{
		cout << "You relive the experience of faceplanting fresh snow. It stormed the day before, and it's one of the best parts. " << endl;
		cout << "Yeah, it was too snowy to go anywhere in short notice, but the slopes of white were a welcome sight. " << endl;
		cout << "You also know where the dent on your lawn came from. You. " << endl;
		cout << "Looking around inside afterward, and find a figurine from a game Francis loves. It's not near Christmas, nor was it on sale.. " << endl;
		if (outOfTime > -1)
		{
			outOfTime -= 1;
			day5 = true;
		}
		choice();
	}
}

void daySix() //event plan
{
	if (outOfTime < 0)
	{
		cout << "Your wrist time machine buzzes with what is definitely a 'no' buzz." << endl;
		Finale();
	}
	else
	{
		cout << "The day of Smores, where you also.. burned your calendar. As kindling... It should still be intact yesterday though. Hopefully. " << endl;
		cout << "You see a list of places that your friends enjoy hanging out at. Party paces, or at least fun experience places. " << endl;
		cout << "Definitely palnning some variety of event, but you suppose the idea was dumped. It looks like a very, very unfinished plan. " << endl;
		if (outOfTime > -1)
		{
			outOfTime -= 1;
			day6 = true;
		}
		choice();
	}
}

void daySeven() //the answer
{
	if (outOfTime < 0)
	{
		cout << "Your wrist time machine buzzes with what is definitely a 'no' buzz." << endl;
		Finale();
	}
	else
	{
		cout << "You look at the calendar that you used as kindling the next day. Smores are good, and it's the end of the year!" << endl;
		cout << "You removed the staples, too. Only paper went in. " << endl;
		cout << "the urge to facepalm overwhelms you. really??? " << endl;
		cout << "Written right on current day, Francis' birthday. How could you forget!?? " << endl;
		if (outOfTime > -1)
		{
			outOfTime -= 1;
			day7 = true;
		}
		choice();
	}
}

void Finale() //resolution; going to add a check to see what numbers have been selected (using booleans) and from there offer clues rather than stating the fact.
{
	cout << "Drats! Time isn't on your side. Now you're being booted back to current day.." << endl;
	cout << "Your head spins as you return to current day, your house. Rapid fire time travel doesn't feel good.." << endl;
	cout << "With your evidence, what is happening today? " << endl;
	if (day7 == true) //get it to stop saying 7 is true after the fact
	{
		cout << "Well, now you know you know. It's Francis' birthday!" << endl;
	}
	else
	{
		if (day1 == true)
		{
			cout << "You saw a decorative card..." << endl;
		}
		if (day2 == true)
		{
			if (day4 == true)
			{
				cout << "You saw what that paper was, thankfully." << endl;
			}
			else 
			{
				cout << "Some paper shreds... " << endl;
			}
		}
		if (day3 == true)
		{
			cout << "Gift wrapping that you bought..." << endl;
		}
		if (day4 == true)
		{
			cout << "A recipie for some pastry..." << endl;
		}
		if (day5 == true)
		{
			cout << "A gift, presumably, based on what it was, for Francis..." << endl;
		}
		if (day6 == true)
		{
			cout << "Some plans for some event being made..." << endl;
		}
	}
}

int main()
{
	char again;

	while (true) 
	{
		while (outOfTime > 0)
		{
			beginning();
		}
		//restart code
		cout << "Play again? Y or N" << endl;
		cin >> again;
		if (again == 'N')
		{
			break;
		}
		if (again == 'n')
		{
			break;
		}
		else if (again == 'Y')
		{
			outOfTime = 3;
		}
		else if (again == 'y')
		{
			outOfTime = 3;
			day1 = false;
			day2 = false;
			day3 = false;
			day4 = false;
			day5 = false;
			day6 = false;
			day7 = false;
		}
		else
		{
			cout << "Please use Y or N!" << endl;
		}
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
// .... .- .--. .--. -.-- / -.. . -.-. --- -.. .. -. --.
// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
