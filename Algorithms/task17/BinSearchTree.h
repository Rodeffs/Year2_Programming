#pragma once

#include "../task15-16/BinTree.h"  // использую уже готовое дерево из предыдущих лаб
#include "../task15-16/Node.h"
#include <string>

using std::string;

class BinSearchTree : public BinTree {
public:
	explicit BinSearchTree(const string& str) : BinTree(str) {}

	Node* getRoot();  // нужен для нормальной работы вывода

	string printTree(Node* parent);

	bool searchTree(int value);

	void addElement(int value);

	void removeElement(int value);
};
