import math


def str_bin(x):
    return str(bin(x)).lstrip("0b")


def bit_count(x):
    # Считаю количество битов через логарифм по осн. 2
    # В случае, если число - степень 2, то добавляю 1 к ответу
    is_power_of_2 = (x & (x-1)) == 0
    return math.ceil(math.log(x, 2)) + is_power_of_2


def polynom_remain(f, g):  # деление многочленов
    r = f
    do_once = True  # костыль, т.к. нужно минимум 1 раз поделить

    while bit_count(g) <= bit_count(r) or do_once:
        do_once = False
        div = g << (bit_count(r) - bit_count(g))
        r = r ^ div  # операция XOR, т.е. модуль от 2 суммы битов

    return r


def main():
    n = 15  # общее число элементов
    m = 5  # информационные элементы
    k = 10  # избыточные элементы
    d = 7  # мин. расстояние
    polynom = 0b10100110111  # порождающий многочлен

    """
    Порождающая матрица имеет m строк и n столбцов, где в каждой строке
    записывается полином в отражённом виде и сдвигается вправо каждую строку
    """

    matrix = [[0]*n for i in range(0, m)]
    offset = 0
    for i in range(0, m):
        pol_copy = polynom
        for j in range(offset, k + offset + 1):
            matrix[i][j] = pol_copy % 2
            pol_copy >>= 1
        offset += 1

    print("Порождающая матрица для многочлена", str(bin(polynom)).lstrip("0b"))
    for i in range(0, m):
        row = ""
        for j in range(0, n):
            row += (str(matrix[i][j])+" ")
        print(row)
    print("\n")

    """
    Слово w кодируются так:
    w = x * pow(2, k) + R, где
      R - остаток от деления на многочлен, см polynom_remain()
      x принимает значения от 1 до (pow(2, m) - 1) включительно
    При том расстояние между каждым кодовым словом w должно быть >= d, т.е.
    они должны отличаться друг от друга минимум d битами
    """

    coded = []
    for x in range(1, 2**m):
        r = polynom_remain(x << k, polynom)  # (x * 2**k) = (x << k)
        code_word = (x << k) + r
        coded.append(code_word)

        print(f"Для слова {str_bin(x)} код {str_bin(code_word)}")


if __name__ == "__main__":
    main()
