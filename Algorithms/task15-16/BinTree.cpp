#include "BinTree.h"

BinTree::BinTree(const string& binTreeInput) {
	this->inputString = binTreeInput;
	removeSpaces();
	root = &assignChildren(0, inputString.length() - 1);
}

BinTree::~BinTree() {
	delete_post_ordered(root);
}

Node& BinTree::assignChildren(int begin, int end) {
	int countBrackets{0}, commaIndex{0}, beginIndex{0}, endIndex{0}, rootValue{0};
	bool wasParent{false}, wasMinus{false};
	auto parent = new Node();

	for (int i = begin; i <= end; i++) {
		auto current = inputString[i];
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
		if (inputString[commaIndex - 1] != '(')
			parent->leftChild = &assignChildren(beginIndex, commaIndex - 1);

		if (inputString[commaIndex + 1] != ')')
			parent->rightChild = &assignChildren(commaIndex + 1, endIndex);
	}
	return *parent;
}

void BinTree::removeSpaces() {
	int i = inputString.find(' ');
	if (i != -1) {
		inputString.erase(inputString.begin() + i);
		removeSpaces();
	}
}

void BinTree::delete_post_ordered(Node* parent) {
	if (parent == nullptr)
		return;
	delete_post_ordered(parent->leftChild);
	delete_post_ordered(parent->rightChild);
	delete parent;
}

void BinTree::pre_ordered_recursive(Node* parent) {
	if (parent == nullptr)
		return;
	returnString += std::to_string(parent->getValue());  // для преобразования int в string
	returnString += ' ';
	pre_ordered_recursive(parent->leftChild);
	pre_ordered_recursive(parent->rightChild);
}

void BinTree::in_ordered_recursive(Node* parent) {
	if (parent == nullptr)
		return;
	in_ordered_recursive(parent->leftChild);
	returnString += std::to_string(parent->getValue());  // для преобразования int в string
	returnString += ' ';
	in_ordered_recursive(parent->rightChild);
}

void BinTree::post_ordered_recursive(Node* parent) {
	if (parent == nullptr)
		return;
	post_ordered_recursive(parent->leftChild);
	post_ordered_recursive(parent->rightChild);
	returnString += std::to_string(parent->getValue());  // для преобразования int в string
	returnString += ' ';
}

string& BinTree::pre_ordered() {
	returnString.clear();
	pre_ordered_recursive(root);
	return returnString;
}

string& BinTree::in_ordered() {
	returnString.clear();
	in_ordered_recursive(root);
	return returnString;
}

string& BinTree::post_ordered() {
	returnString.clear();
	post_ordered_recursive(root);
	return returnString;
}
// `string& BinTree::pre_ordered_non_recursive() {}
