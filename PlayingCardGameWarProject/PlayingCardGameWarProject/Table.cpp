#include "stdafx.h"
#include "Table.h"

Table::Table() {

	int userChoice = 0;
	string trail;

	do {

		cout << "\nWelcome to the table card game War! It is suggested you read the instructions before playing.\n" << endl;

		cout << "1. Start Game\n\n2. Instructions\n\n3. Quit" << endl;
		cin >> userChoice;

		while (userChoice < 1 || userChoice > 3) {

			cout << "Please pick one of the screen options." << endl;
			cin >> userChoice;
			getline(cin, trail);
		}

		getline(cin, trail);

		if (userChoice == 1) {

			StartGame();
			EndGame();
		}
		else if (userChoice == 2) {

			Instructions();
		}
		else if (userChoice == 3) {

			cout << "Thanks for playing!" << endl;
		}

	} while (userChoice == 2);

}

void Table::StartGame() {

	string userName;
	int playerRdy = 0;

	cout << "\nHello Player! Whats your name?" << endl;
	getline(cin, userName);

	Player firstPlayer(userName);
	Computer computer;

	cout << "\nAlright " << userName << " you will be playing against the computer in a game of War. Are you ready?(1=yes/2=no)" << endl;
	cin >> playerRdy;

	while (playerRdy < 1 || playerRdy > 2) {

		cout << "Please pick 1 for yes or 2 for no." << endl;
		cin >> playerRdy;
	}

	if (playerRdy == 1) {

		ShuffleDecks(firstPlayer.GetHand(), computer.GetHand());

		bool continuePlaying = true;
		bool winOrLoss = false;
		int turnCounter = 0;
		int continueGame = 0;

		while (continuePlaying == true && winOrLoss == false) {

			TakeATurn(firstPlayer.GetHand(), computer.GetHand(), turnCounter);

			winOrLoss = WinnerOrLoser(firstPlayer.GetHand(), computer.GetHand());

			if (winOrLoss == false) {

				cout << "\nAre you ready for the next turn?(1=yes/2=no)" << endl;
				cin >> continueGame;

				while (continueGame < 1 || continueGame > 2) {

					cout << "Please pick 1 for yes or 2 for no." << endl;
					cin >> continueGame;
				}

				if (continueGame == 2) {

					continuePlaying = false;
					cout << "\nAw ending so soon?\n" << endl;
				}

			}

		}

		unsigned int pSize = (firstPlayer.GetHand()).size();
		unsigned int cSize = (computer.GetHand()).size();

		if (pSize == 52) {

			cout << "\nCongratulations! You beat the computer!\n" << endl;
		}
		else if (cSize == 52) {

			cout << "\nAw the computer beat you. Don't worry you can always try again!\n" << endl;
		}

	}


}

void Table::Instructions() {

	cout << "\nWar is a card game usually played between two people. They use a single deck of 52 playing cards.\nThe cards are shuffled then split 26 cards for both players. The cards are h\
eld face down by\nboth players and they play their top card without looking at it. Which ever card has the higher\nvalue is the winner of the \"battle\" and the player who won it takes bot\
h cards and places them\nat the bottom of their deck. If there is a turn where the values are the same then War! is called.\nThe players then both play 3 cards all face down without lookin\
g at them. Then both players play\na fourth card and compare their value. Whoever wins that takes all the cards on the table.\nIf the fourth cards of both players are the same value then t\
he previous steps are repeated.\nThe point of the game is to have all 52 cards in your hand to win the War.\n" << endl;
}

bool Table::WinnerOrLoser(vector<Card*>& playerHand, vector<Card*>& computerHand) {

	unsigned int pSize = playerHand.size();
	unsigned int cSize = computerHand.size();

	if (pSize == 52 && cSize == 0) {

		return true;
	}
	else if (pSize == 0 && cSize == 52) {

		return true;
	}

	return false;
}

void Table::EndGame() {

	cout << "\nThanks for playing!\n\nAll programming and design done by Nazily Zaza.\n" << endl;
}

