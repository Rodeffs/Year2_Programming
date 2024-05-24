class Flow:  # скопировано из 8 лабы
    def __init__(self, arr, source, sink):
        self.graph = arr
        self.n = len(arr)
        self.source = source
        self.sink = sink
    
    def dfs_ford_fulk(self, curver, curpath): 
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
                    self.dfs_ford_fulk(i, newpath)

    def ford_fulkerson(self):
        self.max_bipart = 0
        self.dfs_ford_fulk(self.source, [self.source])
        return self.max_bipart

    def set_graph(self, arr):
        self.graph = arr
        self.n = len(arr)

    def get_pair(self, vert1, side):
        for vert2 in range(self.n):
            if side == "left" and self.pairs[vert1][vert2] != -1:
                return self.pairs[vert1][vert2]
            if side == "right" and self.pairs[vert2][vert1] != -1:
                return self.pairs[vert2][vert1]
        return -1

    def bfs_hop_karp(self):
        queue = []

        for u in range(self.n):
            if self.get_pair(u, "left") == -1:
                self.distance[u] = 0
                queue.append(u)
            else:
                self.distance[u+1] = float("inf")

        self.distance[0] = float("inf")

        while queue:
            u = queue[0]
            queue.pop(0)

            if self.distance[u+1] < self.distance[0]:
                for v in range(self.n):
                    leftpair = self.get_pair(v, "right")
                    if self.graph[u][v] and leftpair != -1:
                        if self.distance[leftpair + 1] == float("inf"):
                            self.distance[leftpair + 1] = self.distance[u + 1] + 1
                            queue.append(leftpair)

        return self.distance[0] != float("inf")
 
    def dfs_hop_karp(self, u):
        if u != -1:
            for v in range(self.n):
                leftpair = self.get_pair(v, "right")
                if self.graph[u][v] and leftpair != -1:
                    if self.distance[leftpair + 1] == self.distance[u + 1] + 1:
                        if self.dfs_hop_karp(leftpair):
                            self.pairs[v][leftpair] = u
                            self.pairs[leftpair][v] = v
                            return True

            self.distance[u + 1] = float("inf")
            return False

        return True

    def hopcroft_karp(self, marking):
        self.nax_bipart = 0
        n = self.n
        self.marking = marking

        # -1 значит, что это вершина не левая
        self.pairs = [[-1 for i in range(n)] for j in range(n)]  # паросочетания
        self.distance = [-1 for i in range(n+1)]  # расстояние для вершин слева

        for i in range(n):
            if marking[i] == 2:
                self.distance[i+1] = 0  # значит, вершина левая

        while self.bfs_hop_karp():
            for u in range(n):
                if self.get_pair(u, "left") == -1 and self.dfs_hop_karp(u):
                    self.max_bipart += 1

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

    graph2 = [list(graph[i]) for i in range(n)]  # чтобы не изменить исходный граф

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
    print("\nМаксимальное паросочетание", flow.ford_fulkerson())

    # Другой алгоритм:
    flow.set_graph(graph2)

    print("\nМаксимальное паросочетание", flow.hopcroft_karp(marking))


if __name__ == "__main__":
    main()
