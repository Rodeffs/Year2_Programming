#include "BinSearchTree.h"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

std::string getInput() {  // чтобы не было двойного вывода
	std::string userInput;
	std::getline(cin, userInput);  // для считывания всей строки ввода используется std::getline()
	return userInput;
}

int main() {

	cout << "Введите бинарное дерево поиска в линейно-скобочной записи:" << endl;

	BinSearchTree tree(getInput());

	cout << "Доступные команды (введите имя команды или число):\n1) добавить - добавить вершину\n2) удалить - удалить вершину\n3) поиск - найти вершину\n4) вывод - вывести дерево\n5) выход - выйти и перед этим вывести дерево\n6) помощь - вывести эту строку" << endl;

	while (true) {
		cout << "Введите команду:" << endl;

		string userInput = getInput();

		if (userInput == "добавить" || userInput == "1") {
			cout << "Введите значение для добавляемой вершины:" << endl;

			int value = std::stoi(getInput());

			tree.addElement(value);	

			cout << "Вершина " << value << " добавлена" << endl;
		}

		else if (userInput == "удалить" || userInput == "2") {
			cout << "Введите, какую вершину удалить:" << endl;

			int value = std::stoi(getInput());

			if (tree.searchTree(value)) {
				tree.removeElement(value);
				cout << "Вершина " << value << " удалена" << endl;
			}
			else
				cout << "Вершины " << value << " в дереве нет, удаление невозможно" << endl;
		}

		else if (userInput == "поиск" || userInput == "3") {
			cout << "Введите значение для поиска:" << endl;

			int value = std::stoi(getInput());

			if (tree.searchTree(value))
				cout << "Вершина " << value << " есть в дереве" << endl;
			else
				cout << "Вершины " << value << " нет в дереве" << endl;
		}

		else if (userInput == "вывод" || userInput == "4") {
			auto root = tree.getRoot();
			cout << "Вывод дерева: " << tree.printTree(root) << endl;
		}

		else if (userInput == "выход" || userInput == "5") {
			auto root = tree.getRoot();
			cout << "Вывод дерева: " << tree.printTree(root) << endl << "Работа программы завершена" << endl;
			break;
		}

		else if (userInput == "помощь" || userInput == "6")
			cout << "Доступные команды (введите имя команды или число):\n1) добавить - добавить вершину\n2) удалить - удалить вершину\n3) поиск - найти вершину\n4) вывод - вывести дерево\n5) выход - выйти и перед этим вывести дерево\n6) помощь - вывести данную подсказку" << endl;

		else
			cout << "Команда " << userInput << " не найдена, повторите попытку (введите помощь или цифру 6 для подсказки)" << endl;
	}
	return 0;
}
