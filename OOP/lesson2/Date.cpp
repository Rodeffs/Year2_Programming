#include "Date.h"

Date::Date(int year, int month, int day) : m_year(year), m_month(month), m_day(day) {
    std::cout << "new date constructed" << std::endl;
}

Date::~Date() {
    std::cout << "new date deleted" << std::endl;
}