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
        print(row, "\n")

    """
    Слово w кодируются так:
    w = x * 2^k + R, где
      R = (x * 2^k) % polynom, т.е. остаток от деления на порождающий многочлен
      x принимает значения от 1 до (2^m - 1) включительно
    При том расстояние между каждым кодовым словом w должно быть >= d, т.е.
    они должны отличаться друг от друга минимум d битами
    """

    coded = []
    for x in range(1, 2**m):
        multiply = x * 2**k
        r = multiply % polynom
        coded.append(multiply + r)

    for i in coded:
        in_bin = str(bin(i)).lstrip("0b")
        print(f"Кодовое слово {i}, в двоичной: {in_bin}")


if __name__ == "__main__":
    main()
