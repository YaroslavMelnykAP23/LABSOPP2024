#include "Receipt_Lab6.h"
#include <iomanip>
#include <regex>

// Конструктор
Receipt::Receipt() : currentCount(0) {}

// Деструктор
Receipt::~Receipt() {
    std::cout << "Receipt знищено." << std::endl;
}

// Додавання нової квитанції
void Receipt::addReceipt() {
    if (currentCount >= SIZE) {
        std::cerr << "Досягнуто максимальну кількість квитанцій!" << std::endl;
        return;
    }

    receipt_t newReceipt;
    std::cout << "Введіть номер квитанції: ";
    std::cin >> newReceipt.id;

    std::cout << "Введіть дату (у форматі YYYY-MM-DD): ";
    std::cin >> newReceipt.date;
    if (!validateDate(newReceipt.date)) {
        std::cerr << "Некоректний формат дати!" << std::endl;
        return;
    }

    std::cout << "Введіть суму до сплати: ";
    std::cin >> newReceipt.amount;

    if (newReceipt.amount < 0) {
        std::cerr << "Сума не може бути від'ємною!" << std::endl;
        return;
    }

    receipts[currentCount++] = newReceipt;
}

// Виведення всіх квитанцій
void Receipt::printReceipts() const {
    if (currentCount == 0) {
        std::cout << "Список квитанцій порожній." << std::endl;
        return;
    }

    // Заголовок таблиці
    std::cout << std::left
              << std::setw(10) << "Номер"      
              << std::setw(15) << "Дата" 
              << std::setw(15) << "Сума до сплати" << std::endl;

    // Розділова лінія
    std::cout << std::string(40, '-') << std::endl;

    // Вивід кожної квитанції
    for (int i = 0; i < currentCount; ++i) {
        const auto &r = receipts[i];
        std::cout << std::left
                  << std::setw(10) << r.id                    // Номер квитанції
                  << std::setw(15) << r.date                  // Дата
                  << std::fixed << std::setprecision(2)       // Дві цифри після коми для суми
                  << std::setw(15) << r.amount << std::endl;  // Сума до сплати
    }
}

// Редагування квитанції
void Receipt::modifyReceipt(int id) {
    for (int i = 0; i < currentCount; ++i) {
        if (receipts[i].id == id) {
            std::cout << "Знайдено квитанцію. Введіть нові дані." << std::endl;

            std::cout << "Введіть нову дату (YYYY-MM-DD): ";
            std::string newDate;
            std::cin >> newDate;
            if (!validateDate(newDate)) {
                std::cerr << "Некоректний формат дати!" << std::endl;
                return;
            }
            receipts[i].date = newDate;

            std::cout << "Введіть нову суму: ";
            double newAmount;
            std::cin >> newAmount;
            if (newAmount < 0) {
                std::cerr << "Сума не може бути від'ємною!" << std::endl;
                return;
            }
            receipts[i].amount = newAmount;

            std::cout << "Дані оновлено." << std::endl;
            return;
        }
    }
    std::cerr << "Квитанцію з таким номером не знайдено!" << std::endl;
}

// Перевірка формату дати
bool Receipt::validateDate(const std::string &date) const {
    std::regex dateRegex(R"(\d{4}-\d{2}-\d{2})");
    return std::regex_match(date, dateRegex);
}
