def max_heapify(arr, N, i):  # делаем возрастающую кучу (т.е. родительский элемент должен быть больше своих производных)
    parent_index = i  # родитель, по умолчанию наибольший элемент, но может измениться
    left_index = 2*i + 1  # левый элемент от родительского
    right_index = 2*i + 2  # правый элемент от родительского
   
    if left_index < N and arr[parent_index] < arr[left_index]:  # делаем проверку на то, что левый элемент не больше родительского
        parent_index = left_index

    if right_index < N and arr[parent_index] < arr[right_index]:  # делаем проверку на то, что правый элемент не больше родительского
        parent_index = right_index

    if parent_index != i:  # меняем родителя, если он оказался меньше или правого, или левого элемента
        arr[i], arr[parent_index] = arr[parent_index], arr[i]

        max_heapify(arr, N, parent_index)  # после этого проделываем все вышеуказанные действия, но только теперь с бывшим наибольшим элементом


def heap_sort(arr):  # суть её в том, чтобы создать возрастающую кучу, затем убрать её максимальный элемент и снова создать возрастающую кучу, таким образом сортируя список
    N = len(arr)
    i = N

    for j in range(0, N//2):  # создаём кучу пока есть родительские элементы
        max_heapify(arr, N, j)

    while i > 0:  # потом постепенно выносим максимальный элемент кучи в конец и пересоздаём её
        max_heapify(arr, i, 0)
        arr[i-1], arr[0] = arr[0], arr[i-1]
        i -= 1


if __name__ == "__main__":
    print("Введите числа через пробел для сортировки в порядке возрастания:")
    input_array = input()  # данные на вход
    split_array = [float(i) for i in input_array.split()]  # разделяем входные данные на отдельные числа
    heap_sort(split_array)  # сортировка кучей
    print("Отсортированный список:\n", split_array)

