#include "Keyboard.h"

using std::cout;

void Keyboard::addKey(const Key& key) {

	availableKeys.push_back(key);
}

void Keyboard::consoleOutput(const std::string& keyName) {

	if (y2 >= bottom) {  // для того, чтобы вывод справа не вылазил за нижние рамки консоли
		x2 += 20;
		y2 = 2;
	}
	
	if (keyName == "undo")
		cout << "\033[" << y2 << ";" << x2 << "H| undo()\033[0m";  // ANSI Escape Code
	else
		cout << "\033[" << y2 << ";" << x2 << "H| Pressed(" << keyName << ")\033[0m";
	y2++;
}

void Keyboard::pressKey(const std::string& pressedKey) {

	for (int i = 0; i < availableKeys.size(); i++) {
		auto currentKey = availableKeys[i];  // для этого перегружали оператор присваивания =
		if (currentKey == pressedKey) {  // для этого перегружали оператор сравнения == 
			switch (currentKey.getCommand()) {
				case Command::PRINTKEY:
					printKey(pressedKey);
					break;

				case Command::VOLUMEUP:
					volumeUp();
					break;

				case Command::VOLUMEDOWN:
					volumeDown();
					break;

				case Command::ENTER:
					enter();
					break;
			}
			log.push_back(currentKey);
			consoleOutput(pressedKey);
			break;
		}
	}
}

void Keyboard::printKey(const std::string& keyName) {

	if (x1 > middle - 2) {  // для того, чтобы две части консоли не накладывались друг на друга 
		y1++;
		x1 = 1;
	}

	cout << "\033[" << y1 << ";" << x1 << "H" << keyName << "\033[0m"; 
	x1++;
	lastLetterX = x1;
}

void Keyboard::volumeUp() {
	
	cout << "\033[" << bottom << ";1HVolume Up       \033[0m";
}

void Keyboard::volumeDown() {
		
	cout << "\033[" << bottom << ";1HVolume Down     \033[0m";
}

void Keyboard::enter() {

	x1 = 1;
	y1++;
}

void Keyboard::undo() {
	
	if (!log.empty()) {

		auto lastKey = log.back();

		switch (lastKey.getCommand()) {
			case Command::VOLUMEUP:
				cout << "\033[" << bottom << ";1HVolume Up Undo  \033[0m";
				break;

			case Command::VOLUMEDOWN:
				cout << "\033[" << bottom << ";1HVolume Down Undo\033[0m";
				break;

			case Command::PRINTKEY:
				x1--;
				if (x1 < 1) {
					y1--;
					x1 = middle - 2;
				}
				cout << "\033[" << y1 << ";" << x1 << "H" << " \033[0m";
				break;

			case Command::ENTER:
				if (y1 > 2)
					y1--;
				if (log[log.size() - 2].getCommand() == Command::ENTER)
					x1 = 1;
				else  
					x1 = lastLetterX;

// суть в том, что если до Undo enter был ещё enter, то возращаем курсор в начало строки, а если до undo enter уже шла строка, то возвращаем его в конец этой строки
		}
		log.pop_back();
		consoleOutput("undo");
	}
}
