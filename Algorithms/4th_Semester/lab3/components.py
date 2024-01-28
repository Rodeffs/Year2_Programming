def main():

    with open("input.txt") as mat:
        graph = [i.split() for i in mat.readlines()]
    for i in range(0, len(graph)):
        graph[i] = [int(j) for j in graph[i]]

    queue, visited, component = [], [], []
    i = 1

    for startnode in range(0, len(graph)):
        if startnode not in visited:
            queue.append(startnode)

        while queue:
            node = queue[0]
            visited.append(node)
            component.append(node)
            queue.pop(0)
            for j in range(0, len(graph[node])):
                if graph[node][j] and j not in visited and j not in queue:
                    queue.append(j)

        if component:
            print(f"Компонента связности номер {i} состоит из {len(component)} элементов:\n", component, "\n")
            component.clear()
            i += 1


if __name__ == "__main__":
    main()
