#include "stdafx.h"
#include "KnightAdventure.h"

const int ENEMY_AMOUNT = 3;
const int BASE_LEVEL = 1;

KnightAdventure::KnightAdventure() {

	MainMenu();
}

void KnightAdventure::MainMenu() {

	int menuChoice;
	string trail;
	do {

		cout << "\n\tWelcome to Knight Adventures: The Game!\n\n\t1. Start Game\n\n\t2. What You Must Do...\n\n\t3. Quit" << endl;
		//getline(cin, menuChoice);
		cin >> menuChoice;

		while (menuChoice < 1 || menuChoice > 3) {

			cout << "Pick one of the choices" << endl;
			//getline(cin, menuChoice);
			cin >> menuChoice;
			getline(cin, trail);
		}

		getline(cin, trail);

		switch (menuChoice) {

		case 1:

			StartGame();
			break;

		case 2:

			Instructions();
			break;

		case 3:

			cout << "Thanks for Playing!" << endl;
			break;
		}

	} while (menuChoice == 2);


}

void KnightAdventure::StartGame() {

	string playerName;
	int element = 0;

	cout << "Welcome, brave adventurer, to Avarahs! My name is Josan, a member of the clergy. As you\nknow the church has requested your assistance. It is of great importance that you\nstop the Granite Dragon now tell us, what is thy name?" << endl;

	getline(cin, playerName);

	cout << "\nAlright then " << playerName << " we will not leave you to fight the beast empty handed we shall bless you with an elemental skill, now choose yours.\n" << endl;
	cout << "1. Wind\n2. Lightning\n3. Fire\n4. Water" << endl;
	cin >> element;

	while (element < 1 || element > 4) {

		cout << "Choose one of the numbered elements.(1-4)" << endl;
		cin >> element;
	}

	Knight firstPlayer(playerName, element);

	cout << "\nAlright before we send you off a word of warning. On the way to the Granite Dragon two goblin kings\nreside in nearby castles, if you are able, destroy them and their minions! Now goodluck on your journey " << playerName << " and stay safe!\n\n" << endl;

	LevelOne(firstPlayer);

	if (firstPlayer.Death() == false) {

		DisplayShop(firstPlayer);

		LevelTwo(firstPlayer);
	}

	if (firstPlayer.Death() == false) {

		DisplayShop(firstPlayer);

		LevelThree(firstPlayer);
	}

	if (firstPlayer.Death() == false) {

		Ending();
	}

	if (firstPlayer.Death() == true) {

		cout << "\nSadly, you have failed to stop the dark creatures looking to destroy Avarahs...This isn't over. Start over, you can do better.\n\nAll programming and story developed and\nput together by Nazily M. Zaza. Thanks for playing! :)" << endl;
	}

}

void KnightAdventure::LevelOne(Knight& player) {

	string kingName = "Milo The Goblin King";
	Enemy kingGoblin(kingName, (BASE_LEVEL + 2));

	m_castleOne.push_back(kingGoblin);

	for (int i = 0; i < ENEMY_AMOUNT; i++) {

		Enemy newEnemy(BASE_LEVEL);
		m_castleOne.push_back(newEnemy);
	}

	cout << "Traveling...Traveling...Traveling...\nYou made it to the first castle! You first face off against multiple goblin minions before you fight the king goblin.\n\nThe first minion attacked!\n" << endl;

	Battle(player, m_castleOne);

	if (player.Death() == false) {

		cout << "Second goblin appeared!\n" << endl;
		Battle(player, m_castleOne);
	}

	if (player.Death() == false) {
		cout << "Third goblin appeared!\n" << endl;
		Battle(player, m_castleOne);
		LevelUp(player);
	}

	if (player.Death() == false) {

		cout << "Oh no! It's the King! Prepare for a fierce fight!\n" << endl;
		Battle(player, m_castleOne);
		LevelUp(player);
	}

	if (player.Death() == false) {

		cout << "Congratz on vanqueshing the first goblin king! There is a sideshop near this castle, you can stop there to rest and restore your HP and MP.\n" << endl;
	}

}

