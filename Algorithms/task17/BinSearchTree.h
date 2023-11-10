#pragma once

#include "../task15-16/BinTree.h"  // использую уже готовое дерево из предыдущих лаб
#include <string>

using std::string;

class BinSearchTree : public BinTree {
public:
	explicit BinSearchTree(const string& str) : BinTree(str) {}
	
};
