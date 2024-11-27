#include "receipt_Lab8.h"

// Базовий клас
// Конструктор
BaseReceipt::BaseReceipt(int num, const std::string& d) : number(num), date(d) {}

// Деструктор
BaseReceipt::~BaseReceipt() {}

// Геттери і сеттери
int BaseReceipt::getNumber() const { return number; }
void BaseReceipt::setNumber(int num) { number = num; }

std::string BaseReceipt::getDate() const { return date; }
void BaseReceipt::setDate(const std::string& d) { date = d; }

// Метод для введення даних
void BaseReceipt::inputReceipt() {
    int num;
    std::string d;
    std::cout << "Введіть номер квитанції: ";
    std::cin >> num;
    setNumber(num);

    std::cout << "Введіть дату (YYYY-MM-DD): ";
    std::cin >> d;
    setDate(d);
}

// Метод для виведення даних
void BaseReceipt::printReceipt() const {
    std::cout << "Номер квитанції: " << getNumber() << std::endl;
    std::cout << "Дата: " << getDate() << std::endl;
}

// Похідний клас
// Конструктор
Receipt::Receipt(int num, const std::string& d, double amt) 
    : BaseReceipt(num, d), amount(amt) {}

// Деструктор
Receipt::~Receipt() {}

// Геттери і сеттери
double Receipt::getAmount() const { return amount; }
void Receipt::setAmount(double amt) { amount = amt; }

// Метод для введення даних
void Receipt::inputReceipt() {
    BaseReceipt::inputReceipt();

    double amt;
    std::cout << "Введіть суму до сплати: ";
    std::cin >> amt;

    // Перевірка валідності суми
    while (amt < 0) {
        std::cout << "Сума не може бути від'ємною. Спробуйте ще раз: ";
        std::cin >> amt;
    }

    setAmount(amt);
}

// Метод для виведення даних
void Receipt::printReceipt() const {
    BaseReceipt::printReceipt();
    std::cout << "Сума до сплати: " << getAmount() << std::endl;
}