void KnightAdventure::LevelTwo(Knight& player) {

	string kingName = "Mika The Goblin King";
	Enemy kingGoblin(kingName, (BASE_LEVEL + 4));

	m_castleTwo.push_back(kingGoblin);

	for (int i = 0; i < ENEMY_AMOUNT; i++) {

		Enemy newEnemy(BASE_LEVEL + 2);
		m_castleTwo.push_back(newEnemy);
	}

	cout << "Traveling...Traveling...Traveling...\nYou made it to the final castle! You first face off against multiple goblin minions before you fight the king goblin.\n\nThe first minion attacked!\n" << endl;

	Battle(player, m_castleTwo);

	if (player.Death() == false) {

		cout << "Second goblin appeared!\n" << endl;
		Battle(player, m_castleTwo);
	}

	if (player.Death() == false) {
		cout << "Third goblin appeared!\n" << endl;
		Battle(player, m_castleTwo);
		LevelUp(player);
	}

	if (player.Death() == false) {

		cout << "Oh no! It's the King! Prepare for a fierce fight!\n" << endl;
		Battle(player, m_castleTwo);
		LevelUp(player);
	}

	if (player.Death() == false) {

		cout << "Congratz on vanqueshing the last goblin king! There is a sideshop near this castle, you can stop there to rest and restore your HP and MP.\n" << endl;
		cout << "You've grown in strength and your elemental abilities have matured. You are now capable of a special elemental attack during battle. When you get a chance, use it.\n" << endl;
	}

}

void KnightAdventure::LevelThree(Knight& player) {

	cout << "Traveling...Traveling...Traveling...\n" << endl;
	cout << "You've finally made it to the mountains peak. The clouds are dark....the air heavy...you hear a deep growl...\nUp from behind the giant granite slabs rises the Granite Dragon! he flys straight up and slams back ontop of the mountain.\nHe stares at you, his eyes as black as the smoke escaping from his jaw. Quick as lightning he attacked. And so the battle begins.\n" << endl;

	Dragon graniteDragon;

	int userChoice = 0;
	int whoseTurn = 0;
	bool blockDMG = false;

	while (player.Death() == false && graniteDragon.Death() == false) {

		cout << "Current level: " << DisplayLevel(player) << endl;

		cout << "Your HP and MP: " << player.GetHealth() << "/" << player.ShowMaxHP() << "hp " << player.GetMana() << "/" << player.ShowMaxMP() << "mp" << endl;

		cout << graniteDragon.GetName() << "'s HP: " << graniteDragon.GetHealth() << "hp" << endl;

		if (whoseTurn == 0) {

			cout << "What would you like to do?\n" << endl;

			cout << "1. Attack\n2.Elemental Attack\n3.Block\n4.Special Attack" << endl;
			cin >> userChoice;

			while (userChoice < 1 || userChoice > 4) {

				cout << "Choose to attack, elemental attack, block or special attack.(1-4)" << endl;
				cin >> userChoice;
			}

			if (userChoice == 1) {

				player.Attack(graniteDragon);
			}
			else if (userChoice == 2) {

				player.ElementAttack(graniteDragon);
			}

			else if (userChoice == 3) {

				cout << player.GetName() << " is going to block!" << endl;
				blockDMG = true;
			}
			else if (userChoice == 4) {

				player.SpecialAttack(graniteDragon);
			}

			whoseTurn = 1;
		}

		else if (whoseTurn == 1) {

			if (blockDMG == true) {

				graniteDragon.Attack(player);
				int hpReturn = player.BlockDamage(graniteDragon.GetDmg());
				player.ReturnHP(hpReturn);
				blockDMG = false;
			}
			else {

				srand((unsigned int)time(NULL));
				int randomMove = 0;

				randomMove = rand() % 10;

				if (randomMove == 0 || randomMove == 9) {

					graniteDragon.SpecialAttack(player);
				}
				else {

					graniteDragon.Attack(player);
				}

			}

			whoseTurn = 0;
		}

		if (graniteDragon.Death() == true) {

			cout << "\n" << graniteDragon.GetName() << " fell with a thud. Granite shards flew everywhere. The beasts dark presence over the region was finally lifted.\n" << endl;

			player.AddGold(5000);

		}

		if (player.Death() == true) {

			cout << "\n" << graniteDragon.GetName() << " shear power was too much to handle, with a final blast of elemental color the Granite Dragon destroyed you. you have taken fatal damage...\n" << endl;
		}

	}

}

void KnightAdventure::Ending() {

	cout << "You did it! Congratz! You beat the game!\n\nAll programming and story developed and\nput together by Nazily M. Zaza. Thanks for playing! :)\n" << endl;
}

void KnightAdventure::Instructions() {

	cout << "Welcome! As far as you are concerned you are a wandering knight.\nYou've come across a large community, Avarahs, where the local church has requested your help.\nTwo goblin kings near the area and a hideous dragon are terrorizing the people.\nBut don't worry this is not a complicated game. You have one objective.\nUse the elemental power the Church gave you and slay the Goblins and the dragon. Have fun!" << endl;
}

