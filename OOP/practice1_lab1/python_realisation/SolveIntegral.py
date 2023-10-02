class SolveIntegral:
    pointsQuantity = 10000  # в питоне нету приватных полей, так что переменную инициализирую так

    def __init__(self, pointsQuantity):  # в питоне конструктор класса - это __init__(), где self - это как this в C++
        self.pointsQuantity = pointsQuantity

    def solve(self, a, b, f):  # виртуальный метод можно записать так
        pass
