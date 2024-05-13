class Item:
    def __init__(self, weight, cost):
        self.__weight = weight
        self.__cost = cost

    @property
    def weight(self):
        return self.__weight

    @weight.setter
    def weight(self, w):
        self.__weight = w

    @property
    def cost(self):
        return self.__cost

    @cost.setter
    def cost(self, c):
        self.__cost = c


def main():
    items = []

    max_weight = int(input("Введите грузоподъёмность рюкзака: "))

    print("\nВведите предметы в формате: ВЕС СТОИМОСТЬ")
    while True:
        entry = input()
        
        if entry == "":
            break
        
        items.append(Item(int(entry.split()[0]), int(entry.split()[1])))

    n = len(items)
    
    backpack = [[0 for j in range(max_weight+1)] for i in range(n+1)]
    
    for i in range(1, n+1):
        for w in range(max_weight+1):
            cur = items[i-1] # чтобы не пропустить предметов
            if cur.weight > w:
                backpack[i][w] = backpack[i-1][w]
            else:
                backpack[i][w] = max(backpack[i-1][w], backpack[i-1][w - cur.weight] + cur.cost)
    
    print("Максимальная стоимость равна", backpack[n][max_weight])


if __name__ == "__main__":
    main()
