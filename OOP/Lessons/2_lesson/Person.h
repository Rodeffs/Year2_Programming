#ifndef LESSON2_PERSON_H
#define LESSON2_PERSON_H

#include "Date.h"
#include <string>
#include <iostream>

namespace lesson2 { // запишем всё в пространство имён, чтобы не было переобозначений

    // Пишем через класс, чтобы их нельзя было сравнивать, иначе получилось бы, что MALE == JANUARY
    enum class Gender : char {
        MALE, FEMALE, OTHER
    }; // пишем char чтобы занимать минимум памяти
    enum class Month : char {
        JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER
    };

    class Person {
    private:
        const std::string m_name;
        const Gender m_gender;
        const Date m_date;
    public:
        Person(std::string& name, Gender gender, Date& date); // передаём по ссылке, чтобы сэкономить память

        ~Person();
    };
}

#endif //LESSON2_PERSON_H
