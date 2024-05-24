"""
Имеется N предметов различного размера. Один ящик имеет строгую вместимость. Необходимо разложить все N предметов в минимальное количество ящиков.
"""

def main():
    capacity = float(input("Введите вместимость одного ящика: "))
    items = []

    print("Введите веса предметов:")
    weight = input()
    while weight != "":
        items.append(float(weight))
        weight = input()



if __name__ == "__main__":
    main()
