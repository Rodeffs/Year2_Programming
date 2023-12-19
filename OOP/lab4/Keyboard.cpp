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
		if (*currentKey == pressedKey) {  // для этого перегружали оператор сравнения ==
			currentKey->setX1(x1);
			currentKey->setY1(y1);
			currentKey->setLastLetterX(lastLetterX);
			currentKey->execute();
			x1 = currentKey->getX1();
			y1 = currentKey->getY1();
			lastLetterX = currentKey->getLastLetterX();
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
		lastKey->setY1(y1);
		lastKey->setLastLetterX(lastLetterX);
		lastKey->undo(log);
		x1 = lastKey->getX1();
		y1 = lastKey->getY1();
		lastLetterX = lastKey->getLastLetterX();
		log.pop_back();
		consoleOutput("undo");
	}
}
