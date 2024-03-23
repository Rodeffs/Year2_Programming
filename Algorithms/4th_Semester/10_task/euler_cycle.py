def is_eulerian(graph, n):
    # В графе есть Эйлеров цикл, если все его вершины соединены
    # чётным количеством путей

    for i in range(n):
        path_count = 0
        for j in range(n):
            if graph[i][j]:
                path_count += 1
        if path_count % 2:
            return False

    return True


def dfs_count(node, visited, graph):  # для подсчёта достигаемых вершин
    reachable_vertices = 1
    visited.append(node)
    for i in range(0, len(graph[node])):
        if graph[node][i] and i not in visited:
            reachable_vertices += dfs_count(i, visited, graph)
    return reachable_vertices


def remove_path(begin, end, graph):
    graph[begin][end] = 0
    graph[end][begin] = 0


def copy_2d_list(ls, n):  # list() не работает для многомерных списков
    copy = [list(ls[i]) for i in range(n)]
    return copy


def main():
    with open("input.txt") as mat:
        graph = [i.split() for i in mat.readlines()]
    for i in range(len(graph)):
        graph[i] = [int(j) for j in graph[i]]

    n = len(graph)

    if is_eulerian(graph, n):

        # Fleury's Algorithm:
        # 1) Находимся в вершине v
        # 2.1) Если из неё идёт только один путь, то выбираем его
        # 2.2) Если их несколько, то выбираем путь, не являющийся мостом
        # Путь является мостом, если вершина, в которую он ведёт, станет
        # недоступной, если этот путь убрать
        # 3) Идём по выбранному пути и удаляем его

        node = 0

        print("В графе есть Эйлеров цикл:")

        while True:
            reachable_nodes = []

            for i in range(n):
                if graph[node][i]:
                    reachable_nodes.append(i)

            count_paths = len(reachable_nodes)

            if not count_paths:
                break

            elif count_paths == 1:
                next_node = reachable_nodes[0]
                remove_path(node, next_node, graph)
                print(f"{node} --> {next_node}")
                node = next_node

            else:
                initial_node_count = dfs_count(node, [], graph)

                for potential_path in reachable_nodes:
                    graph_copy = copy_2d_list(graph, n)
                    remove_path(node, potential_path, graph_copy)

                    if dfs_count(node, [], graph_copy) == initial_node_count:
                        remove_path(node, potential_path, graph)
                        print(f"{node} --> {potential_path}")
                        node = potential_path
                        break

    else:
        print("В графе нет Эйлерова цикла")


if __name__ == "__main__":
    main()
