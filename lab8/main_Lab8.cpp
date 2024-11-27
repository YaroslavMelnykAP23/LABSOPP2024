#include "receipt_Lab8.h"
#include <iostream>

int main() {
    // Створення двох квитанцій
    Receipt receipt1;
    Receipt receipt2;

    // Ввід даних першої квитанції
    std::cout << "Введення даних для першої квитанції:\n";
    receipt1.inputReceipt();

    // Ввід даних другої квитанції
    std::cout << "\nВведення даних для другої квитанції:\n";
    receipt2.inputReceipt();

    // Виведення даних обох квитанцій
    std::cout << "\nДані першої квитанції:\n";
    receipt1.printReceipt();

    std::cout << "\nДані другої квитанції:\n";
    receipt2.printReceipt();

    // Обчислення загальної суми
    double totalAmount = receipt1.getAmount() + receipt2.getAmount();
    std::cout << "\nЗагальна сума до сплати: " << totalAmount << std::endl;

    return 0;
}
