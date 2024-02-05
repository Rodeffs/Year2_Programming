'''
Для выполнения этого задания использовался алгоритм Косарайю
Опишу алгоритм через пример:
A -> B -> C
По ходу алгоритма первый элемент здесь A, присвоим ему время входа 1, далее
идёт B, значит ему присвоим 2, в свою очередь из B следует C - присвоим
ему 3. Из C нет никаких путей, значит рекурсивно возвращаемся в B, только
теперь у B будет значение 4, т.к. в него мы пошли после C. Аналогично
идём из B в A, теперь у A значение времени 5.
Нужно теперь расположить элементы в порядке убывания их времени входа,
получаем массив меток. Далее разворачиваем граф (транспонируем его
матрицу) и в конце делаем грубинний поиск по нему, начиная от первого
элемента в массиве меток.
https://habr.com/ru/articles/537290/
'''


class Node:  # т.к. не захотел делать двумерный массив
    __value = 0
    __order = 0

    def __init__(self, val, num):
        self.__value = val
        self.__order = num

    @property
    def value(self):
        return self.__value

    @value.setter
    def value(self, val):
        self.__value = val

    @property
    def order(self):
        return self.__order

    @order.setter
    def order(self, num):
        self.__order = num


def not_within(ls, node):        # чтобы воспользоваться встроенным in пришлось
    for i in range(0, len(ls)):  # бы сделать два массива - один просто для
        if ls[i].value == node:  # посещённых вершин, а другой для их значений
            return False
    return True


def depth(node, visited, graph, order):  # самая важная часть - присваивание
    order += 1                           # времени входа в элемент
    visited.append(Node(node, 0))
    j = len(visited) - 1
    for i in range(0, len(graph[node])):
        if graph[node][i] and not_within(visited, i):
            order = 1 + depth(i, visited, graph, order)
    visited[j].order = order
    return order


def depth_print(node, visited, graph):
    print(node)
    visited.append(node)
    for i in range(0, len(graph[node])):
        if graph[node][i] and i not in visited:
            depth_print(i, visited, graph)


def transpose(graph):
    for i in range(0, len(graph)):
        for j in range(i, len(graph[i])):
            graph[i][j], graph[j][i] = graph[j][i], graph[i][j]


def insert_sort(ls):
    for i in range(1, len(ls)):
        while i > 0 and ls[i-1].order <= ls[i].order:
            if ls[i-1].order < ls[i].order:
                ls[i-1], ls[i] = ls[i], ls[i-1]
            i -= 1


def main():
    with open("input.txt") as mat:
        graph = [i.split() for i in mat.readlines()]
    for i in range(0, len(graph)):
        graph[i] = [int(j) for j in graph[i]]

    visited, assigned_order = [], []
    order, i = 0, 1

    for startnode in range(0, len(graph)):
        if not_within(assigned_order, startnode):
            order = depth(startnode, assigned_order, graph, order)

    transpose(graph)
    insert_sort(assigned_order)

    for j in range(0, len(assigned_order)):
        if assigned_order[j].value not in visited:
            print(f"Компонента связности номер {i}:")
            depth_print(assigned_order[j].value, visited, graph)
            i += 1
            print("\n")


if __name__ == "__main__":
    main()
