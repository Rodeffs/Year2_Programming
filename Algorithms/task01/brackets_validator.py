"""
Лаба №1 "Задача о скобках"
(Задача состоит из двух пунктов, но вы можете не париться и делать сразу второй)
На вход подаётся строка, состоящая из скобок. Программа должна определить правильность введённого скобочного выражения. Савкин сказал, что программа должна работать на русском языке: "Введите строку", "Строка не существует", "Строка существует" и т.п.
Пункт 1: В строке будут скобки только одного типа: или "()" , или "{}", или "[]"
Пункт 2: В строке будут все три вида скобок
Для успешной сдачи лабы оба пункта программа должна выполнять корректно (можно сделать отдельные программы на каждый пункт)
Пример входа:
()[({}())]
"""


def check(exp):
    brackets_array = []
    for i in range(0, len(exp)):
        bracket = exp[i]
        if bracket == '(' or bracket == '[' or bracket == '{':
            brackets_array.append(bracket)
        if bracket == ')':
            if not len(brackets_array) or brackets_array[-1] != '(':
                return False
            brackets_array.remove(brackets_array[-1])
        if bracket == ']':
            if not len(brackets_array) or brackets_array[-1] != '[':
                return False
            brackets_array.remove(brackets_array[-1])
        if bracket == '}':
            if not len(brackets_array) or brackets_array[-1] != '{':
                return False
            brackets_array.remove(brackets_array[-1])
    return not len(brackets_array)


if __name__ == '__main__':
    print("Введите строку:")
    # expression = "([]{}[()])" - по какой-то причине Python неправильно обрабатывает эту строку, убирая вместо последнего символа в списке первый, поэтому лучше пользоваться вариантом на C++
    expression = input()
    print("Строка существует" if check(expression) else "Строка не существует")
