#ifndef PRACTICE1_SOLVEINTEGRAL_H
#define PRACTICE1_SOLVEINTEGRAL_H

#include <stdexcept>
#include <cmath>


class SolveIntegral {
protected:
    signed int pointsQuantity = 10000; // сколько точек проходим, чем больше, тем ответ точнее

public:
    SolveIntegral();

    ~SolveIntegral();

    virtual double solve(double (*f)(double), double a, double b); // virtual необходимо писать для абстрактных классов

    void setQuantity(int x);

    int getQuantity();
};


#endif //PRACTICE1_SOLVEINTEGRAL_H
