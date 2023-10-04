#include <iostream>
#include "SolveIntegral.h"
#include "TrapezoidMethod.h"
#include "SimpsonMethod.h"

using namespace std; // так лучше не делать, но я не собираюсь переопределять стандартные функции

double f(double x) { // функция, от которой считаем интеграл
    return sin(x);
}

int main() {
    auto *integral1 = new TrapezoidMethod;
    auto *integral3 = new SimpsonMethod;

//    integral1->setQuantity(10000); // устанавливаем число точек, если нужна большая точность
    cout << "The solution for the integral via trapezoid method is: " << integral1->solve(&f, 2, 7) << endl;
    cout << "The solution for the integral via Simpson method is: " << integral3->solve(&f, 2, 7) << endl;

    return 0;
}
