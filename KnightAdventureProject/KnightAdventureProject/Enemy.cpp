#include "stdafx.h"
#include "Enemy.h"

const int BASE_DMG = 6;
const int BASE_HP = 50;
const string GOBLIN = "Goblin";
const int DRAGON_LEVEL = 10;

Enemy::Enemy(int level) {

	m_name = GOBLIN;
	m_health = BASE_HP;
	m_level = level;

	switch (level) {

	case 1:

		m_damage = BASE_DMG;
		break;

	case 2:

		m_damage = (BASE_DMG + 3);
		break;

	case 3:

		m_damage = (BASE_DMG + 6);
		break;

	case 4:

		m_damage = (BASE_DMG + 9);
		break;

	case 5:

		m_damage = (BASE_DMG + 12);
		break;
	}

}

Enemy::Enemy(string name) {

	m_name = name;

	m_health = (BASE_HP * 4);

	m_level = DRAGON_LEVEL;

	m_damage = ((BASE_DMG / 2) * DRAGON_LEVEL);
}

Enemy::Enemy(string name, int level) {

	m_name = name;

	m_health = (BASE_HP * 2);

	m_level = level;

	switch (level) {

	case 1:

		m_damage = BASE_DMG;
		break;

	case 2:

		m_damage = (BASE_DMG + 3);
		break;

	case 3:

		m_damage = (BASE_DMG + 6);
		break;

	case 4:

		m_damage = (BASE_DMG + 9);
		break;

	case 5:

		m_damage = (BASE_DMG + 12);
		break;
	}

}

void Enemy::SetName(string name) {

	m_name = name;
}

string Enemy::GetName() {

	return m_name;
}

void Enemy::SetHealth(int HP) {

	m_health = HP;
}

int Enemy::GetHealth() {

	return m_health;
}

void Enemy::SetDmg(int dmg) {

	m_damage = dmg;
}

int Enemy::GetDmg() {

	return m_damage;
}

void Enemy::SetLevel(int level) {

	m_level = level;
}

int Enemy::GetLevel() {

	return m_level;
}

void Enemy::Attack(Knight& user) {

	int userHP = user.GetHealth();

	userHP = userHP - m_damage;

	user.SetHealth(userHP);

	cout << "\n" << m_name << " charged toward you attacking recklessly! " << m_name << " did " << m_damage << " damage.\n" << endl;
}

bool Enemy::Death() {

	if (m_health < 1) {

		return true;
	}

	return false;
}
