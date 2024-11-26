#ifndef RECEIPT_H_LAB6
#define RECEIPT_H_LAB6

#include <iostream>
#include <string>
#include <array>

// Структура для зберігання даних квитанції
struct receipt_t {
    int id;             // Номер квитанції
    std::string date;   // Дата
    double amount;      // Сума до сплати
};

// Клас Квитанція
class Receipt {
private:
    static const int SIZE = 10;              // Максимальна кількість квитанцій
    std::array<receipt_t, SIZE> receipts;    // Масив квитанцій
    int currentCount;                        // Поточна кількість квитанцій

public:
    // Конструктор та деструктор
    Receipt();
    ~Receipt();

    // Методи
    void addReceipt();                      // Додавання квитанції
    void printReceipts() const;             // Виведення всіх квитанцій
    void modifyReceipt(int id);             // Редагування квитанції
    bool validateDate(const std::string &date) const;  // Перевірка формату дати
};

#endif
