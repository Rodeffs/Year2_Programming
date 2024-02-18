#include "BinSearchTree.h"

Node* BinSearchTree::getRoot() {
	return this->root;
}

string BinSearchTree::printTree(Node* parent) {
	string outputString = "";

	if (parent != nullptr) {
		outputString.append(std::to_string(parent->getValue()));

		if (parent->getLeft() != nullptr || parent->getRight() != nullptr) {  // чтобы не было пустых скобок
			outputString.append(" (");
			outputString.append(printTree(parent->getLeft()));
			outputString.append(", ");
			outputString.append(printTree(parent->getRight()));
			outputString.append(")");
		}
	}
	return outputString;
}

bool BinSearchTree::searchTree(int value) {
	auto parent = root;

	while (parent->getValue() != value) {
		if (parent->getValue() > value) {
			if (parent->getLeft() != nullptr)
				parent = parent->getLeft();
			else
				return false;
		}

		if (parent->getValue() < value) {
			if (parent->getRight() != nullptr)
				parent = parent->getRight();
			else
				return false;
		}
	}
	return true;
}

void BinSearchTree::addElement(int value) {  // просто ищем подходящее место для элемента через поиск и добавляем его туда
	auto parent = root;
	auto child = new Node(value);

	while (true) {
		if (parent->getValue() >= value) {
			if (parent->getLeft() == nullptr) {
				parent->setLeft(child);
				return;
			}
			parent = parent->getLeft();
		}

		else {
			if (parent->getRight() == nullptr) {
				parent->setRight(child);
				return;
			}
			parent = parent->getRight();
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
			element = element->getLeft();
		}

		if (element->getValue() < value) {
			isLeft = false;
			element = element->getRight();
		}
	}

	if (element->getLeft() == nullptr && element->getRight() == nullptr) {  // самый простой случай - когда у удаляемого элемента нет детей	
		if (parent != nullptr) {  // не забываем удалять указатель на элемент в родительском, чтобы не возникло ошибки сегментации
			if (isLeft)
				parent->setLeft(nullptr);
			else
				parent->setRight(nullptr);
		}
		delete element;
	}

	else if (element->getLeft() == nullptr && element->getRight() != nullptr) {  // случаи, когда у элемента только один ребёнок тоже простые - нужно только поменять их местами
		auto swap = *element->getRight();
		delete element->getRight();
		*element = swap;
	}

	else if (element->getLeft() != nullptr && element->getRight() == nullptr) {
		auto swap = *element->getLeft();
		delete element->getLeft();
		*element = swap;
	}

	else {
		/* Удаление вершины у которой есть дети в бинарном дереве поиска проходит по следующему алгоритму:
		 * 1) Идём по дереву от данной вершины с целью найти такую вершину, которая будет больше удаляемой вершины на самое маленькое значение (т.е. сначала идём в правого ребёнка, потом до конца в левого)
		 * 2) Меняем местами значения у найденной вершины и у удаляемой
		 * 3) Удаляем найденную вершину (т.к. у неё теперь будет значение удаляемого элемента) по уже готовому алгоритму для вершины без детей
		 */

		auto minMax = element->getRight();
		while (minMax->getLeft() != nullptr)
			minMax = minMax->getLeft();
		
		int swap = minMax->getValue();
		removeElement(swap);
		element->setValue(swap);
	}
}
