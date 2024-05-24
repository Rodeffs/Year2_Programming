"""
Суть задачи: дан целочисленный промежуток: [a, b], b > a; и дано число x. Нужно выписать числа из промежутка [a, b] сумма которых равна x
"""

def main():
    x = int(input("Введите x, которое нужно получить суммой чисел из промежутка [a, b]: "))
    a = int(input("Введите a, при условии b > a: "))
    b = int(input("Введите b, при условии b > a: "))

    for offset in range(b):
        int_sum, cursum = [], 0
        for number in range(b - offset, a - 1, -1):
            if (cursum + number) <= x:
                cursum += number
                int_sum.append(number)
            if cursum == x:
                print(f"Сумма этих чисел из промежутка [{a}, {b}] даст {x}:")
                for entry in int_sum:
                    print(entry)
                return

    print(f"Из данного промежутка получить {x} нельзя")


if __name__ == "__main__":
    main()
