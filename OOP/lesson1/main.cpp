#include <iostream>
#include "figure.h"
#include <string>

int main() {

    // f-string:
    std::string name = "MyName";
    std::string hello = "Hello, " + name; // к сожалению в C++ fstring нет

    // Figure* figure1 = new Figure(); - указатель нужен, т.к. здесь new, т.е. мы создаём объект через указатель, чтобы не копировать весь класс
    auto figure1 = new Figure(); // аналогичная запись, что выше

    figure1->x = 100; // если переменные публичные, то мы их можем изменить здесь
    figure1->y = 200;

    auto var1 = figure1->x;

    figure1->level = Level::HIGH;

    auto x1 = figure1->getX();
    figure1->setX(1233223);

    // и т.д. и т.п., короче, Тарачков и Копытов рассказали всё то же самое лучше

    return 0;
}
