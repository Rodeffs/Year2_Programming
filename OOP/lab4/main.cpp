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

	Key u{"u"}, d{"d"}, p{"p"}, L{"L"}, O{"O"}, H{"H"}, E{"E"}, exMark{"!"}, enter{"Enter"};

	u.setCommand(Command::VOLUMEUP);
	d.setCommand(Command::VOLUMEDOWN);
	p.setCommand(Command::PRINTKEY);
	H.setCommand(Command::PRINTKEY);
	E.setCommand(Command::PRINTKEY);
	L.setCommand(Command::PRINTKEY);
	O.setCommand(Command::PRINTKEY);
	exMark.setCommand(Command::PRINTKEY);
	enter.setCommand(Command::ENTER);

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
	std::this_thread::sleep_for(std::chrono::milliseconds(500));  // чтобы между вводами было время для считывания следующего ввода

	keyboard.pressKey("p");
	std::this_thread::sleep_for(std::chrono::milliseconds(500));

	keyboard.pressKey("u");
	std::this_thread::sleep_for(std::chrono::milliseconds(500));

	keyboard.undo();
	std::this_thread::sleep_for(std::chrono::milliseconds(500));

	keyboard.pressKey("Enter");

	for (int i = 0; i < 9; i++) {
		keyboard.pressKey("H");
		keyboard.pressKey("E");
		keyboard.pressKey("L");
		keyboard.pressKey("L");
		keyboard.pressKey("O");
		keyboard.pressKey("!");
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
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
