from random import uniform


class Flow:
    def __init__(self, arr):
        self.paths = []
        self.graph = arr
        self.n = len(arr)
        self.source = self.find_source()
        self.sink = self.find_sink()
        self.max_flow = self.ford_fulkerson()

    def find_source(self):
        # Исток - вершина, в которую не ведёт ни одна другая
        source = 0

        for i in range(self.n):
            potential = True

            for j in range(self.n):
                potential = (self.graph[j][i] == 0)

                if not potential:
                    break

            if potential:
                source = i
                break

        return source
    
    def find_sink(self):
        # Сток - вершина, которая не ведёт ни в какую другую
        sink = 0

        for i in range(self.n):
            potential = True

            for j in range(self.n):
                potential = (self.graph[i][j] == 0)

                if not potential:
                    break

            if potential:
                sink = i
                return sink

    def dfs(self, node, visited, path):
        path_extended = path + [node]

        if node == self.sink:
            self.paths.append(path_extended)
            return

        visited_extended = visited + [node]
        for i in range(self.n):
            if self.graph[node][i] and i not in visited_extended:
                self.dfs(i, visited_extended, path_extended)

    def ford_fulkerson(self):
        max_flow = 0  # изначально значение потока равно 0
        net = [list(self.graph[i]) for i in range(self.n)]  # чтобы не изменить исходный граф
        
        # Используем поиск в глубину для нахождения пути:
        self.dfs(self.source, [], [])

        # Сам алгоритм: проходимся по каждому пути в графе, уменьшая поток по нему
        # на значение минимальной пропускной способности, а обратный поток наоборот,
        # увеличиваем на это значение. Это нужно затем, чтобы можно было разгрузить
        # ребро, если поток его перегрузит
        for path in self.paths:
            max_increase = float("inf")

            for i in range(len(path)-1):
                v0, v1 = path[i], path[i+1]
                max_increase = min(max_increase, net[v0][v1])

            for i in range(len(path)-1):
                v0, v1 = path[i], path[i+1]
                net[v0][v1] -= max_increase
                net[v1][v0] += max_increase

            max_flow += max_increase

        return max_flow

    def get_source(self):
        return self.source

    def get_sink(self):
        return self.sink

    def get_max_flow(self):
        return self.max_flow

    def print_flow(self):
        print("Сеть (вход -> выход = пропускная способность):")
        for i in range(self.n):
            for j in range(self.n):
                bandwidth = self.graph[i][j]
                if bandwidth:
                    print(f"    {i} -> {j} = {bandwidth}")
        print()


def main():

    # Задаём граф матрицей смежности:
    with open("graph.txt") as mat:
        graph = [i.split() for i in mat.readlines()]
    n = len(graph)
    for i in range(n):
        graph[i] = [int(j) for j in graph[i]]
    
    flow = Flow(graph)

    flow.print_flow()
    
    source = flow.get_source()
    print("Исток - вершина под индексом", source, "\n")
    
    sink = flow.get_sink()
    print("Сток - вершина под индексом", sink, "\n")

    max_flow = flow.get_max_flow()
    print("Максимальный поток равен", max_flow, "\n")
   
    # Рандомизация пропускной способности:
    for i in range(n):
        for j in range(n):
            if graph[i][j]:  # чтобы не изменить сеть
                graph[i][j] = int(uniform(100, 1000))

    flow2 = Flow(graph)

    print("--После рандомизации пропускной способности--\n")

    flow2.print_flow()

    max_flow2 = flow2.get_max_flow()
    print("Максимальный поток теперь равен", max_flow2, "\n")


if __name__ == "__main__":
    main()
