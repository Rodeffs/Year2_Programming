#include "BinSearchTree.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
	
	BinSearchTree tree("8 (3 (1, 6 (4,7)), 10 (, 14(13,)))");

	cout << "Testing: " << tree.pre_ordered() << endl;

	return 0;
}
