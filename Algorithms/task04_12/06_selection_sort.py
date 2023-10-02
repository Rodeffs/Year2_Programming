def selection_sort(ls):  # суть сортировки выбором - при каждой итерации ставим в начало списка наименьший элемент
    for i in range(0, len(ls)):
        min = i
        for j in range(i, len(ls)):  # мы каждый раз пробегаемся от i элемента до конца, находя наименьший элемент списка и ставя его на место i-того, затем повторяем процесс
            min = j if ls[j] < ls[min] else min
        ls[i], ls[min] = ls[min], ls[i]


if __name__ == "__main__":
    print("Введите числа через пробел для сортировки в порядке возрастания:")
    input_array = input()  # данные на вход
    split_array = [float(i) for i in input_array.split()]  # разделяем входные данные на отдельные числа
    selection_sort(split_array)  # сортируем через сортировку выбором
    print("Отсортированный список:\n", split_array)
