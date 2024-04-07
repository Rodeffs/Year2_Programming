"""
Построим конечный автомат для шаблона:
    ACACAGA

Имеем двумерный массив FA[S][C], где строки - это состояния, а столбцы - символы из текста
Соответственно, S - длина шаблона + 1, а C - количество уникальных символов в тексте

    A   C   G   T
0   1   0   0   0
1   1   2   0   0
2   3   0   0   0
3   1   4   0   0
4   5   0   0   0
5   1   4   6   0
6   7   0   0   0
7   1   2   0   0

Изначально, каждому элементу присваивается значение 0.
Потом, проходимся по каждому уникальному символу, присваивая ему значение состояния таким образом:
    1) Если символ такой же, как и следующий в шаблоне, то увеличиваем значение на 1
    2) Иначе ищем длину наибольшей строки, оканчивающейся на этот символ, у которой префикс и суффикс одинаковые
    Т.е. в нашем случае, если было состояние 5 и следующий символ - это C, то эта подстрока выглядет так ACAC (начинается и заканчивается на AC), её длина 4, значит состояние = 4

Когда массив будет составлен, останется лишь пройтись по всему тексту циклом, меняя значение состояние, и если оно совпадёт с длиной шаблона, то выводим нужный индекс
"""


def next_state(pattern, state, char, state_count):
    if state < state_count and pattern[state] == char:
        return state + 1

    for i in range(state, 0, -1):  # начинаем с самого большого значения
        if pattern[i-1] == char and i % 2 == 0:  # т.к. не получится поделить на префикс и суффикс, если нечётная длина
            if pattern[:int(i/2)] == pattern[int(i/2):i]:
                return i

    return 0


def create_table(pattern, file, state_count):
    table = {}
    for i in file:
        if i not in list(table.keys()):
            table[i] = [0 for j in range(state_count+1)]

    for state in range(state_count+1):
        for char in list(table.keys()):
            table[char][state] = next_state(pattern, state, char, state_count)

    return table


def main():
    with open("sample.txt") as f:
        file = f.read()

    pattern = input("Введите строку для поиска:\n")
    state_count = len(pattern)

    state = 0
    table = create_table(pattern, file, state_count)

    for i in range(len(file)):
        state = table[file[i]][state]
        if state == state_count:
            print("Шаблон найден по индексу", i + 1 - state_count)


if __name__ == "__main__":
    main()
