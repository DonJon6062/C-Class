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
    const int numProfessors = 10;
    string professorArray[numProfessors] = { "Dr.Brendly-Clark","Mr.Habib","Mrs.Crusoe","Mr.Hreshchyshyn","Mrs.Peters","Dr.Brokaw","Mr.Sinca-Williams","Dr.Pike","Mr.Clark","Mrs.Valenzuela"};

    //state who they are in order
    for (int i = 0; i < 10; i++)
    {
        cout << professorArray[i] << " " << endl;
    }
    //run the game until the player wants to stop
    while (true)
    {
        //play ten times
        for (int i = 0; i < 10; i++)
        {
            //ask user to select a professor
            cout << "Enter a number between 1 and 10 to choose a professor!" << endl;
            int professorIndex;
            cin >> professorIndex;

            //select the professor correctly
            string visitingProfessor = professorArray[professorIndex - 1];
            string hypotheticalProfessor = professorArray[rand()% numProfessors];
            while (hypotheticalProfessor == visitingProfessor)
            {
                hypotheticalProfessor = professorArray[rand() % numProfessors];
            }

            //restate selected professor, enable guessing
            cout << "Guess where " << visitingProfessor << " will visit! Select a number between 1 and 20." << endl;
            cin >> guess;
            
            //random number generator picks professor room from pool of 1-20
            int answer = rand() % 20 + 1; 

            //generate a random number out of 20 for other professors to occupy
            int otherProf_1 = rand() % 20 + 1;
            if (otherProf_1 == answer) 
            {
                otherProf_1 = rand() % 20 + 1;
                while (otherProf_1 == answer)
                {
                    otherProf_1 = rand() % 20 + 1;
                }
            }
            //second
            int otherProf_2 = rand() % 20 + 1;
            if (otherProf_2 == answer || otherProf_2 == otherProf_1) 
            {
                otherProf_2 = rand() % 20 + 1;
                while (otherProf_2 == answer || otherProf_2 == otherProf_1)
                {
                    otherProf_2 = rand() % 20 + 1;
                }
            }
            //third
            int otherProf_3 = rand() % 20 + 1;
            if (otherProf_3 == answer || otherProf_3 == otherProf_2 || otherProf_3 == otherProf_1)
            {
                otherProf_3 = rand() % 20 + 1;
                while (otherProf_3 == answer || otherProf_3 == otherProf_2 || otherProf_3 == otherProf_1)
                {
                    otherProf_3 = rand() % 20 + 1;
                }
            }
            //fourth
            int otherProf_4 = rand() % 20 + 1;
            if (otherProf_4 == answer || otherProf_4 == otherProf_3 ||otherProf_4 == otherProf_2 || otherProf_4 == otherProf_1)
            {
                otherProf_4 = rand() % 20 + 1;
                while (otherProf_4 == answer || otherProf_4 == otherProf_3 || otherProf_4 == otherProf_2 || otherProf_4 == otherProf_1)
                {
                    otherProf_4 = rand() % 20 + 1;
                }
            }
            //fifth
            int otherProf_5 = rand() % 20 + 1;
            if (otherProf_5 == answer || otherProf_5 == otherProf_4|| otherProf_5 == otherProf_3 || otherProf_5 == otherProf_2 || otherProf_5 == otherProf_1)
            {
                otherProf_5 = rand() % 20 + 1;
                while (otherProf_5 == answer || otherProf_5 == otherProf_4 || otherProf_5 == otherProf_3 || otherProf_5 == otherProf_2 || otherProf_5 == otherProf_1)
                {
                    otherProf_5 = rand() % 20 + 1;
                }
            }
            //sixth
            int otherProf_6 = rand() % 20 + 1;
            if (otherProf_6 == answer || otherProf_6 == otherProf_5 || otherProf_6 == otherProf_4 || otherProf_6 == otherProf_3 || otherProf_6 == otherProf_2 || otherProf_6 == otherProf_1)
            {
                otherProf_6 = rand() % 20 + 1;
                while (otherProf_6 == answer || otherProf_6 == otherProf_5 || otherProf_6 == otherProf_4 || otherProf_6 == otherProf_3 || otherProf_6 == otherProf_2 || otherProf_6 == otherProf_1)
                {
                    otherProf_6 = rand() % 20 + 1;
                }
            }
            //seventh
            int otherProf_7 = rand() % 20 + 1;
            if (otherProf_7 == answer || otherProf_7 == otherProf_6|| otherProf_7 == otherProf_5 || otherProf_7 == otherProf_4 || otherProf_7 == otherProf_3 || otherProf_7 == otherProf_2 || otherProf_7 == otherProf_1)
            {
                otherProf_7 = rand() % 20 + 1;
                while (otherProf_7 == answer || otherProf_7 == otherProf_6 || otherProf_7 == otherProf_5 || otherProf_7 == otherProf_4 || otherProf_7 == otherProf_3 || otherProf_7 == otherProf_2 || otherProf_7 == otherProf_1)
                {
                    otherProf_7 = rand() % 20 + 1;
                }
            }
            //eighth
            int otherProf_8 = rand() % 20 + 1;
            if (otherProf_8 == answer || otherProf_8 == otherProf_7 || otherProf_8 == otherProf_6 || otherProf_8 == otherProf_5 || otherProf_8 == otherProf_4 || otherProf_8 == otherProf_3 || otherProf_8 == otherProf_2 || otherProf_8 == otherProf_1)
            {
                otherProf_8 = rand() % 20 + 1;
                while (otherProf_8 == answer || otherProf_8 == otherProf_7 || otherProf_8 == otherProf_6 || otherProf_8 == otherProf_5 || otherProf_8 == otherProf_4 || otherProf_8 == otherProf_3 || otherProf_8 == otherProf_2 || otherProf_8 == otherProf_1)
                {
                    otherProf_8 = rand() % 20 + 1;
                }
            }
            //ninth; total of ten occupied rooms, no repeats
            int otherProf_9 = rand() % 20 + 1;
            if (otherProf_9 == answer || otherProf_9 == otherProf_8 || otherProf_9 == otherProf_7 || otherProf_9 == otherProf_6 || otherProf_9 == otherProf_5 || otherProf_9 == otherProf_4 || otherProf_9 == otherProf_3 || otherProf_9 == otherProf_2 || otherProf_9 == otherProf_1)
            {
                otherProf_9 = rand() % 20 + 1;
                while (otherProf_9 == answer || otherProf_9 == otherProf_8 || otherProf_9 == otherProf_7 || otherProf_9 == otherProf_6 || otherProf_9 == otherProf_5 || otherProf_9 == otherProf_4 || otherProf_9 == otherProf_3 || otherProf_9 == otherProf_2 || otherProf_9 == otherProf_1)
                {
                    otherProf_9 = rand() % 20 + 1;
                }
            }

            //compare values to see if user was right or wrong
            if (guess == answer)
            {
                //call user impressive for winning a 1/20 guessing game 
                cout << "Good job! You were right! " << visitingProfessor << " is there!" << endl;
                Beep(500, 1000);//hertz, milliseconds
            }
            else if (guess == otherProf_1 || guess == otherProf_2 || guess == otherProf_3 || guess == otherProf_4 || guess == otherProf_5 || guess == otherProf_6 || guess == otherProf_7 || guess == otherProf_8 || guess == otherProf_9)
            {
                //state they chose a winning room
                cout << "They weren't there, but " << hypotheticalProfessor << " was!" << endl;
                Beep(500, 1000);//hertz, milliseconds
            }
            else
            {
                //state goal number and other ppassing numbers
                cout << "Better luck next time... " << visitingProfessor << " in classroom " << answer << endl;
                cout << "Other professors were in " << otherProf_1 << ", " << otherProf_2 << ", " << otherProf_3 << ", " << otherProf_4 << ", " << otherProf_5 << ", " << otherProf_6 << ", " << otherProf_7 << ", " << otherProf_8 << ", " << otherProf_9 << endl;
                Beep(500, 1000);//hertz, milliseconds
            }
        }
        //after 10 plays, ask user if they want to continue
        cout << "The classroom part of the trip is over. Visit again? (Y/N) (Please use lowercase)" << endl;
        cin >> playAgain;
        if (playAgain == 'n')
        {
            break;
        }
    }
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
