"""
Лаба №3 "Задача о простых множителях"
На вход дается одно число х, нужно вывести все числа от 1 до х, удовлетворяющие условию:

3^K  * 5^L  * 7^M = t, где 1 <= t <= x

где K, L, M - натуральные числа или могут быть равны 0.
"""

import math


def quick_sort(ls: list, start: int, end: int) -> list: # Быстрая сортировка для вывода t в порядке возрастания
    if start >= end:
        return
    mid = (start + end) // 2
    sample = ls[mid][0]
    L = start
    R = end
    while L <= R:
        while ls[L][0] < sample:
            L += 1
        while ls[R][0] > sample:
            R -= 1
        if L <= R:
            ls[L][0], ls[R][0] = ls[R][0], ls[L][0]
            L += 1
            R -= 1
    quick_sort(ls, start, R)
    quick_sort(ls, L, end)


def print_t(x):
    t_array = []
    max_k = math.ceil(math.log(x, 3)) # Это всё максимально возможные степени, выше которых искать нет смысла
    max_l = math.ceil(math.log(x, 5))
    max_m = math.ceil(math.log(x, 7))
    for k in range(0, max_k):
        for l in range(0, max_l):
            for m in range(0, max_m):
                t = pow(3, k) * pow(5, l) * pow(7, m)
                if t <= x:
                    t_array.append([t, k, l, m])
    quick_sort(t_array, 0, len(t_array)-1)
    for i in range(0, len(t_array)):
        print(f"t={t_array[i][0]}, K={t_array[i][1]}, L={t_array[i][2]}, M={t_array[i][3]}")


if __name__ == '__main__':
    print("Введите число x")
    x = int(input())
    print_t(x)
