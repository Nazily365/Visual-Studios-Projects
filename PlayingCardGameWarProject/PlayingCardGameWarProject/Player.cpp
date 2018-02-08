#include "stdafx.h"
#include "Player.h"

Player::Player(string name) {

	m_name = name;
}

Player::~Player() {

	unsigned int vecSize = m_hand.size();

	if (vecSize > 0) {

		for (unsigned int i = 0; i < m_hand.size(); i++) {

			delete m_hand[i];
			m_hand[i] = NULL;
		}

	}

}

void Player::SetName(string name) {

	m_name = name;
}

string Player::GetName() {

	return m_name;
}

vector<Card*>& Player::GetHand() {

	return m_hand;
}
