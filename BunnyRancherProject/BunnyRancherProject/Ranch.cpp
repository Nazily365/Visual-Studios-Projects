#include "stdafx.h"
#include "Ranch.h"

using namespace std;

const int INITIAL_BUNNY_POPULATION = 5;
const int MAX_POPULATION = 1000;
const int YEAR_OF_DEATH_BUNNY = 10;
const int YEAR_OF_DEATH_MUTANT = 49;
const int ADULT_AGE = 2;

Ranch::Ranch() {

}

Ranch::Ranch(string fileName) {

	srand((unsigned int)time(NULL));

	m_head = NULL;
	m_years = 1;

	ifstream bunnyFile;
	bunnyFile.open(fileName.c_str());

	string bunnyName = "";

	while (bunnyFile) {

		bunnyFile >> bunnyName;
		m_bunnyNames.push_back(bunnyName);
	}

	bunnyFile.close();

	vector<string> colors;
	colors.push_back("White");
	colors.push_back("Black");
	colors.push_back("Brown");
	colors.push_back("Spotted");
	unsigned int numColors = colors.size();
	unsigned int colorCount = 0;

	for (int i = 0; i < INITIAL_BUNNY_POPULATION; i++) {

		int randomNum = rand() % 80;
		string randomName = m_bunnyNames[randomNum];
		string color;

		if (colorCount < numColors) {

			color = colors[colorCount];
		}
		else if (colorCount == numColors) {

			color = colors[colorCount - colorCount];
			colorCount = 0;
		}

		Node* newNode = new Node(randomName, color, false);
		Node* last = m_head;
		newNode->SetNext(NULL);

		if (m_head == NULL) {

			m_head = newNode;
			//newNode->SetNext(NULL);
		}
		else {

			//Node* temp = m_head;

			while (last->GetNext() != NULL) {

				last = last->GetNext();
			}

			last->SetNext(newNode);
		}

		colorCount += 1;
	}

	m_bunnyPop = INITIAL_BUNNY_POPULATION;
}

Ranch::~Ranch() {

	if (m_head->GetNext() == NULL) {

		delete m_head;
		m_head = NULL;
	}
	else {

		while (m_head != NULL) {

			Node* oneAfterBegin = m_head;
			oneAfterBegin = m_head->GetNext();
			delete m_head;
			m_head = oneAfterBegin;

			if (m_head->GetNext() == NULL) {

				delete m_head;
				m_head = NULL;
			}
		}

	}

}

void Ranch::GrowUp() {

	Node* temp = m_head;

	if (m_head == NULL) {

		cout << "You don't have any bunnies!" << endl;
	}
	else {

		while (temp->GetNext() != NULL) {

			int age = (temp->GetBunny()).GetAge() + 1;
			(temp->GetBunny()).SetAge(age);

			temp = temp->GetNext();
		}

		int age = (temp->GetBunny()).GetAge() + 1;
		(temp->GetBunny()).SetAge(age);
		cout << "\nAll your bunnies have grown up 1 year!\n" << endl;
	}

}

void Ranch::AnotherYear() {

	m_years += 1;

	GrowUp();

	BunnyDeath();

	int maleBunnies = 0;
	int femaleBunnies = 0;
	int newBabies = 0;

	Node* temp = m_head;

	if (m_head == NULL) {

		cout << "You don't have any bunnies! The entire population is dead and your ranch is over, no point in continuing to the next year. You may exit the program." << endl;
	}
	else {

		while (temp->GetNext() != NULL) {

			if ((temp->GetBunny()).GetSex() == "Male" && (temp->GetBunny()).GetAge() >= ADULT_AGE && (temp->GetBunny()).GetMutant() == false) {

				maleBunnies += 1;
			}
			else if ((temp->GetBunny()).GetSex() == "Female" && (temp->GetBunny()).GetAge() >= ADULT_AGE && (temp->GetBunny()).GetMutant() == false) {

				femaleBunnies += 1;
			}

			temp = temp->GetNext();
		}

		if ((temp->GetBunny()).GetSex() == "Male") {

			maleBunnies += 1;
		}
		else if ((temp->GetBunny()).GetSex() == "Female") {

			femaleBunnies += 1;
		}
	}

	if (maleBunnies > femaleBunnies) {

		newBabies = femaleBunnies;
	}
	else if (maleBunnies < femaleBunnies) {

		newBabies = maleBunnies * femaleBunnies;
	}
	else if (maleBunnies == femaleBunnies) {

		newBabies = maleBunnies;
	}

	BunnyBirth(newBabies);

	MutantTransform();

	if (m_bunnyPop > MAX_POPULATION) {

		BunnyPurge();
	}

	cout << "\nAnother year has gone by...\n" << endl;
}

