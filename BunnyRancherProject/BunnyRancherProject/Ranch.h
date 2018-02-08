#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Node.h"
#include "Bunny.h"

using namespace std;

//const string NAMES_FILE = "BunnyNames.txt";

class Ranch {

public:
	Ranch();
	Ranch(string filename);
	~Ranch();
	void AnotherYear();
	void GrowUp();
	void BunnyBirth(int numBirths);
	void BunnyDeath();
	void MutantTransform(); 
	void BunnyPurge(); //Once Bunny Population gets to 1000 half the bunnies die
	void DisplayColony(); //Prints all the information of each Bunny in the Linked List
	int GetPop(); //Gets the size of the Linked List
	int GetYear(); //returns how many turns (in years) the program has run

private:
	Node* m_head; //Will be the first bunny in the Linked List
	int m_bunnyPop; //size of the Linked List
	int m_years;
	vector<string> m_bunnyNames;

};