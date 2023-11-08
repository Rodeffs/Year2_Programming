#pragma once

#include "Node.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>  // для преобразования типов

using namespace std;

class BinTree {
private:
	string str;

	Node root;

	Node& assignChildren(int begin, int end);

	void removeSpaces();

public:
	BinTree(const string& binTreeInput);

	Node& getRoot();

	void pre_ordered(Node* root);  // прямой обход

	void in_ordered(Node* root);  // центральный обход

	void post_ordered(Node* root); // концевой обход

	string& pre_ordered_non_recursive();  // прямой не рекурсивный обход 
};
