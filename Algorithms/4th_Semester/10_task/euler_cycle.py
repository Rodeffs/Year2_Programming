def is_eulerian(graph, n):
    # В графе есть Эйлеров цикл, если все его вершины соединены
    # чётным количеством путей

    for i in range(0, n):
        path_count = 0
        for j in range(0, n):
            if graph[i][j]:
                path_count += 1
        if path_count % 2:
            return False

    return True


def dfs(node, visited, parent, graph):
    visited.append(node)

    for i in range(0, len(graph[node])):
        if graph[node][i]:
            if i not in visited:
                if dfs(i, visited, node, graph):
                    return True
            elif parent != i:
                return True
    return False


def find_cycle(graph, node):
    visited = []

    if dfs(node, visited, -1, graph):
        visited.append(node)

        for i in range(1, len(visited)):
            prev = visited[i-1]
            cur = visited[i]

            graph[prev][cur] = 0
            graph[cur][prev] = 0

        visited.pop()

        return visited

    return [node]


def find_all_cycles(graph, node):
    euler_cycle = []
    cycle = find_cycle(graph, node)

    for i in cycle:
        euler_cycle.append(find_all_cycles(graph, i))

    return euler_cycle


def main():
    with open("input.txt") as mat:
        graph = [i.split() for i in mat.readlines()]
    for i in range(0, len(graph)):
        graph[i] = [int(j) for j in graph[i]]

    n = len(graph)

    if is_eulerian(graph, n):
        cycle = find_all_cycles(graph, 0)

        print("В графе есть Эйлеров цикл, например:")
        for i in range(1, len(cycle)):
            print(f"    {cycle[i-1]} --> {cycle[i]}")

    else:
        print("В графе нет Эйлерова цикла")


if __name__ == "__main__":
    main()
