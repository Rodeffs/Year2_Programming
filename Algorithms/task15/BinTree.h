#pragma once

#include "Node.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>  // для преобразования типов

using namespace std;

struct Indexes {  // чтобы хранить все индексы в одном месте
	int parent;
	int left;
	int right;

	int begin;
	int end;
};

class BinTree {
private:
	vector<Node*> tree;

	void assignChildren(const string& binTreeInput, Indexes& indexes);

public:
	BinTree(const string& binTreeInput);
};
