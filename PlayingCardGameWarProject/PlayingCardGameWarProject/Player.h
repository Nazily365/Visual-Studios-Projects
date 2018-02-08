#pragma once

#include "Card.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player {

public:

	Player(string name);
	~Player();
	void SetName(string name);
	string GetName();
	vector<Card*> &GetHand();

private:

	string m_name;
	vector<Card*> m_hand;

};

