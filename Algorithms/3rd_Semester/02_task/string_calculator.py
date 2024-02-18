"""
Лаба №2 "Задача об арифметическом выражении"
На вход подаётся математическое выражение. Элементы - числа. Операции - "+ - * /". Также есть скобочки. Окончанием выражения служит "=". Программа должна вывести результат выражения

Пример ввода:
2+7*(3/9)-5=

Замечание:
Программа также должна делать "проверку на дурака": нет деления на 0, все скобки стоят верно (см лабу №1) и т.п.
"""


def check_correct(exp):  # Сначала проверяем выражение на корректность исходя из условия, а именно:
    if exp[-1] != '=':  # Отсутствие знака равенства в конце
        return False
    brackets_array = []
    for i in range(0, len(exp)):
        if exp[i] == '(':  # Неправильная расстановка скобок, см. лабу №1
            if i+1 == len(exp) or exp[i+1] == '/' or exp[i+1] == '*':
                return False
            brackets_array.append('(')
        if exp[i] == ')':
            if not brackets_array or brackets_array[-1] != '(':
                return False
            brackets_array.remove(brackets_array[-1])
        if exp[i] == '+' or exp[i] == '-' or exp[i] == '/' or exp[i] == '*':  # Невозможная операция (после знака операции должна идти либо цифра, либо открывающая скобка, иначе эта операция невозможна, а также деление на 0)
            if i+1 == len(exp) or exp[i+1] != '(' and not exp[i+1].isdigit() or exp[i] == '/' and exp[i+1] == '0':
                return False
    return not brackets_array


def solve(exp, begin, end):  # Здесь выполняем саму операцию, нам подаётся индекс от какой скобки до какой считать, либо же всё выражение целиком, если их нет
    solution = 0
    stalled_number = []  # stalled_number - это последнее число, его же мы умножаем и делим на последующее, а также прибавляем к ответу
    was_minus, was_multiplication, was_division = False, False, False
    for i in range(begin, end+1):
        elem = exp[i]
        if (elem == '+' or elem == '-' or i == end) and stalled_number:
            solution += (-1)**was_minus * stalled_number[0]
            stalled_number.clear()
            was_minus = (elem == '-')
        was_minus = True if elem == '-' else was_minus
        if isinstance(elem, float):  # Проверяет, является ли нынешний элемент числом и выполняет необходимые операции, иначе же делает его stalled_number
            if was_multiplication:
                stalled_number[0] *= elem
                was_multiplication = False
            elif was_division:
                stalled_number[0] /= elem
                was_division = False
            else:
                stalled_number.append(elem)
        was_multiplication = True if elem == '*' else was_multiplication
        was_division = True if elem == '/' else was_division
    return exp[:begin] + [solution] + exp[end+1:]  # После выполнения всех операций, преобразуем исходное выражение, заменяя выражение в скобках на готовый ответ


def scan_expression(exp):  # Сканируем строку на скобки и выполняем операцию в них (сначала в самой глубокой скобке, потом на уровень выше и т.д., а в конце считаем всё выражение сразу)
    open_bracket_index = 0
    for i in range(0, len(exp)):
        if exp[i] == '(':
            open_bracket_index = i
        if exp[i] == ')':
            exp = solve(exp, open_bracket_index, i)
            return scan_expression(exp)
    return solve(exp, 0, len(exp)-1)[0]  # Здесь 0 индекс нужен, т.к. под индексом 1 находится знак равенства


def split_expression(exp):  # Нарезаем строку на отдельные числа и операции
    new_exp = []
    temp_number = 0.0
    number_began = False
    for i in range(0, len(exp)):
        if exp[i].isdigit():
            number_began = True
            temp_number = temp_number * 10 + float(exp[i])
        else:
            if number_began:
                new_exp.append(temp_number)
                temp_number = 0.0
                number_began = False
            new_exp.append(exp[i])
    return new_exp


if __name__ == '__main__':
    print("Введите выражение:")
    expression = input()
    if check_correct(expression):
        print(f"Ответ: {scan_expression(split_expression(expression))}")
    else:
        print("Ошибка: уравнение некорректно")
