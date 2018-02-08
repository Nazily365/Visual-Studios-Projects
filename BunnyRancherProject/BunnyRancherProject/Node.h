#pragma once

#include "Bunny.h"
#include <string>

using namespace std;

class Node {

public:
	Node();
	Node(string name);
	Node(string name, string color);
	Node(string name, string color, bool mutant);
	~Node();
	Bunny& GetBunny();
	void SetBunny(Bunny& bun);
	Node* GetNext();
	void SetNext(Node* next);

private:

	Bunny m_bunny;
	Node* m_next;
};