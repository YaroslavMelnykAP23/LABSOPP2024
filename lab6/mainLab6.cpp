#include "Receipt_Lab6.h"

int main() {
    Receipt receiptManager;

    while (true) {
        std::cout << "\n1. Додати квитанцію\n"
                  << "2. Вивести всі квитанції\n"
                  << "3. Редагувати квитанцію\n"
                  << "4. Вийти\n"
                  << "Ваш вибір: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                receiptManager.addReceipt();
                break;
            case 2:
                receiptManager.printReceipts();
                break;
            case 3:
                std::cout << "Введіть номер квитанції для редагування: ";
                int id;
                std::cin >> id;
                receiptManager.modifyReceipt(id);
                break;
            case 4:
                return 0;
            default:
                std::cerr << "Некоректний вибір!" << std::endl;
        }
    }
}
