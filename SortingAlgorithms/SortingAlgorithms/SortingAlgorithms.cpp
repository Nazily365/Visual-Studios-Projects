// SortingAlgorithms.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

void sortVector(vector<int>& v);

int main()
{
	cout << "Sorting a vector using Bubble Sort\n" << endl;
	cout << "Before sort, vector contains elements:" << endl;

	vector<int> myVector;
	int starter = 10;

	while(starter > 0) {

		myVector.push_back(starter);
		starter--;
	}

	for(unsigned int i = 0; i < myVector.size(); i++) {

		cout << myVector[i] << " ";
	}

	//Bubble sort occurs
	sortVector(myVector);

	cout << "\nAfter sort, vector contains elements:" << endl;

	for (unsigned int i = 0; i < myVector.size(); i++) {

		cout << myVector[i] << " ";
	}
    return 0;
}

void sortVector(vector<int>& myVec) {

	bool sorted = false;

	while (sorted == false) {

		bool notYet = false;

		for (unsigned int i = 0; i < myVec.size(); i++) {

			if (i < myVec.size() - 1) {

				if (myVec[i] > myVec[i + 1]) {
					int swapper = myVec[i];
					myVec[i] = myVec[i + 1];
					myVec[i + 1] = swapper;
				}
			}
		}

		for (unsigned int i = 0; i < myVec.size(); i++) {

			if (i < myVec.size() - 1) {

				if (myVec[i] > myVec[i + 1]) {

					notYet = true;
				}
			}
		}

		if (notYet == false) {

			sorted = true;
		}
	}
}

