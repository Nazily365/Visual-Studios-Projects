#pragma once

#include "Enemy.h"
#include "Knight.h"
#include "Dragon.h"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

class KnightAdventure {
public:

	KnightAdventure();
	void MainMenu(); //Hold startGame, Instructions, and Quit out
	void StartGame(); //Ask name, element of choice
	void LevelOne(Knight& player); //Castle 1 battle
	void LevelTwo(Knight& player); //Castle 2 battle
	void LevelThree(Knight& player); //Final fight
	void Ending(); //Credits
	void Battle(Knight& player, vector<Enemy>& enemies);
	void Instructions(); //what you gotta do
	int DisplayLevel(Knight& player);
	int DisplayNextLevel(Knight& player); //Use switch cases to print out exp till nxt lvl (max exp - cur exp)
	void LevelUp(Knight& player);

	//before displaying the shop in the program run, ask if they would like to go to the shop
	void DisplayShop(Knight& player); //Tell the user their current HP and advises them to buy HP or MP potion

private:

	vector <Enemy> m_castleOne;
	vector <Enemy> m_castleTwo;
};

