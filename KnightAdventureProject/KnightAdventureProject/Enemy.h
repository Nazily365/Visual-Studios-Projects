#pragma once

#include "Knight.h"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Knight;

class Enemy {
public:

	Enemy(int level);
	Enemy(string name);
	Enemy(string name, int level);
	void SetName(string name);
	string GetName();
	void SetHealth(int HP);
	int GetHealth();
	void SetDmg(int dmg);
	int GetDmg();
	void SetLevel(int level);
	int GetLevel();

	virtual void Attack(Knight& user);
	bool Death();

private:

	string m_name;
	int m_health;
	int m_damage;
	int m_level;
};
