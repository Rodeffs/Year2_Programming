#include "BinSearchTree.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {

	cout << "Введите бинарное дерево поиска в линейно-скобочной записи:" << endl;

	string binTreeInput;
	std::getline(cin, binTreeInput);  // для считывания всей строки ввода используется std::getline()
	BinSearchTree tree(binTreeInput);

	cout << "Доступные команды (введите имя команды или число):\n1) добавить - добавить вершину\n2) удалить - удалить вершину\n3) поиск - найти вершину\n4) вывод - вывести дерево\n5) выход - выйти и перед этим вывести дерево\n6) помощь - вывести эту строку" << endl;

	while (true) {
		cout << "Введите команду:" << endl;

		string userInput;
		std::getline(cin, userInput);

		if (userInput == "добавить" || userInput == "1") {
			cout << "Введите значение для вершины:" << endl;

			int value;
			cin >> value;

			tree.addElement(value);	

			cout << "Вершина " << value << " добавлена" << endl;
		}

		else if (userInput == "удалить" || userInput == "2") {
			cout << "Введите, какую вершину удалить:" << endl;

			int value;
			cin >> value;

			if (tree.searchTree(value)) {
				tree.removeElement(value);
				cout << "Вершина " << value << " удалена" << endl;
			}
			else
				cout << "Вершины " << value << " в дереве нет, удаление невозможно" << endl;
		}

		else if (userInput == "поиск" || userInput == "3") {
			cout << "Введите значение для поиска:" << endl;

			int value;
			cin >> value;

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
			cout << "Вывод дерева: " << tree.printTree(root) << endl;
			break;
		}

		else if (userInput == "помощь" || userInput == "6")
			cout << "Доступные команды (введите имя команды или число):\n1) добавить - добавить вершину\n2) удалить - удалить вершину\n3) поиск - найти вершину\n4) вывод - вывести дерево\n5) выход - выйти и перед этим вывести дерево\n6) помощь - вывести эту строку" << endl;

		else
			cout << "Команда " << userInput << " не найдена, повторите попытку (введите помощь для подсказки)" << endl;
	}
	return 0;
}
