from random import uniform


def dfs(graph, sink, node, visited, path, paths, n):
    visited.append(node)
    path_extended = list(path)
    path_extended.append(node)

    if node == sink:
        return path_extended

    for i in range(n):
        if graph[node][i] and i not in visited:
            paths.append(dfs(graph, sink, i, visited, path_extended, paths, n))

    return paths

def ford_fulkerson(graph, source, sink, n):
    # Изначально значение потока равно 0:
    max_flow = 0
    flow_net = [[0 for i in range(n)] for j in range(n)]
    
    # Используем поиск в глубину для нахождения пути:
    paths = dfs(graph, sink, source, [], [], [], n)
    print(paths)
    for path in paths:
        max_increase = 1000

        for i in range(len(path)-1):
            v0, v1 = path[i], path[i+1]
            max_increase = min(max_increase, graph[v0][v1] - flow_net[v0][v1])

        for i in range(len(path)-1):
            v0, v1 = path[i], path[i+1]
            flow_net[v0][v1] += max_increase

        max_flow += max_increase

    return max_flow


def print_net(graph, n):
    print("Сеть (вход -> выход = пропускная способность):")
    for i in range(n):
        for j in range(n):
            bandwidth = graph[i][j]
            if bandwidth:
                print(f"    {i} -> {j} = {bandwidth}")
    print()


def find_in_net(graph, n, search):
    # Исток - вершина, в которую не ведёт ни одна другая
    # Сток - вершина, которая не ведёт ни в какую другую
    answer = 0

    for i in range(n):
        potential = True

        for j in range(n):
            if search == "source":
                potential = (graph[j][i] == 0)
            elif search == "sink":
                potential = (graph[i][j] == 0)

            if not potential:
                break

        if potential:
            answer = i
            break

    return answer


def main():

    # Задаём граф матрицей смежности:
    with open("graph.txt") as mat:
        graph = [i.split() for i in mat.readlines()]
    n = len(graph)
    for i in range(n):
        graph[i] = [int(j) for j in graph[i]]

    print_net(graph, n)
    
    source = find_in_net(graph, n, "source")
    print("Исток - вершина под индексом", source, "\n")
    
    sink = find_in_net(graph, n, "sink")
    print("Сток - вершина под индексом", sink, "\n")

    max_flow = ford_fulkerson(graph, source, sink, n)
    print("Максимальный поток равен", max_flow, "\n")
   
    # Рандомизация пропускной способности:
    for i in range(n):
        for j in range(n):
            if graph[i][j]:  # чтобы не изменить сеть
                graph[i][j] = int(uniform(100, 1000))

    print("--После рандомизации пропускной способности--\n")

    print_net(graph, n)

    max_flow2 = ford_fulkerson(graph, source, sink, n)
    print("Максимальный поток теперь равен", max_flow2, "\n")


if __name__ == "__main__":
    main()
