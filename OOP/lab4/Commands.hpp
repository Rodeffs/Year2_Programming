#include <iostream>
#include <string>

#define middle 40  // центр, между левой и правой частью
#define bottom 41  // нижняя грань

using std::cout;
using std::string;

namespace PrintKey {  // можно было сделать отдельные классы, но я решил сделать так

	int execute(const string& keyName, int x1) {
		int x = x1;

		if (x > middle - 2) {  // для того, чтобы две части консоли не накладывались друг на друга 
			cout << "\033[u \033[1E \033[s";
			x = 1;
		}

		cout << "\033[u \033[" << x << "G" << keyName << "\033[s";  // [s - сохраняет позицию, [u - восстанавливает, G - передвигает курсор в нужную колонну
		x++;
		return x;
	}

	int undo(int x1) {
		int x = x1;
		x--;
		if (x < 1) {
			cout << "\033[u \033[1F \033[s";
			x = middle - 2;
		}
		cout << "\033[u \033[" << x << "G" << "\033[s";
		return x;
	}
}

namespace Enter {

	int execute(const string& keyName, int x1) {
		cout << "\033[u \033[1E \033[s";
		return 1;
	}

	int undo(int x1) {
		cout << "\033[u \033[1F\033[s";
		return x1;
	}
}

namespace VolumeUp {

	int execute(const string& keyName, int x1) {
		cout << "\033[" << bottom << ";1HVolume Up       ";
		return x1;
	}

	int undo(int x1) {
		cout << "\033[" << bottom << ";1HVolume Up Undo  ";
		return x1;
	}
}

namespace VolumeDown {

	int execute(const string& keyName, int x1) {
		cout << "\033[" << bottom << ";1HVolume Down     ";
		return x1;
	}

	int undo(int x1) {
		cout << "\033[" << bottom << ";1HVolume Down Undo";
		return x1;
	}
}
