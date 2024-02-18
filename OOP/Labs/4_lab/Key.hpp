#pragma once
#include <string>
#include <iostream>
#include <vector>

using std::vector;
using std::string;
using std::cout;

class Key {

private:

	string keyName;

	int (*command)(const string&, int) = nullptr;

	int (*undoCommand)(int) = nullptr;

	int x1;
	
public:

	explicit Key(const string& key, int (*f)(const string&, int), int (*g)(int)) : keyName{key}, command{f}, undoCommand{g} {}

	void setCommand(int (*f)(const string&, int)) {
		this->command = f;
	}

	void setUndo(int (*f)(int)) {
		this->undoCommand = f;
	}

	void setName(const string& name) {
		this->keyName = name;
	}

	const string& getName() const {
		return this->keyName;
	}

	void execute() {
		x1 = command(keyName, x1);
	}

	void undo() {
		x1 = undoCommand(x1);
	}

	void setX1(int x) {
		this->x1 = x;
	}

	int getX1() const {
		return this->x1;
	}

	bool operator==(const string& key) {  // перегружаем оператор для того, чтобы проще было сравнивать вывод клавиши с тем, какие клавиши есть на клавиатуре
		return this->keyName == key;
	}
};
