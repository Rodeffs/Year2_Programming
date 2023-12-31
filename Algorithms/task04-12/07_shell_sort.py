def shell_sort(ls):  # суть этого алгоритма - совершенствование алгоритма вставок
    N = len(ls)
    gaps = []  # для этого нам понадобится список так называемых пробелов (расстояний)
    k = 1
    while pow(2, k) - 1 < N:  # однозначной формулы для пробелов нет, но эта показалась мне наиболее оптимальной
        gaps = [pow(2, k) - 1] + gaps  # т.е. у нас получится список из пробелов 1, 3, 7, 15, 31 и т.д., но в порядке убывания
        k += 1
    for i in range(0, len(gaps)):  # далее начинаем с самого большого пробела и идём по списку
        gap = gaps[i]
        for j in range(gap, N):  # идея алгоритма в том, что мы сначала сортируем элементы, стоящие далеко друг от друга (на разных концах списка), чтобы маленькие элементы сразу перенести в начало, а затем идёт простой алгоритм вставок
            temp = ls[j]
            k = j
            while k >= gap and ls[k-gap] > temp:  # сам алгоритм вставок
                ls[k] = ls[k-gap]
                k -= gap
            ls[k] = temp


if __name__ == "__main__":
    print("Введите числа через пробел для сортировки в порядке возрастания:")
    input_array = input()  # данные на вход
    split_array = [float(i) for i in input_array.split()]  # разделяем входные данные на отдельные числа
    shell_sort(split_array)  # сортируем через сортировку Шелла
    print("Отсортированный список:\n", split_array)
