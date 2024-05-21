class Flow:  # скопировано из 8 лабы
    def __init__(self, arr, source, sink):
        self.graph = [list(arr[i]) for i in range(len(arr))]  # чтобы не изменить исходный граф
        self.n = len(arr)
        self.source = source
        self.sink = sink
        self.max_bipart = 0
    
    def dfs(self, curver, curpath): 
        for i in range(self.n):
            if self.graph[curver][i]:
                newpath = curpath + [i]

                if i == self.sink:
                    valid_path = True

                    for j in range(len(newpath)-1):
                        if not self.graph[newpath[j]][newpath[j+1]]:
                            valid_path = False
                            break

                    if valid_path:
                        for j in range(len(newpath)-1):
                            self.graph[newpath[j]][newpath[j+1]] = 0
                        self.max_bipart += 1
                else:
                    self.dfs(i, newpath)

    def get_max_bipart(self):
        self.dfs(self.source, [self.source])
        return self.max_bipart


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

    # Выводим граф и заодно делаем его ориентированным для алгоритма Форда-Фулкерсона
    marking = bipartite(graph, n)
    print("Двудольный граф:")
    for i in range(n):
        if marking[i] == 2:
            for j in range(n):
                if graph[i][j]:
                    print(f"    {i} --- {j}")
                    graph[j][i] = 0

    # Теперь создаём исток, который ведёт во все левые вершины, и сток, в который ведут все правые 
    source, sink = n, n + 1
    for i in range(n):
        graph[i] += [0, 0]
    graph.append([0 for i in range(n+2)])
    graph.append([0 for i in range(n+2)])

    for i in range(n):
        if marking[i] == 1:
            graph[i][sink] = 1
        if marking[i] == 2:
            graph[source][i] = 1
    
    # Теперь считаем кол-во уникальных путей (т.е. рёбра не повторяются) от source в sink
    flow = Flow(graph, source, sink)
    print("\nМаксимальное паросочетание", flow.get_max_bipart())

    # Другой алгоритм:
    flow = Flow(graph, source, sink)

    # https://www.geeksforgeeks.org/hopcroft-karp-algorithm-for-maximum-matching-set-2-implementation/


if __name__ == "__main__":
    main()
