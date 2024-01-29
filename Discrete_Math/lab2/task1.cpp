#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::string;

bool isNumIn(int num, vector<int> &numbers) {
	return std::find(numbers.begin(), numbers.end(), num) != numbers.end();
}

bool isCharIn(char letter, vector<char> &letters) {
	return std::find(letters.begin(), letters.end(), letter) != letters.end();
}

void makeword(string& base, int length, vector<string> &used_words, vector<int> &new_word) {
	vector<char> used_letters;

	for (int i = 0; i < base.length(); i++)
		if (!isNumIn(i, new_word) && !isCharIn(base[i], used_letters)) {
			new_word.push_back(i);
			used_letters.push_back(base[i]);

			if (new_word.size() == length) {
				string actual_word = "";

				for (int j = 0; j < new_word.size(); j++)
					actual_word += base[new_word[j]];

				cout << actual_word << endl;
				used_words.push_back(actual_word);
			}
			else
				makeword(base, length, used_words, new_word);

			new_word.pop_back();
		}
}

int main() {
	string base = "KOMBINATORIKA";
	vector<string> used_words;
	vector<int> new_word;
	int word_length = 6;

	makeword(base, word_length, used_words, new_word);

	cout << "Всего слов " << used_words.size() << endl;

	return 0;
}
