#include "Date_Lab10.h"
#include <stdexcept>
#include <sstream>
#include <iomanip>

#include <ctime>

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {
    calculateWeekday();
}

Date::~Date() {}

// Гетери
int Date::getDay() const { return day; }
int Date::getMonth() const { return month; }
int Date::getYear() const { return year; }
int Date::getWeekday() const { return weekday; }

// Вирахування дня тижня
void Date::calculateWeekday() {
    std::tm time_in = { 0, 0, 0, day, month - 1, year - 1900 };
    std::mktime(&time_in);
    weekday = time_in.tm_wday; // 0 - неділя, ..., 6 - субота
}

// Перевантаження операторів
bool Date::operator<=(const Date& other) const {
    return weekday <= other.weekday;
}

Date Date::operator+(int targetWeekday) const {
    int daysToAdd = (targetWeekday - weekday + 7) % 7;
    std::tm time_in = { 0, 0, 0, day + daysToAdd, month - 1, year - 1900 };
    std::mktime(&time_in);
    return Date(time_in.tm_mday, time_in.tm_mon + 1, time_in.tm_year + 1900);
}

// Форматування дати
std::string Date::toString() const {
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << day << "/"
        << std::setw(2) << std::setfill('0') << month << "/"
        << year << " (День тижня: " << weekday << ")";
    return oss.str();
}
