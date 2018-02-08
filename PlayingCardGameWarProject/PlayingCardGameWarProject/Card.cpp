#include "stdafx.h"
#include "Card.h"

Card::Card(int type, int name, int value) {

	switch (type) {

	case 1:

		m_type = "Hearts";
		break;

	case 2:

		m_type = "Diamonds";
		break;

	case 3:

		m_type = "Clubs";
		break;

	case 4:

		m_type = "Spades";
		break;
	}

	switch (name) {

	case 2:

		m_name = "Two";
		break;

	case 3:

		m_name = "Three";
		break;

	case 4:

		m_name = "Four";
		break;

	case 5:

		m_name = "Five";
		break;

	case 6:

		m_name = "Six";
		break;

	case 7:

		m_name = "Seven";
		break;

	case 8:

		m_name = "Eight";
		break;

	case 9:

		m_name = "Nine";
		break;

	case 10:

		m_name = "Ten";
		break;

	case 11:

		m_name = "Jack";
		break;

	case 12:

		m_name = "Queen";
		break;

	case 13:

		m_name = "King";
		break;

	case 14:

		m_name = "Ace";
		break;

	}

	m_value = value;
}

void Card::SetName(string name) {

	m_name = name;
}

string Card::GetName() {

	return m_name;
}

void Card::SetType(string type) {

	m_type = type;
}

string Card::GetType() {

	return m_type;
}

void Card::SetValue(int value) {

	m_value = value;
}

int Card::GetValue() {

	return m_value;
}
