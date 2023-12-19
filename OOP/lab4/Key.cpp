#include "Key.h"

void Key::setCommand(Command command) {

	this->commandName = command;
}

Command Key::getCommand() const {

	return this->commandName; 
}

void Key::setName(const string& name) {

	this->keyName = name;
}

const string& Key::getName() const {

	return this->keyName;
}

void Key::execute() {

	switch (commandName) {
		case Command::VOLUMEUP:
			cout << "\033[" << bottom << ";1HVolume Up       \033[0m";
			break;

		case Command::VOLUMEDOWN:
			cout << "\033[" << bottom << ";1HVolume Down     \033[0m";
			break;

		case Command::PRINTKEY:
			if (x1 > middle - 2) {  // для того, чтобы две части консоли не накладывались друг на друга 
				y1++;
				x1 = 1;
			}

			cout << "\033[" << y1 << ";" << x1 << "H" << keyName << "\033[0m"; 
			x1++;
			lastLetterX = x1;
			break;

		case Command::ENTER:
			x1 = 1;
			y1++;
			break;

	}
}

void Key::undo(vector<Key*>& log) {

	switch (getCommand()) {
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
			if (log[log.size() - 2]->getCommand() == Command::ENTER)
				x1 = 1;
			else  
				x1 = lastLetterX;
	}
}

void Key::setX1(int x) {

	this->x1 = x;
}

int Key::getX1() const {

	return this->x1;
}

void Key::setY1(int y) {

	this->y1 = y;
}

int Key::getY1() const {

	return this->y1;
}

void Key::setLastLetterX(int x) {

	this->lastLetterX = x;
}

int Key::getLastLetterX() const {

	return this->lastLetterX;
}

bool Key::operator==(const string& key) {

	return this->keyName == key;
}

Key& Key::operator=(const Key& key) {
	this->keyName = key.getName();
	this->commandName = key.getCommand();
	this->x1 = key.getX1();
	this->y1 = key.getY1();
	this->lastLetterX = key.getLastLetterX();
	return *this;
}
