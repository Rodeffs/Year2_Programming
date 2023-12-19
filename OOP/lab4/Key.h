#pragma once
#include <string>
#include <iostream>
#include <vector>

#define middle 40  // центр, между левой и правой частью
#define bottom 41  // нижняя грань

using std::vector;
using std::string;
using std::cout;

enum class Command {PRINTKEY, VOLUMEUP, VOLUMEDOWN, ENTER};  // доступные команды

class Key {

private:

	string keyName;

	Command commandName;

	int x1, y1;
	
	int lastLetterX;  // костыль для правильной работы undo enter 

public:

	explicit Key(const string& key, Command command) : keyName{key}, commandName{command} {}

	void setCommand(Command command);

	Command getCommand() const;

	void setName(const string& name);

	const string& getName() const;

	void execute();

	void undo(vector<Key*>& log);

	void setX1(int x);

	int getX1() const;

	void setY1(int y);

	int getY1() const;

	void setLastLetterX(int x);

	int getLastLetterX() const;

	bool operator==(const string& key);  // перегружаем оператор для того, чтобы проще было сравнивать вывод клавиши с тем, какие клавиши есть на клавиатуре

	Key& operator=(const Key& key);  // для временных переменных

};
