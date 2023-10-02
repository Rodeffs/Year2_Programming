#ifndef PRACTICE1_TRAPEZOIDMETHOD_H
#define PRACTICE1_TRAPEZOIDMETHOD_H

#include "SolveIntegral.h"

class TrapezoidMethod : public SolveIntegral { // необходимо указать public, иначе не унаследуются не виртуальные методы
public:
    double solve(double (*f)(double), double a, double b) override;
};


#endif //PRACTICE1_TRAPEZOIDMETHOD_H
