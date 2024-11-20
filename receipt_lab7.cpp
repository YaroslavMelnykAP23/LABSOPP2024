#include "receipt_lab7.h"
#include <regex>

// Конструктор
Receipt::Receipt() {
    std::cout << "Клас Receipt створено." << std::endl;
}

// Деструктор
Receipt::~Receipt() {
    std::cout << "Клас Receipt знищено." << std::endl;
}

// Метод додавання квитанції
void Receipt::addReceipt() {
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

    receipts.push_back(newReceipt);
    std::cout << "Квитанцію додано!" << std::endl;
}

// Метод вставки квитанції на задану позицію
void Receipt::insertReceipt(int index) {
    if (index < 0 || index > receipts.size()) {
        std::cerr << "Некоректна позиція!" << std::endl;
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

    receipts.insert(receipts.begin() + index, newReceipt);
    std::cout << "Квитанцію вставлено!" << std::endl;
}

// Видалення квитанції за номером
void Receipt::removeReceipt(int id) {
    auto it = std::find_if(receipts.begin(), receipts.end(),
                           [id](const receipt_t &r) { return r.id == id; });

    if (it != receipts.end()) {
        receipts.erase(it);
        std::cout << "Квитанцію видалено!" << std::endl;
    } else {
        std::cerr << "Квитанцію з таким номером не знайдено!" << std::endl;
    }
}

// Очищення списку квитанцій
void Receipt::clearReceipts() {
    receipts.clear();
    std::cout << "Список квитанцій очищено!" << std::endl;
}

// Обмін квитанцій за їх номерами
void Receipt::swapReceipts(int id1, int id2) {
    auto it1 = std::find_if(receipts.begin(), receipts.end(),
                            [id1](const receipt_t &r) { return r.id == id1; });
    auto it2 = std::find_if(receipts.begin(), receipts.end(),
                            [id2](const receipt_t &r) { return r.id == id2; });

    if (it1 != receipts.end() && it2 != receipts.end()) {
        std::swap(*it1, *it2);
        std::cout << "Квитанції обміняно!" << std::endl;
    } else {
        std::cerr << "Не вдалося знайти одну або обидві квитанції!" << std::endl;
    }
}

// Виведення всіх квитанцій
void Receipt::printReceipts() const {
    if (receipts.empty()) {
        std::cout << "Список квитанцій порожній." << std::endl;
        return;
    }

    std::cout << std::left << std::setw(10) << "Номер"
              << std::setw(15) << "Дата"
              << std::setw(15) << "Сума до сплати" << std::endl;
    std::cout << std::string(40, '-') << std::endl;

    for (const auto &r : receipts) {
        std::cout << std::left << std::setw(10) << r.id
                  << std::setw(15) << r.date
                  << std::fixed << std::setprecision(2)
                  << std::setw(15) << r.amount << std::endl;
    }
}

// Перевірка дати
bool Receipt::validateDate(const std::string &date) const {
    std::regex dateRegex(R"(\d{4}-\d{2}-\d{2})");
    return std::regex_match(date, dateRegex);
}

// Редагування квитанції
void Receipt::modifyReceipt(int id) {
    for (auto &r : receipts) {
        if (r.id == id) {
            std::cout << "Введіть нову дату (YYYY-MM-DD): ";
            std::string newDate;
            std::cin >> newDate;
            if (!validateDate(newDate)) {
                std::cerr << "Некоректний формат дати!" << std::endl;
                return;
            }
            r.date = newDate;

            std::cout << "Введіть нову суму: ";
            double newAmount;
            std::cin >> newAmount;
            if (newAmount < 0) {
                std::cerr << "Сума не може бути від'ємною!" << std::endl;
                return;
            }
            r.amount = newAmount;

            std::cout << "Квитанцію оновлено!" << std::endl;
            return;
        }
    }
    std::cerr << "Квитанцію з таким номером не знайдено!" << std::endl;
}
