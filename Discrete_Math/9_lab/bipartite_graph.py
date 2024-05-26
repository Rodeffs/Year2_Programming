class BipGraph:
    def __init__(self, left, right):
        self.left = left  # вершины слева
        self.right = right  # вершины справа
        self.adjacent = [[] for i in range(right+1)]  # пары для левых вершин
 
    def addEdge(self, u, v):
        self.adjacent[u].append(v) 
 
    def bfs(self):  # если есть добавочный путь, то истина, иначе ложь
        queue = []

        for u in range(1, self.left+1):
            if self.pair_for_left[u] == 0:
                self.distance[u] = 0
                queue.append(u)
            else:
                self.distance[u] = float("inf")

        self.distance[0] = float("inf")

        while queue:
            u = queue[0]
            queue.pop(0)

            if self.distance[u] < self.distance[0]:
                for v in self.adjacent[u]:
                    if self.distance[self.pair_for_right[v]] == float("inf"):
                        self.distance[self.pair_for_right[v]] = self.distance[u] + 1
                        queue.append(self.pair_for_right[v])

        return self.distance[0] != float("inf")
 
    def dfs(self, u):
        if u != 0:
            for v in self.adjacent[u]:
                if self.distance[self.pair_for_right[v]] == self.distance[u] + 1:
                    if self.dfs(self.pair_for_right[v]):
                        self.pair_for_right[v] = u
                        self.pair_for_left[u] = v
                        return True

            self.distance[u] = float("inf")
            return False

        return True
 
    def hopcroftKarp(self):
        self.pair_for_left = [0 for _ in range(self.left+1)]  # пара для каждой вершины слева
        self.pair_for_right = [0 for _ in range(self.right+1)]  # пара для каждой вершины справа
        self.distance = [0 for _ in range(self.left+1)]  # расстояния для левых вершин
        result = 0
 
        while self.bfs():
            for u in range(1, self.left+1):
                if self.pair_for_left[u] == 0 and self.dfs(u):
                    result += 1

        return result
 

class Flow:  # скопировано из 8 лабы с нужными изменениями
    def __init__(self, arr, marking):
        self.graph = arr
        self.n = len(arr)
        self.marking = marking
    
    def dfs(self, left, mathes_for_right, checked, right_vert):
        for right in right_vert:  # подбираем пару, проверяя все правые вершины
            if self.graph[left][right] and not checked[right]:  # если есть путь и эту правую вершину ещё не проверяли
                checked[right] = True  # то помечаем её как проверенную
                
                # Если этой правой вершине ещё не назначена пара, то теперь левая ей будет
                # Однако, может возникнуть ситуация, что этой правой вершине уже назначена какая-нибудь
                # левая вершина, которая в свою очередь может ещё иметь другую пару. Для этого и нужно второе условие, оно проверит, возможно ли для сей левой вершины найти другую пару и если да, то так и делаем
                if mathes_for_right[right] == -1 or self.dfs(mathes_for_right[right], mathes_for_right, checked, right_vert):
                    mathes_for_right[right] = left
                    return True
        return False


    def ford_fulkerson(self):
        left_vert, right_vert = [], []
        self.max_bipart = 0

        for i in range(self.n):
            if self.marking[i] == 1:
                right_vert.append(i)
            elif self.marking[i] == 2:
                left_vert.append(i)

        mathes_for_right = [-1 for i in range(self.n)]  # пары для правых вершин

        print(len(left_vert), len(right_vert))

        for i in left_vert:
            checked = [False for j in range(self.n)]  # изначально для левой вершины пока не проверена ни одна правая

            if self.dfs(i, mathes_for_right, checked, right_vert):
                self.max_bipart += 1

        return self.max_bipart

    def hopcroft_karp(self):
        self.max_bipart = 0
        left_count, right_count = 0, 0

        for i in self.marking:
            if i == 2:
                left_count += 1
            elif i == 1:
                right_count += 1

        bi_graph = BipGraph(left_count, right_count)
        
        left_vert, right_vert = 0, 0
        for i in range(self.n):
            if self.marking[i] == 2:
                left_vert += 1

            for j in range(self.n):
                if self.marking[j] == 1:
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

    # Выводим граф и заодно делаем его снова ориентированным
    marking = bipartite(graph, n)
    print("Двудольный граф:")
    for i in range(n):
        if marking[i] == 2:
            for j in range(n):
                if graph[i][j]:
                    print(f"    {i} --- {j}")
                    graph[j][i] = 0

    flow = Flow(graph, marking)

    print("\nМаксимальное паросочетание алгоритмом Форда-Фулкерсона:", flow.ford_fulkerson())

    print("\nМаксимальное паросочетание алгоритмом Хопкрофта-Карпа:", flow.hopcroft_karp())


if __name__ == "__main__":
    main()
