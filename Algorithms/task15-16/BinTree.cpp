#include "BinTree.h"
#include <vector>
#include <iostream>

BinTree::BinTree(const string& binTreeInput) {
	this->inputString = binTreeInput;
	removeSpaces();
	root = assignChildren(0, inputString.length() - 1);
}

BinTree::~BinTree() {
	delete_post_ordered(root);
	std::cout << "BinTree destructor called" << std::endl;
}

Node* BinTree::assignChildren(int begin, int end) {
	int countBrackets{0}, commaIndex{0}, beginIndex{0}, endIndex{0}, rootValue{0};
	bool wasParent{false}, wasMinus{false};
	auto parent = new Node();

	for (int i = begin; i <= end; i++) {
		auto current = inputString[i];
		if (!wasParent) {  // присваиваем значение только для родительского элемента, остальным - по рекурсии в следующих итерациях 
			wasMinus = (current == '-' ? !wasMinus : wasMinus);  // если минус встретился n раз, то умножаем rootValue на (-1)^n

			if (current >= '0' && current <= '9')
				rootValue = rootValue * 10 + (current - 48);   // преобразование char в int, т.к. в ASCII таблице цифры 0, 1, ... , 9 имеют значения 48, 49, ... , 57

			if ((current != '-' && current < '0') || current > '9' || i == end) {  // не забываем также и про случай, когда у нас задан только корневой элемент без детей
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
			parent->setLeft(assignChildren(beginIndex, commaIndex - 1));

		if (inputString[commaIndex + 1] != ')')
			parent->setRight(assignChildren(commaIndex + 1, endIndex));
	}
	return parent;
}

void BinTree::removeSpaces() {
	int i = inputString.find(' ');
	if (i == -1)
		return;
	inputString.erase(inputString.begin() + i);
	removeSpaces();
}

void BinTree::delete_post_ordered(Node* parent) {
	if (parent == nullptr)
		return;
	delete_post_ordered(parent->getLeft());
	delete_post_ordered(parent->getRight());
	delete parent;
}

void BinTree::pre_ordered_recursive(Node* parent) {
	if (parent == nullptr)
		return;
	traverseTree += std::to_string(parent->getValue());  // для преобразования int в string
	traverseTree += ' ';
	pre_ordered_recursive(parent->getLeft());
	pre_ordered_recursive(parent->getRight());
}

void BinTree::in_ordered_recursive(Node* parent) {
	if (parent == nullptr)
		return;
	in_ordered_recursive(parent->getLeft());
	traverseTree += std::to_string(parent->getValue());  // для преобразования int в string
	traverseTree += ' ';
	in_ordered_recursive(parent->getRight());
}

void BinTree::post_ordered_recursive(Node* parent) {
	if (parent == nullptr)
		return;
	post_ordered_recursive(parent->getLeft());
	post_ordered_recursive(parent->getRight());
	traverseTree += std::to_string(parent->getValue());  // для преобразования int в string
	traverseTree += ' ';
}

string& BinTree::pre_ordered() {
	traverseTree.clear();
	pre_ordered_recursive(root);
	return traverseTree;
}

string& BinTree::in_ordered() {
	traverseTree.clear();
	in_ordered_recursive(root);
	return traverseTree;
}

string& BinTree::post_ordered() {
	traverseTree.clear();
	post_ordered_recursive(root);
	return traverseTree;
}

string& BinTree::pre_ordered_non_recursive() {
	traverseTree.clear();

	std::vector<Node*> treeNodes;  // создаём стек, где храним ещё не пройденные элементы, т.е. это очередь элементов, по которым надо пройтись
	treeNodes.push_back(root);  // добавляем в него корневой элемент

	while (!treeNodes.empty()) {
		auto currentNode = treeNodes.back();  // элемент в данный момент, сначала родитель, потом левый и в конце правый ребенок
		treeNodes.pop_back();  // удаляем этот элемент из стека, чтобы не проходится по нему несколько раз

		if (currentNode != nullptr) {  // проходимся по этому элементу, а затем по его детям, начиная с левого элемента, т.к. это прямой обход
			traverseTree += std::to_string(currentNode->getValue());
			traverseTree += ' ';

			treeNodes.push_back(currentNode->getRight());
			treeNodes.push_back(currentNode->getLeft());
		}
	}
	return traverseTree;
}
