from SolveIntegral import SolveIntegral
import math


class TrapezoidMethod(SolveIntegral):

    def __init__(self, pointsQuantity):
        super().__init__(pointsQuantity)  # super - наследует методы и переменные родительского класса

    def solve(self, a, b, f):
        step = math.fabs((a-b)/self.pointsQuantity)  # шаг - это расстояние от a до b, делёное на количество точек
        solution = 0
        minus = False

        if b < a:
            minus = True
            a, b = b, a

        x = a
        while x < b:
            solution += 0.5 * (f(x) + f(x+step)) * step  # сам метод трапеций: сумма произведения полусуммы функции в точках x(i) и x(i+1), и расстояния между этими точками
            x += step

        return solution * (-1 if minus else 1)

