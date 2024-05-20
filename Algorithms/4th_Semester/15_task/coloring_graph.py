def coloring(graph, max_colors, colors, current_vertice, n):
    if current_vertice == n:  # всё раскрашено
        return True

    for color in range(1, max_colors + 1):  # перебираем все цвета для вершины
        can_be_colored = True

        for i in range(n):  # проверка на то, что соседние вершины не имеют этот цвет
            if graph[current_vertice][i] and colors[i] == color:
                can_be_colored = False
                break

        if can_be_colored:  # если соседние вершины не имеют этот цвет, то раскрашиваем
            colors[current_vertice] = color
            
            if coloring(graph, max_colors, colors, current_vertice + 1, n):
                return True  # если при раскраске этим цветом получилось решение, то возвращаем True

            colors[current_vertice] = 0  # иначе, обнуляем цвет и пробуем другой

    return False  # если же раскрасить не получилось, то возвращаем False и пробуем либо другой цвет, либо увеличиваем хроматическое число на 1


def main():
    with open("input.txt") as mat:
        graph = [i.split() for i in mat.readlines()]
    n = len(graph)
    for i in range(len(graph)):
        graph[i] = [int(j) for j in graph[i]]
    
    # Попытка решить полным перебором
    colors = [0 for i in range(n)]  # цвета - числа

    max_colors = 1  # перебираем максимальное кол-во цветов, т.е. хроматическое число
    while True:
        if coloring(graph, max_colors, colors, 0, n):
            break
        else:
            max_colors += 1
            colors = [0 for i in range(n)]

    print("Хроматическое число", max_colors)
    print("Раскраска:")
    for i in range(n):
        print(f"    У вершины {i} цвет {colors[i]}")

if __name__ == "__main__":
    main()