void Ranch::BunnyBirth(int numBirths) {

	if (numBirths == 0) {

		cout << "\nSorry, no births this year!" << endl;
	}

	for (int i = 0; i < numBirths; i++) {

		int randomNum = rand() % 80;
		string randomName = m_bunnyNames[randomNum];

		Node* newNode = new Node(randomName);
		Node* last = m_head;
		newNode->SetNext(NULL);

		if (m_head == NULL) {

			m_head = newNode;
		}
		else {

			while (last->GetNext() != NULL) {

				last = last->GetNext();
			}

			last->SetNext(newNode);
		}

		if ((newNode->GetBunny()).GetMutant() == true) {

			cout << "Radioactive mutant vampire baby bunny " << (newNode->GetBunny()).GetName() << " was born!\n" << endl;
		}
		else {

			cout << "Baby bunny " << (newNode->GetBunny()).GetName() << " was born!\n" << endl;
		}

		m_bunnyPop += 1;
	}

}

void Ranch::BunnyDeath() {

	Node* temp = m_head;

	if (m_head == NULL) {

		cout << "You don't have any bunnies!" << endl;
	}
	else {

		while (temp->GetNext() != NULL) {

			if ((temp->GetBunny()).GetMutant() == true && (temp->GetBunny()).GetAge() > YEAR_OF_DEATH_MUTANT) {

				cout << "\nRadioactive mutant vampire bunny " << (temp->GetBunny()).GetName() << " has reached the age of " << (temp->GetBunny()).GetAge() << " and died.\n" << endl;
				temp = m_head->GetNext();
				delete m_head;
				m_head = temp;
				m_bunnyPop -= 1;
			}
			else if ((temp->GetBunny()).GetAge() > YEAR_OF_DEATH_BUNNY) {

				cout << "\nOh no! Adult bunny " << (temp->GetBunny()).GetName() << " has reached the age of " << (temp->GetBunny()).GetAge() << " and died.\n" << endl;
				temp = m_head->GetNext();
				delete m_head;
				m_head = temp;
				m_bunnyPop -= 1;
			}
			else {

				if ((temp->GetNext())->GetBunny().GetMutant() == true && (temp->GetNext())->GetBunny().GetAge() > YEAR_OF_DEATH_MUTANT) {

					cout << "\nRadioactive mutant vampire bunny " << (temp->GetNext())->GetBunny().GetName() << " has reached the age of " << (temp->GetNext())->GetBunny().GetAge() << " and died.\n" << endl;

					temp->SetNext((temp->GetNext())->GetNext());

					delete temp->GetNext();

					temp = temp->GetNext();
					m_bunnyPop -= 1;
				}
				else if ((temp->GetNext())->GetBunny().GetAge() > YEAR_OF_DEATH_BUNNY) {
					//delete the getNext's pointer data and re-work the setNext's

					cout << "\nOh no! Adult bunny " << (temp->GetNext())->GetBunny().GetName() << " has reached the age of " << (temp->GetNext())->GetBunny().GetAge() << " and died.\n" << endl;
					temp->SetNext((temp->GetNext())->GetNext());
					delete temp->GetNext();
					//temp = (temp->GetNext())->GetNext();
					temp = temp->GetNext();
					m_bunnyPop -= 1;
				}
				else {

					temp = temp->GetNext();
				}
			}

		}

		if ((temp->GetBunny()).GetMutant() == true && (temp->GetBunny()).GetAge() > YEAR_OF_DEATH_MUTANT) {

			cout << "\nRadioactive mutant vampire bunny " << (temp->GetBunny()).GetName() << " has reached the age of " << (temp->GetBunny()).GetAge() << " and died.\n" << endl;
			temp = m_head->GetNext();
			delete m_head;
			m_head = temp;
			m_bunnyPop -= 1;
		}
		else if ((temp->GetBunny()).GetAge() > YEAR_OF_DEATH_BUNNY) {

			cout << "\nOh no! Adult bunny " << (temp->GetBunny()).GetName() << " has reached the age of " << (temp->GetBunny()).GetAge() << " and died.\n" << endl;
			temp = m_head->GetNext();
			delete m_head;
			m_head = temp;
			m_bunnyPop -= 1;
		}

	}
}

