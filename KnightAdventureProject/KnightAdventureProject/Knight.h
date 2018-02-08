#pragma once

#include "Enemy.h"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

class Enemy;

class Knight {
public:

	Knight(string name, int element);
	void SetName(string name);
	string GetName();
	void SetHealth(int HP);
	int GetHealth();
	void SetMana(int MP);
	int GetMana();
	void SetElement(int choice);
	string GetElement();
	void SetGold(int gold);
	int GetGold();
	void SetEXP(int EXP);
	int GetEXP();
	void SetLevel(int level);
	int GetLevel();
	void SetDamage(int damage);
	int GetDamage();

	bool ManaCheck(int basicOrSpecial);
	bool Death();
	int BlockDamage(int dmgRecieved);
	void ReturnHP(int hpRestored);
	void AddGold(int goldAdded);
	void AddEXP(int expAdded);
	int ShowMaxHP();
	int ShowMaxMP();
	void Attack(Enemy& monster);
	void ElementAttack(Enemy& monster);
	void SpecialAttack(Enemy& monster);

private:

	string m_name;
	int m_health;
	int m_mana;
	string m_element;
	int m_gold;
	int m_EXP;
	int m_level;
	int m_damage;
	//vector <int> m_moves;
};

