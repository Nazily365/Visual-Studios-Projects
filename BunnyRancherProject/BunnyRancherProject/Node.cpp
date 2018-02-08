#include "stdafx.h"
#include "Node.h"
using namespace std;

Node::Node() {

	m_bunny = Bunny();
	m_next = NULL;
}

Node::Node(string name) {

	m_bunny = Bunny(name);
	m_next = NULL;
}

Node::Node(string name, string color) {

	m_bunny = Bunny(name, color);
	m_next = NULL;
}

Node::Node(string name, string color, bool mutant) {

	m_bunny = Bunny(name, color, mutant);
	m_next = NULL;
}

Node::~Node() {

	m_bunny.SetName("");
	m_bunny.SetSex("");
	m_bunny.SetColor("");
	m_bunny.SetAge(0);
	m_bunny.SetMutant(false);
	m_next = NULL;
}

Bunny& Node::GetBunny() {

	return m_bunny;
}

void Node::SetBunny(Bunny& bun) {

	m_bunny = bun;
}

Node* Node::GetNext() {

	return m_next;
}

void Node::SetNext(Node* next) {

	m_next = next;
}