def merge_sort(arr):  # сортировка слиянием
    N = len(arr)

    if N > 1:
        left_arr = arr[:N//2]  # нужно делить список пополам, пока не остануться списки из двух элементов, которые мы можем легко отсортировать
        right_arr = arr[N//2:]

        merge_sort(left_arr)  # сортировка левой части
        merge_sort(right_arr)  # сортировка правой части

        i = j = k = 0
        L, R = len(left_arr), len(right_arr)

        while i < L and j < R:  # само слияние происходит так: идём по обоим частям одновременно, добавляя наименьший элемент по порядку из левой или правой части
            if left_arr[i] <= right_arr[j]:
                arr[k] = left_arr[i]
                i += 1
            else:
                arr[k] = right_arr[j]
                j += 1
            k += 1

        arr[k:] = left_arr[i:] + right_arr[j:]  # т.к. мы сливаем левую и правую часть до тех пор, пока в одной из них не останется элементов, то логично, что в другой части ещё будут элементы, которые добавим в конец списка, т.к. они определённо будут наибольшими


if __name__ == "__main__":  # суть внешней сортировки - разбиваем ввод на S элементов, сортируем их, добавляем попеременно в 2 разных файла, сортируем их отдельно через merge_sort, потом сливаем в один файл и повторяем
    S = 5  # максимальная длина списка, хранящаяся в оперативной памяти
    A, B = [], []

    input_array = input("Введите числа через пробел: ")  # данные на вход
    split_array = [float(i) for i in input_array.split()]  # разделяем входные данные на отдельные числа

    swap = False
    count = 0
    for i in split_array:
        if count < S:
            if not swap:
                A.append(i)
            else:
                B.append(i)
            count += 1
        else:
            if not swap:
                A.append(i)
                merge_sort(A)
                swap = True
            else:
                B.append(i)
                merge_sort(B)
                swap = False
            count = 0
    merge_sort(A)
    merge_sort(B)

    output_arr = []
    i = j = 0
    while i < len(A) and j < len(B):
        if A[i] <= B[j]:
            output_arr.append(A[i])
            i += 1
        else:
            output_arr.append(B[j])
            j += 1

    output_arr += (A[i:] + B[j:])

    print("Отсортированный массив через внешнюю сортировку:\n", output_arr)
