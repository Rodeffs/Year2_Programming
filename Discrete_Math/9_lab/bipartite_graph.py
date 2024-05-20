def bipartite(graph, n):
    queue, visited = [], []
    marking = [0 for i in range(n)]  # помечаем вершины как чётные-нечётные поочерёдно, где 1 - нечётная, 2 - чётная, 0 - не помечена

    for startnode in range(n):

        if startnode not in visited:
            queue.append(startnode)
            marking[startnode] = 2

        while queue:
            node = queue[0]
            visited.append(node)
            queue.pop(0)
            for i in range(0, len(graph[node])):
                if graph[node][i]:
                    if marking[node] == 2 and marking[i] != 2:
                        if not marking[i]:
                            marking[i] = 1
                        if i not in visited and i not in queue:
                            queue.append(i)
                    elif marking[node] == 1 and marking[i] != 1:
                        if not marking[i]:
                            marking[i] = 2
                        if i not in visited and i not in queue:
                            queue.append(i)
                    else:  # если возникло столкновение, то просто удаляем это ребро
                        graph[node][i] = 0
                        graph[i][node] = 0

    return marking


def make_non_oriented(graph, n):
    for i in range(n):
        for j in range(i, n):
            if graph[i][j] or graph[j][i]:
                graph[i][j] = 1
                graph[j][i] = 1


def main():
    with open("graph.txt") as mat:
        graph = [i.split() for i in mat.readlines()]
    n = len(graph)
    for i in range(n):
        graph[i] = [int(j) for j in graph[i]]
    
    # Сначала делаем граф неориентированным
    make_non_oriented(graph, n)

    marking = bipartite(graph, n)
    
    # Выводим граф и заодно делаем его ориентированным для алгоритма Форда-Фулкерсона
    print("Двудольный граф:")
    for i in range(n):
        if marking[i] == 2:
            for j in range(n):
                if graph[i][j]:
                    print(f"    {i+1} --- {j+1}")
                    graph[j][i] = 0

    # Теперь создаём исток, который ведёт во все левые вершины, и сток, в который ведут все правые 
    source, sink = n, n + 1
    for i in range(n):
        graph[i] += [0, 0]
    temp = [0 for i in range(n+2)]
    graph.append(temp)
    graph.append(temp)

    for i in range(n):
        if marking[i] == 1:
            graph[i][sink] = 1
        if marking[i] == 2:
            graph[source][i] = 1

    # Теперь просто ищем максимальный поток, это и будет максимальное паросочетание


if __name__ == "__main__":
    main()
