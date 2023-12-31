#include "Keyboard.h"

Keyboard::~Keyboard() {
	
	for (int i = 0; i < availableKeys.size(); i++)
		delete availableKeys[i];

	availableKeys.clear();
	log.clear();
}

void Keyboard::addKey(Key* key) {

	availableKeys.push_back(key);
}

void Keyboard::consoleOutput(const std::string& keyName) {

	if (y >= bottom) {  // для того, чтобы вывод справа не вылазил за нижние рамки консоли
		x2 += 20;
		y = 2;
	}
	
	if (keyName == "undo")
		cout << "\033[" << y << ";" << x2 << "H| undo()";  // ANSI Escape Code
	else
		cout << "\033[" << y << ";" << x2 << "H| Pressed(" << keyName << ")";
	y++;
}

void Keyboard::pressKey(const std::string& pressedKey) {

	for (int i = 0; i < availableKeys.size(); i++) {
		auto currentKey = availableKeys[i];
		if (*currentKey == pressedKey) {  // для этого перегружали оператор сравнения ==
			currentKey->setX1(x1);
			currentKey->execute();
			x1 = currentKey->getX1();
			log.push_back(currentKey);
			consoleOutput(pressedKey);
			return;
		}
	}
}

void Keyboard::undo() {

	if (!log.empty()) {
		auto lastKey = log.back();
		lastKey->setX1(x1);
		lastKey->undo();
		x1 = lastKey->getX1();
		log.pop_back();
		consoleOutput("undo");
	}
}
