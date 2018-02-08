#pragma once

#include "Enemy.h"
#include "Knight.h"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Dragon : public Enemy {
public:

	Dragon();
	virtual void Attack(Knight& player);
	void SpecialAttack(Knight& player);
	/*
	private:

	string m_name;
	int m_health;
	int m_damage;
	int m_level;
	*/
};

