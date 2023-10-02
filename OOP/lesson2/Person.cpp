#include "Person.h"

lesson2::Person::Person(std::string& name, Gender gender, Date& date) : m_name(name), m_gender(gender), m_date(date) { // нужно использовать инициализацию для констант
    std::cout << "new person constructed" << std::endl;
}

lesson2::Person::~Person() {
    std::cout << "new person deleted" << std::endl;
}
