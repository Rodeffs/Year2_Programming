#include "figure.h"
#include <iostream>

void Figure::setX(int x) {
    this->x = x;

    if (x<0)
        throw new std::exception("incorrect value"); // обработка ошибок, почему-то не работает, видимо из-за стандарта C++
}

int Figure::getX() {
    return x;
}
