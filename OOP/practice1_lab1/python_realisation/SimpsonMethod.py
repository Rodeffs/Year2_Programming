from SolveIntegral import SolveIntegral


class SimpsonMethod(SolveIntegral):

    def __init__(self, pointsQuantity):
        super().__init__(pointsQuantity)

    def solve(self, a, b, f):
        return (b - a)*(f(a) + 4*f(0.5*(a + b)) + f(b))/6
