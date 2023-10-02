#pragma once
#include <iostream>

class Date {
private:
    int m_year{}, m_month{}, m_day{};

public:
    Date(int year, int month, int day);
    ~Date();
};