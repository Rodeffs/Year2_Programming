#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::string;

bool isNumIn(int num, vector<int> &numbers) {  // поиск индекса буквы из основного слова в нынешнем
	return std::find(numbers.begin(), numbers.end(), num) != numbers.end();
}

bool isCharIn(char letter, vector<char> &letters) {  // проверка на то, была ли эта буква на данной итерации цикла
	return std::find(letters.begin(), letters.end(), letter) != letters.end();
}

void makeword(string& base, int length, int* wordcounter, vector<int> &new_word) {
	vector<char> used_letters;

	for (int i = 0; i < base.length(); i++)
		if (!isNumIn(i, new_word) && !isCharIn(base[i], used_letters)) {
			new_word.push_back(i);  // добавляем букву в слово, потом по рекурсии добавим другую, которой ещё не было
			used_letters.push_back(base[i]);  // чтобы цикл проходился только по УНИКАЛЬНЫМ буквам, т.е. по тем, которых не было в предыдущих итерациях ЦИКЛА

			if (new_word.size() == length) {
				(*wordcounter)++;

				// Для вывода всех слов, это необязательно для работы программы:
				string actual_word = "";
				for (int j = 0; j < new_word.size(); j++)
					actual_word += base[new_word[j]];
				std::cout << actual_word << std::endl;
			}
			else
				makeword(base, length, wordcounter, new_word);

			new_word.pop_back();
		}
}

int main() {
	std::cout << "Введите слово (латиницей):" << std::endl;
	
	string base;
	std::cin >> base;

	std::cout << "Введите, слова какой длины из него получить (не длиннее самого слова):" << std::endl;

	int word_length;
	std::cin >> word_length;

	vector<int> new_word;
	int wordcounter = 0;

	makeword(base, word_length, &wordcounter, new_word);

	std::cout << "Из слова " << base << " можно составить столько слов длины " << word_length << ": " << wordcounter << std::endl;

	return 0;
}
