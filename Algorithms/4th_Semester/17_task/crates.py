"""
Имеется N предметов различного размера. Один ящик имеет строгую вместимость. Необходимо разложить все N предметов в минимальное количество ящиков.
"""


def main():
    capacity = float(input("Введите вместимость одного ящика: "))
    items, crates = [], []

    weight = input("Введите веса предметов:\n")
    while weight != "":
        temp = float(weight)
        if temp > capacity:
            print("Этот предмет не влезет ни в один ящик. Введите другой:")
        else:
            items.append(temp)
        weight = input()
    
    # Алгоритм наилучшего остатка
    for item in items:
        potential_crates = []
        
        # Суть в том, чтобы после добавления предмета в яшике оставалось как можно меньше места
        # Для этого создаём сначала массив ящиков в которых предмет вообще может поместиться
        for i in range(len(crates)):
            if item <= crates[i]:
                potential_crates.append(i)
        
        # Если такого ящика не оказалось, берём новый ящик и сразу ложим в него предмет
        if not potential_crates:
            crates.append(capacity - item)
        
        # Если же нашлись такие ящики, то кладём предмет в тот, в котором после этого останется как можно меньше места
        else:
            best_fit, max_cap = 0, capacity

            for i in potential_crates:
                if (crates[i] - item) < max_cap:
                    max_cap = crates[i] - item
                    best_fit = i

            crates[best_fit] -= item

    if crates:
        print("Распределение предметов по ящикам:")
        for i in range(len(crates)):
            print(f"Ящик {i+1}: вес = {capacity - crates[i]}")
        return

    print("Ни один предмет не влез ни в один ящик")


if __name__ == "__main__":
    main()
