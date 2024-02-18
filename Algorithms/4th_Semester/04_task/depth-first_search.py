def depth(node, visited, graph):
    print(node)
    visited.append(node)
    for i in range(0, len(graph[node])):
        if graph[node][i] and i not in visited:
            depth(i, visited, graph)


def main():

    with open("input.txt") as mat:
        graph = [i.split() for i in mat.readlines()]
    for i in range(0, len(graph)):
        graph[i] = [int(j) for j in graph[i]]

    visited = []
    i = 1

    for startnode in range(0, len(graph)):
        if startnode not in visited:
            print(f"Компонента связности номер {i}:")
            depth(startnode, visited, graph)
            i += 1
            print("\n")


if __name__ == "__main__":
    main()