void Ranch::MutantTransform() {

	int mutantCount = 0;

	Node* temp = m_head;

	if (m_head == NULL) {

		cout << "You don't have any bunnies!" << endl;
	}
	else {

		while (temp->GetNext() != NULL) {

			if ((temp->GetBunny()).GetMutant() == true) {

				mutantCount += 1;
			}

			temp = temp->GetNext();
		}

		if ((temp->GetBunny()).GetMutant() == true) {

			mutantCount += 1;
		}
	}

	if (mutantCount == 0) {

		cout << "\nYay! There are 0 radioactive mutant vampire bunnies within the colony!! For now..." << endl;
	}
	else {

		cout << "\nOh no! You have exactly " << mutantCount << " radioactive mutant vampire bunnies within the colony!!\nEach one will turn exaclty one other bunny into a mutant!" << endl;
	}

	temp = m_head;

	while (mutantCount != 0) {

		if (temp->GetNext() == NULL) {

			if ((temp->GetBunny()).GetMutant() == false) {

				cout << (temp->GetBunny()).GetName() << " has turned into a radioactive mutant vampire bunny!!" << endl;
				(temp->GetBunny()).SetMutant(true);
				mutantCount = 0;
			}

		}
		else {

			if ((temp->GetBunny()).GetMutant() == false) {

				cout << (temp->GetBunny()).GetName() << " has turned into a radioactive mutant vampire bunny!!" << endl;
				(temp->GetBunny()).SetMutant(true);
				mutantCount -= 1;
			}

			temp = temp->GetNext();
		}

	}

}

void Ranch::BunnyPurge() {

	for (int i = 0; i < m_bunnyPop / 2; i++) {

		if (m_head == NULL) {

			cout << "There are no bunnies to purge." << endl;
		}
		else if (m_head->GetNext() == NULL) {

			delete m_head;
			m_head = NULL;
			cout << "Wow you had one bunny....and you purged it. Despicable" << endl;
		}
		else {

			cout << "\nThe population reached maximum! A food shortage caused half of your bunnies to die!\n" << endl;

			Node* oneAfterBegin = m_head;
			cout << (oneAfterBegin->GetBunny()).GetName() << " has died because of the food shortage.\n" << endl;

			oneAfterBegin = m_head->GetNext();
			delete m_head;
			m_head = oneAfterBegin;
		}
		m_bunnyPop -= 1;
	}

}

void Ranch::DisplayColony() {

	cout << "BUNNY RANCH:\n" << endl;
	cout << "Year: " << m_years << endl;
	cout << "You have " << m_bunnyPop << " bunnies in the colony!\n" << endl;
	Node* temp = m_head;
	int bunnyNum = 1;

	if (m_head == NULL) {

		cout << "You don't have any bunnies!" << endl;
	}
	else {

		while (temp->GetNext() != NULL) {

			cout << bunnyNum << ").\n" << "Bunny name: " << (temp->GetBunny()).GetName() << endl;
			cout << "Bunny sex: " << (temp->GetBunny()).GetSex() << endl;
			cout << "Bunny color: " << (temp->GetBunny()).GetColor() << endl;
			cout << "Bunny age: " << (temp->GetBunny()).GetAge() << endl;

			if ((temp->GetBunny()).GetMutant() == false) {

				cout << "Is mutant?: False\n" << endl;
			}
			else if ((temp->GetBunny()).GetMutant() == true) {

				cout << "Is mutant?: True\n" << endl;
			}

			temp = temp->GetNext();
			bunnyNum += 1;
		}

		cout << bunnyNum << ").\n" << "Bunny name: " << (temp->GetBunny()).GetName() << endl;
		cout << "Bunny sex: " << (temp->GetBunny()).GetSex() << endl;
		cout << "Bunny color: " << (temp->GetBunny()).GetColor() << endl;
		cout << "Bunny age: " << (temp->GetBunny()).GetAge() << endl;

		if ((temp->GetBunny()).GetMutant() == false) {

			cout << "Is mutant?: False\n" << endl;
		}
		else if ((temp->GetBunny()).GetMutant() == true) {

			cout << "Is mutant?: True\n" << endl;
		}
	}

}

int Ranch::GetPop() {

	return m_bunnyPop;
}

int Ranch::GetYear() {

	return m_years;
}