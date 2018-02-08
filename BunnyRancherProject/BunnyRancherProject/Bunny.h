#pragma once

#include <iostream>
#include <string>

using namespace std;

class Bunny {

public:
	Bunny();
	Bunny(string name);
	Bunny(string name, string color);
	Bunny(string name, string color, bool mutant);
	void SetName(string name);
	string GetName();
	void SetSex(string sex);
	string GetSex();
	void SetColor(string color);
	string GetColor();
	void SetAge(int age);
	int GetAge();
	void SetMutant(bool mutant);
	bool GetMutant();

private:
	string m_name;
	string m_sex;
	string m_color;
	int m_age;
	bool m_radioactive_mutant_vampire;
	
};