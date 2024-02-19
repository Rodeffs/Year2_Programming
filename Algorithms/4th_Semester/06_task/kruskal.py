class Edge:
    __start = 0
    __end = 0
    __weight = 0

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

    def check_link(self, other):
        return self.start == other.start or self.start == other.end or \
            self.end == other.end or self.end == other.start


def cycles(cur_edge, edges, total_nodes):  # проверка на зацикливание через поиск в ширину
    queue, visited, to_visit = [], [], []
    graph = [[] for i in range(0, total_nodes)]
    for i in range(0, total_nodes):
        graph[i] = [0 for i in range(0, total_nodes)]

    for i in range(0, len(edges)):
        cur = edges[i]
        graph[cur.start][cur.end] = cur.weight
        graph[cur.end][cur.start] = cur.weight
        if cur.start not in to_visit:
            to_visit.append(cur.start)
        if cur.end not in to_visit:
            to_visit.append(cur.end)

    for startnode in range(0, len(to_visit)):
        if startnode not in visited:
            queue.append(startnode)

        while queue:
            node = queue[0]
            visited.append(node)
            queue.pop(0)
            for j in range(0, len(graph[node])):
                if graph[node][j] and j in to_visit:
                    if j in visited or j in queue:
                        return True
                    else:
                        queue.append(j)

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
    print("Изначальный граф:")
    for i in range(0, len(edges)):
        print(f"    {edges[i].start} <--> {edges[i].end} = {edges[i].weight}")
    edges = sorted(edges, key=lambda item: item.weight)
    print("Отсортированный граф:")
    for i in range(0, len(edges)):
        print(f"    {edges[i].start} <--> {edges[i].end} = {edges[i].weight}")

    # Ищем кратчайший путь по Крускалу, т.е. добавляем кратчайшие пути без зацикливаний
    shortest, nodes, i, smallest_weight = [edges[0]], 2, 1, edges[0].weight
    while nodes < total_nodes:
        link = False
        cur_edge = edges[i]
        shortest.append(cur_edge)
        print(f"\n{cur_edge.start} <--> {cur_edge.end}")
        for j in range(0, len(shortest) - 1):
            if shortest[j].check_link(cur_edge):
                if cycles(cur_edge, shortest, total_nodes):
                    link = False
                    shortest.remove(cur_edge)
                    break
                link = True
                print(f"    links to {shortest[j].start} <--> {shortest[j].end}")
        if link:
            nodes += 1
            smallest_weight += cur_edge.weight
        i += 1

    print("Кратчайший путь:")
    for i in range(0, len(shortest)):
        print(f"    {shortest[i].start} <--> {shortest[i].end} = {shortest[i].weight}")
    print("Длина кратчайшего пути:", smallest_weight)


if __name__ == "__main__":
    main()
