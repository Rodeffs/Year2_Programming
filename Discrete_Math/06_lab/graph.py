def main():
    n = int(input("Введите количество вершин в графе: "))
    graph = [[] for i in range(0, n)]
    incident = [[] for i in range(0, n)]

    for i in range(0, n):
        for j in range(0, n):
            graph[i].append(0)

    print("Введите рёбра графа в формате: НАЧ КОН ВЕС")

    edge_count = 0
    most_digits = 1
    while edge_count < n*(n-1):
        str_input = input()

        if str_input == "":
            break

        str_split = str_input.split()
        x, y, w = int(str_split[0]), int(str_split[1]), int(str_split[2])

        most_digits = max(most_digits, len(str_split[2]))

        graph[x][y] = w

        edge_count += 1

    print("\nМатрица смежности:")
    for i in range(0, n):
        out = ""
        for j in range(0, n):
            weight = str(graph[i][j])
            out += weight + " " * (1 + most_digits - len(weight))
        print(out)

    for i in range(0, n):
        for j in range(0, edge_count):
            incident[i].append(0)

    k = 0
    for i in range(0, n):
        for j in range(0, n):
            path = graph[i][j]
            if path:
                incident[i][k] = 1
                incident[j][k] = -1
                k += 1

    print("\nМатрица инцидентности:")
    for i in range(0, n):
        out = ""
        for k in range(0, edge_count):
            space_count = 1 if incident[i][k] == -1 else 2
            out += str(incident[i][k]) + " " * space_count
        print(out)


if __name__ == "__main__":
    main()
