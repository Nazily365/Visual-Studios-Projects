#include "stdafx.h"
#include "Bunny.h"

using namespace std;

Bunny::Bunny() {

	m_name = "Test Bunny";
	m_sex = "Male";
	m_color = "White";
	m_age = 0;
	m_radioactive_mutant_vampire = false;
}

Bunny::Bunny(string name) {

	m_name = name;
	m_age = 0;
	
	int randomNum = rand() % 10;

	if (randomNum % 2 == 0) {

		m_sex = "Male";
	}
	else {

		m_sex = "Female";
	}

	randomNum = rand() % 100;

	if (randomNum > -1 && randomNum <= 24) {

		m_color = "White";
	}
	else if (randomNum > 24 && randomNum <= 49) {

		m_color = "Black";
	}
	else if (randomNum > 49 && randomNum <= 74) {

		m_color = "Brown";
	}
	else if (randomNum > 74 && randomNum <= 99) {

		m_color = "Spotted";
	}

	randomNum = rand() % 100;

	if (randomNum == 13 || randomNum == 66) {

		m_radioactive_mutant_vampire = true;
	}
	else {

		m_radioactive_mutant_vampire = false;
	}
}

Bunny::Bunny(string name, string color) {

	m_name = name;
	m_color = color;
	m_age = 0;

	int randomNum = rand() % 10;

	if (randomNum % 2 == 0) {

		m_sex = "Male";
	}
	else {

		m_sex = "Female";
	}

	randomNum = rand() % 100;

	if (randomNum == 13 || randomNum == 66) {

		m_radioactive_mutant_vampire = true;
	}
	else {

		m_radioactive_mutant_vampire = false;
	}
}

Bunny::Bunny(string name, string color, bool mutant) {

	m_name = name;
	m_color = color;
	m_age = 0;
	m_radioactive_mutant_vampire = mutant;

	int randomNum = rand() % 10;

	if (randomNum % 2 == 0) {

		m_sex = "Male";
	}
	else {

		m_sex = "Female";
	}
}

void Bunny::SetName(string name) {

	m_name = name;
}

string Bunny::GetName() {

	return m_name;
}

void Bunny::SetSex(string sex) {

	m_sex = sex;
}

string Bunny::GetSex() {

	return m_sex;
}

void Bunny::SetColor(string color) {

	m_color = color;
}

string Bunny::GetColor() {

	return m_color;
}

void Bunny::SetAge(int age) {

	m_age = age;
}

int Bunny::GetAge() {

	return m_age;
}

void Bunny::SetMutant(bool mutant) {

	m_radioactive_mutant_vampire = mutant;
}

bool Bunny::GetMutant() {

	return m_radioactive_mutant_vampire;
}
