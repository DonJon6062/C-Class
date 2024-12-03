// Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>
#include <ctime>
#include <Windows.h>
#include<thread>
using namespace std;

void liftOff(int n)
{
    cout<<"\nRocket number " << n << " blasting off!" << endl;
}


int main()
{
    //instantiate all threads
    thread rocketOne(liftOff, 1);
    thread rocketTwo(liftOff, 2);
    thread rocketThree(liftOff, 3);
    thread rocketFour(liftOff, 4);
    thread rocketFive(liftOff, 5);
    thread rocketSix(liftOff, 6);
    thread rocketSeven(liftOff, 7);
    thread rocketEight(liftOff, 8);
    thread rocketNine(liftOff, 9);
    thread rocketTen(liftOff, 10);

    //have each thread wait three seconds longer than the last
    cout << "All rockets have been cleared for takeoff." << endl;
    this_thread::sleep_for(chrono::seconds(3));
    rocketOne.join();
    this_thread::sleep_for(chrono::seconds(6));
    rocketTwo.join();
    this_thread::sleep_for(chrono::seconds(9));
    rocketThree.join();
    this_thread::sleep_for(chrono::seconds(12));
    rocketFour.join();
    this_thread::sleep_for(chrono::seconds(15));
    rocketFive.join();
    this_thread::sleep_for(chrono::seconds(18));
    rocketSix.join();
    this_thread::sleep_for(chrono::seconds(21));
    rocketSeven.join();
    this_thread::sleep_for(chrono::seconds(24));
    rocketEight.join();
    this_thread::sleep_for(chrono::seconds(27));
    rocketNine.join();
    this_thread::sleep_for(chrono::seconds(30));
    rocketTen.join();
}
