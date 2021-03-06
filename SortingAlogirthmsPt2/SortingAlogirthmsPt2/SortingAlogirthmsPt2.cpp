// SortingAlogirthmsPt2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


using namespace std;

void sortArray(int a[], int size);

int main()
{
	cout << "Sorting an array using Selection Sort\n" << endl;
	cout << "Before sort, array contains elements:" << endl;

	int myArray[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	int arraySize = 10;


	for (int i = 0; i < arraySize; i++) {

		cout << myArray[i] << " ";
	}

	//Selection sort occurs
	sortArray(myArray, arraySize);

	cout << "\nAfter sort, array contains elements:" << endl;

	for (int i = 0; i < arraySize; i++) {

		cout << myArray[i] << " ";
	}
    return 0;
}

void sortArray(int myArr[], int size)
{

	int startPosition = 0;
	bool sorted = false;
	int smallestPosition;

	while (sorted == false) {

		bool notYet = false;

		int smallestNum = myArr[startPosition];

		for (int i = startPosition; i < size; i++) {

			if (i < size - 1) {

				if (smallestNum > myArr[i + 1]) {

					smallestNum = myArr[i + 1];
					smallestPosition = i + 1;
				}
			}
		}

		int switcher = myArr[startPosition];
		myArr[startPosition] = smallestNum;
		myArr[smallestPosition] = switcher;

		startPosition++;

		for (int i = 0; i < size; i++) {

			if (i < size - 1) {

				if (myArr[i] > myArr[i + 1]) {

					notYet = true;
				}
			}
		}

		if (notYet == false) {

			sorted = true;
		}
	}
}
