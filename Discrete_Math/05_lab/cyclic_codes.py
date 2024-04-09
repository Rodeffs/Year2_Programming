from math import factorial as fact


def to_bin(x):
    return bin(x).lstrip("0b")


def bits(x):
    return len(to_bin(x))


def leading_0(x, n):  # для того, чтобы кол-во битов было ровно n
    return '0' * (n - bits(x)) + to_bin(x)


def polynom_remain(f, g):  # деление многочленов
    r = f

    while bits(r) >= bits(g):
        div = g << (bits(r) - bits(g))
        r = r ^ div  # операция XOR, т.е. модуль по 2 от суммы битов

    return r


def bin2dec(bininput):
    result = 0

    for i in range(len(bininput)):
        result <<= 1
        result += int(bininput[i])

    return result


def main():
    n = int(input("Введите общее число элементов, n = "))
    m = int(input("\nВведите число информационных элементов, m = "))
    k = int(input("\nВведите число избыточных элементов, k = "))

    if n != (m+k):
        print("\nИсходные данные введены неверно, n != m + k")
        quit()

    polynom = input("\nВведите порождающий многочлен в двоичной системе: ")
    polynom = bin2dec(polynom)

    select_d_min = input("\nВведите d min (если пусто, то алгоритм сам посчитает): ")

    if select_d_min == "":
        d_min = float("inf")
    else:
        d_min = int(select_d_min)

    # Порождающая матрица имеет m строк и n столбцов, где в каждой строке
    # записывается полином в отражённом виде и сдвигается вправо каждую строку

    matrix = [[0]*n for i in range(0, m)]
    offset = 0
    for i in range(0, m):
        pol_copy = polynom
        for j in range(offset, k + offset + 1):
            matrix[i][j] = pol_copy % 2
            pol_copy >>= 1
        offset += 1

    print("\nПорождающая матрица:")
    for i in range(0, m):
        row = ""
        for j in range(0, n):
            row += (str(matrix[i][j])+" ")
        print(row)
    print()

    # Слово w кодируются так:
    # w = x * pow(2, k) + R, где
    #   R - остаток от деления на многочлен, см polynom_remain()
    #   x принимает значения от 1 до (pow(2, m) - 1) включительно
    # При том расстояние между каждым кодовым словом w должно быть >= d, т.е.
    # они должны отличаться друг от друга минимум d битами

    coded = {}
    for x in range(1, 2**m):
        multiply = x << k  # (x * 2**k) = (x << k)
        r = polynom_remain(multiply, polynom)
        coded[x] = [multiply + r, d_min]

    keys = list(coded.keys())
    values = list(coded.values())

    # Определение минимального расстояния Хемминга, операций = (2^n-1)*2^(n-1)
    if d_min == float("inf"):
        for i in range(len(keys)):
            current = keys[i]
            for j in range(i+1, len(keys)):
                other = keys[j]
                d = to_bin(coded[current][0] ^ coded[other][0]).count('1')
                coded[current][1] = min(coded[current][1], d)
                coded[other][1] = min(coded[other][1], d)
                d_min = min(d_min, d)

    for i in keys:
        initial = to_bin(i) + " " * (m - bits(i))
        result = leading_0(coded[i][0], n)
        print(f"Для слова {initial} код = {result}")

    print(f"\nМинимальное расстояние Хемминга d_min = {d_min}\n")

    guarantee = int((d_min - 1)/2)
    print(f"Кратность гарантированно исправляемых ошибок: {guarantee}\n")

    errors = 0
    for i in range(1, guarantee + 1):
        errors += (fact(n) / (fact(i) * fact(n - i)))  # бином. коэф.
    print("Число различных векторов ошибок, которые можно исправить:", errors)

    error_vector = 0b010010001
    print("\nВозьмём вектор ошибки:", leading_0(error_vector, n))

    wrong_code = coded[1][0] ^ error_vector
    syndrome = polynom_remain(wrong_code, polynom)
    print("\nСиндром этого вектора:", to_bin(syndrome))

    # Чтобы найти все возможные вектора ошибок с одинаковым синдромом, нужно:
    #   1) вектор ошибок E1 поделить (как многочлены) на кодовое слово X1
    #   2) получившийся результат поделить на другое кодовое слово X2
    #   3) результат из шага 2 снова поделить на кодовое слово X2, получим E2
    #   4) проделать шаги 2 и 3 для всех слов, записывая все E в список
    #   5) получившийся в итоге список и будет ответом

    error_vectors = [error_vector]
    for i in range(1, len(values)):  # нужно увеличить шаг для больших m
        current = values[i][0]
        wrong_code = wrong_code ^ current
        new_error_vector = wrong_code ^ current
        if new_error_vector not in error_vectors:
            error_vectors.append(new_error_vector)

    print("\nДругие вектора ошибок с этим же синдромом:")
    for i in range(1, len(error_vectors)):
        print(leading_0(error_vectors[i], n))

    print("\nКратность гарантированно обнаружаемых ошибок:", d_min - 1)

    # Эти вектора не могут быть обнаружены, т.к. в них столько много ошибок,
    # что они полностью заменяют одно кодовое слово на другое
    # Эти вектора совпадают с кодовыми словами
    print("\nВектора ошибок, которые не могут быть обнаружены, совпадают с кодовыми словами, см. их вывод")


if __name__ == "__main__":
    main()
