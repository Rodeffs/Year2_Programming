/*
Условие этой лабораторной - создать виртуальную клавиатуру, т.е. каждой клавише присваеваем команду, и в окне слева выводим то, что она делает, а справа - это лог всех выводов. Нужно реализовать ввод, повышение/понижение громкости и прочее по выбору. Также нужна команда undo которая отменяет последний ввод с клавиатуры и возращает консоль слева в состояние до того ввода.
*/

#include "Key.hpp"
#include "Keyboard.h"
#include "Commands.hpp"

#include <iostream>
#include <chrono>
#include <thread>
#include <string>

int main() {

	Keyboard keyboard;
	 cout << "\033[H\033[1E\033[s";  // чтобы вывод не залез на мою консоль

	auto u = new Key("u", VolumeUp::execute, VolumeUp::undo);
	auto d = new Key("d", VolumeDown::execute, VolumeDown::undo);
	auto p = new Key("p", PrintKey::execute, PrintKey::undo);
	auto L = new Key("L", PrintKey::execute, PrintKey::undo);
	auto O = new Key("O", PrintKey::execute, PrintKey::undo);
	auto H = new Key("H", PrintKey::execute, PrintKey::undo);
	auto E = new Key("E", PrintKey::execute, PrintKey::undo);
	auto exMark = new Key("!", PrintKey::execute, PrintKey::undo);
	auto enter = new Key("Enter", Enter::execute, Enter::undo);

	keyboard.addKey(u);
	keyboard.addKey(d);
	keyboard.addKey(p);
	keyboard.addKey(H);
	keyboard.addKey(E);
	keyboard.addKey(L);
	keyboard.addKey(O);
	keyboard.addKey(exMark);
	keyboard.addKey(enter);

	int timeout = 500;

	keyboard.pressKey("d");
	std::this_thread::sleep_for(std::chrono::milliseconds(timeout));  // чтобы между вводами было время для считывания следующего ввода

	keyboard.pressKey("p");
	keyboard.pressKey("p");
	std::this_thread::sleep_for(std::chrono::milliseconds(timeout));

	keyboard.pressKey("u");
	std::this_thread::sleep_for(std::chrono::milliseconds(timeout));

	keyboard.undo();
	std::this_thread::sleep_for(std::chrono::milliseconds(timeout));

	keyboard.pressKey("Enter");

	for (int i = 0; i < 10; i++) {
		keyboard.pressKey("H");
		keyboard.pressKey("E");
		keyboard.pressKey("L");
		keyboard.pressKey("L");
		keyboard.pressKey("O");
		keyboard.pressKey("!");
		std::this_thread::sleep_for(std::chrono::milliseconds(timeout));
	}

	keyboard.pressKey("Enter");
	keyboard.pressKey("Enter");

	keyboard.pressKey("H");
	keyboard.pressKey("E");
	keyboard.pressKey("L");
	keyboard.pressKey("p");

	keyboard.pressKey("Enter");
	keyboard.pressKey("Enter");
	keyboard.pressKey("Enter");
	keyboard.undo();
	keyboard.undo();

	keyboard.pressKey("!");

	cout << "\033[" << bottom << ";1H" << std::endl;  // чтобы моя консоль в Linux не залазила на вывод
	return 0;
}
