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

    def bfs(self, parent, net):
        # Помечаем все вершины как не посещённые
        visited = [False]*(self.n)
 
        # Помечаем исток как посещённый
        queue = [self.source]
        visited[self.source] = True
 
        while queue:
            u = queue.pop(0)
 
            # Находим прилегающие вершины к вершине u и посещаем их, если ещё этого не сделали
            for ind, val in enumerate(net[u]):
                if visited[ind] == False and val > 0:
                    # Если есть связь с sink, то сразу оканчиваем bfs
                    queue.append(ind)
                    visited[ind] = True
                    parent[ind] = u
                    if ind == self.sink:
                        return True
 
        return False

    def ford_fulkerson(self):
        max_flow = 0  # изначально значение потока равно 0
        net = [list(self.graph[i]) for i in range(self.n)]  # чтобы не изменить исходный граф
        
        # Этот массив заполняем в bfs (поиск в ширину) для сохранения путей
        parent = [-1]*(self.n)

        # Сам алгоритм: проходимся по каждому пути в графе, уменьшая поток по нему
        # на значение минимальной пропускной способности, а обратный поток наоборот,
        # увеличиваем на это значение. Это нужно затем, чтобы можно было разгрузить
        # ребро, если поток его перегрузит
        while self.bfs(parent, net):
            max_increase = float("Inf")
            
            current = self.sink
            while(current !=  self.source):
                max_increase = min(max_increase, net[parent[current]][current])
                current = parent[current]
 
            max_flow +=  max_increase
 
            current = self.sink
            while(current !=  self.source):
                previous = parent[current]
                net[previous][current] -= max_increase
                net[current][previous] += max_increase
                current = parent[current]

        return max_flow

    def remove_from_list(self, arr, node):  # утобы не пытаться разрезать грани, ведущие в эту вершину
        copy = [list(arr[i]) for i in range(len(arr))]  # чтобы не изменить исходный граф
        for elem in copy:
            if elem[1] == node:
                arr.remove(elem)

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
        queue, cut = [self.source], []

        while queue:
            node = queue[0]
            queue.pop(0)
            self.remove_from_list(cut, node)

            for j in range(self.n):
                if self.graph[node][j]:
                    queue.append(j)
                    potential_cut = [node, j]
                    if potential_cut not in cut:
                        cut.append([node, j])

            if self.try_to_remove(cut):
                break  # да, можно было тут return прописать, но иначе pyright ругается

        return cut

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
    
    mincut = flow.get_min_cut()
    if mincut:
        print("Соответствующий ему минимальный разрез:")
        for cut in mincut:
            x, y = cut[0], cut[1]
            print(f"    {x} -> {y} = {graph[x][y]}")
        print()


if __name__ == "__main__":
    main()
