#include "BinTree.h"

void BinTree::assignChildren(const string& binTreeInput, Indexes& indexes) {

	Indexes newIndexes;
	newIndexes = indexes;

	int countBrackets{0}, commaIndex{0};
	bool wasRoot{false}, leftIsNull{false}, rightIsNull{false};

// Суть в том, чтобы сначала для корневого элемента присвоить детей, затем для его левого ребёнка (если он есть) и потом для правого по рекурсии	
	for (int i = indexes.begin; i <= indexes.end; i++) {
		auto current = binTreeInput[i];

		switch (current) {
			case '(':
				if (!wasRoot) {
					newIndexes.begin = i;
					newIndexes.parent++;
					newIndexes.left++;
					newIndexes.right++;
					wasRoot = true;
				}
				else
					countBrackets++;
				break;

			case ')':
				if (countBrackets)
					countBrackets--;
				else {
					newIndexes.right++;
					newIndexes.end = i;
				}
				break;

			case ',':
				if (!countBrackets) {
					if (binTreeInput[i-1] == '(')
						leftIsNull = true;
					else if (binTreeInput[i+1] == ')')
						rightIsNull = true;
					newIndexes.left++;
					newIndexes.right++;
					commaIndex = i;
				}
				break;
		}
	}

	if (!leftIsNull) {
		tree[newIndexes.parent]->leftChild = tree[newIndexes.left];
		
		Indexes parentLeft;
		parentLeft = newIndexes;
		parentLeft.parent = parentLeft.left;
		parentLeft.right = parentLeft.parent;
		parentLeft.begin++;
		parentLeft.end = commaIndex - 1;
		
		if (parentLeft.begin != parentLeft.end)
			assignChildren(binTreeInput, parentLeft);
	}

	if (!rightIsNull) {
		tree[newIndexes.parent]->rightChild = tree[newIndexes.right];
		
		Indexes parentRight;
		parentRight = newIndexes;
		parentRight.parent = parentRight.right;
		parentRight.left = parentRight.parent;
		parentRight.begin = commaIndex + 1;
		parentRight.end--;
		
		if (parentRight.begin != parentRight.end)
			assignChildren(binTreeInput, parentRight);
	}
}

BinTree::BinTree(const string& binTreeInput) {

	int beginIndex{0};
	bool numberBegan{false};
	for (int i = 0; i < binTreeInput.size(); i++) {  // здесь мы пока просто добавляем все элементы в дерево, затем будем решать кто кому родитель/ребёнок
		auto current = binTreeInput[i];

		if (!numberBegan && current != ' ' && current != ',' && current != '(' && current != ')') {
			beginIndex = i;
			numberBegan = true;
		}

		if (numberBegan && (current == ' ' || current == ',' || current == '(' || current == ')')) {
			stringstream convert;
			convert << binTreeInput.substr(beginIndex, i - beginIndex + 1);  // здесь суть в том, что stringstream сам производит преобразования, нам лишь нужно подавать ему нужную строку, для чего как раз и находим подстроку через метож substr, где первый параметр - начальный индекс, а второй - длина этой строки

			int val{0};
			convert >> val;

			auto newNode = new Node(val);
			tree.push_back(newNode);

			beginIndex = 0;
			numberBegan = false;
		}
	}
	
	Indexes indexes;
	indexes.parent = -1;
	indexes.left = indexes.parent;
	indexes.right = indexes.parent;
	indexes.begin = 0;
	indexes.end = tree.size() - 1;

	if (tree.size() > 1)
		assignChildren(binTreeInput, indexes);
}
