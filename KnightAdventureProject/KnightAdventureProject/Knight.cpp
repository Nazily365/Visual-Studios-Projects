
#include "stdafx.h"
#include "Knight.h"

using namespace std;

const int HEALTH = 100;
const int MANA = 50;
const int GOLD = 0;
const int EXPERIENCE = 100;
const int LEVEL = 1;
const int BASE_HERO_DMG = 17;
const int BASIC_MANA_USE = 6;
const int SPECIAL_MANA_USE = 25;
const double DMG_MULTIPLIER = 1.4;
const int ELEMENT_PURE_DMG = 75;

Knight::Knight(string name, int element) {

	m_name = name;
	m_health = HEALTH;
	m_mana = MANA;

	switch (element) {

	case 1:

		m_element = "Wind";
		break;

	case 2:

		m_element = "Lightning";
		break;

	case 3:

		m_element = "Fire";
		break;

	case 4:

		m_element = "Water";
		break;
	}

	m_gold = GOLD;
	m_EXP = EXPERIENCE;
	m_level = LEVEL;
	m_damage = BASE_HERO_DMG;
}

void Knight::SetName(string name) {

	m_name = name;
}

string Knight::GetName() {

	return m_name;
}

void Knight::SetHealth(int HP) {

	m_health = HP;
}

int Knight::GetHealth() {

	return m_health;
}

void Knight::SetMana(int MP) {

	m_mana = MP;
}

int Knight::GetMana() {

	return m_mana;
}

void Knight::SetElement(int choice) {

	switch (choice) {

	case 1:

		m_element = "Wind";
		break;

	case 2:

		m_element = "Lightning";
		break;

	case 3:

		m_element = "Fire";
		break;

	case 4:

		m_element = "Water";
		break;
	}

}

string Knight::GetElement() {

	return m_element;
}

void Knight::SetGold(int gold) {

	m_gold = gold;
}

int Knight::GetGold() {

	return m_gold;
}

void Knight::SetEXP(int EXP) {

	m_EXP = EXP;
}

int Knight::GetEXP() {

	return m_EXP;
}

void Knight::SetLevel(int level) {

	m_level = level;
}

int Knight::GetLevel() {

	return m_level;
}

void Knight::SetDamage(int damage) {

	m_damage = damage;
}

int Knight::GetDamage() {

	return m_damage;
}

bool Knight::ManaCheck(int basicOrSpecial) {

	if (basicOrSpecial == 1) {

		if (m_mana - BASIC_MANA_USE > -1) {

			return true;
		}
		else {

			return false;
		}
	}

	else if (basicOrSpecial == 2) {

		if (m_mana - SPECIAL_MANA_USE > -1) {

			return true;
		}
		else {

			return false;
		}
	}

	return false;
}

bool Knight::Death() {

	if (m_health < 1) {

		return true;
	}

	return false;
}

int Knight::BlockDamage(int dmgRecieved) {

	cout << m_name << " blocked half the damage and recieved "
		<< (dmgRecieved / 2) << " damage instead!" << endl;

	return (dmgRecieved / 2);
}

void Knight::ReturnHP(int hpRestored) {

	m_health = m_health + hpRestored;
}

void Knight::AddGold(int goldAdded) {

	m_gold = m_gold + goldAdded;
}

void Knight::AddEXP(int expAdded) {

	m_EXP = m_EXP + expAdded;
}

int Knight::ShowMaxHP() {

	switch (m_level) {

	case 1:

		return 100;

	case 2:

		return 125;

	case 3:

		return 150;

	case 4:

		return 175;

	case 5:

		return 200;
	}

	return 0;
}

int Knight::ShowMaxMP() {

	switch (m_level) {

	case 1:

		return 50;

	case 2:

		return 55;

	case 3:

		return 60;

	case 4:

		return 65;

	case 5:

		return 70;
	}

	return 0;
}

void Knight::Attack(Enemy& monster) {

	int enemyHP = monster.GetHealth();

	enemyHP = enemyHP - m_damage;

	monster.SetHealth(enemyHP);

	cout << m_name << " attacked fiercly with their broadsword dealing " << m_damage << " damage!\n" << endl;
}

void Knight::ElementAttack(Enemy& monster) {

	int basic = 1;
	int enemyHP = monster.GetHealth();

	if (ManaCheck(basic) == true) {

		enemyHP = (enemyHP - (m_damage * DMG_MULTIPLIER));

		monster.SetHealth(enemyHP);

		cout << m_name << " reinforced their broadsword with their elemental ability and attacked dealing "
			<< (m_damage * DMG_MULTIPLIER) << " damage!" << endl;

		m_mana = m_mana - BASIC_MANA_USE;

		cout << BASIC_MANA_USE << " mana was used for this attack. You have " << m_mana << " mana left!\n" << endl;
	}
	else {

		cout << "You don't have enough mana to do an elemental attack try your basic attack!\n" << endl;
	}

}

void Knight::SpecialAttack(Enemy& monster) {

	int special = 2;
	int enemyHP = monster.GetHealth();

	if (ManaCheck(special) == true) {

		int element = 0;

		if (m_element == "Wind") {

			element = 1;
		}
		else if (m_element == "Lightning") {

			element = 2;
		}
		else if (m_element == "Fire") {

			element = 3;
		}
		else if (m_element == "Water") {

			element = 4;
		}

		enemyHP = enemyHP - ELEMENT_PURE_DMG;
		monster.SetHealth(enemyHP);

		switch (element) {

		case 1:

			cout << "\n" << m_name << " used Gale! Using full elemental strength demon winds were called\nupon the battlefield to slash at the opponent dealing massive damage!\nDamage done: " << ELEMENT_PURE_DMG << "hp!" << endl;
			break;

		case 2:

			cout << "\n" << m_name << " used Demon Spark! Using full elemental strength a wicked blue\nbolt of lightning struck the opponent dealing massive damage!\nDamage done: " << ELEMENT_PURE_DMG << "hp!" << endl;
			break;

		case 3:

			cout << "\n" << m_name << " used Burnout! Using full elemental strength black, violent, flames engulfed the opponent dealing massive damage!\nDamage done: " << ELEMENT_PURE_DMG << "hp!" << endl;
			break;

		case 4:

			cout << "\n" << m_name << " used Aqua Pulse! Using full elemental strength a giant wave of\nfrigid ice water smashed against the opponent dealing massive damage!\nDamage done: " << ELEMENT_PURE_DMG << "hp!" << endl;
			break;
		}

		m_mana = m_mana - SPECIAL_MANA_USE;

		cout << SPECIAL_MANA_USE << " mana was used for this attack. You have " << m_mana << " mana left!\n" << endl;
	}

	else {

		cout << "\nYou don't have enough mana for your special attack, try using your elemental attack or basic attack!\n" << endl;
	}

}
