class BipGraph:
    def __init__(self, left, right):
        self.__left = left  # вершины слева
        self.__right = right  # вершины справа
        self.__adj = [[] for i in range(right+1)]  # пары для левых вершин
 
    def addEdge(self, u, v):
        self.__adj[u].append(v) 
 
    def bfs(self):  # если есть добавочный путь, то истина, иначе ложь
        queue = []

        for u in range(1, self.__left+1):
            if self.__pairForLeft[u] == 0:
                self.__dist[u] = 0
                queue.append(u)
            else:
                self.__dist[u] = float("inf")

        self.__dist[0] = float("inf")

        while queue:
            u = queue[0]
            queue.pop(0)

            if self.__dist[u] < self.__dist[0]:
                for v in self.__adj[u]:
                    if self.__dist[self.__pairForRight[v]] == float("inf"):
                        self.__dist[self.__pairForRight[v]] = self.__dist[u] + 1
                        queue.append(self.__pairForRight[v])

        return self.__dist[0] != float("inf")
 
    def dfs(self, u):
        if u != 0:
            for v in self.__adj[u]:
                if self.__dist[self.__pairForRight[v]] == self.__dist[u] + 1:
                    if self.dfs(self.__pairForRight[v]):
                        self.__pairForRight[v] = u
                        self.__pairForLeft[u] = v
                        return True

            self.__dist[u] = float("inf")
            return False

        return True
 
    def hopcroftKarp(self):
        self.__pairForLeft = [0 for _ in range(self.__left+1)]  # пара для каждой вершины слева
        self.__pairForRight = [0 for _ in range(self.__right+1)]  # пара для каждой вершины справа
        self.__dist = [0 for _ in range(self.__left+1)]  # расстояния для левых вершин
        result = 0
 
        while self.bfs():
            for u in range(1, self.__left+1):
                if self.__pairForLeft[u] == 0 and self.dfs(u):
                    result += 1

        return result
 

class Flow:  # скопировано из 8 лабы
    def __init__(self, arr, source, sink):
        self.graph = arr
        self.n = len(arr)
        self.source = source
        self.sink = sink
    
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

    def ford_fulkerson(self):
        self.max_bipart = 0
        self.dfs(self.source, [self.source])
        return self.max_bipart
    
    def set_graph(self, arr):
        self.graph = arr
        self.n = len(arr)
        self.max_bipart = 0

    def hopcroft_karp(self, marking):
        left_count, right_count = 0, 0

        for i in marking:
            if i == 2:
                left_count += 1
            elif i == 1:
                right_count += 1

        bi_graph = BipGraph(left_count, right_count)
        
        left_vert, right_vert = 0, 0
        for i in range(self.n):
            if marking[i] == 2:
                left_vert += 1

            for j in range(self.n):
                if marking[j] == 1:
                    right_vert += 1
                if self.graph[i][j]:
                    bi_graph.addEdge(left_vert, right_vert)

            right_vert = 0

        self.max_bipart = bi_graph.hopcroftKarp()

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

    graph2 = [list(graph[i]) for i in range(n)]  # чтобы не изменить исходный граф

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
    print("\nМаксимальное паросочетание", flow.ford_fulkerson())

    # Другой алгоритм:
    flow.set_graph(graph2)

    print("\nМаксимальное паросочетание", flow.hopcroft_karp(marking))


if __name__ == "__main__":
    main()
