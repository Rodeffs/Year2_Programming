def main():
    with open("input.txt") as mat:
        graph = [i.split() for i in mat.readlines()]
    for i in range(0, len(graph)):
        graph[i] = [int(j) for j in graph[i]]

    total_nodes = len(graph)

    start = int(input(f"Введите номер вершины от 0 до {total_nodes-1}, от которой искать пути: "))

    queue = {}  # приоритетная очередь
    for i in range(0, total_nodes):
        if i == start:
            queue[i] = 0
        else:
            queue[i] = 99999999999

    while len(queue) > 0:
        closest = min(queue.items(), key=lambda x: x[1])  # ближайший элемент
        node, mark = closest[0], closest[1]

        for i in range(0, total_nodes):
            path = graph[node][i]
            if path and (i in queue.keys()):
                if mark + path < queue[i]:
                    queue[i] = mark + path

        if start != node:
            print(f"Кратчайшее расстояние от {start} до {node} равно {mark}")
        queue.pop(node)


if __name__ == "__main__":
    main()
