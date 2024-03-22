def dfs(node, visited, graph, n):  # поиск в глубину
    vertice_count = 1

    visited.append(node)
    for i in range(n):
        if graph[node][i] and i not in visited:
            vertice_count += dfs(i, visited, graph, n)

    return vertice_count


def strongly_connected(graph, n):
    # Ориентированный граф называется сильно связным,
    # если из каждой его вершины можно попасть в любую другую

    for node in range(n):
        visited = []
        if dfs(node, visited, graph, n) != n:
            return False

    return True


def check_degrees(graph, n):
    vertice = 0

    while vertice < n:
        in_degree = 0
        out_degree = 0

        for i in range(n):
            if graph[vertice][i]:
                in_degree += 1
            if graph[i][vertice]:
                out_degree += 1

        if in_degree != out_degree or in_degree * out_degree == 0:
            return False

        vertice += 1

    return True


def main():
    n = int(input("Введите количество вершин в графе: "))

    # Создание матрицы смежности
    print("Введите рёбра графа в формате: НАЧ КОН ВЕС")
    edge_count = 0
    most_digits = 1
    graph = [[0 for j in range(n)] for i in range(n)]
    while edge_count < n*(n-1):
        str_input = input()

        if str_input == "":
            break

        str_split = str_input.split()

        most_digits = max(most_digits, len(str_split[2]))

        x, y, w = int(str_split[0]), int(str_split[1]), int(str_split[2])
        graph[x][y] = w
        edge_count += 1

    # Вывод её
    print("\nМатрица смежности:")
    for i in range(n):
        out = ""
        for j in range(n):
            weight = str(graph[i][j])
            out += weight + " " * (1 + most_digits - len(weight))
        print(out)

    # Создание матрицы инцидентности из матрицы смежности
    incident = [[0 for j in range(edge_count)] for i in range(n)]
    k = 0
    for i in range(n):
        for j in range(n):
            if graph[i][j]:
                incident[i][k] = 1
                incident[j][k] = -1
                k += 1

    # Вывод её
    print("\nМатрица инцидентности:")
    for i in range(n):
        out = ""
        for k in range(edge_count):
            space_count = 1 if incident[i][k] == -1 else 2
            out += str(incident[i][k]) + " " * space_count
        print(out)

    # Ориентированный граф является Эйлеровым тогда и только тогда, когда:
    # 1) Для каждой вершины входящая степень (кол-во входящих вершин) равно
    #    исходящей степени (кол-ву исходящих вершин);
    # 2) Он сильно связан.

    if check_degrees(graph, n) and strongly_connected(graph, n):
        print("\nЭто Эйлеровый граф\n")
    else:
        print("\nЭтот граф не Эйлеровый\n")

    # Делаем граф неориентированным:
    for i in range(n):
        for j in range(i+1, n):
            if not graph[i][j] and graph[j][i]:
                graph[i][j] = graph[j][i]
            elif not graph[j][i] and graph[i][j]:
                graph[j][i] = graph[i][j]
            else:
                graph[i][j] = float("inf")
                graph[j][i] = float("inf")

    # Алгоритм Флойда — Уоршелла:
    short = list(graph)
    for k in range(n):
        for i in range(n):
            for j in range(n):
                short[i][j] = min(short[i][j], short[i][k] + short[k][j])

    print("Считая данный граф неориентированным, кратчайшие пути будут:")
    for i in range(n):
        for j in range(i+1, n):
            print(f"Между {i} и {j} кратчайший путь = {short[i][j]}")


if __name__ == "__main__":
    main()
