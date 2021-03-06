// BunnyRancherProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Ranch.h"
using namespace std;

const string NAMES_FILE = "BunnyNames.txt";

int main()
{
	cout << "Welcome to the Bunny Rancher Program. You start off with 5 bunnies\nand get to see how your colony grows but you must be careful of the mutant bunnies!\n" << endl;
	cout << "When you are ready to begin your colony enter '1' or enter '2' to quit.\n" << endl;

	int choice = 0;

	cout << "1. Start Colony\n2. Quit" << endl;
	cin >> choice;

	while (choice < 1 || choice > 2) {

		cout << "Please enter '1' or '2'." << endl;
		cin >> choice;
	}

	if (choice == 1) {

		cout << "\nColony has successfully been created with 5 bunnies.\n" << endl;

		Ranch userRanch(NAMES_FILE);

		int continueGame = 0;

		do {

			userRanch.DisplayColony();

			cout << "\nAre you ready to continue to the next year?(1=yes/2=no)" << endl;
			cin >> continueGame;

			while (continueGame < 1 || continueGame > 2) {

				cout << "Please enter '1' or '2'." << endl;
				cin >> choice;
			}

			if (continueGame == 1) {

				userRanch.AnotherYear();
			}
			else {

				cout << "\nAww abandoning your ranch so soon??\n" << endl;
			}

		} while (continueGame == 1);


	}

	cout << "Thanks for using the Bunny Rancher Program! All programming done by Nazily Zaza." << endl;
    return 0;
}

//Pontential Add-ons:
//Allow the user the ability to kill half the bunny population if they so desire by typing a key
//Make the program run in real time, a turn occuring every 2 seconds