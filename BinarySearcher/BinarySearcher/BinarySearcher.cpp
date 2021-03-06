// BinarySearcher.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

bool binarySearch(int myArray[], int minn, int maxx, int num, int& numTurns, int maxNum, int minNum);

int main()
{

	int myArray[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100 };

	int userNum = 0;
	int maxx = sizeof(myArray) / sizeof(myArray[0]);
	int maxNum = maxx + 1;
	int minNum = 0;
	int minn = 0;
	int numTurns = 1;

	cout << "Binary Search implementation\n" << endl;
	cout << "A sorted array has " << maxx << " int elements. Try entering a number and see if it's in the array.\nNumber to find:" << endl;
	cin >> userNum;

	bool found = binarySearch(myArray, minn, maxx - 1, userNum, numTurns, maxNum, minNum);

	if (found == true) {

		cout << "\n" << userNum << " was found inside the array. It took " << numTurns << " turns for Binary Search to find your number." << endl;
	}
	else {

		cout << "\n" << userNum << " was NOT found inside the array. Binary Search used a total of " << numTurns << " turns before figuring out the number was not in the array." << endl;
	}
	return 0;
}

bool binarySearch(int myArray[], int minn, int maxx, int num, int& numTurns, int maxNum, int minNum) {

	if (maxx >= minn && num < maxNum && num > minNum) {

		int midCut = minn + (maxx - minn) / 2; //take average of min and max

		if (myArray[midCut] == num) {

			return true; //When found returns true
		}

		if (num < myArray[midCut]) {

			numTurns += 1;
			return binarySearch(myArray, minn, midCut - 1, num, numTurns, maxNum, minNum); //when the # being looked for is smaller than the middle guess change the maxx to be the middle guess - 1
		}

		numTurns += 1;
		return binarySearch(myArray, midCut + 1, maxx, num, numTurns, maxNum, minNum); //when the # being looked for is bigger than the middle guess change the minn to be the middle guess + 1
	}

	return false; //If element is never found returns false
}

