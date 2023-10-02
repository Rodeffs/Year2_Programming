def quick_sort(ls: list, start: int, end: int) -> list:  # быстрая сортировка
    if start >= end:
        return
    mid = (start + end) // 2  # индекс посередине между начальным значением и конечным
    sample = ls[mid]  # с чем сравниваем
    left, right = start, end  # левое и правое число, которое изначально будут совпадать с начальным и конечным, но потом будут подходить ближе к сравниваему значению
    while left <= right:  # пока индекс левого числа не больше правого, мы в процессе сближения индексов ищем число слева, которое не меньше сравниваемого, и справа, которое не больше сравниваемого
        # while ls[left] > sample: # для сортировки в порядке возрастания
        while ls[left] < sample:
            left += 1
        # while ls[right] < sample: # для сортировки в порядке возрастания
        while ls[right] > sample:
            right -= 1
        if left <= right:  # меняем местами левое и правое значения, когда левое стало не меньше сравниваемого, а правое - не больше сравниваемого
            ls[left], ls[right] = ls[right], ls[left]
            left += 1
            right -= 1
    quick_sort(ls, start, right)  # сортируем левую часть списка
    quick_sort(ls, left, end)  # сортируем правую часть списка


if __name__ == "__main__":
    print("Введите числа через пробел для сортировки в порядке возрастания:")
    input_array = input()  # данные на вход
    split_array = [float(i) for i in input_array.split()]  # разделяем входные данные на отдельные числа
    array_length = len(split_array)
    quick_sort(split_array, 0, array_length-1)  # сортируем через быструю сортировку
    print("Отсортированный список:\n", split_array)

