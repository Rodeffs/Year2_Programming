#include "BinTree.h"

Node& BinTree::assignChildren(int begin, int end) {

	int countBrackets{0}, commaIndex{0}, beginIndex{0}, endIndex{0}, rootValue{0};
	bool wasParent{false}, wasMinus{false};

	auto parent = new Node();

	for (int i = begin; i <= end; i++) {
		auto current = str[i];
		
		if (!wasParent) {  // присваиваем значение только для родительского элемента, остальным - по рекурсии в следующих итерациях 
			
			wasMinus = (current == '-' ? !wasMinus : wasMinus);  // если минус встретился n раз, то умножаем rootValue на (-1)^n

			if (current >= 48 && current <= 57)  // преобразование char в int, т.к. в ASCII таблице цифры 0, 1, ... , 9 имеют значения 48, 49, ... , 57
				rootValue = rootValue * 10 + (current - 48); 

			if ((current != '-' && current < 48) || current > 57 || i == end) {  // не забываем также и про случай, когда у нас задан только корневой элемент без детей
				rootValue = (wasMinus ? -rootValue : rootValue);
				parent->setValue(rootValue);
				beginIndex = i + 1;
				wasParent = true;
			}
		}
		
		else  // нам нужно лишь помнить индексы начала левого и правого элемента в строке, дабы потом по рекурсии присвоить им значения 
			
			switch (current) {
				
				case '(':
					countBrackets++;
					break;

				case ')':
					if (countBrackets)
						countBrackets--;
					else
						endIndex = i - 1;
					break;

				case ',':
					if (!countBrackets)
						commaIndex = i;
					break;
			}
	}

	if (commaIndex) {  // если нету какого-либо из ребёнков, то их даже не рассматриваем далее, т.к. по умолчанию указатель на них будет nullptr
		
		if (str[commaIndex - 1] != '(')
			parent->leftChild = &assignChildren(beginIndex, commaIndex - 1);

		if (str[commaIndex + 1] != ')')
			parent->rightChild = &assignChildren(commaIndex + 1, endIndex);
	}

	return *parent;
}

void BinTree::removeSpaces() {

	int i = str.find(' ');
	if (i != -1) {
		str.erase(str.begin() + i);
		removeSpaces();
	}
}

BinTree::BinTree(const string& binTreeInput) {

	this->str = binTreeInput;
	removeSpaces();

	root = assignChildren(0, str.length() - 1);
}

Node& BinTree::getRoot() {

	return this->root;
}

void BinTree::pre_ordered(Node* root) {

	if (root == nullptr)
		return;

	cout << root->getValue() << endl;
	pre_ordered(root->leftChild);
	pre_ordered(root->rightChild);
}

void BinTree::in_ordered(Node* root) {

	if (root == nullptr)
		return;

	in_ordered(root->leftChild);
	cout << root->getValue() << endl;
	in_ordered(root->rightChild);
}

void BinTree::post_ordered(Node* root) {

	if (root == nullptr)
		return;

	post_ordered(root->leftChild);
	post_ordered(root->rightChild);
	cout << root->getValue() << endl;
}

// `string& BinTree::pre_ordered_non_recursive() {}
