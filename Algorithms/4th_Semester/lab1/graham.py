import math


class Point:
    __x = 0
    __y = 0
    __pol = 0.0

    def __init__(self, newx, newy):
        self.__x = newx
        self.__y = newy

    @property  # лаконичное использование декораторов
    def x(self):
        return self.__x

    @x.setter
    def x(self, newx):
        self.__x = newx

    @property
    def y(self):
        return self.__y

    @y.setter
    def y(self, newy):
        self.__y = newy

    @property
    def pol(self):
        return self.__pol

    @pol.setter
    def pol(self, Point0):
        # Полярный угол найдём через проекцию на ось абсцисс, но сначала надо сделать перенос координат
        x1, x2, y1, y2 = self.__x, Point0.x, self.__y, Point0.y
        x1 -= x2
        y1 -= y2
        x2, y2 = 0, 0
        self.__pol = math.acos(x1/math.sqrt(x1**2 + y1**2))


def distance(Point1, Point2):
    return math.sqrt((Point2.x - Point1.x)**2 + (Point2.y - Point1.y)**2)


# Сортировка по полярному углу, в случае совпадения - по расстоянию
def sortGraph(graph):
    minY = []
    curMin, swapIndex = 9999999999999, 0
    p0 = Point(0, 0)

    for i in range(0, len(graph)):
        curY = graph[i].y
        if curY <= curMin:
            if curY < curMin:
                minY.clear()
                curMin = curY
            minY.append(i)

    curMin = 9999999999999
    for j in range(0, len(minY)):
        curPoint = graph[minY[j]]
        if curPoint.x < curMin:
            curMin = curPoint.x
            p0 = curPoint
            swapIndex = minY[j]

    # Перенесём точку отсчёта в начало
    graph[0], graph[swapIndex] = graph[swapIndex], graph[0]

    # И задаём каждой точке угол поворота от точки отсчёта
    for i in range(1, len(graph)):
        graph[i].pol = p0

    # Сортировка вставкой
    for i in range(1, len(graph)):
        j = i
        while j > 1 and graph[j-1].pol >= graph[j].pol:
            if graph[j-1].pol == graph[j].pol and distance(p0, graph[j-1]) <= distance(p0, graph[j]):
                break
            graph[j-1], graph[j] = graph[j], graph[j-1]
            j -= 1


# Условие левого поворота, исходя из векторного произведения
def leftRotation(p1, p2, p3):
    a_x = p2.x - p1.x
    a_y = p2.y - p1.y
    b_x = p3.x - p2.x
    b_y = p3.y - p2.y
    return (a_x*b_y - a_y*b_x) > 0  # в случае =0 все 3 точки лежат на прямой, а в <0 - правый поворот


# Сам алгоритм Грэхема
def Graham(graph):
    convexhull = []
    convexhull.append(graph[0])
    convexhull.append(graph[1])

    # Суть его в том, чтобы удалить вершины, которые не являются вершинами выпуклой оболочки путём сначала
    # сортировки всех вершин по полярному углу от точки в левом нижнем углу, а затем проверки, будут ли
    # последовательно идущие вершины совершать левый поворот, т.е. путь от точки до точки должен как бы заворачивать налево
    for i in range(2, len(graph)):
        top, pretop = convexhull[-1], convexhull[-2]

        while len(convexhull) >= 2 and not leftRotation(pretop, top, graph[i]):
            convexhull.pop()
            if len(convexhull) >= 2:
                top, pretop = convexhull[-1], convexhull[-2]

        convexhull.append(graph[i])

    return convexhull


def main():
    graph = [Point(0, 0), Point(0, 100), Point(100, 0), Point(50, 50), Point(3, 0), Point(5, 0), Point(1, 0), Point(0, 3), Point(0, 1), Point(0, 8),
             Point(15, 20)]

    if len(graph) < 3:
        print("Слишком мало точек, нужно минимум 3")
        return

    sortGraph(graph)
    convexhull = Graham(graph)

    # Для того, чтобы была выпуклая оболочка, минимум одна точка не должна лежать на одной прямой с остальными
    if len(convexhull) < 3:
        print("Выпуклой оболочки нет")
    else:
        print("Выпуклая оболочка выглядит так:\n")
        for i in range(0, len(convexhull)):
            print(f"{i+1}. Point(x = {convexhull[i].x}, y = {convexhull[i].y}, angle = {convexhull[i].pol})\n")


if __name__ == "__main__":
    main()
