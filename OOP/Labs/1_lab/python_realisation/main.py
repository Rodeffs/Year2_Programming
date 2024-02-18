from SolveIntegral import SolveIntegral  # в питоне для подключения других файлов писать так: from имя_файла import имя_класса
from TrapezoidMethod import TrapezoidMethod
from SimpsonMethod import SimpsonMethod
import math


def f(x):  # функцию можно передать как переменную
    return math.sin(x)


if __name__ == "__main__":
    integral1 = TrapezoidMethod(10000)
    integral2 = SimpsonMethod(10000)

    print(f"The solution via TrapezoidMethod is: {integral1.solve(2, 7, f)}\n")  # f-string
    print(f"The solution via SimpsonMethod is: {integral2.solve(2, 7, f)}\n")
