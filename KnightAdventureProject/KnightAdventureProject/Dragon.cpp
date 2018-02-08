#include "stdafx.h"
#include "Dragon.h"

const int BASE_DMG = 3;
const int BASE_HP = 50;
const string BOSS = "Granite Dragon";
const int dragonLevel = 10;

Dragon::Dragon() : Enemy(BOSS) {

}
/*
bool Dragon::Death() {

if (m_health < 1) {

cout << "Did work" << endl;
return true;
}

cout << "Didn't work the m_health is: " << m_health << endl;
return false;
}

void Dragon::SetHealth(int newHP) {

m_health = newHP;
}
*/

void Dragon::Attack(Knight& user) {

	int userHP = user.GetHealth() - Enemy::GetDmg();

	user.SetHealth(userHP);

	int randomMove = 0;

	srand((unsigned int)time(NULL));

	randomMove = rand() % 4;

	switch (randomMove) {

	case 0:

		cout << "\n" << Enemy::GetName() << " used Dark Frenzy! Dark claws of energy rip and tear at you doing serious damage!\n" << Enemy::GetDmg() << " damage was done.\n" << endl;
		break;

	case 1:

		cout << "\n" << Enemy::GetName() << " used Scale Slam! The scaley beast\nlifted its heavy tail and slammed it on you....Ouch.\n" << Enemy::GetDmg() << " damage was done.\n" << endl;
		break;

	case 2:

		cout << "\n" << Enemy::GetName() << " used Granite Crunch! The dragon lunged at you\nwith its long neck piercing your armor with its jagged teeth!\n" << Enemy::GetDmg() << " damage was done.\n" << endl;
		break;

	case 3:

		cout << "\n" << Enemy::GetName() << " used Ghost Flame! A black ancient fire rose from\nthe gullet of the Granite beast engulfing you! The screams of past souls could be faintly heard...\n" << Enemy::GetDmg() << " damage was done.\n" << endl;
		break;
	}

}

void Dragon::SpecialAttack(Knight& user) {

	int specialDamage = 50;

	int userHP = user.GetHealth() - specialDamage;

	user.SetHealth(userHP);

	cout << "\n" << Enemy::GetName() << " used Elemental breath! In a blast of bright color from the dragons\nmaw the elements joined together to create a violent wet wave\nof flame charged wind torrents! The knight finally witnessed the Granite beasts TRUE power!\nA catastrophic " << specialDamage << " damage was done.\n" << endl;
}

