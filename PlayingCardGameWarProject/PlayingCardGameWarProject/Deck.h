#pragma once

#include "Card.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Deck {

public:

	Deck();
	~Deck();
	Deck(const Deck& other);
	Deck& operator=(const Deck& other);
	vector<Card*> &GetDeck();

private:

	vector<Card*> m_deck;

};

