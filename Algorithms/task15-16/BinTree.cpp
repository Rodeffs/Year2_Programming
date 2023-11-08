#include "BinTree.h"

Node& BinTree::assignChildren(int begin, int end) {

	int countBrackets{0}, commaIndex{0}, numberStartIndex{0}, beginIndex{0}, endIndex{0};
	bool leftIsNull{false}, rightIsNull{false}, wasParent{false}, numberBegan{false};

	auto parent = new Node();

	for (int i = begin; i <= end; i++) {
		auto current = str[i];
		
		if (!wasParent) {  // присваиваем значение только для родительского элемента, остальным - по рекурсии в следующих итерациях

			if (!numberBegan && current != ',' && current != '(' && current != ')') {
				numberStartIndex = i;
				numberBegan = true;
			}
			
			if (numberBegan && (current == ',' || current == '(' || current == ')')) {
				stringstream convert;
				convert << str.substr(numberStartIndex, i - numberStartIndex);  // здесь суть в том, что stringstream сам производит преобразования, нам лишь нужно подавать ему нужную строку, для чего как раз и находим подстроку через метож substr, где первый параметр - начальный индекс, а второй - длина этой строки

				int val{0};
				convert >> val;

				parent->setValue(val);
				wasParent = true;
			}
		}
		
		else  // нам нужно лишь помнить индексы начала левого и правого элемента в строке, дабы потом по рекурсии присвоить им значения 
			switch (current) {
				case '(':
					if (!beginIndex)
						beginIndex = i + 1;
					else
						countBrackets++;
					break;

				case ')':
					if (countBrackets)
						countBrackets--;
					else
						endIndex = i - 1;
					break;

				case ',':
					if (!countBrackets) {
						if (str[i-1] == '(')
							leftIsNull = true;  // если нету какого-либо из ребёнков, то их даже не рассматриваем далее, т.к. по умолчанию указатель на них будет nullptr
						else if (str[i+1] == ')')
							rightIsNull = true;
						commaIndex = i;
					}
					break;
			}
	}

	if (!leftIsNull)
		parent->leftChild = &assignChildren(beginIndex, commaIndex - 1);

	if (!rightIsNull)
		parent->rightChild = &assignChildren(commaIndex + 1, endIndex);

	return *parent;
}

void BinTree::removeSpaces() {  // очищаем строку от пробелов, т.к. они нам не нужны

	int i = str.find(' ');
	if (i != -1) {
		str.erase(i);
		removeSpaces();
	}
}

BinTree::BinTree(const string& binTreeInput) {

	this->str = binTreeInput;
	removeSpaces();
	
	root = assignChildren(0, str.size() - 1);
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
