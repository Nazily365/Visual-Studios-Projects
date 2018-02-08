#include "stdafx.h"
#include "Deck.h"

const int NUM_CARDS_IN_DECK = 52;

Deck::Deck() {

	int typeCounter = 1;
	int nameCounter = 2;
	int valueCounter = 2;

	for (int i = 0; i < NUM_CARDS_IN_DECK; i++) {

		Card* newCard;

		if (typeCounter == 1 && nameCounter == 2) {
			newCard = new Card(typeCounter, nameCounter, valueCounter);
		}
		else if (typeCounter == 1 && nameCounter == 3) {
			newCard = new Card(typeCounter, nameCounter, valueCounter);
		}
		else if (typeCounter == 1 && nameCounter == 4) {
			newCard = new Card(typeCounter, nameCounter, valueCounter);
		}
		else if (typeCounter == 1 && nameCounter == 5) {
			newCard = new Card(typeCounter, nameCounter, valueCounter);
		}
		else if (typeCounter == 1 && nameCounter == 6) {
			newCard = new Card(typeCounter, nameCounter, valueCounter);
		}
		else if (typeCounter == 1 && nameCounter == 7) {
			newCard = new Card(typeCounter, nameCounter, valueCounter);
		}
		else if (typeCounter == 1 && nameCounter == 8) {
			newCard = new Card(typeCounter, nameCounter, valueCounter);
		}
		else if (typeCounter == 1 && nameCounter == 9) {
			newCard = new Card(typeCounter, nameCounter, valueCounter);
		}
		else if (typeCounter == 1 && nameCounter == 10) {
			newCard = new Card(typeCounter, nameCounter, valueCounter);
		}
		else if (typeCounter == 1 && nameCounter == 11) {
			newCard = new Card(typeCounter, nameCounter, valueCounter);
		}
		else if (typeCounter == 1 && nameCounter == 12) {
			newCard = new Card(typeCounter, nameCounter, valueCounter);
		}
		else if (typeCounter == 1 && nameCounter == 13) {
			newCard = new Card(typeCounter, nameCounter, valueCounter);
		}
		else if (typeCounter == 1 && nameCounter == 14) {
			newCard = new Card(typeCounter, nameCounter, valueCounter);
			nameCounter = 1;
			valueCounter = 1;
		}

		else if (typeCounter == 2 && nameCounter == 2) {
			newCard = new Card(typeCounter, nameCounter, valueCounter);
		}
		else if (typeCounter == 2 && nameCounter == 3) {
			newCard = new Card(typeCounter, nameCounter, valueCounter);
		}
		else if (typeCounter == 2 && nameCounter == 4) {
			newCard = new Card(typeCounter, nameCounter, valueCounter);
		}
		else if (typeCounter == 2 && nameCounter == 5) {
			newCard = new Card(typeCounter, nameCounter, valueCounter);
		}
		else if (typeCounter == 2 && nameCounter == 6) {
			newCard = new Card(typeCounter, nameCounter, valueCounter);
		}
		else if (typeCounter == 2 && nameCounter == 7) {
			newCard = new Card(typeCounter, nameCounter, valueCounter);
		}
		else if (typeCounter == 2 && nameCounter == 8) {
			newCard = new Card(typeCounter, nameCounter, valueCounter);
		}
		else if (typeCounter == 2 && nameCounter == 9) {
			newCard = new Card(typeCounter, nameCounter, valueCounter);
		}
		else if (typeCounter == 2 && nameCounter == 10) {
			newCard = new Card(typeCounter, nameCounter, valueCounter);
		}
		else if (typeCounter == 2 && nameCounter == 11) {
			newCard = new Card(typeCounter, nameCounter, valueCounter);
		}
		else if (typeCounter == 2 && nameCounter == 12) {
			newCard = new Card(typeCounter, nameCounter, valueCounter);
		}
		else if (typeCounter == 2 && nameCounter == 13) {
			newCard = new Card(typeCounter, nameCounter, valueCounter);
		}
		else if (typeCounter == 2 && nameCounter == 14) {
			newCard = new Card(typeCounter, nameCounter, valueCounter);
			nameCounter = 1;
			valueCounter = 1;
		}

		else if (typeCounter == 3 && nameCounter == 2) {
			newCard = new Card(typeCounter, nameCounter, valueCounter);
		}
		else if (typeCounter == 3 && nameCounter == 3) {
			newCard = new Card(typeCounter, nameCounter, valueCounter);
		}
		else if (typeCounter == 3 && nameCounter == 4) {
			newCard = new Card(typeCounter, nameCounter, valueCounter);
		}
		else if (typeCounter == 3 && nameCounter == 5) {
			newCard = new Card(typeCounter, nameCounter, valueCounter);
		}
		else if (typeCounter == 3 && nameCounter == 6) {
			newCard = new Card(typeCounter, nameCounter, valueCounter);
		}
		else if (typeCounter == 3 && nameCounter == 7) {
			newCard = new Card(typeCounter, nameCounter, valueCounter);
		}
		else if (typeCounter == 3 && nameCounter == 8) {
			newCard = new Card(typeCounter, nameCounter, valueCounter);
		}
		else if (typeCounter == 3 && nameCounter == 9) {
			newCard = new Card(typeCounter, nameCounter, valueCounter);
		}
		else if (typeCounter == 3 && nameCounter == 10) {
			newCard = new Card(typeCounter, nameCounter, valueCounter);
		}
		else if (typeCounter == 3 && nameCounter == 11) {
			newCard = new Card(typeCounter, nameCounter, valueCounter);
		}
		else if (typeCounter == 3 && nameCounter == 12) {
			newCard = new Card(typeCounter, nameCounter, valueCounter);
		}
		else if (typeCounter == 3 && nameCounter == 13) {
			newCard = new Card(typeCounter, nameCounter, valueCounter);
		}
		else if (typeCounter == 3 && nameCounter == 14) {
			newCard = new Card(typeCounter, nameCounter, valueCounter);
			nameCounter = 1;
			valueCounter = 1;
		}

		else if (typeCounter == 4 && nameCounter == 2) {
			newCard = new Card(typeCounter, nameCounter, valueCounter);
			typeCounter = 0;
		}
		else if (typeCounter == 4 && nameCounter == 3) {
			newCard = new Card(typeCounter, nameCounter, valueCounter);
			typeCounter = 0;
		}
		else if (typeCounter == 4 && nameCounter == 4) {
			newCard = new Card(typeCounter, nameCounter, valueCounter);
			typeCounter = 0;
		}
		else if (typeCounter == 4 && nameCounter == 5) {
			newCard = new Card(typeCounter, nameCounter, valueCounter);
			typeCounter = 0;
		}
		else if (typeCounter == 4 && nameCounter == 6) {
			newCard = new Card(typeCounter, nameCounter, valueCounter);
			typeCounter = 0;
		}
		else if (typeCounter == 4 && nameCounter == 7) {
			newCard = new Card(typeCounter, nameCounter, valueCounter);
			typeCounter = 0;
		}
		else if (typeCounter == 4 && nameCounter == 8) {
			newCard = new Card(typeCounter, nameCounter, valueCounter);
			typeCounter = 0;
		}
		else if (typeCounter == 4 && nameCounter == 9) {
			newCard = new Card(typeCounter, nameCounter, valueCounter);
			typeCounter = 0;
		}
		else if (typeCounter == 4 && nameCounter == 10) {
			newCard = new Card(typeCounter, nameCounter, valueCounter);
			typeCounter = 0;
		}
		else if (typeCounter == 4 && nameCounter == 11) {
			newCard = new Card(typeCounter, nameCounter, valueCounter);
			typeCounter = 0;
		}
		else if (typeCounter == 4 && nameCounter == 12) {
			newCard = new Card(typeCounter, nameCounter, valueCounter);
			typeCounter = 0;
		}
		else if (typeCounter == 4 && nameCounter == 13) {
			newCard = new Card(typeCounter, nameCounter, valueCounter);
			typeCounter = 0;
		}
		else if (typeCounter == 4 && nameCounter == 14) {
			newCard = new Card(typeCounter, nameCounter, valueCounter);
			typeCounter = 0;
			nameCounter = 1;
			valueCounter = 1;
		}


		m_deck.push_back(newCard);

		typeCounter += 1;
		nameCounter += 1;
		valueCounter += 1;
  }

}

Deck::~Deck() {

	for (unsigned int i = 0; i < m_deck.size(); i++) {

		delete m_deck[i];
		m_deck[i] = NULL;
	}

}

Deck::Deck(const Deck& other) {

	for (unsigned int i = 0; i < other.m_deck.size(); i++) {

		Card* newCard = new Card(*other.m_deck[i]);

		m_deck.push_back(newCard);
	}

}

Deck& Deck::operator=(const Deck& other) {

	if (&other == this) {

		return *this;
	}

	unsigned int sizeCheck = m_deck.size();

	while (sizeCheck > 0) {

		unsigned int i = m_deck.size();

		delete m_deck[(i - 1)];
		m_deck[(i - 1)] = NULL;
		m_deck.pop_back();
		sizeCheck -= 1;
	}

	for (unsigned int i = 0; i < other.m_deck.size(); i++) {

		Card* newCard = new Card(*other.m_deck[i]);

		m_deck.push_back(newCard);
	}

	return *this;
}

vector<Card*>& Deck::GetDeck() {

	return m_deck;
}




