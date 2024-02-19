"""
Ресурсы:
    https://habr.com/ru/articles/569444/
    https://www.geeksforgeeks.org/detect-cycle-undirected-graph/
"""


class Edge:
    def __init__(self, a, b, val):
        self.__start = a
        self.__end = b
        self.__weight = val

    @property
    def start(self):
        return self.__start

    @start.setter
    def start(self, val):
        self.__start = val

    @property
    def end(self):
        return self.__end

    @end.setter
    def end(self, val):
        self.__end = val

    @property
    def weight(self):
        return self.__weight

    @weight.setter
    def weight(self, val):
        self.__weight = val

    def __eq__(self, other):  # перегрузка оператора ==
        return (self.start == other.start and self.end == other.end) or \
                (self.start == other.end and self.end == other.start)


def dfs(node, visited, parent, subgraph):
    visited.append(node)

    for i in range(0, len(subgraph[node])):
        if subgraph[node][i]:
            if i not in visited:
                if dfs(i, visited, node, subgraph):
                    return True
            elif parent != i:
                return True
    return False


def cycles(shortest, total_nodes, nodes):
    # Суть в том, чтобы понять, зациклит ли добавленное ребро граф или нет
    # Для этого добавим его в список рёбер shortest и построим из них подграф
    # Далее, проходимся по всем вершинам этого подграфа, см. список to_visit
    # На каждой итерации будем вызывать поиск в глубину dfs()
    # Также каждый раз запоминаем parent - предыдущую вершину
    # Если нынешнюю вершину мы не посещали, то рекурсивно вызываем dfs() от неё
    # Если же посещали и при этом это не предыдущая вершина, то граф зациклился

    visited = []
    to_visit = list(nodes)
    last = shortest[-1]
    if last.start not in to_visit:
        to_visit.append(last.start)
    if last.end not in to_visit:
        to_visit.append(last.end)

    subgraph = [[] for i in range(0, total_nodes)]
    for i in range(0, total_nodes):
        subgraph[i] = [0 for i in range(0, total_nodes)]

    for i in range(0, len(shortest)):
        cur = shortest[i]
        subgraph[cur.start][cur.end] = cur.weight
        subgraph[cur.end][cur.start] = cur.weight

    for i in range(0, len(to_visit)):
        node = to_visit[i]
        if node not in visited:
            if dfs(node, visited, -1, subgraph):
                return True

    return False


def main():
    with open("input.txt") as mat:
        graph = [i.split() for i in mat.readlines()]
    for i in range(0, len(graph)):
        graph[i] = [int(j) for j in graph[i]]

    total_nodes = len(graph)

    # Добавляем рёбра в массив
    edges = []
    for i in range(0, total_nodes):
        for j in range(0, total_nodes):
            path = graph[i][j]
            if i != j and path:
                temp = Edge(i, j, path)
                if temp not in edges:
                    edges.append(temp)

    # Сортируем рёбра в порядке неубывания их весов:
    edges = sorted(edges, key=lambda item: item.weight)

    # Ищем кратчайший путь по Крускалу
    # Суть в добавлении таких ребёр к новому подграфу, чтобы не было циклов
    shortest, nodes, i, smallest_weight = [], [], 0, 0
    while len(nodes) < total_nodes:
        cur_edge = edges[i]
        shortest.append(cur_edge)
        if cycles(shortest, total_nodes, nodes):
            shortest.remove(cur_edge)
        else:
            if cur_edge.start not in nodes:
                nodes.append(cur_edge.start)
            if cur_edge.end not in nodes:
                nodes.append(cur_edge.end)
            smallest_weight += cur_edge.weight
        i += 1

    print("Кратчайший путь:")
    for i in range(0, len(shortest)):
        print(f"    {shortest[i].start} <--> {shortest[i].end} = {shortest[i].weight}")
    print("Длина кратчайшего пути:", smallest_weight)


if __name__ == "__main__":
    main()
