// C++Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
using std::endl;
using namespace std;

int main()
{
    //vars
    int guess;
    char playAgain;
   
    //Array of professors 
    const int numProfessors = 20;
    string professorArray[numProfessors] = {"Dr.Brendly-Clark","Mr.Habib","Mrs.Crusoe","Mr.Hreshchyshyn","Mrs.Peters","Dr.Brokaw","Mr.Sinca-Williams","Dr.Pike","Mr.Clark","Mrs.Valenzuela", "not there", "not there" , "not there" , "not there" , "not there" , "not there" , "not there" , "not there" , "not there" , "not there" };
   
    for (int i = 0; i < 10; i++) 
    {
        cout << professorArray[i] << " " << endl;
    }
    while (true) 
    {
        for (int i = 0; i < 10; i++)
        {
            //random number generator picks professor
            int answer = rand() % numProfessors + 1;
            string visitingProfessor = professorArray[answer];
            //ask user to guess professor
            cout << "Enter a number between 1 and 20 to guess what professor will visit you!" << endl;
            cin >> guess;
            //compare values to see if user was right or wrong
            if (guess != answer)
            {
                cout << "Better luck next time... the professor was " << visitingProfessor << " in classroom " << answer << endl;
                Beep(500, 1000);//hertz, milliseconds
            }
            else
            {
                cout << "Good job! you were right!" << endl;
                Beep(500, 1000);//hertz, milliseconds
            }
        }
        cout << "The classroom part of the trip is over. Visit again? (Y/N) (Please use lowercase)" << endl;
        cin >> playAgain;
        if (playAgain == 'n')
        {
            break;
        }
    }
   

    //string thisString = "Hello!";
    //cout << "Original string." << thisString;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// -.. ..- -.-. -.- ... / .- -. -.. / -.-. ..- -.-. -.- ...

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
