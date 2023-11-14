#include "BinSearchTree.h"

bool BinSearchTree::searchTree(int value) {
	auto parent = root;

	while (parent != nullptr) {
		if (parent->getValue() == value)
			return true;

		if (parent->getValue() > value)
			parent = parent->leftChild;

		if (parent->getValue() < value)
			parent = parent->rightChild;
	}
	return false;
}

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

void BinSearchTree::addElement(int value) {
	auto parent = root;
	auto child = new Node();

	while (true) {
		if (parent->getValue() >= value) {
			if (parent->leftChild == nullptr) {
				child->setValue(value);
				parent->leftChild = child;
				return;
			}
			parent = parent->leftChild;
		}

		if (parent->getValue() < value) {
			if (parent->rightChild == nullptr) {
				child->setValue(value);
				parent->rightChild = child;
				return;
			}
			parent = parent->rightChild;
		}
	}
}

void BinSearchTree::removeElement(int value) {
	auto element = root;

	while (true) {  // поиск удаляемого значения
		if (element->getValue() == value)
			break;

		if (element->getValue() > value) {
			element = element->leftChild;
		}

		if (element->getValue() < value) {
			element = element->rightChild;
		}
	}

	if (element->leftChild == nullptr && element->rightChild == nullptr)  // самый простой случай - когда у удаляемого элемента нет детей
		delete element;

	else if (element->leftChild == nullptr && element->rightChild != nullptr) {  // случаи, когда у элемента только один ребёнок тоже простые - нужно только поменять их местами
		auto swap = element->rightChild;
		delete element->rightChild;
		*element = *swap;
	}

	else if (element->leftChild != nullptr && element->rightChild == nullptr) {
		auto swap = element->leftChild;
		delete element->leftChild;
		*element = *swap;
	}

	else {
	/* Удаление вершины у которой есть дети в бинарном дереве поиска проходит по следующему алгоритму:
	 * 1) Идём по дереву от данной вершины с целью найти такую вершину, которая будет больше удаляемой вершины на самое маленькое значение (т.е. сначала идём в правого ребёнка, потом до конца в левого)
	 * 2) Меняем местами значения у найденной вершины и у удаляемой
	 * 3) Удаляем найденную вершину (т.к. у неё теперь будет значение удаляемого элемента)
	 */
		auto minMax = element->rightChild;
		while (minMax->leftChild != nullptr)
			minMax = minMax->leftChild;
		
		auto swap = minMax;
		removeElement(minMax->getValue());
		*element = *swap;		
	}
}
