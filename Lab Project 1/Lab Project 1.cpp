/*
This program calculates the difference between two times in military format
and displays the calculates difference in a human readable format

Written By Jonathan Buma
*/

//Include required libraries
#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


void main()
{
	//Declare Variables
	char flag;
	int firstTime;
	int secondTime;
	int difference;
	int firstLength;
	int secondLength;
	string stringDif;
	string hours;
	string minutes;
	string firstIn;
	string secondIn;
	const int timeLimit = 4;

	//Prompt user to input times and set variables to user input values
	cout << "Please enter the first time" << endl;
	cin >> firstTime;
	cout << "Please enter the second time" << endl;
	cin >> secondTime;

	//Convert inputed times to string in order to measure length to ensure correct format
	firstIn = to_string(firstTime);
	secondIn = to_string(secondTime);
	firstLength = firstIn.length();
	secondLength = secondIn.length();

	//Check if input lengths exceed military time format
	if (firstLength > timeLimit || secondLength > timeLimit) {
		//Inform user that entered times were invalid
		cout << "The time you entered is not in military time format" << endl;
		cout << "Either " << firstLength << " or " << secondLength << " is more than " << timeLimit << " integers" << endl;
		cout << "Press any key to continue" << endl;
		cin >> flag;
		return;
	}

	//On input of correctly formatted times calculate difference
	else {
		//Check which time is greater to ensure correct calculation for all scenarios
		if (firstTime > secondTime) {
			difference = firstTime - secondTime;
		}
		else {
			difference = secondTime - firstTime;
		}

		//Convert difference calculation to string in order to separate hours from minutes
		stringDif = to_string(difference);

		//Depending on length of difference calculation, separate integers from string to a human readable format
		if (stringDif.length() <= 3) {
			hours = stringDif.substr(0, 1);
			minutes = stringDif.substr(1);
		}
		else {
			hours = stringDif.substr(0, 2);
			minutes = stringDif.substr(2);
		}

		//Display calculation results to user
		cout << "The difference between " << firstTime << " and " << secondTime << " is " << hours << " Hours and " << minutes << " Minutes" << endl;
		cout << "Press any key to continue" << endl;
		cin >> flag;

		//End of program
		return;
	}
}

