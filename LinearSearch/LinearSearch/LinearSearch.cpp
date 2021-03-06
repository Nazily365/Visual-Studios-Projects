// LinearSearch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

bool linearSearch(int myArray[], int arraySize, int userNum);


int main()
{

	int myArray[] = { 10, 5, 2, 9, 1, 7, 3, 8, 6, 4 };

	int userNum = 0;
	int numElems = sizeof(myArray) / sizeof(myArray[0]);

	cout << "An array has " << numElems << " int elements. Try entering a number and see if it's in the array.\nNumber to find:" << endl;
	cin >> userNum;

	bool found = linearSearch(myArray, numElems, userNum);

	if (found == true) {

		cout << "\n" << userNum << " is an element of the array." << endl;
	}
	else {

		cout << "\n" << userNum << " is NOT an element of the array." << endl;
	}

    return 0;
}

bool linearSearch(int myArray[], int arraySize, int userNum)
{

	for (int i = 0; i < arraySize; i++) {

		if (myArray[i] == userNum) {

			return true;
		}

	}

	return false;
}
