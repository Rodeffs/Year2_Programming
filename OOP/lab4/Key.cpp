#include "Key.h"

Key::Key(const std::string& key) {
	this->keyName = key;
}

void Key::setCommand(Command command) {
	this->commandName = command;
}

Command Key::getCommand() const {
	return this->commandName; 
}

bool Key::operator==(const std::string& key) {
	return this->keyName == key;
}


const std::string& Key::getName() const {
	return this->keyName;
}

Key& Key::operator=(const Key& key) {
	this->keyName = key.getName();
	this->commandName = key.getCommand();
	return *this;
}
