#include "Node.h"
#include "BinTree.h"

int main() {

	cout << "Введите бинарное дерево в линейно-скобочной записи, т.е. в формате: родитель (левый_ребёнок, правый_ребёнок) и так далее для остальных:" << endl;

	string binTreeInput;
	
	std::getline(cin, binTreeInput);  // для считывания всей строки ввода используется std::getline()

	BinTree tree(binTreeInput);
	auto root = tree.getRoot();

	cout << "Прямой обход:" << endl;
	tree.pre_ordered(&root);
	cout << "\n\n";

	cout << "Центральный (обратный) обход:" << endl;
	tree.in_ordered(&root);
	cout << "\n\n";

	cout << "Концевой обход:" << endl;
	tree.post_ordered(&root);
	cout << "\n\n";

	// cout << "Не рекурсивный прямой обход:" << tree.pre_ordered_non_recursive() << endl;

	return 0;
}
