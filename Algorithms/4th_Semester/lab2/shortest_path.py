def not_in(elem, ls):
    for i in range(0, len(ls)):
        if ls[i][0] == elem:
            return False
    return True


def main():

    with open("input.txt") as mat:
        graph = [i.split() for i in mat.readlines()]
    for i in range(0, len(graph)):
        graph[i] = [int(j) for j in graph[i]]

    startnode = int(input(f"В графе всего {len(graph)} вершин, от 0 до {len(graph)-1} включительно.\nВыберете из которой из них посчитать кратчайшее расстояние до всех остальных:\n"))
    queue, visited = [[startnode, 0]], []
    node = 0

    # Суть поиска в ширину - добавлять в конец очереди те элементы, в которые мы можем попасть из нынешнего, затем идти по очереди сначала, удаляя пройденные элементы
    # Также мы должны помнить, в какие элементы уже ходили, и какие элементы уже в очереди, чтобы не дублироваться
    # Но т.к. по заданию нам нужно ещё считать кратчайший путь, то надо знать на какой итерации цикла был добавлен элемент, чтобы правильно считать расстояния
    # Для этого я как раз и сделал список queue двумерным, но поэтому пришлось сделать костыль в виде функции not_in(), иначе нельзя проверить элемент на повтор и на наличие в очереди
    while queue:
        node = queue[0]
        queue.pop(0)
        for j in range(0, len(graph[node[0]])):
            if graph[node[0]][j] and not_in(j, visited) and not_in(j, queue):
                queue.append([j, node[1]+1])
                visited.append([j, node[1]+1])

    print("\n")
    for i in range(0, len(visited)):
        print(f"Кратчайшее расстояние от вершины {startnode} до вершины {visited[i][0]} равно {visited[i][1]}\n")


if __name__ == '__main__':
    main()
