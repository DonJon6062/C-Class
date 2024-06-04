// ConsoleAppGameOver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::endl;
using namespace std;
int main()
{
	int i = 0;

    string firstName;
    string weather;
    string emotion;
    string verb;
    string adverb;
    int frequency;
    char choiceAM;
    char choicePM;
    char choiceAfterNoon;
    char again;
    double time;

    while (true)
	{
        //Questionare for variables that will be used
        cout << " This story needs for you to finish it! Please complete the prompts." << endl;
        cout << "What time is it? Please use military time /and/ the period/decimal instead of a colon. (ex: 13.58 is 1:58)" << endl;
        //double
        cin >> time;
        //string
        cout << "Please enter a name: " << endl;
        cin >> firstName;
        cout << "Please enter a type of weather (ex: snowy, sunny, windy..):" << endl;
        cin >> weather;
        cout << "Please enter an emotion: " << endl;
        cin >> emotion;
        cout << "Please enter a /singular/ verb (ex: run, sleep, play..): " << endl;
        cin >> verb;
        cout << "Please enter an adverb (ex: quickly, slowly, quietly..): " << endl;
        cin >> adverb;
        cout << "Finally, give me a number! " << endl;
        //int
        cin >> frequency;
        if (frequency == 69) {
            cout << "nice" << endl;
        }
        cout << "Thank you!" << endl;
        cout << firstName << " is " << emotion << " today, as today is " << weather << "." << endl;
        cout << weather << " days are perfect for " << verb << "ing, and on " << weather << " days, " << firstName << " is " << emotion << " to do so." << endl;
        cout << firstName << " " << adverb << " " << verb << "s " << frequency << " time(s)." << endl;

        //choice circumstances are dependent on the time entered previously
        if (time < 12.00)
        {
            cout << "It's rather early. Which means it is the perfect time to get productive. Should " << firstName << " start doing something? (Y/N)" << endl;
            cin >> choiceAM;
            if (choiceAM == 'Y', 'y')
            {
                cout << "And so " << firstName << " started.. well.. " << verb << "ing even more " << adverb << " than before. I suppose that's how they have fun." << endl;
                cout << "Play again? (Y/N) (Please use lowercase)" << endl;
                cin >> again;
                if (again == 'n')
                {
                    break;
                }
            }
            else
            {
                cout << "Huh. Really? Alright. I can't change your mind." << endl;
                cout << "Play again? (Y/N) (Please use lowercase)" << endl;
                cin >> again;
                if (again == 'n')
                {
                    break;
                }
            }
        }
        else if (time > 18.00)
        {
            cout << "I'm certain " << firstName << " has had an enthralling time " << verb << "ing, but surely they're tired now? They should sleep, yeah? (Y/N)" << endl;
            cin >> choicePM;
            if (choicePM == 'Y', 'y')
            {
                cout << "And so they have a peaceful sleep. " << endl;
                cout << "Play again? (Y/N) (Please use lowercase)" << endl;
                cin >> again;
                if (again == 'n')
                {
                    break;
                }
            }
            else
            {
                cout << firstName << "'s head is going to HURT later, but it's a personal choice." << endl;
                cout << "Play again? (Y/N) (Please use lowercase)" << endl;
                cin >> again;
                if (again == 'n')
                {
                    break;
                }
            }
        }
        else
        {
            cout << "It's lunchtime, prime time to get something to eat. Should " << firstName << " get something to eat? (Y/N)" << endl;
            cin >> choiceAfterNoon;
            if (choiceAfterNoon == 'Y', 'y')
            {
                cout << "And what a lovely meal they have. " << endl;
                cout << "Play again? (Y/N) (Please use lowercase)" << endl;
                cin >> again;
                if (again == 'n')
                {
                    break;
                }

            }
            else
            {
                cout << "That isn't really healthy. They should have something. If they're nauseous, a bit of salt can help with that. " << endl;
                cout << "Play again? (Y/N) (Please use lowercase)" << endl;
                cin >> again;
                if (again == 'n')
                {
                    break;
                }
            }
        }
    } 
    cout << "Have a swell day!" << endl;
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
