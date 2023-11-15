#include "BinSearchTree.h"

Node* BinSearchTree::getRoot() {
	return this->root;
}

string BinSearchTree::printTree(Node* parent) {
	string outputString = "";

	if (parent != nullptr) {
		outputString.append(std::to_string(parent->getValue()));

		if (parent->leftChild != nullptr || parent->rightChild != nullptr) {  // чтобы не было пустых скобок
			outputString.append(" (");
			outputString.append(printTree(parent->leftChild));
			outputString.append(", ");
			outputString.append(printTree(parent->rightChild));
			outputString.append(")");
		}
	}
	return outputString;
}

bool BinSearchTree::searchTree(int value) {
	auto parent = root;

	while (true) {
		if (parent->getValue() == value)
			return true;

		if (parent->getValue() > value) {
			if (parent->leftChild != nullptr)  // это нужно, т.к. цикл по какой-то причине ломается, если присвоить нулевой указатель (видимо, проверка не выполняется)
				parent = parent->leftChild;
			else
				break;
		}

		if (parent->getValue() < value) {
			if (parent->rightChild != nullptr)
				parent = parent->rightChild;
			else
				break;
		}
	}
	return false;
}

void BinSearchTree::addElement(int value) {  // просто ищем подходящее место для элемента через поиск и добавляем его туда
	auto parent = root;
	auto child = new Node(value);

	while (true) {
		if (parent->getValue() >= value) {
			if (parent->leftChild == nullptr) {
				parent->leftChild = child;
				return;
			}
			parent = parent->leftChild;
		}

		else {
			if (parent->rightChild == nullptr) {
				parent->rightChild = child;
				return;
			}
			parent = parent->rightChild;
		}
	}
}

void BinSearchTree::removeElement(int value) {
	auto element = root;
	Node* parent = nullptr;
	bool isLeft{false};

	while (element->getValue() != value) {  // поиск удаляемого значения
		parent = element;

		if (element->getValue() > value) {
			isLeft = true;
			element = element->leftChild;
		}

		if (element->getValue() < value) {
			isLeft = false;
			element = element->rightChild;
		}
	}

	if (element->leftChild == nullptr && element->rightChild == nullptr) {  // самый простой случай - когда у удаляемого элемента нет детей	
		if (parent != nullptr) {  // не забываем удалять указатель на элемент в родительском, чтобы не возникло ошибки сегментации
			if (isLeft)
				parent->leftChild = nullptr;
			else
				parent->rightChild = nullptr;
		}
		delete element;
	}

	else if (element->leftChild == nullptr && element->rightChild != nullptr) {  // случаи, когда у элемента только один ребёнок тоже простые - нужно только поменять их местами
		auto swap = *element->rightChild;
		delete element->rightChild;
		*element = swap;
	}

	else if (element->leftChild != nullptr && element->rightChild == nullptr) {
		auto swap = *element->leftChild;
		delete element->leftChild;
		*element = swap;
	}

	else {
		/* Удаление вершины у которой есть дети в бинарном дереве поиска проходит по следующему алгоритму:
		 * 1) Идём по дереву от данной вершины с целью найти такую вершину, которая будет больше удаляемой вершины на самое маленькое значение (т.е. сначала идём в правого ребёнка, потом до конца в левого)
		 * 2) Меняем местами значения у найденной вершины и у удаляемой
		 * 3) Удаляем найденную вершину (т.к. у неё теперь будет значение удаляемого элемента) по уже готовому алгоритму для вершины без детей
		 */

		auto minMax = element->rightChild;
		while (minMax->leftChild != nullptr)
			minMax = minMax->leftChild;
		
		int swap = minMax->getValue();
		removeElement(swap);
		element->setValue(swap);
	}
}