void KnightAdventure::Battle(Knight& firstPlayer, vector<Enemy>& enemies) {

	int userChoice = 0;
	int whoseTurn = 0;
	unsigned int fightPos = enemies.size();
	bool blockDMG = false;

	while (firstPlayer.Death() == false && enemies[fightPos - 1].Death() == false) {

		cout << "Current level: " << DisplayLevel(firstPlayer) << "  EXP needed for next level: " << DisplayNextLevel(firstPlayer) << endl;

		cout << "Your HP and MP: " << firstPlayer.GetHealth() << "/" << firstPlayer.ShowMaxHP() << "hp " << firstPlayer.GetMana() << "/" << firstPlayer.ShowMaxMP() << "mp" << endl;

		cout << enemies[fightPos - 1].GetName() << "'s HP: " << enemies[fightPos - 1].GetHealth() << "hp" << endl;

		if (whoseTurn == 0) {

			cout << "What would you like to do?\n" << endl;

			cout << "1. Attack\n2.Elemental Attack\n3.Block" << endl;
			cin >> userChoice;

			while (userChoice < 1 || userChoice > 3) {

				cout << "Choose to attack, elemental attack, or block.(1-3)" << endl;
				cin >> userChoice;
			}

			if (userChoice == 1) {

				firstPlayer.Attack(enemies[fightPos - 1]);
			}
			else if (userChoice == 2) {

				firstPlayer.ElementAttack(enemies[fightPos - 1]);
			}
			else if (userChoice == 3) {

				cout << firstPlayer.GetName() << " is going to block!" << endl;
				blockDMG = true;
			}

			whoseTurn = 1;
		}

		else if (whoseTurn == 1) {

			if (blockDMG == true) {

				enemies[fightPos - 1].Attack(firstPlayer);
				int hpReturn = firstPlayer.BlockDamage(enemies[fightPos - 1].GetDmg());
				firstPlayer.ReturnHP(hpReturn);
				blockDMG = false;
			}
			else {

				enemies[fightPos - 1].Attack(firstPlayer);
			}

			whoseTurn = 0;
		}

		if (enemies[fightPos - 1].Death() == true) {

			cout << enemies[fightPos - 1].GetName() << " was vanqueshed!\n" << endl;

			if (enemies[fightPos - 1].GetName() == "Milo The Goblin King" || enemies[fightPos - 1].GetName() == "Mika The Goblin King") {

				firstPlayer.AddGold(100);
				firstPlayer.AddEXP(100);
			}
			else {

				firstPlayer.AddGold(50);
				firstPlayer.AddEXP(35);
			}

			//enemies.pop_back();
		}

		if (firstPlayer.Death() == true) {

			cout << enemies[fightPos - 1].GetName() << " attacks were too fierce and you have taken fatal damage..." << endl;
		}

		//fightPos = enemies.size();

	}

	enemies.pop_back();
}

int KnightAdventure::DisplayLevel(Knight& player) {

	return player.GetLevel();
}

int KnightAdventure::DisplayNextLevel(Knight& player) {

	int lvlCap1 = 200;
	int lvlCap2 = 300;
	int lvlCap3 = 400;
	int lvlCap4 = 500;

	switch (player.GetLevel()) {

	case 1:

		return lvlCap1 - player.GetEXP();

	case 2:

		return lvlCap2 - player.GetEXP();

	case 3:

		return lvlCap3 - player.GetEXP();

	case 4:

		return lvlCap4 - player.GetEXP();

	}

	return 0;
}

void KnightAdventure::LevelUp(Knight& player) {

	if (player.GetEXP() >= 200 && player.GetEXP() <= 299) {

		player.SetLevel(2);
		player.SetDamage(player.GetDamage() + 3);
	}

	else if (player.GetEXP() >= 300 && player.GetEXP() <= 399) {

		player.SetLevel(3);
		player.SetDamage(player.GetDamage() + 3);
	}

	else if (player.GetEXP() >= 400 && player.GetEXP() <= 499) {

		player.SetLevel(4);
		player.SetDamage(player.GetDamage() + 3);
	}

	else if (player.GetEXP() >= 500) {

		player.SetLevel(5);
		player.SetDamage(player.GetDamage() + 3);
	}

	cout << "\nYou leveled up! You are now level " << DisplayLevel(player) << " with " << player.GetEXP() << " exp!\n" << endl;
}

