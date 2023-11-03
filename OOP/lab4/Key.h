#pragma once
#include <string>

enum class Command {PRINTKEY, VOLUMEUP, VOLUMEDOWN, ENTER};  // доступные команды

class Key {

private:

	std::string keyName;

	Command commandName;

public:

	Key(const std::string& key);

	void setCommand(Command command);

	Command getCommand() const;

	const std::string& getName() const;

	bool operator==(const std::string& key);  // перегружаем оператор для того, чтобы проще было сравнивать вывод клавиши с тем, какие клавиши есть на клавиатуре

	Key& operator=(const Key& key);  // для временных переменных

};
