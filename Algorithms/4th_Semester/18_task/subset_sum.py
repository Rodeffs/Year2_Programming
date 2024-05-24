"""
Суть задачи: даны последовательность чисел и число x. Нужно выписать числа из этой последовательности, сумма которых равна x
"""

def main():
    array = []
    entry = input("Введите последовательность чисел:\n")
    while entry != "":
        array.append(int(entry))
        entry = input()

    x = int(input("Введите число, которое нужно получить из последовательности: "))

    # Сортируем в порядке неубывания:
    array.sort(reverse=True)
    
    n = len(array)
    for offset in range(n):
        int_sum, cursum = [], 0
        for i in range(offset, n):
            number = array[i]
            if (cursum + number) <= x:
                cursum += number
                int_sum.append(number)
            if cursum == x:
                print("Сумма следующих чисел из последовательности даст", x)
                for sumnum in int_sum:
                    print(sumnum)
                return

    print(f"Из данной последовательности получить {x} нельзя")


if __name__ == "__main__":
    main()