void KnightAdventure::DisplayShop(Knight& player) {

	int item;
	int amount;
	int healthPrice = 25;
	int manaPrice = 75;
	int total = 0;

	int potionGain = 30;
	int hpHeal = 0;
	int manaGain = 30;
	int mpRestore = 0;
	bool makePurc = true;

	int morePurc = 0;
	int healAmount = 0;
	int mpRestored = 0;
	int playerMaxHP;
	int playerMaxMP;

	int userHP = player.GetHealth();
	int userMP = player.GetMana();
	int userGold = player.GetGold();

	switch (player.GetLevel()) {

	case 1:

		playerMaxHP = 100;
		playerMaxMP = 50;
		break;

	case 2:

		playerMaxHP = 125;
		playerMaxMP = 55;
		break;

	case 3:

		playerMaxHP = 150;
		playerMaxMP = 60;
		break;

	case 4:

		playerMaxHP = 175;
		playerMaxMP = 65;
		break;

	case 5:

		playerMaxHP = 200;
		playerMaxMP = 70;
		break;
	}

	cout << "\tYour current HP: " << player.GetHealth() << "/" << player.ShowMaxHP() << "hp" << endl;
	cout << "\tYour current MP: " << player.GetMana() << "/" << player.ShowMaxMP() << "mp" << endl;

	cout << "\t*************SIDE*************\n\t*************SHOP*************\n\n\tWelcome!" << endl;

	cout << "\n\tITEM:\t\t\tPRICE:\n\n\t1. Health Potion\t" << healthPrice << " gold\n\t2. Mana Potion\t\t" << manaPrice << " gold\n\n" << endl;

	cout << "You have " << player.GetGold() << " gold to use.\n" << endl;

	bool firstTime = true;
	bool stayShop = true;

	do {

		if (firstTime == true) {

			//bool enterShop = true;
			int shopOption = 0;

			cout << "Would you like to buy anything today?(1=yes/2=no)" << endl;
			cin >> shopOption;

			while (shopOption < 1 || shopOption > 2) {

				cout << "Choose 1 or 2 to buy something from the shop or leave.\n" << endl;
				cin >> shopOption;
			}

			if (shopOption == 2) {

				stayShop = false;
			}

			firstTime = false;
		}


		if (player.GetGold() < healthPrice || stayShop == false) {

			if (player.GetGold() < healthPrice) {

				cout << "\nYou don't have enough gold for purchases. Thanks for stopping by though!\n" << endl;
			}
			else {

				cout << "\nAlright thanks for stopping by though!\n" << endl;
			}

			makePurc = false;
		}

		else {

			do {

				cout << "What would you like to buy?" << endl;
				cin >> item;

				while (item < 1 || item > 2) {

					cout << "There are only two store options currently. Sorry, try again." << endl;
					cin >> item;
				}

				cout << "How many would you like to buy?" << endl;

				cin >> amount;

				while (amount < 0) {

					cout << "You can't buy negative items! Enter a positive amount." << endl;
					cin >> amount;
				}

				if (item == 1) {

					total = healthPrice * amount;
				}
				else if (item == 2) {

					total = manaPrice * amount;
				}
				if (total > player.GetGold()) {

					cout << "You don't have enough gold for that purchase. Try buying something else.\n" << endl;
				}

			} while (total > player.GetGold());

			if (item == 1) {

				//heal
				hpHeal = amount * potionGain;

				cout << "You bought " << amount << " health potions. For a total of " << total << " gold." << endl;

				while (userHP < playerMaxHP && hpHeal > 0) {

					userHP += 1;
					hpHeal -= 1;
					healAmount += 1;
				}

				player.SetHealth(userHP);

				cout << "Cool! You just healed " << healAmount << "hp now you have " << player.GetHealth() << "hp out of " << playerMaxHP << "hp." << endl;
			}

			else if (item == 2) {

				//restore mp
				mpRestore = amount * manaGain;

				cout << "You bought " << amount << " mana potions. For a total of " << total << " gold." << endl;

				while (userMP < playerMaxMP && mpRestore > 0) {

					userMP += 1;
					mpRestore -= 1;
					mpRestored += 1;
				}

				player.SetMana(userMP);

				cout << "Cool! Your mana has been restored by " << mpRestored << "mp now you have " << player.GetMana() << "mp out of " << playerMaxMP << "mp." << endl;
			}

			userGold = userGold - total;
			player.SetGold(userGold);

			cout << "Would you like to buy more items to heal your HP or MP? You have " << player.GetGold() << " gold left.(yes=1/no=2)" << endl;
			cin >> morePurc;

			while (morePurc < 1 || morePurc > 2) {

				cout << "Enter 1 for yes, or 2 for no." << endl;
				cin >> morePurc;
			}

			if (morePurc == 2 || player.GetGold() < healthPrice) {

				if (player.GetGold() < healthPrice && morePurc == 1) {

					cout << "You have no more gold to buy items, go back to adventuring!\n\n" << endl;
				}
				else {

					cout << "Thanks for coming to the Side Shop!\n\n" << endl;
				}

				makePurc = false;
			}

			total = 0;
		}

  }while (makePurc == true);


}

