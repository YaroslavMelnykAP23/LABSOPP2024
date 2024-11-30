#include "Date_Lab10.h"
#include <stdexcept>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <iostream>
#include <limits>

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {
    if (!isValidDate(day, month, year)) {
        throw std::invalid_argument("Некоректна дата!");
    }
    calculateWeekday();
}

Date::Date() : day(1), month(1), year(1900), weekday(0) {}

Date::~Date() {}

int Date::getDay() const { return day; }
int Date::getMonth() const { return month; }
int Date::getYear() const { return year; }
int Date::getWeekday() const { return weekday; }

void Date::calculateWeekday() {
    std::tm time_in = {0, 0, 0, day, month - 1, year - 1900};
    std::mktime(&time_in);
    weekday = time_in.tm_wday;
}

bool Date::isValidDate(int day, int month, int year) const {
    if (month < 1 || month > 12 || year < 0)
        return false;
    static const int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int max_days = days_in_month[month - 1];
    if (month == 2 && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))) {
        max_days = 29; // Високосний рік
    }
    return day >= 1 && day <= max_days;
}

bool Date::inputFromKeyboard() {
    std::cout << "Введіть дату через пробіл (день місяць рік): ";
    int d, m, y;
    std::cin >> d >> m >> y;

    if (std::cin.fail() || !isValidDate(d, m, y)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Некоректна дата! Спробуйте ще раз.\n";
        return false;
    }

    day = d;
    month = m;
    year = y;
    calculateWeekday();
    return true;
}

bool Date::operator<=(const Date& other) const {
    return weekday <= other.weekday;
}

Date Date::operator+(int targetWeekday) const {
    int daysForward = (targetWeekday - weekday + 7) % 7;
    int daysBackward = (weekday - targetWeekday + 7) % 7;

    // Вибір ближчої дати
    int daysToAdd = daysForward <= daysBackward ? daysForward : -daysBackward;
    std::tm time_in = {0, 0, 0, day + daysToAdd, month - 1, year - 1900};
    std::mktime(&time_in);

    return Date(time_in.tm_mday, time_in.tm_mon + 1, time_in.tm_year + 1900);
}

std::string Date::toString() const {
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << day << "/"
        << std::setw(2) << std::setfill('0') << month << "/"
        << year << " (День тижня: " << weekday << ")";
    return oss.str();
}
