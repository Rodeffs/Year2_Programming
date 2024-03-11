def main():
    with open("input.txt") as mat:
        graph = [i.split() for i in mat.readlines()]
    for i in range(0, len(graph)):
        graph[i] = [int(j) for j in graph[i]]

    v = len(graph[i])
    start = int(input(f"В графе {v} вершин, введите стартовую вершину: "))
    distance = []

    for i in range(0, v):
        if i == start:
            distance.append(0)
        else:
            distance.append(float('inf'))  # бесконечность в питоне

    # Суть этого алгоритма: n-1 раз проходим по графу из n вершин, каждый раз
    # расслабляя веса вершин (т.е. уменьшать их веса, если нашёлся путь короче)
    # Отличительная черта от алгоритма Дейкстры - возможность работы с
    # отрицательными весами, но за счёт скорости работы алгоритма
    for x in range(0, v-1):
        for i in range(0, v):
            for j in range(0, v):
                path = graph[i][j]
                if path != 0:  # т.к. расстояние может быть < 0 а это False
                    if distance[j] > distance[i] + path:
                        distance[j] = distance[i] + path

    for i in range(0, v):
        if i != start:
            print(f"Кратчайшее расстояние от {start} до {i} = {distance[i]}")


if __name__ == '__main__':
    main()
