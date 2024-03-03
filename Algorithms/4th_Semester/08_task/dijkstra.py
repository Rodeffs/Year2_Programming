def main():
    with open("input.txt") as mat:
        graph = [i.split() for i in mat.readlines()]
    for i in range(0, len(graph)):
        graph[i] = [int(j) for j in graph[i]]

    total_nodes = len(graph)

    print(f"В графе всего {total_nodes} вершин. Введите вершину (отсчёт от 0), от которой искать кратчаший путь:")
    while True:
        start = int(input())
        if start < 0 or start >= total_nodes:
            print("Такой вершины в графе нет. Попробуйте ещё раз")
        else:
            break

    nodes = {}
    for i in range(0, total_nodes):
        if i == start:
            nodes[i] = 0
        else:
            nodes[i] = 99999999999

    priority_queue = dict(nodes)  # это и есть приоритетная очередь
    while len(priority_queue) > 0:
        closest_node = min(priority_queue.items(), key=lambda value: value[1])  # элемент с наименьшей маркой
        cur_node, mark = closest_node[0], closest_node[1]

        for i in range(0, total_nodes):
            cur_path = graph[cur_node][i]
            if cur_path and (i in priority_queue.keys()):
                if mark + cur_path < nodes[i]:
                    nodes[i] = mark + cur_path
                    priority_queue[i] = mark + cur_path

        priority_queue.pop(cur_node)

    for i in range(0, total_nodes):
        if i != start:
            print(f"Кратчайшее расстояние от вершины {start} до {i} равно {nodes[i]}")


if __name__ == "__main__":
    main()
