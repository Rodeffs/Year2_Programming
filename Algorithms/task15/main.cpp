#include "Node.h"
#include "BinTree.h"

int main() {

	cout << "Введите бинарное дерево в линейно-скобочной записи:" << endl;

	string binTreeInput;
	cin >> binTreeInput;

	BinTree tree(binTreeInput);

	return 0;
}
