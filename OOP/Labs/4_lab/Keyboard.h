#pragma once
#include "Key.hpp"

#define middle 40  // центр, между левой и правой частью
#define bottom 41  // нижняя грань

class Keyboard {

private:

	int x1{1}, x2{middle}, y{2};  // слева то, что выводится в левой части консоли, остальное - с правой

	vector<Key*> availableKeys;  // доступные клавиши

	vector<Key*> log;  // здесь храняться нажатые клавиши

	void consoleOutput(const string& keyName);  // эта команда будет выводить введёные команды в правую часть консоли

public:
	Keyboard() = default;

	~Keyboard();

	void addKey(Key* key);  // для добавления клавиши на клавиатуру

	void pressKey(const string& pressedKey);  // для нажатия клавиши на клавиатуре

	void undo();
};
