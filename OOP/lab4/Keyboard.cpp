#include "Keyboard.h"

using std::cout;

void Keyboard::addKey(const Key& key) {

	availableKeys.push_back(key);
}

void Keyboard::consoleOutput(const std::string& keyName) {
	
	cout << "\033[" << y2 << ";20H| Pressed(" << keyName << ")\033[0m";
	y2++;
}

void Keyboard::pressKey(const std::string& pressedKey) {

	for (int i = 0; i < availableKeys.size(); i++) {
		auto currentKey = availableKeys[i];
		if (currentKey == pressedKey) {
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
			consoleOutput(pressedKey);
			log.push_back(currentKey);
			break;
		}
	}
}

void Keyboard::printKey(const std::string& keyName) {

	if (x >= 20) {  // для того, чтобы две части консоли не накладывались друг на друга 
		y1++;
		x = 1;
	}

	cout << "\033[" << y1 << ";" << x << "H" << keyName << "\033[0m";  // ANSI Escape Code
	x++;
	lastLetterX = x;
}

void Keyboard::volumeUp() {
	
	cout << "\033[41;1HVolume Up       \033[0m";  // здесь 40 стоит чтобы печаталось в самом низу
}

void Keyboard::volumeDown() {
		
	cout << "\033[41;1HVolume Down     \033[0m";
}

void Keyboard::enter() {

	x = 1;
	y1++;
}

void Keyboard::undo() {
	
	if (!log.empty()) {

		auto lastKey = log.back();

		switch (lastKey.getCommand()) {
			case Command::VOLUMEUP:
				cout << "\033[41;1HVolume Up Undo  \033[0m";
				break;

			case Command::VOLUMEDOWN:
				cout << "\033[41;1HVolume Down Undo\033[0m";
				break;

			case Command::PRINTKEY:
				x--;
				if (x < 1) {
					y1--;
					x = 19;
				}
				cout << "\033[" << y1 << ";" << x << "H" << " \033[0m";  // ANSI Escape Code
				break;

			case Command::ENTER:
				if (y1 > 2)
					y1--;
				if (log[log.size() - 2].getCommand() == Command::ENTER)
					x = 1;
				else  
					x = lastLetterX;

			// суть в том, что если до Undo enter был ещё enter, то возращаем курсор в начало строки, а если до undo enter уже шла строка, то возвращаем его в конец этой строки
		}

		log.pop_back();

		cout << "\033[" << y2 << ";20H| undo()\033[0m";
		y2++;
	}
}
