#include "stdafx.h"
#include "Computer.h"

const string COMPUTER_NAME = "Computer";

Computer::Computer() {

	m_name = COMPUTER_NAME;
}

Computer::~Computer() {

	unsigned int vecSize = m_hand.size();

	if (vecSize > 0) {

		for (unsigned int i = 0; i < m_hand.size(); i++) {

			delete m_hand[i];
			m_hand[i] = NULL;
		}

	}

}


void Computer::SetName(string name) {

	m_name = name;
}

string Computer::GetName() {

	return m_name;
}

vector<Card*>& Computer::GetHand() {

	return m_hand;
}
