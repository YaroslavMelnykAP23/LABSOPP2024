#ifndef DATE_H_LAB10
#define DATE_H_LAB10

#include <string>

class Date {
private:
    int day;
    int month;
    int year;
    int weekday; // День тижня (0 - неділя, 1 - понеділок, ..., 6 - субота)

    void calculateWeekday(); // Вираховує день тижня для заданої дати

public:
    Date(int day, int month, int year);
    ~Date();

    // Гетери
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    int getWeekday() const;

    // Перевантаження операторів
    bool operator<=(const Date& other) const; // Порівняння за днем тижня
    Date operator+(int targetWeekday) const;  // Пошук найближчої дати

    // Форматований вивід
    std::string toString() const;
};

#endif // DATE_H_LAB10