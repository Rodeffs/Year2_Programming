#include "Node.h"
#include "BinTree.h"

int main() {

	cout << "Введите бинарное дерево в линейно-скобочной записи:" << endl;

	string binTreeInput;
	// cin >> binTreeInput;
	binTreeInput = "8 (3 (1, 6 (4,7)), 10 (, 14(13,)))";

	BinTree tree(binTreeInput);
	auto root = tree.getRoot();

	cout << "Корневой элемент: " << root.getValue() << endl; 

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
