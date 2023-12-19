#pragma once
#include "Key.h"

class Keyboard {

private:

	int x1{1}, y1{2}, x2{middle}, y2{2};  // слева то, что выводится в левой части консоли, остальное - с правой

	int lastLetterX = x1;

	vector<Key> availableKeys;  // доступные клавиши

	vector<Key> log;  // здесь храняться нажатые клавиши

	void consoleOutput(const std::string& keyName);  // эта команда будет выводить введёные команды в правую часть консоли

public:

	void addKey(const Key& key);  // для добавления клавиши на клавиатуру

	void pressKey(const std::string& pressedKey);  // для нажатия клавиши на клавиатуре

	void undo();
};
