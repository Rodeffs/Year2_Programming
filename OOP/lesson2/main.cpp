#include "Person.h"
#include <iostream>


int main() {

    int a = 5; // копирующая инициализация
    int b(5); // прямая инициализация
    int c{5}; // инициализация списком / унифицированная

    using namespace lesson2; // здесь такое применять можно

    std::string name = "Adam";
    Date *date = new Date(2000, 4, 24);

    auto *person1 = new Person(name, Gender::MALE, *date);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
