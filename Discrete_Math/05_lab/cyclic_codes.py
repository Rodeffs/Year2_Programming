def to_bin(x):
    return bin(x).lstrip("0b")


def bits(x):
    return len(to_bin(x))


def polynom_remain(f, g):  # деление многочленов
    r = f

    while bits(r) >= bits(g):
        div = g << (bits(r) - bits(g))
        r = r ^ div  # операция XOR, т.е. модуль от 2 суммы битов

    return r


def main():
    n = 15  # общее число элементов
    m = 5  # информационные элементы
    k = 10  # избыточные элементы
    polynom = 0b10100110111  # порождающий многочлен

    print("Порождающий многочлен: ", to_bin(polynom), "\n")

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

    print("Порождающая матрица:")
    for i in range(0, m):
        row = ""
        for j in range(0, n):
            row += (str(matrix[i][j])+" ")
        print(row)
    print()

    """
    Слово w кодируются так:
    w = x * pow(2, k) + R, где
      R - остаток от деления на многочлен, см polynom_remain()
      x принимает значения от 1 до (pow(2, m) - 1) включительно
    При том расстояние между каждым кодовым словом w должно быть >= d, т.е.
    они должны отличаться друг от друга минимум d битами
    """

    coded = {}
    for x in range(1, 2**m):
        multiply = x << k  # (x * 2**k) = (x << k)
        r = polynom_remain(multiply, polynom)
        coded[x] = [multiply + r, float("inf")]

    keys = list(coded.keys())
    for i in range(len(keys)):
        current = keys[i]
        for j in range(i+1, len(keys)):
            other = keys[j]
            d = to_bin(coded[current][0] ^ coded[other][0]).count('1')
            coded[current][1] = min(coded[current][1], d)
            coded[other][1] = min(coded[other][1], d)

    for i in keys:
        initial = to_bin(i) + " " * (m - bits(i))
        result = '0' * (n - bits(coded[i][0])) + to_bin(coded[i][0])
        print(f"Для слова {initial} код {result} минимальное расстояние {coded[i][1]}")


if __name__ == "__main__":
    main()
