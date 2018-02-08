#pragma once

#include <iostream>
#include <string>
using namespace std;

class Card {

public:

	Card(int type, int name, int value);
	void SetName(string name);
	string GetName();
	void SetType(string type);
	string GetType();
	void SetValue(int value);
	int GetValue();

private:

	string m_name;
	string m_type;
	int m_value;
};


