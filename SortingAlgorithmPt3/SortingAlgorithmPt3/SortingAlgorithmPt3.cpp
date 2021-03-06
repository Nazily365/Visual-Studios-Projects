// SortingAlgorithmPt3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void sortArray(int myArray[], int size);

int main()
{
	cout << "Sorting an array using Quick Sort\n" << endl;
	cout << "Before sort, array contains elements:" << endl;

	int myArray[10] = { 3, 9, 2, 7, 1, 5, 4, 10, 8, 6 };
	int arraySize = 10;


	for (int i = 0; i < arraySize; i++) {

		cout << myArray[i] << " ";
	}

	//Quick sort occurs
	sortArray(myArray, arraySize);

	cout << "\nAfter sort, array contains elements:" << endl;

	for (int i = 0; i < arraySize; i++) {

		cout << myArray[i] << " ";
	}

    return 0;
}


void sortArray(int myArr[], int size) {

	int hinge = myArr[size - 1];

	int lowerHalf = 0;

	for (int i = 0; i < size - 1; i++) {

		if (myArr[i] <= hinge) {

			int swap = myArr[lowerHalf];
			myArr[lowerHalf] = myArr[i];
			myArr[i] = swap;
			lowerHalf++;
		}
	}
	
	//Puts the hinge in place
	int swap = myArr[lowerHalf];
	myArr[lowerHalf] = myArr[size - 1];
	myArr[size - 1] = swap;

}