void Table::War(vector<Card*>& playerHand, vector<Card*>& computerHand) {

	int amntBack = 4;

	unsigned int pLast = playerHand.size();
	unsigned int cLast = computerHand.size();

	cout << "\nBoth you and the computer played 3 cards face down on the table." << endl;

	cout << "\nYour 4th card played was a " << playerHand[pLast - amntBack]->GetName() << " of " << playerHand[pLast - amntBack]->GetType() << "!\n" << endl;

	cout << "The computer's 4th card was a " << computerHand[cLast - amntBack]->GetName() << " of " << computerHand[cLast - amntBack]->GetType() << "!\n" << endl;

	if (playerHand[pLast - amntBack]->GetValue() > computerHand[cLast - amntBack]->GetValue()) {

		for (int i = 4; i > 0; i--) {

			Card* newCard = new Card(*computerHand[cLast - i]);
			playerHand.push_back(newCard);

			delete computerHand[cLast - i];
		}

		for (int i = 4; i > 0; i--) {

			computerHand.pop_back();
		}

		cout << "You won the war and took all 4 cards!\n" << endl;
	}

	else if (playerHand[pLast - amntBack]->GetValue() < computerHand[cLast - amntBack]->GetValue()) {

		for (int i = 4; i > 0; i--) {

			Card* newCard = new Card(*playerHand[pLast - i]);
			computerHand.push_back(newCard);

			delete playerHand[pLast - i];
		}

		for (int i = 4; i > 0; i--) {

			playerHand.pop_back();
		}

		cout << "The computer won the war and took all 4 cards!\n" << endl;
	}

	else if (playerHand[pLast - amntBack]->GetValue() == computerHand[cLast - amntBack]->GetValue()) {

		cout << "A second war has been called....a winner shall be randomly selected.\n" << endl;

		int randomNum = 0;
		srand((unsigned int)time(NULL));
		randomNum = rand() % 10;

		if (randomNum >= 0 && randomNum <= 4) {

			for (int i = 4; i > 0; i--) {

				Card* newCard = new Card(*computerHand[cLast - i]);
				playerHand.push_back(newCard);

				delete computerHand[cLast - i];
			}

			for (int i = 4; i > 0; i--) {

				computerHand.pop_back();
			}

			cout << "You won the war and took all 4 cards!\n" << endl;

		}

		else if (randomNum >= 5 && randomNum <= 9) {

			for (int i = 4; i > 0; i--) {

				Card* newCard = new Card(*playerHand[pLast - i]);
				computerHand.push_back(newCard);

				delete playerHand[pLast - i];
			}

			for (int i = 4; i > 0; i--) {

				playerHand.pop_back();
			}

			cout << "The computer won the war and took all 4 cards!\n" << endl;

		}

	}

}

void Table::ShuffleDecks(vector<Card*>& playerHand, vector<Card*>& computerHand) {

	Deck newDeck;

	vector<Card*> theDeck = newDeck.GetDeck();

	srand((unsigned int)time(NULL));

	random_shuffle(theDeck.begin(), theDeck.end());

	int switcher = 1;

	for (vector<Card*>::iterator it = theDeck.begin(); it != theDeck.end(); ++it) {

		if (switcher == 1) {

			Card* newCard = new Card(*(*it));

			playerHand.push_back(newCard);
			switcher = 2;
		}

		else if (switcher == 2) {

			Card* newCard = new Card(*(*it));

			computerHand.push_back(newCard);
			switcher = 1;
		}

	}

	/*
	for(unsigned int i = 0; i < theDeck.size(); i++) {

	delete theDeck[i];
	theDeck[i] = NULL;
	}
	*/
	cout << "\nThe Deck has succesfully been shuffled and split." << endl;
}

void Table::TakeATurn(vector<Card*>& playerHand, vector<Card*>& computerHand, int& turn) {

	random_shuffle(playerHand.begin(), playerHand.end());
	random_shuffle(computerHand.begin(), computerHand.end());

	unsigned int pLast = playerHand.size();
	unsigned int cLast = computerHand.size();

	turn += 1;

	cout << "\nTurn #: " << turn << endl;

	cout << "\nYou played a " << playerHand[pLast - 1]->GetName() << " of " << playerHand[pLast - 1]->GetType() << "!\n" << endl;

	cout << "The computer played a " << computerHand[cLast - 1]->GetName() << " of " << computerHand[cLast - 1]->GetType() << "!\n" << endl;

	if (playerHand[pLast - 1]->GetValue() > computerHand[cLast - 1]->GetValue()) {

		Card* newCard = new Card(*computerHand[cLast - 1]);
		playerHand.push_back(newCard);

		delete computerHand[cLast - 1];
		computerHand.pop_back();

		cout << "You won the battle and took both cards!\n" << endl;
	}

	else if (playerHand[pLast - 1]->GetValue() < computerHand[cLast - 1]->GetValue()) {

		Card* newCard = new Card(*playerHand[pLast - 1]);
		computerHand.push_back(newCard);

		delete playerHand[pLast - 1];
		playerHand.pop_back();

		cout << "The computer won the battle and took both cards!\n" << endl;
	}

	else if (playerHand[pLast - 1]->GetValue() == computerHand[cLast - 1]->GetValue()) {

		if (pLast > 3 && cLast > 3) {

			cout << "War has been called!\n" << endl;

			War(playerHand, computerHand);

		}
		else {

			if (pLast > cLast) {

				cout << "War was called, but the computer has less than 4 cards, so the player takes them all!\n" << endl;

				for (unsigned int i = 0; i < cLast; i++) {

					Card* newCard = new Card(*computerHand[i]);
					playerHand.push_back(newCard);

					delete computerHand[i];
				}

				for (unsigned int i = 0; i < cLast; i++) {

					computerHand.pop_back();
				}

			}

			else if (cLast > pLast) {

				cout << "War was called, but the player has less than 4 cards, so the computer takes them all!\n" << endl;

				for (unsigned int i = 0; i < cLast; i++) {

					Card* newCard = new Card(*playerHand[i]);
					computerHand.push_back(newCard);

					delete playerHand[i];
				}

				for (unsigned int i = 0; i < cLast; i++) {

					playerHand.pop_back();
				}

			}

		}

	}

	unsigned int newPSize = playerHand.size();
	unsigned int newCSize = computerHand.size();
	cout << "You have " << newPSize << " cards left. And the computer has " << newCSize << " cards left.\n" << endl;
}
