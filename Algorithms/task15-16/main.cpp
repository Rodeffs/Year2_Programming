#include "Node.h"
#include "BinTree.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {

	cout << "Введите бинарное дерево в линейно-скобочной записи, т.е. в формате: родитель (левый_ребёнок, правый_ребёнок) и так далее для остальных:" << endl;

	string binTreeInput;
	
	std::getline(cin, binTreeInput);  // для считывания всей строки ввода используется std::getline()

	BinTree tree(binTreeInput);

	cout << "Прямой обход: " << tree.pre_ordered() << endl;

	cout << "Центральный (обратный) обход: " << tree.in_ordered() << endl;

	cout << "Концевой обход: " << tree.post_ordered() << endl;

	// cout << "Не рекурсивный прямой обход:" << tree.pre_ordered_non_recursive() << endl;

	return 0;
}
