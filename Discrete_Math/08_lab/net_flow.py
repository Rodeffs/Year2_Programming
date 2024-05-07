from random import uniform

class Edge:
    def __init__(self, begin, end, bandwidth):
        self.__begin = begin
        self.__end = end
        self.__bandwidth = bandwidth

    @property
    def begin(self):
        return self.__begin

    @begin.setter
    def begin(self, val):
        self.__begin = val

    @property
    def end(self):
        return self.__end

    @end.setter
    def end(self, val):
        self.__end = val

    @property
    def bandwidth(self):
        return self.__bandwidth

    @bandwidth.setter
    def bandwidth(self, val):
        self.__bandwidth = val


class Flow:
    def __init__(self, arr):
        self.paths = []
        self.graph = arr
        self.n = len(arr)
        self.source = self.find_source()
        self.sink = self.find_sink()
        self.max_flow = self.ford_fulkerson()
        self.min_cut = self.find_mincut_with_bfs()

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

    def try_to_remove(self, arr):
        flow_val = 0

        for x in arr:
            flow_val += self.graph[x[0]][x[1]]

        if flow_val == self.max_flow:
            return True

        return False


    def find_mincut_with_bfs(self):  # по теореме Форда-Фулкерсона, пропускная способность мин. разреза = макс. поток
        # Чтобы не проверять двудольность, я решил просто через поиск в ширину идти от source до sink и пытаться удалить
        # грани, сумма пропускной способности которых равна максимальному потоку
        # Плюс по условию сказано найти ОДИН такой разрез, так что пойдёт
        # Т.к. граф ориентированный, то проверку на посещённые вершины делать не надо
        queue, cut, previous = [self.source], [], self.source

        while queue:
            node = queue[0]
            queue.pop(0)

            if node != self.source:  # лень писать try catch
                cut.remove((previous, node))

            for j in range(self.n):
                if self.graph[node][j]:
                    queue.append(j)
                    cut.append((node, j))

            if self.try_to_remove(cut):
                return cut

            previous = node

    def print_flow(self):
        print("Сеть (вход -> выход = пропускная способность):")
        for i in range(self.n):
            for j in range(self.n):
                bandwidth = self.graph[i][j]
                if bandwidth:
                    print(f"    {i} -> {j} = {bandwidth}")
        print()

    def randomize(self):
        for i in range(self.n):
            for j in range(self.n):
                if self.graph[i][j]:  # чтобы не изменить сеть
                    self.graph[i][j] = int(uniform(100, 1000))
        self.max_flow = self.ford_fulkerson()
        self.min_cut = self.find_mincut_with_bfs()
    
    def get_source(self):
        return self.source

    def get_sink(self):
        return self.sink

    def get_max_flow(self):
        return self.max_flow

    def get_min_cut(self):
        return self.min_cut


def main():

    # Задаём граф матрицей смежности:
    with open("graph.txt") as mat:
        graph = [i.split() for i in mat.readlines()]
    n = len(graph)
    for i in range(n):
        graph[i] = [int(j) for j in graph[i]]
    
    flow = Flow(graph)

    flow.print_flow()
    
    print("Исток - вершина под индексом", flow.get_source(), "\n")
    
    print("Сток - вершина под индексом", flow.get_sink(), "\n")

    print("Максимальный поток равен", flow.get_max_flow(), "\n")

    print("Соответствующий ему минимальный разрез:")
    mincut = flow.get_min_cut()
    for cut in mincut:
        x, y = cut[0], cut[1]
        print(f"    {x} -> {y} = {graph[x][y]}")
    print()
   
    print("--После рандомизации пропускной способности--\n")

    # Рандомизация пропускной способности:
    flow.randomize()

    flow.print_flow()

    print("Максимальный поток теперь равен", flow.get_max_flow(), "\n")

    print("Соответствующий ему минимальный разрез:")
    mincut = flow.get_min_cut()
    for cut in mincut:
        x, y = cut[0], cut[1]
        print(f"    {x} -> {y} = {graph[x][y]}")
    print()


if __name__ == "__main__":
    main()
