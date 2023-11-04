#pragma once
#include <vector>
#include <iostream>
#include "Key.h"

#define middle 40  // центр, между левой и правой частью
#define bottom 41  // нижняя грань

using std::vector;

class Keyboard {

private:

	int x1{1}, x2{middle}, y1{2}, y2{2};  // первые координаты - то, что выводится в левой части консоли; вторые - в правой

	int lastLetterX = x1;  // костыль для правильной работы undo enter 

	vector<Key> availableKeys;  // доступные клавиши

	vector<Key> log;  // здесь храняться нажатые клавиши

	void consoleOutput(const std::string& keyName);  // эта команда будет выводить введёные команды в правую часть консоли

	void printKey(const std::string& keyName);  // команда вывести клавишу

	void volumeUp();  // команда повысить громкость

	void volumeDown();  // команда понизить громкость

	void enter();  // команда перейти на следующую строчку

public:

	void addKey(const Key& key);  // для добавления клавиши на клавиатуру

	void pressKey(const std::string& pressedKey);  // для нажатия клавиши на клавиатуре

	void undo();
};
