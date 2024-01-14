import math


def digit(number, place):  # т.к. мы считаем поразрядно, значит нам нужно узнать конкретную цифру числа number на месте place с конца, модуль нужен для правильной сортировки отрицательных чисел
    return abs(number // 10**place) % 10


def counting_sort(arr, p):  # поразрядная сортировка опирается на сортировку подсчётом, суть поразрядной сортировки - сортировать числа по цифрам с конца (т.е. разрядам) от меньшего к большего и так до тех пор, пока все они не будут отсортированы
    N = len(arr)
    max_digit = 0

    for i in range(0, N):  # для сортировки подсчётом сначала нам нужно узнать максимальное число, в данном случае это будет цифрой, т.к. мы сортируем по разрядам
        current_digit = digit(arr[i], p)
        max_digit = current_digit if (current_digit > max_digit) else max_digit 
    
    count_arr = [0]*(max_digit+1)  # далее создаём массив, в котором каждый индекс - это цифра, встречающаяся в вводных числах, а значение под индексом - число раз, сколько она встретилась
    new_arr = [0 for i in arr]

    for i in range(0, N):  # сам подсчёт количества цифр
        count_arr[digit(arr[i], p)] += 1

    for i in range(1, len(count_arr)):  # затем для правильной работы алгоритма складываем количество, сколько раз встретилась эта цифра и количество, сколько раз встретилась предыдущая 
        count_arr[i] = count_arr[i-1] + count_arr[i]

    for i in range(N-1, -1, -1):  # чтобы алгоритм был устойчив, идём с конца списка
        current_input = digit(arr[i], p)
        new_arr[count_arr[current_input] - 1] = arr[i]  # получается, что число, у которого эта цифра наименьшая среди остальных, встаёт в начало списка, и так далее по возрастанию
        count_arr[current_input] -= 1  # важно не забыть уменьшить значение сколько раз встретилась цифра
    
    return new_arr


def radix_sort(ls):  # поразрядная сортировка
    
    positive, negative = [], []  # необходимо отдельно сортировать положительные и отрицательные числа

    for i in range(0, len(ls)):  
        if ls[i] < 0:
            negative.append(ls[i])
        else:
            positive.append(ls[i])

    if negative:  # таким образом в питоне можно проверить, пустой ли список
        max_digits_negative = math.ceil(math.log(abs(min(negative)), 10))  # максимальное количество цифр в отрицательных числах, логично, что минимальное отрицательное число максимально по модулю

        for i in range(0, max_digits_negative):
            negative = counting_sort(negative, i)

        negative.reverse()  # важно развернуть список отрицательных чисел, т.к. мы их сортировали по модулю

    if positive:
        max_digits_positive = math.ceil(math.log(max(ls), 10))  # максимальное количество цифр в положительных числах
    
        for i in range(0, max_digits_positive):
            positive = counting_sort(positive, i)
    
    return negative + positive


if __name__ == "__main__":
    print("Введите целые числа через пробел для сортировки в порядке возрастания:")
    input_array = input()  # данные на вход
    split_array = [int(i) for i in input_array.split()]  # разделяем входные данные на отдельные числа, однако важно то, что поразрядная сортировка работает только с целыми числами
    print(f"Отсортированный список: {radix_sort(split_array)}")  # сортируем через поразрядную сортировку и выводим

