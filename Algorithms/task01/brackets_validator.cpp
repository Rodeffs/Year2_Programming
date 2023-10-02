/*
Лаба №1 "Задача о скобках"
(Задача состоит из двух пунктов, но вы можете не париться и делать сразу второй)
На вход подаётся строка, состоящая из скобок. Программа должна определить правильность введённого скобочного выражения. Савкин сказал, что программа должна работать на русском языке: "Введите строку", "Строка не существует", "Строка существует" и т.п.
Пункт 1: В строке будут скобки только одного типа: или "()" , или "{}", или "[]"
Пункт 2: В строке будут все три вида скобок
Для успешной сдачи лабы оба пункта программа должна выполнять корректно (можно сделать отдельные программы на каждый пункт)
*/
#include <vector>
#include <iostream>

using std::cin, std::cout, std::vector, std::string, std::endl;

int check(string input) {
    vector<char> bracketsArray; // список открывающих скобок
    for (int i = 0; i < input.size(); i++) {
        char currentBracket = input.at(i);
        if (currentBracket == '(' || currentBracket == '[' || currentBracket == '{')
            bracketsArray.push_back(currentBracket); // если данная скобка является открывающей, то добавляем её в список
        else {
            if (bracketsArray.empty() ||
            (currentBracket == ')' && bracketsArray.back() != '(') ||
            (currentBracket == ']' && bracketsArray.back() != '[') ||
            (currentBracket == ')' && bracketsArray.back() != '('))
                    return false; // если данная скобка является закрывающей, а предыдущая не является открывающей того же типа, то сразу выдаём ошибку
            bracketsArray.pop_back(); // иначе, если для открывающей скобки нашлась закрывающая, то убираем её из списка
        }
    }
    return bracketsArray.empty(); // если всем открывающим скобкам нашлась пара и список стал пустым, значит строка верная, иначе - нет
}

int main() {
    string input;
    cout << "Введите строку:" << endl;
    cin >> input;
    cout << (check(input) ? "Строка существует" : "Строка не существует") << endl;
    return 0;
}
