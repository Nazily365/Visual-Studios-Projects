#pragma once

#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "Computer.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

class Table {

public:

	Table();
	void StartGame();
	void Instructions();
	bool WinnerOrLoser(vector<Card*>& user, vector<Card*>& computer);
	void EndGame();
	void War(vector<Card*>& user, vector<Card*>& computer);
	void ShuffleDecks(vector<Card*>& user, vector<Card*>& computer);
	void TakeATurn(vector<Card*>& user, vector<Card*>& computer, int& turn);

};

