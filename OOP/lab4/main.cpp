/*
Условие этой лабораторной - создать виртуальную клавиатуру, т.е. каждой клавише присваеваем команду, и в окне слева выводим то, что она делает, а справа - это лог всех выводов. Нужно реализовать ввод, повышение/понижение громкости и прочее по выбору. Также нужна команда undo которая отменяет последний ввод с клавиатуры и возращает консоль слева в состояние до того ввода.
*/

#include "Key.h"
#include "Keyboard.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <string>

int main() {

	Keyboard keyboard;

	auto u = new Key("u", Command::VOLUMEUP);
	auto d = new Key("d", Command::VOLUMEDOWN);
	auto p = new Key("p", Command::PRINTKEY);
	auto L = new Key("L", Command::PRINTKEY);
	auto O = new Key("O", Command::PRINTKEY);
	auto H = new Key("H", Command::PRINTKEY);
	auto E = new Key("E", Command::PRINTKEY);
	auto exMark = new Key("!", Command::PRINTKEY);
	auto enter = new Key("Enter", Command::ENTER);

	keyboard.addKey(u);
	keyboard.addKey(d);
	keyboard.addKey(p);
	keyboard.addKey(H);
	keyboard.addKey(E);
	keyboard.addKey(L);
	keyboard.addKey(O);
	keyboard.addKey(exMark);
	keyboard.addKey(enter);

	keyboard.pressKey("d");
	std::this_thread::sleep_for(std::chrono::milliseconds(100));  // чтобы между вводами было время для считывания следующего ввода

	keyboard.pressKey("p");
	std::this_thread::sleep_for(std::chrono::milliseconds(100));

	keyboard.pressKey("u");
	std::this_thread::sleep_for(std::chrono::milliseconds(100));

	keyboard.undo();
	std::this_thread::sleep_for(std::chrono::milliseconds(100));

	keyboard.pressKey("Enter");

	for (int i = 0; i < 9; i++) {
		keyboard.pressKey("H");
		keyboard.pressKey("E");
		keyboard.pressKey("L");
		keyboard.pressKey("L");
		keyboard.pressKey("O");
		keyboard.pressKey("!");
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	keyboard.pressKey("Enter");
	keyboard.pressKey("Enter");

	keyboard.pressKey("H");
	keyboard.pressKey("E");
	keyboard.pressKey("L");
	keyboard.pressKey("p");

	keyboard.pressKey("Enter");
	keyboard.pressKey("Enter");
	keyboard.undo();
	keyboard.undo();

	keyboard.pressKey("!");

	std::cout << "\033[" << bottom << ";1H" << std::endl;  // чтобы моя консоль в Linux не залазила на вывод
	return 0;
}
