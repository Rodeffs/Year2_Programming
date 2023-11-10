#pragma once

#include "Node.h"
#include <string>

using std::string;

class BinTree {
private:
	string inputString;

	string returnString;

	Node* root;

	Node* assignChildren(int begin, int end);

	void pre_ordered_recursive(Node* parent);  // пришлось писать саму рекурсию отдельно, т.к. иначе не получается вернуть returnString, ибо его нужно каждый раз очищать от предыдущего вывода
	
	void in_ordered_recursive(Node* parent);
	
	void post_ordered_recursive(Node* parent);
	
	void delete_post_ordered(Node* parent);  // для деструктора (т.к. в деструктор глупо передавать параметры) 

	void removeSpaces();  // для очищения строки от пробелов, т.к. они нам не нужны и будут только мешать при проверке наличия детей

public:
	explicit BinTree(const string& binTreeInput);

	~BinTree();

	string& pre_ordered();  // прямой обход

	string& in_ordered();  // центральный обход

	string& post_ordered(); // концевой обход

	string& pre_ordered_non_recursive();  // прямой не рекурсивный обход 
};
