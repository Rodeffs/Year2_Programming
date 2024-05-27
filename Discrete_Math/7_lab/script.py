from random import uniform


def main():
    createGraphAndPrintResults(1200)
    createGraphAndPrintResults(3200)
    createGraphAndPrintResults(8000)
    createGraphAndPrintResults(20000)
    createGraphAndPrintResults(50000)


def createGraphAndPrintResults(graphSize):
    maxDistance = 1000
    graph = createGraph(graphSize, 10, 100, maxDistance)
    addCompleteGraph(graph, 6, maxDistance)

    graphDegree = getGraphDegree(graph)
    dijkstraIterations = dijkstraAlgorithm(graph, 0)[1]
    bellmanFordIterations = bellmanFordAlgorithm(graph, 0)[1]
    with open(f"{graphSize}_results.txt", "w+") as file:
        file.write(f"Graph degree: {graphDegree}\n")
        file.write(f"Dijkstra algorithm iterations count: {dijkstraIterations}\n")
        file.write(f"Bellman-Ford algorithm iterations count: {bellmanFordIterations}\n")


def createGraph(size, expectedDegreeMin, expectedDegreeMax, maxDistance):
    graph = [[0 for j in range(size)] for i in range(size)]
    for i in range(size):
        lastIndex = i + 1
        nonZeroElementsInRow = int(min(uniform(expectedDegreeMin / 2, expectedDegreeMax / 2), size - i - 1))
        while (nonZeroElementsInRow > 0):
            lastIndex = int(uniform(lastIndex + 1, size - nonZeroElementsInRow - 1))
            graph[i][lastIndex] = int(uniform(1, maxDistance))
            graph[lastIndex][i] = graph[i][lastIndex]
            nonZeroElementsInRow -= 1
    for i in range(size - 1):
        graph[i][i+1] = int(uniform(1, maxDistance))
        graph[i+1][i] = graph[i][i+1]
    return graph


def addCompleteGraph(graph, completeGraphSize, maxDistance):
    positionToAddGraph = int(uniform(0, len(graph) - completeGraphSize))
    for i in range(positionToAddGraph, positionToAddGraph + completeGraphSize):
        for j in range(positionToAddGraph, positionToAddGraph + completeGraphSize):
            if (i == j):
                continue
            graph[i][j] = int(uniform(1, maxDistance))


def getGraphDegree(graph):
    totalDegree = 0
    size = len(graph)
    for row in graph:
        for element in row:
            if (element):
                totalDegree += 1

    return totalDegree / size


def dijkstraAlgorithm(graph, originNode):
    totalIterationsCount = 0

    result = {originNode: 0}
    queue = {}
    for i in range(len(graph)):
        if (i == originNode):
            queue[i] = 0
            continue
        queue[i] = float("inf")

    accessibleNodes = getAccessibleNodes(graph)

    while len(queue) > 0:
        closest = min(queue.items(), key=lambda x: x[1])
        totalIterationsCount += len(queue)
        node, mark = closest[0], closest[1]
        for secondNode in accessibleNodes[node]:
            totalIterationsCount += 1
            if (secondNode not in queue):
                continue
            path = graph[node][secondNode]
            queue[secondNode] = min(queue[secondNode], mark + path)

        result[node] = queue[node]
        queue.pop(node)

    return (result, totalIterationsCount)


def bellmanFordAlgorithm(graph, originNode):
    totalIterationsCount = 0

    result = []
    for i in range(len(graph)):
        if (i == originNode):
            result.append(0)
            continue
        result.append(float("inf"))

    accessibleNodes = getAccessibleNodes(graph)
    for i in range(len(graph)):
        for startingNode in range(len(graph)):
            for secondNode in accessibleNodes[startingNode]:
                totalIterationsCount += 1
                path = graph[startingNode][secondNode]
                result[secondNode] = min(result[secondNode], result[startingNode] + path)

    return (result, totalIterationsCount)


def getAccessibleNodes(graph):
    accessibleNodes = []
    for currentNode in range(len(graph)):
        accessibleNodes.append([])
        for secondNode in range(len(graph)):
            if (graph[currentNode][secondNode]):
                accessibleNodes[currentNode].append(secondNode)
    return accessibleNodes


if __name__ == "__main__":
    main()
