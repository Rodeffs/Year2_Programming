#pragma once

#include "Node.h"
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

class BinTree {
private:
	string str;

	Node root;

	Node& assignChildren(int begin, int end);

	void removeSpaces();  // для очищения строки от пробелов, т.к. они нам не нужны

public:
	BinTree(const string& binTreeInput);

	Node& getRoot();

	void pre_ordered(Node* root);  // прямой обход

	void in_ordered(Node* root);  // центральный обход

	void post_ordered(Node* root); // концевой обход

	string& pre_ordered_non_recursive();  // прямой не рекурсивный обход 
};
