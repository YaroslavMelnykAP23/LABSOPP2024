#ifndef RECEIPT_H_LAB8
#define RECEIPT_H_LAB8

#include <string>
#include <iostream>

// Базовий клас
class BaseReceipt {
private:
    int number;
    std::string date;

protected:
    int getNumber() const;
    void setNumber(int num);
    std::string getDate() const;
    void setDate(const std::string& d);

public:
    BaseReceipt(int num = 0, const std::string& d = "");
    virtual ~BaseReceipt();

    virtual void inputReceipt();
    virtual void printReceipt() const;
};

// Похідний клас
class Receipt : public BaseReceipt {
private:
    double amount;

public:
    // Конструктор
    Receipt(int num = 0, const std::string& d = "", double amt = 0.0);

    // Деструктор
    ~Receipt();

    // Геттери і сеттери для доступу до суми
    double getAmount() const;
    void setAmount(double amt);

    // Перевизначені методи для введення і виведення
    void inputReceipt() override;
    void printReceipt() const override;
};

#endif // RECEIPT_H_LAB8
