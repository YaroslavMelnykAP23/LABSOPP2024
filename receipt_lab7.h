#ifndef RECEIPT_H_LAB7
#define RECEIPT_H_LAB7

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

// Структура для зберігання інформації про квитанцію
struct receipt_t {
    int id;              // Номер квитанції
    std::string date;    // Дата (формат YYYY-MM-DD)
    double amount;       // Сума до сплати
};

// Клас Receipt
class Receipt {
private:
    std::vector<receipt_t> receipts;  // Динамічний список квитанцій

public:
    // Конструктор та деструктор
    Receipt();
    ~Receipt();

    // Методи для введення/виведення
    void addReceipt();                     // Додати квитанцію
    void insertReceipt(int index);         // Вставити квитанцію
    void removeReceipt(int id);            // Видалити квитанцію за номером
    void clearReceipts();                  // Очистити список квитанцій
    void swapReceipts(int id1, int id2);   // Обміняти дві квитанції

    void printReceipts() const;            // Вивести всі квитанції
    bool validateDate(const std::string &date) const; // Перевірка дати

    // Додаткові методи
    void modifyReceipt(int id);            // Редагувати квитанцію
};

#endif