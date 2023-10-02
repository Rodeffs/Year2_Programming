#include "TrapezoidMethod.h"

double TrapezoidMethod::solve(double (*f)(double), double a, double b) {
    double step = fabs((a-b)/pointsQuantity); // шаг - это расстояние от a до b, делёное на количество точек
    double solution = 0;
    bool minus = false;

    if (b < a) { // если a > b, то меняем их значениями, а результат домножаем на минус
        minus = true;
        double temp = a;
        a = b;
        b = temp;
    }

    for (double x = a; x < b; x += step)
        solution += 0.5 * (f(x) + f(x+step)) * step; // сам метод трапеций: сумма произведения полусуммы функции в точках x(i) и x(i+1), и расстояния между этими точками

    return solution * (minus ? -1 : 1);
}
